// Fill out your copyright notice in the Description page of Project Settings.


#include "Lever_panel.h"
#include "Components/BoxComponent.h"

// Sets default values
ALever_panel::ALever_panel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root; // Set the root component of the actor

	// Create the static mesh component
	panel_right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Panel"));
	panel_right->SetupAttachment(Root); // Attach the mesh component to the root
	// Create the static mesh component
	lever = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lever"));
	lever->SetupAttachment(panel_right); // Attach the mesh component to the panel

	//Attach a collision box to the lever
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(lever);
	CollisionBox->SetCollisionProfileName(TEXT("Trigger")); // Set appropriate collision profile

}

// Called when the game starts or when spawned
void ALever_panel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALever_panel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(startlifting && !isUsed)
	{
		FRotator currentLeverRotation = lever->GetRelativeRotation();
		if(currentIncrement <= maxIncrement)
		{
			currentLeverRotation.Yaw += 1;
			currentIncrement++;
			lever->SetRelativeRotation(currentLeverRotation);
		}
		else
		{
			startlifting = false;
			isUsed = true;
		}
	}
}

void ALever_panel::openDoors()
{
	//lever->SetRelativeRotation(FRotator(0, 0, 0));
	if(IsValid(doorsRef))
	{
		startlifting = true;
		doorsRef->OpenDoor();
	}
}

bool ALever_panel::GetIsUsed() const
{
	return this->isUsed;
}

