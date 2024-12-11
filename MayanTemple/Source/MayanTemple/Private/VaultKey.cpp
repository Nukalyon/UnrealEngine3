// Fill out your copyright notice in the Description page of Project Settings.


#include "VaultKey.h"

#include "Autel.h"
#include "VaultLock.h"

// Sets default values
AVaultKey::AVaultKey()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	//RootComponent = Root;
	Key = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key"));
	RootComponent = Key;
	//Key->SetupAttachment(Root);
	TogglePhysics(false);
}

// Called when the game starts or when spawned
void AVaultKey::BeginPlay()
{
	Super::BeginPlay();
	if(autel)
	{
		Key->SetWorldScale3D(FVector(1.4f, 1.4f, 1.4f));
		Key->AttachToComponent(autel->KeySocket,  FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Référence Autel manquante pour BP_KeyVault"))
	}	
}

// Called every frame
void AVaultKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AVaultKey::TogglePhysics(bool isEnabled)
{
	//UE_LOG(LogTemp, Warning, TEXT("Physics toggled to %s"), isEnabled ? TEXT("true") : TEXT("false"));
	Key->SetSimulatePhysics(isEnabled);
	Key->SetEnableGravity(isEnabled);
	//Key->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.0f));
	Key->SetCollisionEnabled(isEnabled ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
	Key->SetCollisionResponseToAllChannels(ECR_Block); // Block all by default
	Key->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // Ignore player character (Pawn)
}

void AVaultKey::UseKey()
{
	if(IsValid(VaultLock))
	{
		//Logic for the key to open the vaultDoor
		UE_LOG(LogTemp, Warning, TEXT("Enter UseKey()"));
		VaultLock->UnlockVaultDoor();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Missing -- in VaultKey ref VaultLock"));
	}
}

