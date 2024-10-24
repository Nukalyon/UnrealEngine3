// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockCage.h"

// Sets default values
ABlockCage::ABlockCage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Création de l'élément qui va devenir la racine
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	
	// Création arborescence
	Wall = CreateDefaultSubobject<UStaticMeshComponent>("Wall");
	// https://forums.unrealengine.com/t/how-to-create-a-cylinder-in-c/467194/6
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CylinderAsset.Succeeded())
	{
		Wall->SetStaticMesh(CylinderAsset.Object);
		Wall->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Wall->SetWorldScale3D(FVector(1.0f));
	}
	Wall -> SetupAttachment(Root);

}

// Called when the game starts or when spawned
void ABlockCage::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABlockCage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

