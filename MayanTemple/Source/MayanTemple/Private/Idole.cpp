// Fill out your copyright notice in the Description page of Project Settings.


#include "Idole.h"

// Sets default values
AIdole::AIdole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Idole = CreateDefaultSubobject<UStaticMeshComponent>("Idole");
	RootComponent = Idole;
}

// Called when the game starts or when spawned
void AIdole::BeginPlay()
{
	Super::BeginPlay();
	TogglePhysics(true);
}

// Called every frame
void AIdole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AIdole::CollectIdole()
{
	
}

void AIdole::TogglePhysics(bool isEnabled)
{
	//UE_LOG(LogTemp, Warning, TEXT("Physics toggled to %s"), isEnabled ? TEXT("true") : TEXT("false"));
	Idole->SetSimulatePhysics(isEnabled);
	Idole->SetEnableGravity(isEnabled);
	Idole->SetCollisionEnabled(isEnabled ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
	Idole->SetCollisionResponseToAllChannels(ECR_Block); // Block all by default
	Idole->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // Ignore player character (Pawn)
}

