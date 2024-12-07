// Fill out your copyright notice in the Description page of Project Settings.


#include "Stairs.h"

// Sets default values
AStairs::AStairs()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root; // Set the root component of the actor
	Stair01 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stair01"));
	Stair01->SetupAttachment(Root);
	Stair02 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stair02"));
	Stair02->SetupAttachment(Root);
	Stair03 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stair03"));
	Stair03->SetupAttachment(Root);
	Stair04 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stair04"));
	Stair04->SetupAttachment(Root);
	Stair05 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stair05"));
	Stair05->SetupAttachment(Root);
	Stair06 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stair06"));
	Stair06->SetupAttachment(Root);
	Stair07 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stair07"));
	Stair07->SetupAttachment(Root);
	Stair08 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stair08"));
	Stair08->SetupAttachment(Root);
	Stair09 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stair09"));
	Stair09->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AStairs::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStairs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

