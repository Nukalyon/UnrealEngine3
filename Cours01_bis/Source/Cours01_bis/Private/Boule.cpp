// Fill out your copyright notice in the Description page of Project Settings.


#include "Boule.h"

// Sets default values
ABoule::ABoule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoule::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoule::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	Destroy();
}

