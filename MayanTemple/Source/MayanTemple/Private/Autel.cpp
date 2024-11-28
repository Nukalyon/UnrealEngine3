// Fill out your copyright notice in the Description page of Project Settings.


#include "Autel.h"

// Sets default values
AAutel::AAutel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root; // Set the root component of the actor

	// Create the static mesh component
	Altar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Autel"));
	Altar->SetupAttachment(Root); // Attach the mesh component to the root
	// Create the static mesh component
	GoldPlace = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gold Space"));
	GoldPlace->SetupAttachment(Root); // Attach the mesh component to the root
	// Create the static mesh component
	JadePlace = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Jade Space"));
	JadePlace->SetupAttachment(Root); // Attach the mesh component to the root
	// Create the static mesh component
	ObsidianPlace = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obsidian Space"));
	ObsidianPlace->SetupAttachment(Root); // Attach the mesh component to the root
	// Create the static mesh component
	TurquoisePlace = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turquoise Space"));
	TurquoisePlace->SetupAttachment(Root); // Attach the mesh component to the root
}

// Called when the game starts or when spawned
void AAutel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAutel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

