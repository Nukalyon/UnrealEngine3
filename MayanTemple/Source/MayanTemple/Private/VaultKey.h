// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VaultKey.generated.h"

class AVaultLock;
class AAutel;

UCLASS()
class AVaultKey : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVaultKey();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void TogglePhysics(bool isEnabled);
	void UseKey();

	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Key;
private:
	// Root component
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, Category = "Components")
	AAutel* autel;
	UPROPERTY(EditAnywhere, Category = "Components")
	AVaultLock* VaultLock;
};
