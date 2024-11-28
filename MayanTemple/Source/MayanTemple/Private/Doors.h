// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Doors.generated.h"

class USphereComponent;

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
	//When the player is near after having opened the door once
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	
private:
	bool isOpening = false;
	bool isClosing = false;
	bool isOpenedAtLeastOnce = false;
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
	UPROPERTY(EditAnywhere, Category = "Collider")
	USphereComponent* CollisionBox;

public:
	UFUNCTION(BlueprintCallable, Category="Door")
	void OpenDoor();
	void CloseDoors();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings Doors")
	float OpenDistance = 200.0f; // Distance the doors will slide apart
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings Doors")
	float OpenSpeed = 2.0f; // Speed at which the doors open
};
