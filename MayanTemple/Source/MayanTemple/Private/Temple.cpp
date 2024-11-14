#include "Temple.h"
#include "FindMeshFile.h"

// Sets default values
ATemple::ATemple()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root; // Set the root component of the actor

	// Create the static mesh component
	floor_room1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor_Room_1"));
	floor_room1->SetupAttachment(Root); // Attach the mesh component to the root
	floor_room2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor_Room_2"));
	floor_room2->SetupAttachment(Root); // Attach the mesh component to the root
	floor_room3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor_Room_3"));
	floor_room3->SetupAttachment(Root); // Attach the mesh component to the root
	floor_room4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor_Room_4"));
	floor_room4->SetupAttachment(Root); // Attach the mesh component to the root

	
}

// Called when the game starts or when spawned
void ATemple::BeginPlay()
{
	Super::BeginPlay();

	// Ensure the mesh manager is initialized before finding and assigning the mesh
	//UFindMeshFile::InitializeMeshManager();
	
	// Example of finding and assigning a mesh
	UFindMeshFile::FindAndAssignMesh("Floor_001", floor_room1);
	UFindMeshFile::FindAndAssignMesh("Floor_002", floor_room2);
	UFindMeshFile::FindAndAssignMesh("Floor_003", floor_room3);
	UFindMeshFile::FindAndAssignMesh("Floor_004", floor_room4);

}

// Called every frame
void ATemple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
