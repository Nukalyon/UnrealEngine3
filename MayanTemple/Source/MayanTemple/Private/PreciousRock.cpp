// Fill out your copyright notice in the Description page of Project Settings.


#include "PreciousRock.h"

#include "Autel.h"

// Sets default values
APreciousRock::APreciousRock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the root component
	//Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//RootComponent = Root;

	// Create the static mesh component
	Rock = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rock"));
	//Rock->SetupAttachment(Root);
	RootComponent = Rock;

	RockOptions.Add(TEXT("Gold"));
	RockOptions.Add(TEXT("Jade"));
	RockOptions.Add(TEXT("Obsidian"));
	RockOptions.Add(TEXT("Turquoise"));

}

// Called when the game starts or when spawned
void APreciousRock::BeginPlay()
{
	Super::BeginPlay();
	RockName = RockOptions[RockNameIndex];
	TogglePhysics(true);
}

// Called every frame
void APreciousRock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}

void APreciousRock::TogglePhysics(bool isEnabled)
{
	//UE_LOG(LogTemp, Warning, TEXT("Physics toggled to %s"), isEnabled ? TEXT("true") : TEXT("false"));
	Rock->SetSimulatePhysics(isEnabled);
	Rock->SetEnableGravity(isEnabled);
	Rock->SetCollisionEnabled(isEnabled ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
	Rock->SetCollisionResponseToAllChannels(ECR_Block); // Block all by default
	Rock->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // Ignore player character (Pawn)
}
