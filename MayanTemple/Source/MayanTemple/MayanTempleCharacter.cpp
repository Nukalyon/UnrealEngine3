// Copyright Epic Games, Inc. All Rights Reserved.

#include "MayanTempleCharacter.h"

#include "Autel.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "PlayerWidget.h"
#include "PreciousRock.h"
#include "VaultLock.h"
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
	InspectOrigin->SetRelativeLocation(FVector(40.f, 0.f, 0.f));
	
	HoldOrigin = CreateDefaultSubobject<USceneComponent>(TEXT("Holdrigin"));
	HoldOrigin->SetupAttachment(FirstPersonCameraComponent);

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
	
	if(PlayerWidgetClass)
	{
		auto userWidget =  CreateWidget<UUserWidget>(GetWorld(), PlayerWidgetClass);
		PlayerWidget = Cast<UPlayerWidget>(userWidget);
		if(PlayerWidget)
		{
			PlayerWidget->AddToViewport();
			PlayerWidget->togglePrompts(false);
		}
	}
}

void AMayanTempleCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if ((!isInspecting && !isHolding) || isAbleToPlaceRock || isAbleToUseKey)
	{
		FHitResult HitResult;
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * 500.f;
		FCollisionObjectQueryParams QueryParams;
		QueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	
		FCollisionQueryParams CollisionParams;
		CollisionParams.bTraceComplex = true;
		CollisionParams.AddIgnoredActor(this);

		if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams))
		{
			ALever_panel* HitLever = Cast<ALever_panel>(HitResult.GetActor());
			APreciousRock* HitRock = Cast<APreciousRock>(HitResult.GetActor());
			AAutel* HitAutel = Cast<AAutel>(HitResult.GetActor());
			AVaultKey* HitKey = Cast<AVaultKey>(HitResult.GetActor());
			AVaultLock* HitLock = Cast<AVaultLock>(HitResult.GetActor());

			if (HitLever && !isAbleToPlaceRock)
			{
				//UE_LOG(LogTemp, Warning, TEXT("HitLever"));
				PlayerWidget->setPromptF(false);
				PlayerWidget->setPromptR(true);
				CurrentInspectActor = HitLever;
			}
			else if (HitRock && !isAbleToPlaceRock)
			{
				//UE_LOG(LogTemp, Warning, TEXT("HitRock"));
				PlayerWidget->togglePrompts(true);
				CurrentInspectActor = HitRock;
			}
			else if(HitAutel && isAbleToPlaceRock)
			{
				//UE_LOG(LogTemp, Warning, TEXT("HitAutel"));
				PlayerWidget->setPromptF(false);
				PlayerWidget->setPromptR(true);
				CurrentInspectActor = HitAutel;
			}
			else if(HitKey && !isAbleToPlaceRock)
			{
				//UE_LOG(LogTemp, Warning, TEXT("HitKey"));
				PlayerWidget->setPromptF(false);
				PlayerWidget->setPromptR(true);
				CurrentInspectActor = HitKey;
			}
			else if(HitLock && isAbleToUseKey)
			{
				PlayerWidget->setPromptF(false);
				PlayerWidget->setPromptR(true);
				CurrentInspectActor = HitLock;
			}
			else
			{
				PlayerWidget->togglePrompts(false);
				CurrentInspectActor = nullptr;
			}
		}
		else
		{
			PlayerWidget->togglePrompts(false);
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
		//Exit Inspect
		EnhancedInputComponent->BindAction(ExitInspectAction, ETriggerEvent::Triggered, this, &AMayanTempleCharacter::ExitInspect);
		//Rotate Inspect
		EnhancedInputComponent->BindAction(RotateInspectAction, ETriggerEvent::Triggered, this, &AMayanTempleCharacter::RotateInspect);
		
		//Interact with Actor
		EnhancedInputComponent->BindAction(EnterHoldActorAction, ETriggerEvent::Triggered, this, &AMayanTempleCharacter::EnterHoldActor);
		//Interact with Actor
		EnhancedInputComponent->BindAction(ExitHoldActorAction, ETriggerEvent::Triggered, this, &AMayanTempleCharacter::ExitHoldActor);
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
		PlayerWidget->togglePrompts(false);
		// if the player is look at a rock
		if(CurrentInspectActor->IsA<APreciousRock>()){
			//UE_LOG(LogTemp, Warning, TEXT("Object is APreciousRock"));
			Cast<APreciousRock>(CurrentInspectActor)->TogglePhysics(false);
			InspectOrigin->SetRelativeRotation(FRotator::ZeroRotator);
			InitialInspectTransform = CurrentInspectActor->GetActorTransform();
			CurrentInspectActor->AttachToComponent(InspectOrigin, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

			//Mapping changement
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
		Cast<APreciousRock>(CurrentInspectActor)->TogglePhysics(true);
		CurrentInspectActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
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
	// Check if we are currently inspecting an object
	if (isInspecting)
	{
		// Get the mouse movement input
		FVector2D MouseDelta = InputActionValue.Get<FVector2D>();

		// Sensitivity factor for rotation
		const float Sensitivity = 1.0f;

		// Calculate the rotation based on mouse movement
		FRotator NewRotation = CurrentInspectActor->GetActorRotation();
		NewRotation.Yaw += MouseDelta.X * Sensitivity;
		NewRotation.Pitch -= MouseDelta.Y * Sensitivity;

		// Apply the new rotation to the object
		CurrentInspectActor->SetActorRotation(NewRotation);
	}
}

void AMayanTempleCharacter::EnterHoldActor(const FInputActionValue& InputActionValue)
{
	//UE_LOG(LogTemp, Warning, TEXT("CurrentInspectActor: %s"), *GetNameSafe(CurrentInspectActor));
	//UE_LOG(LogTemp, Warning, TEXT("CurrentHoldActor: %s"), *GetNameSafe(CurrentHoldActor));
	
	PlayerWidget->togglePrompts(false);
	if(!isHolding && IsValid(CurrentInspectActor))
	{
		//Utilisation du levier
		if(CurrentInspectActor->IsA<ALever_panel>())
		{
			ALever_panel* temp = Cast<ALever_panel>(CurrentInspectActor);
			if(!temp->GetIsUsed())
			{
				temp->openDoors();
			}
		}
		// Utilisation qui fait changer le mapping
		else 
		{
			isHolding = true;
			// Utilisation des pierres
			if(CurrentInspectActor->IsA<APreciousRock>())
			{
				isAbleToPlaceRock = true;
				CurrentHoldActor = CurrentInspectActor;			
				APreciousRock* rock = Cast<APreciousRock>(CurrentInspectActor);
				rock->TogglePhysics(false);
			}
			//Utilisation de la clef
			else if(CurrentInspectActor->IsA<AVaultKey>())
			{
				isAbleToUseKey = true;
				CurrentHoldActor = CurrentInspectActor;
				AVaultKey* key = Cast<AVaultKey>(CurrentInspectActor);
				key->TogglePhysics(false);
			}
			
			HoldOrigin->SetRelativeRotation(FRotator::ZeroRotator);
			CurrentInspectActor->AttachToComponent(HoldOrigin, FAttachmentTransformRules::SnapToTargetIncludingScale);
			
			auto PlayerController = Cast<APlayerController>(GetController());
			auto inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
				PlayerController->GetLocalPlayer());
			inputSubsystem->RemoveMappingContext(DefaultMappingContext);
			inputSubsystem->AddMappingContext(HoldActorMappingContext, 0);
		}		
	}
	UE_LOG(LogTemp, Warning, TEXT("CurrentInspectActor: %s"), *GetNameSafe(CurrentInspectActor));
	UE_LOG(LogTemp, Warning, TEXT("CurrentHoldActor: %s"), *GetNameSafe(CurrentHoldActor));
}

void AMayanTempleCharacter::ExitHoldActor(const FInputActionValue& InputActionValue)
{
	if(isHolding)
	{
		//UE_LOG(LogTemp, Warning, TEXT("CurrentInspectActor: %s"), *GetNameSafe(CurrentInspectActor));
		//UE_LOG(LogTemp, Warning, TEXT("CurrentHoldActor: %s"), *GetNameSafe(CurrentHoldActor));
	
		if(IsValid(CurrentInspectActor))
		{
			if(isAbleToPlaceRock && CurrentInspectActor->IsA<AActor>())
			{
				isAbleToPlaceRock = false;
				// on détache le currentholdactor, on le fixe dans l'autel à sa position
				AAutel* autel = Cast<AAutel>(CurrentInspectActor);
				APreciousRock* rock = Cast<APreciousRock>(CurrentHoldActor);
				autel->SnapThatRock(rock);
			}
			else if(isAbleToUseKey && CurrentInspectActor->IsA<AVaultLock>())
			{
				isAbleToUseKey = false;
				Cast<AVaultKey>(CurrentInspectActor)->UseKey();
			}
		}
		else
		{
			if(isAbleToPlaceRock)
			{
				isAbleToPlaceRock = false;
				Cast<APreciousRock>(CurrentHoldActor)->TogglePhysics(true);
			}
			if(isAbleToUseKey)
			{
				isAbleToUseKey = false;
				Cast<AVaultKey>(CurrentHoldActor)->TogglePhysics(true);
			}
		}
		isHolding = false;
		CurrentHoldActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		CurrentHoldActor = nullptr;
	}

	auto PlayerController = Cast<APlayerController>(GetController());
	auto inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		PlayerController->GetLocalPlayer());
	inputSubsystem->RemoveMappingContext(HoldActorMappingContext);
	inputSubsystem->AddMappingContext(DefaultMappingContext, 0);	
}
