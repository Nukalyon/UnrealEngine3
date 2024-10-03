// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Ctrl + B pour la signature
	//Skip 1er + 2eme Param (FActorHitSignature, AActor OnActorHit)
	//Type et nom séparé par une virugule, simplement la retirer
	//void onHit(AActor, OnActorHit, AActor*, SelfActor, AActor*, OtherActor, FVector, NormalImpulse, const FHitResult&, Hit);
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	//Si ne s'affiche pas dans Unreal, Shift + F10 pour compiler et vérifier si BP est relié au .cpp (Paramètres de classe)
	UPROPERTY(EditAnywhere)
	int Threshold;
};
