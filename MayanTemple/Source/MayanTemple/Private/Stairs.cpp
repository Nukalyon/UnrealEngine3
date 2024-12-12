#include "Stairs.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h" // Include for UBoxComponents

// Sets default values
AStairs::AStairs()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create the root component
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent = Root; // Set the root component of the actor
    
    // Create stair components
    for (int32 i = 1; i <= 9; ++i)
    {
        FString StairName = FString::Printf(TEXT("Stair%02d"), i);
        UStaticMeshComponent* Stair = CreateDefaultSubobject<UStaticMeshComponent>(*StairName);
        Stair->SetupAttachment(Root);
        Stairs.Add(Stair); // Store the stair component in an array for easy access
    }

    CollisionBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollisionBox"));
    CollisionBox->SetupAttachment(Root);

    // Initialize pop-up variables
    PopProgress = 0.0f;
    bIsPopping = false;
    PopDuration = 1.0f; // Set the duration for the pop-up
}

// Called when the game starts or when spawned
void AStairs::BeginPlay()
{
    Super::BeginPlay();
    StartLocation = GetActorLocation();
    EndLocation = GetActorLocation().DownVector * 50;
    SetActorLocation(EndLocation);
}

// Called every frame
void AStairs::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsPopping)
    {
        // Calculate the new position using Lerp
        for (int32 i = 0; i < Stairs.Num(); ++i)
        {
            FVector NewLocation = FMath::Lerp(EndLocation + FVector(0, 0, -100 * (i + 1)), StartLocation, PopProgress);
            Stairs[i]->SetWorldLocation(NewLocation);
        }
        //CollisionBox->SetWorldLocation(FMath::Lerp(StartLocation + FVector(0, 0, -100), EndLocation + FVector(0, 0, 0), PopProgress));

        // Update the progress
        PopProgress += DeltaTime / PopDuration;

        // Check if the pop is complete
        if (PopProgress >= 1.0f)
        {
            bIsPopping = false; // Stop popping
        }
    }
}

void AStairs::Rise()
{
	PopProgress = 0.0f; // Reset progress
	bIsPopping = true; // Start popping
}