// Fill out your copyright notice in the Description page of Project Settings.


#include "LasorTrap.h"

// Sets default values
ALasorTrap::ALasorTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/* Il va manquer la mesh Cylindre, orientation, etc...
	LasorBase = CreateDefaultSubobject<UStaticMeshComponent>("LasorBase");
	RootComponent = LasorBase;
	LasorBeam = CreateDefaultSubobject<UStaticMeshComponent>("LasorBeam");
	LasorBeam->AttachToComponent(LasorBase, FAttachmentTransformRules::KeepRelativeTransform);
	*/
}

// Called when the game starts or when spawned
void ALasorTrap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALasorTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

