// Fill out your copyright notice in the Description page of Project Settings.


#include "WheelMachine.h"

// Sets default values
AWheelMachine::AWheelMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Création de l'élément qui va devenir la racine
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	
	// Création arborescence
	Roue = CreateDefaultSubobject<UStaticMeshComponent>("Cylindre");
	// https://forums.unrealengine.com/t/how-to-create-a-cylinder-in-c/467194/6
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	if (CylinderAsset.Succeeded())
	{
		Roue->SetStaticMesh(CylinderAsset.Object);
		Roue->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Roue->SetWorldScale3D(FVector(1.0f));
	}
	Roue -> SetupAttachment(Root);
	Cube = CreateDefaultSubobject<UStaticMeshComponent>("Cube");
	BoutonNoir = CreateDefaultSubobject<UStaticMeshComponent>("BoutonNoir");
	BoutonJaune = CreateDefaultSubobject<UStaticMeshComponent>("BoutonJaune");
	// https://forums.unrealengine.com/t/how-to-create-a-cylinder-in-c/467194/6
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeAsset.Succeeded())
	{
		BoutonNoir->SetStaticMesh(CubeAsset.Object);
		BoutonJaune->SetStaticMesh(CubeAsset.Object);
		Cube->SetStaticMesh(CubeAsset.Object);
		/*
		BoutonNoir->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		BoutonJaune->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		BoutonNoir->SetWorldScale3D(FVector(1.0f));
		BoutonJaune->SetWorldScale3D(FVector(1.0f));
		*/
	}
	Cube -> SetupAttachment(Root);
	BoutonNoir -> SetupAttachment(Cube);
	BoutonJaune -> SetupAttachment(Cube);

}

// Called when the game starts or when spawned
void AWheelMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWheelMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

