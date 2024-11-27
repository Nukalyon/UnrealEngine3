// Fill out your copyright notice in the Description page of Project Settings.


#include "PreciousRock.h"

#include "Components/BoxComponent.h"

// Sets default values
APreciousRock::APreciousRock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root; // Set the root component of the actor

	// Create the static mesh component
	Rock = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rock"));
	Rock->SetupAttachment(Root);

	//Attach a collision box to the lever
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(Rock);
	CollisionBox->SetCollisionProfileName(TEXT("Trigger")); // Set appropriate collision profile
}

// Called when the game starts or when spawned
void APreciousRock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APreciousRock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

