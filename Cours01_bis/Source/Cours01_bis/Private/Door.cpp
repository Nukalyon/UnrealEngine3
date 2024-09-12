// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "Cours01_bis/Cours01_bisCharacter.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	//Si &ADoor::onHit sousligné, ajouter UFUNCTION()
	OnActorHit.AddDynamic(this, &ADoor::OnHit);
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UFUNCTION()
void ADoor::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	//La porte s'ouvre seulement si le joueur à le minimum de coin
	auto Player = Cast<ACours01_bisCharacter>(OtherActor);
	if(Player != nullptr && Player->CoinCounter >= Threshold)
	{
		Destroy();
	}
}

