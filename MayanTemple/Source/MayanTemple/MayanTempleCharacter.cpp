// Copyright Epic Games, Inc. All Rights Reserved.

#include "MayanTempleCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "PlayerWidget.h"
#include "PreciousRock.h"
#include "Lever_panel.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"

//DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AMayanTempleCharacter

AMayanTempleCharacter::AMayanTempleCharacter()
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

void AMayanTempleCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	
	isInspecting = false;
	isOverLever = false;
	isOverRock = false;
	if(PlayerWidgetClass)
	{
		auto userWidget =  CreateWidget<UUserWidget>(GetWorld(), PlayerWidgetClass);
		PlayerWidget = Cast<UPlayerWidget>(userWidget);
		if(PlayerWidget)
		{
			PlayerWidget->AddToViewport();
			PlayerWidget->setPromptF(false);
		}
	}
}

void AMayanTempleCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!isInspecting)
	{
		FHitResult HitResult;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * 2000.f;
		FCollisionObjectQueryParams QueryParams;
		QueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	
		FCollisionQueryParams CollisionParams;
		CollisionParams.bTraceComplex = true;
		CollisionParams.AddIgnoredActor(this);

		if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams))
		{
			ALever_panel* HitLever = Cast<ALever_panel>(HitResult.GetActor());
			APreciousRock* HitRock = Cast<APreciousRock>(HitResult.GetActor());

			if (HitLever)
			{
				isOverLever = true;
				isOverRock = false;
				PlayerWidget->setPromptF(true);
				CurrentInspectActor = HitLever;
			}
			else if (HitRock)
			{
				isOverRock = true;
				isOverLever = false;
				PlayerWidget->setPromptF(true);
				CurrentInspectActor = HitRock;
			}
			else
			{
				isOverRock = false;
				isOverLever = false;
				PlayerWidget->setPromptF(false);
				CurrentInspectActor = nullptr;
			}
		}
		else
		{
			isOverRock = false;
			isOverLever = false;
			PlayerWidget->setPromptF(false);
			CurrentInspectActor = nullptr;
		}
	}
}

//////////////////////////////////////////////////////////////////////////// Input

void AMayanTempleCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMayanTempleCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMayanTempleCharacter::Look);

		//Enter Inspect
		EnhancedInputComponent->BindAction(EnterInspectAction, ETriggerEvent::Triggered, this, &AMayanTempleCharacter::EnterInspect);

		//Enter Inspect
		EnhancedInputComponent->BindAction(ExitInspectAction, ETriggerEvent::Triggered, this, &AMayanTempleCharacter::ExitInspect);

		//Enter Inspect
		EnhancedInputComponent->BindAction(RotateInspectAction, ETriggerEvent::Triggered, this, &AMayanTempleCharacter::RotateInspect);
	}
	else
	{
		//UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void AMayanTempleCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AMayanTempleCharacter::Look(const FInputActionValue& Value)
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

void AMayanTempleCharacter::EnterInspect(const FInputActionValue& InputActionValue)
{
	if (!isInspecting && IsValid(CurrentInspectActor))
	{
		isInspecting = true;
		PlayerWidget->setPromptF(false);
		if(CurrentInspectActor->IsA<ALever_panel>())
		{
			ALever_panel* temp = Cast<ALever_panel>(CurrentInspectActor);
			temp->openDoors();
			isInspecting = false;
		}
		else
		{
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
}

void AMayanTempleCharacter::ExitInspect(const FInputActionValue& InputActionValue)
{
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

void AMayanTempleCharacter::RotateInspect(const FInputActionValue& InputActionValue)
{
}
