// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Doors.generated.h"

UCLASS()
class ADoors : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoors();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool isOpening = false;
	float currentSlidingAmount = 0.0f;
	// Root component
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* Root;

	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* porteGauche;
	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* porteDroite;

public:
	UFUNCTION(BlueprintCallable, Category="Door")
	void OpenDoor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings Doors")
	float OpenDistance = 200.0f; // Distance the doors will slide apart
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings Doors")
	float OpenSpeed = 2.0f; // Speed at which the doors open
};
