// Fill out your copyright notice in the Description page of Project Settings.


#include "VaultDoor.h"

// Sets default values
AVaultDoor::AVaultDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root; // Set the root component of the actor
	VaultDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Vault Door"));
	VaultDoor->SetupAttachment(Root);
	AngleDeg = 360.0f / 700.0f;
}

// Called when the game starts or when spawned
void AVaultDoor::BeginPlay()
{
	Super::BeginPlay();
	BaseLocation = VaultDoor->GetComponentTransform().GetLocation();
}

// Called every frame
void AVaultDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bCanBeOpen)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AVaultDoor EnableMovement "));
		currentSlidingAmount += OpenSpeed * DeltaTime;

		//UE_LOG(LogTemp, Error, TEXT("Amount : %f"), currentSlidingAmount);
		if(currentSlidingAmount >= OpenDistance)
		{
			currentSlidingAmount = OpenDistance;
			bCanBeOpen = false;
		}
		else
		{
			FTransform DoorTransform = VaultDoor->GetRelativeTransform();
			FVector DoorLocation = DoorTransform.GetLocation();
			FVector DoorRotation = DoorTransform.GetRotation().Euler();
			
			DoorLocation.X -= currentSlidingAmount;
			
			FRotator newRotator = FRotator(DoorRotation.Y + AngleDeg, 0, 0);
			
			VaultDoor->SetRelativeLocation(DoorLocation);
			VaultDoor->SetRelativeRotation(newRotator);
		}		
	}
}

void AVaultDoor::EnableMovement()
{
	//Open the door
	bCanBeOpen = true;
}