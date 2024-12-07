// Fill out your copyright notice in the Description page of Project Settings.


#include "VaultLock.h"

#include "VaultDoor.h"

// Sets default values
AVaultLock::AVaultLock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	KeyLock = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyLock"));
	KeyLock->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AVaultLock::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AVaultLock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVaultLock::UnlockVaultDoor()
{
	if(Door)
	{
		Door->EnableMovment();
	}
}

