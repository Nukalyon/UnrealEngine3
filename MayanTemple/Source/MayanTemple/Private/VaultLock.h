// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VaultLock.generated.h"

class AVaultDoor;

UCLASS()
class AVaultLock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVaultLock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UnlockVaultDoor();

private:	
	// Root component
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* Root;
	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* KeyLock;
	
	UPROPERTY(EditAnywhere, Category = "References")
	AVaultDoor* VaultDoor;
};
