// Fill out your copyright notice in the Description page of Project Settings.


#include "Temple.h"

// Sets default values
ATemple::ATemple()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root; // Set the root component of the actor

	// Create the static mesh component
	meshTemple = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshTemple"));
	meshTemple->SetupAttachment(Root); // Attach the mesh component to the root
}

// Called when the game starts or when spawned
void ATemple::BeginPlay()
{
	Super::BeginPlay();
	
	// Example of finding and assigning a mesh
	FindAndAssignMesh(TEXT("Temple_Floor"), meshTemple);
}

// Called every frame
void ATemple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATemple::FindAndAssignMesh(const FString& MeshName, UStaticMeshComponent* staticComponent)
{
	FString FoundMeshPath;
	if (UFindMeshFile::FindMeshByName(MeshName, FoundMeshPath))
	{
		// Ensure the path is correctly formatted
		// Remove the .uasset extension if it's included
		FString extension = TEXT(".uasset");
		if (FoundMeshPath.EndsWith(TEXT(".uasset")))
		{
			FoundMeshPath = FoundMeshPath.LeftChop(extension.Len()); // Remove ".uasset"
		}

		// Construct the correct load path
		FString CorrectPath = FString::Printf(TEXT("StaticMesh'%s'"), *FoundMeshPath);

		// Load the static mesh from the found path
		UStaticMesh* LoadedMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *CorrectPath));

		if (LoadedMesh)
		{
			// Assign the loaded mesh to the static mesh component
			staticComponent->SetStaticMesh(LoadedMesh);
			UE_LOG(LogTemp, Log, TEXT("Assigned mesh: %s"), *CorrectPath);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load mesh from path: %s"), *CorrectPath);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Mesh not found: %s"), *MeshName);
	}
}

