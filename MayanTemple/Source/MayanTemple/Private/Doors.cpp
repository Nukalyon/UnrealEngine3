// Fill out your copyright notice in the Description page of Project Settings.


#include "Doors.h"

#include "Components/SphereComponent.h"

// Sets default values
ADoors::ADoors()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root; // Set the root component of the actor

	// Create the static mesh component
	porteDroite = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Porte Droite"));
	porteDroite->SetupAttachment(Root); // Attach the mesh component to the root
	// Create the static mesh component
	porteGauche = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Porte Gauche"));
	porteGauche->SetupAttachment(Root); // Attach the mesh component to the panel
	
	//Attach a collision box to the lever
	CollisionBox = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionBox->SetSphereRadius(300, false);
	CollisionBox->SetLineThickness(5.0f);
	CollisionBox->SetupAttachment(Root);
	CollisionBox->SetCollisionProfileName(TEXT("Trigger")); // Set appropriate collision profile
	
}

// Called when the game starts or when spawned
void ADoors::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADoors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isOpening)
	{
		// Increment the current open amount
		currentSlidingAmount += OpenSpeed * DeltaTime;

		// Clamp the value to the OpenDistance
		if (currentSlidingAmount >= OpenDistance)
		{
			currentSlidingAmount = OpenDistance;
			isOpening = false; // Stop opening when we reach the target distance
			isOpenedAtLeastOnce = true;
		}

		// Update the position of the doors
		FVector RightDoorLocation = porteDroite->GetRelativeLocation();
		RightDoorLocation.X += currentSlidingAmount; // Move the right door to the right
		porteDroite->SetRelativeLocation(RightDoorLocation);

		FVector LeftDoorLocation = porteGauche->GetRelativeLocation();
		LeftDoorLocation.X -= currentSlidingAmount; // Move the left door to the left
		porteGauche->SetRelativeLocation(LeftDoorLocation);
	}
	if(isClosing)
	{
		// Decrement the current open amount
		currentSlidingAmount -= OpenSpeed * DeltaTime;

		// Clamp the value to the OpenDistance
		if (currentSlidingAmount <= 0)
		{
			currentSlidingAmount = 0;
			isOpening = false; // Stop opening when we reach the target distance
		}

		// Update the position of the doors
		FVector RightDoorLocation = porteDroite->GetRelativeLocation();
		RightDoorLocation.X -= currentSlidingAmount; // Move the right door to the right
		porteDroite->SetRelativeLocation(RightDoorLocation);

		FVector LeftDoorLocation = porteGauche->GetRelativeLocation();
		LeftDoorLocation.X += currentSlidingAmount; // Move the left door to the left
		porteGauche->SetRelativeLocation(LeftDoorLocation);
	}
}

void ADoors::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Actor Begin Overlap"));
	if(isOpenedAtLeastOnce && !isOpening)
	{
		OpenDoor();
	}
	//Super::NotifyActorBeginOverlap(OtherActor);
}

void ADoors::NotifyActorEndOverlap(AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Actor End Overlap"));
	if(isOpenedAtLeastOnce && !isClosing)
	{
		CloseDoors();
	}
}

void ADoors::OpenDoor()
{
	//Logic to open the doors
	isOpening = true;
	isClosing = false;
	UE_LOG(LogTemp, Log, TEXT("Enter OpenDoor()"));
}

void ADoors::CloseDoors()
{
	isOpening = false;
	isClosing = true;
	UE_LOG(LogTemp, Log, TEXT("Enter CloseDoors()"));	
}


