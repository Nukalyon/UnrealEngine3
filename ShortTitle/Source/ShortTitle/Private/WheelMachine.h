// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WheelMachine.generated.h"

UCLASS()
class AWheelMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWheelMachine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:	
	UPROPERTY(EditAnywhere)
	USceneComponent* Root;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Cube;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Roue;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BoutonNoir;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BoutonJaune;

	float rotateTime;
};
