// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "PreciousRock.generated.h"

UCLASS()
class APreciousRock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APreciousRock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Root component
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* Root;

	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Rock;
	// used for the Linetrace from Player
	UPROPERTY(EditAnywhere, Category = "Collider")
	UBoxComponent* CollisionBox;
};
