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
	KeySocket = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key Socket"));
	KeySocket->SetRelativeLocation(FVector(-12,1,65));
	KeySocket->SetRelativeRotation(FRotator(90,0,0));
	KeySocket->SetupAttachment(Root);

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
					NbRocksInAltar++;
					break;
				case 1:
					rock->AttachToComponent(JadePlace, FAttachmentTransformRules::KeepWorldTransform);
					rock->SetActorTransform(JadePlace->GetComponentTransform());
					NbRocksInAltar++;
					break;
				case 2:
					rock->AttachToComponent(ObsidianPlace, FAttachmentTransformRules::KeepWorldTransform);
					rock->SetActorTransform(ObsidianPlace->GetComponentTransform());
					NbRocksInAltar++;
					break;
				case 3:
					rock->AttachToComponent(TurquoisePlace, FAttachmentTransformRules::KeepWorldTransform);
					rock->SetActorTransform(TurquoisePlace->GetComponentTransform());
					NbRocksInAltar++;
					break;
				default: ;
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Pierre non trouvée"));
		}
		
		if(NbRocksInAltar == Rocks.Num())
		{
			DetachKey();
		}
	}
	//ActivateNiagara(rock, true);
	//Snap the rock to its socket
}

void AAutel::DetachKey()
{
	if(VaultKey)
	{
		KeySocket->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
		FVector DropLocation = KeySocket->GetComponentLocation() - FVector(10, 10, 10); // Adjust as needed
		KeySocket->SetWorldLocation(DropLocation);
		VaultKey->TogglePhysics(true);
	}
	
    /*
	
	KeySocket->SetSimulatePhysics(true);
	KeySocket->SetEnableGravity(true);
	KeySocket->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	*/
    
	// Log for debugging
	UE_LOG(LogTemp, Warning, TEXT("Key has been detached from the altar."));
	
}
