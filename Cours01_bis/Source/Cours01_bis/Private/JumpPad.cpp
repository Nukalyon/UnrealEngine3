// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpPad.h"

#include "Cours01_bis/Cours01_bisCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AJumpPad::AJumpPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJumpPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJumpPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJumpPad::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	//Test si c'est le perso qui touche ou un Character
	auto Player = Cast<ACharacter>(Other);
	if (Player)
	{
		//Player->LaunchCharacter(FVector(0,0,1000), false, true);
		Player->GetCharacterMovement()->AddImpulse(FVector(0,0,1000));
	}
}

