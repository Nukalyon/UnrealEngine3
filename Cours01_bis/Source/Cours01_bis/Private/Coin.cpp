// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"

#include "Cours01_bis/Cours01_bisCharacter.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
}

void ACoin::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	auto Player = Cast<ACours01_bisCharacter>(OtherActor);
	if(Player != nullptr)
	{
		Player->CoinCounter++;
		FString message = FString::Printf(TEXT("Number of Coins: %d"),Player->CoinCounter);
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, message);
	}
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoin::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	Destroy();
}

