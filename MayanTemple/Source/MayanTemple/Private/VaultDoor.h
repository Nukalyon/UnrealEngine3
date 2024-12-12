// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VaultDoor.generated.h"

UCLASS()
class AVaultDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVaultDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void EnableMovement();
	bool bCanBeOpen = false;

private:
	// Root component
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* Root;
	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* VaultDoor;
	FVector BaseLocation;
	float currentSlidingAmount = 0.0f;
	float OpenDistance = 5.0f;
	float OpenSpeed = 2.0f;
	float AngleDeg;
};
