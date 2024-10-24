// Fill out your copyright notice in the Description page of Project Settings.


#include "FireTorch.h"

// Sets default values
AFireTorch::AFireTorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	// Création de l'élément qui va devenir la racine
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	
	// Création arborescence
	Hand = CreateDefaultSubobject<UStaticMeshComponent>("Cylindre");
	// https://forums.unrealengine.com/t/how-to-create-a-cylinder-in-c/467194/6
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	if (CylinderAsset.Succeeded())
	{
		Hand->SetStaticMesh(CylinderAsset.Object);
		Hand->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Hand->SetWorldScale3D(FVector(1.0f));
	}
	Hand -> SetupAttachment(Root);

	Fire = CreateDefaultSubobject<UNiagaraComponent>("Fire");
	Fire -> SetupAttachment(Hand);

}

// Called when the game starts or when spawned
void AFireTorch::BeginPlay()
{
	Super::BeginPlay();
	//Enregistrement du NiagaraSystem pour le feu
	FString ns_fire = "/Game/FirstPerson/Niagara/NS_Fire";
	UNiagaraSystem* ns = LoadObject<UNiagaraSystem>(nullptr, *ns_fire);
	//UNiagaraSystem* ns = Cast<UNiagaraSystem>(LoadObject<UNiagaraSystem>(nullptr, *ns_fire));
	if(IsValid(ns))	//Vérification si le NiagaraSystem est trouvé sinon rien -> Empêche bug
	{
		Fire->SetAutoActivate(false);
		Fire->SetAsset(ns);
	}
}

// Called every frame
void AFireTorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFireTorch::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	//Collision avec uniquement le joueur
	//if(Other == UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	//{
	//}
	Fire->SetActive(true);
	Fire->SetVisibility(true);
}

bool AFireTorch::isLit()
{
	return Fire->IsActive();
}

