// Copyright Epic Games, Inc. All Rights Reserved.

#include "InspectModeCharacter.h"
#include "InspectModeProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "MovieSceneTracksComponentTypes.h"
#include "PlayerWidget.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AInspectModeCharacter

AInspectModeCharacter::AInspectModeCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	InspectOrigin = CreateDefaultSubobject<USceneComponent>(TEXT("InspectOrigin"));
	InspectOrigin->SetupAttachment(FirstPersonCameraComponent);
	InspectOrigin->SetRelativeLocation(FVector(40.f, 0.f, 0.f)); // Position the camera

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));
}

void AInspectModeCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//On assigne le UI
	auto userWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerWidgetClass);
	PlayerWidget = Cast<UPlayerWidget>(userWidget);
	PlayerWidget->AddToViewport();
}

void AInspectModeCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!isInspecting)
	{
		FHitResult Hit;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * 2000.f;
		FCollisionObjectQueryParams QueryParams;
		QueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

		FCollisionQueryParams CollisionParams;
		CollisionParams.bTraceComplex = true;
		CollisionParams.AddIgnoredActor(this);

		if (GetWorld()->LineTraceSingleByObjectType(Hit, Start, End, QueryParams, CollisionParams)
			&&
			IsValid(Hit.GetActor()))
		{
			CurrentInspectActor = Hit.GetActor();
			PlayerWidget->SetPromptF(true);
		}
		else
		{
			CurrentInspectActor = nullptr;
			PlayerWidget->SetPromptF(false);
		}
	}
}

//////////////////////////////////////////////////////////////////////////// Input

void AInspectModeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AInspectModeCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AInspectModeCharacter::Look);

		// EnterInspect
		EnhancedInputComponent->BindAction(EnterInspectAction, ETriggerEvent::Triggered, this,
		                                   &AInspectModeCharacter::EnterInspect);

		// ExitInspect
		EnhancedInputComponent->BindAction(ExitInspectAction, ETriggerEvent::Triggered, this,
		                                   &AInspectModeCharacter::ExitInspect);

		// RotateInspect
		EnhancedInputComponent->BindAction(RotateInspectAction, ETriggerEvent::Triggered, this,
		                                   &AInspectModeCharacter::RotateInspect);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error,
		       TEXT(
			       "'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."
		       ), *GetNameSafe(this));
	}
}


void AInspectModeCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		//PlayerWidget->SetPromptF(false);
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AInspectModeCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AInspectModeCharacter::EnterInspect()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Entering InspectMode");
	if (!isInspecting && IsValid(CurrentInspectActor))
	{
		isInspecting = true;
		PlayerWidget->SetPromptF(false);
		
		InspectOrigin->SetRelativeRotation(FRotator::ZeroRotator);
		InitialInspectTransform = CurrentInspectActor->GetActorTransform();
		CurrentInspectActor->AttachToComponent(InspectOrigin, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

		auto PlayerController = Cast<APlayerController>(GetController());
		auto inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
			PlayerController->GetLocalPlayer());
		inputSubsystem->RemoveMappingContext(DefaultMappingContext);
		inputSubsystem->AddMappingContext(InspectMappingContext, 0);
	}
}

void AInspectModeCharacter::ExitInspect()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Exiting InspectMode");

	if (isInspecting)
	{
		isInspecting = false;
		CurrentInspectActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		CurrentInspectActor->SetActorTransform(InitialInspectTransform);
		CurrentInspectActor = nullptr;

		//https://forums.unrealengine.com/t/get-enhanced-input-local-player-subsystem-in-c/1732524/2
		auto PlayerController = Cast<APlayerController>(GetController());
		auto inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
			PlayerController->GetLocalPlayer());
		inputSubsystem->RemoveMappingContext(InspectMappingContext);
		inputSubsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AInspectModeCharacter::RotateInspect()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, "Rotating InspectMode");
}
