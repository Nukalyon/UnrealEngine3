// Fill out your copyright notice in the Description page of Project Settings.


#include "Autel.h"


// Sets default values
AAutel::AAutel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create the root component
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root;

	Altar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Autel"));
	Altar->SetupAttachment(Root);
	GoldPlace = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gold Space"));
	GoldPlace->SetupAttachment(Root);
	JadePlace = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Jade Space"));
	JadePlace->SetupAttachment(Root);
	ObsidianPlace = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Obsidian Space"));
	ObsidianPlace->SetupAttachment(Root);	
	TurquoisePlace = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turquoise Space"));
	TurquoisePlace->SetupAttachment(Root);

	NS_Rocks = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NS_Rocks"));
	NS_Rocks->SetupAttachment(Root);

	
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

void AAutel::ActivateNiagara(APreciousRock* rock)
{
	//Switch with the rock
	//Activate Niagara here for specific rock
	//Set relative location, change main color // second ?
}

void AAutel::SnapThatRock(APreciousRock* rock)
{
	//UE_LOG(LogTemp, Warning, TEXT("Enter SnapThatRock"));
	//UE_LOG(LogTemp, Warning, TEXT("This rock %s"), *rock->GetName());
	if(!Rocks.IsEmpty())
	{
		VariableSizeType index = Rocks.Find(rock);
		if(index != INDEX_NONE)
		{
			NS_Rocks->Deactivate();
			//UE_LOG(LogTemp, Warning, TEXT("Pierre trouvée %s"), *rock->RockName);
			
			switch (rock->RockNameIndex)
			{
				case 0:
					rock->AttachToComponent(GoldPlace, FAttachmentTransformRules::KeepWorldTransform);
					rock->SetActorTransform(GoldPlace->GetComponentTransform());
					break;
				case 1:
					rock->AttachToComponent(JadePlace, FAttachmentTransformRules::KeepWorldTransform);
					rock->SetActorTransform(JadePlace->GetComponentTransform());
						break;
				case 2:
					rock->AttachToComponent(ObsidianPlace, FAttachmentTransformRules::KeepWorldTransform);
					rock->SetActorTransform(ObsidianPlace->GetComponentTransform());
						break;
				case 3:
					rock->AttachToComponent(TurquoisePlace, FAttachmentTransformRules::KeepWorldTransform);
					rock->SetActorTransform(TurquoisePlace->GetComponentTransform());
					break;
				default: ;
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Pierre non trouvée"));
		}
	}
	//ActivateNiagara(rock, true);
	//Snap the rock to its socket
}

/*
 *#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "NiagaraFunctionLibrary.h"

// Example Actor class where we will handle the color change
class AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor()
    {
        // Create the Niagara Component as a subobject
        NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));

        // Find and assign the Niagara System
        static ConstructorHelpers::FObjectFinder<UNiagaraSystem> NiagaraSystemAsset(TEXT("NiagaraSystem'/Game/Path/To/Your/NiagaraSystem.NiagaraSystem'"));
        if (NiagaraSystemAsset.Succeeded())
        {
            NiagaraComponent->SetAsset(NiagaraSystemAsset.Object);
        }

        // Attach the Niagara Component to the actor's root
        NiagaraComponent->SetupAttachment(RootComponent);

        // Optionally activate it at start
        NiagaraComponent->Activate();
    }

    // Method to change the color based on the rock picked up
    void ChangeNiagaraColor(FLinearColor NewColor)
    {
        if (NiagaraComponent)
        {
            // Set the new color to the Niagara system (assuming "User.Color" is the color parameter in Niagara)
            NiagaraComponent->SetVectorParameter("User.Color", NewColor);
        }
    }

    // Example of handling rock pickup logic
    void OnRockPickedUp(int32 RockType)
    {
        // Change the color based on the rock picked up
        FLinearColor NewColor;

        switch (RockType)
        {
        case 0:  // Rock Type 0
            NewColor = FLinearColor::Red;  // Red for rock type 0
            break;
        case 1:  // Rock Type 1
            NewColor = FLinearColor::Blue;  // Blue for rock type 1
            break;
        case 2:  // Rock Type 2
            NewColor = FLinearColor::Green;  // Green for rock type 2
            break;
        default:
            NewColor = FLinearColor::White;  // Default to white
            break;
        }

        // Apply the new color to the Niagara system
        ChangeNiagaraColor(NewColor);
    }

protected:
    UPROPERTY(VisibleAnywhere, Category = "FX")
    UNiagaraComponent* NiagaraComponent;
};

 */