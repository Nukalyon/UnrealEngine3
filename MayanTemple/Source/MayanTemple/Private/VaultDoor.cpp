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

}

// Called when the game starts or when spawned
void AVaultDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVaultDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVaultDoor::EnableMovment()
{
	//Open the door
}

