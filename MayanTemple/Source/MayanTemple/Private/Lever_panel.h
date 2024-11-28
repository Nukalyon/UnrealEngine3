// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Doors.h"
#include "GameFramework/Actor.h"
#include "Lever_panel.generated.h"

class UBoxComponent;

UCLASS()
class ALever_panel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALever_panel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	UFUNCTION()
	void openDoors();
	UFUNCTION()
	bool GetIsUsed() const;
	// Doors to open
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components")
	ADoors* doorsRef;
	
private:
	// Root component
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* Root;

	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* panel_right;
	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* lever;
	// used for the Linetrace from Player
	UPROPERTY(EditAnywhere, Category = "Collider")
	UBoxComponent* CollisionBox;


	bool startlifting = false;
	bool isUsed = false;
	int maxIncrement = 135;
	int currentIncrement = 0;
};
