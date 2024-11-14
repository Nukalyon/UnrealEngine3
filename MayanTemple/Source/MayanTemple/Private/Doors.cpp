// Fill out your copyright notice in the Description page of Project Settings.


#include "Doors.h"

#include "FindMeshFile.h"

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
	
}

// Called when the game starts or when spawned
void ADoors::BeginPlay()
{
	Super::BeginPlay();	
	// Example of finding and assigning a mesh
	UFindMeshFile::FindAndAssignMesh("Door_Room1_R", porteDroite);
	// Example of finding and assigning a mesh
	UFindMeshFile::FindAndAssignMesh("Door_Room1_L", porteGauche);

	
}

// Called every frame
void ADoors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoors::OpenDoor()
{
	//Logic to open the doors
	UE_LOG(LogTemp, Log, TEXT("Enter openDoor()"));

}

