// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stairs.generated.h"

UCLASS()
class AStairs : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStairs();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* Root;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Stair01;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Stair02;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Stair03;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Stair04;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Stair05;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Stair06;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Stair07;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Stair08;
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Stair09;

};
