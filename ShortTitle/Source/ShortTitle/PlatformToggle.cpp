// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformToggle.h"

#include "GameFramework/EngineMessage.h"

// Sets default values
APlatformToggle::APlatformToggle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Création de l'élément qui va devenir la racine
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	
	// Création arborescence
	Cylinder = CreateDefaultSubobject<UStaticMeshComponent>("Cylindre");
	// https://forums.unrealengine.com/t/how-to-create-a-cylinder-in-c/467194/6
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	if (CylinderAsset.Succeeded())
	{
		Cylinder->SetStaticMesh(CylinderAsset.Object);
		Cylinder->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Cylinder->SetWorldScale3D(FVector(1.0f));
	}
	Cylinder -> SetupAttachment(Root);

	//Attachement des matériaux
	FString greenMatPath = "/Engine/MapTemplates/Materials/BasicAsset03.BasicAsset03";
	FString redMatPath = "/Engine/EngineDebugMaterials/VertexColorViewMode_RedOnly.VertexColorViewMode_RedOnly";
	greenMat = Cast<UMaterialInterface>(LoadObject<UMaterialInterface>(nullptr, *greenMatPath));
	redMat = Cast<UMaterialInterface>(LoadObject<UMaterialInterface>(nullptr, *redMatPath));
	
}

// Called when the game starts or when spawned
void APlatformToggle::BeginPlay()
{
	Super::BeginPlay();
	ChangeMaterial(greenMat, 0);
}

// Called every frame
void APlatformToggle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlatformToggle::ChangeMaterial(UMaterialInterface* mat, int indexToActivate)
{
	if(IsValid(mat))
	{
		// index 0 = green
		// index 1 = red
		switch (indexToActivate)
		{
			//Vu qu'on a que deux plateformes à gérer, c'est plus simple
			//Sinon on ferait un parcours de liste en inversant chanque visibilités
			case 0:
				plateforms[1]->SetActorHiddenInGame(false);
				plateforms[0]->SetActorHiddenInGame(true);
				break;
			case 1:
				plateforms[1]->SetActorHiddenInGame(true);
				plateforms[0]->SetActorHiddenInGame(false);
				break;
			default:
				break;
		}
		Cylinder->SetMaterial(0, mat);
	}
}

void APlatformToggle::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	//Les Plateformes sont enregistrées dans la TArray plateformes dans l'editeur:
	// index 0 = green
	// index 1 = red
	if(Cylinder->GetMaterial(0) == greenMat)
	{
		ChangeMaterial(redMat, 0);
	}
	else
	{
		ChangeMaterial(greenMat, 1);
	}
}

