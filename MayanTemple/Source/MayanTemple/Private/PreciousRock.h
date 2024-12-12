// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PreciousRock.generated.h"

class AAutel;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRockInteracted);

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
	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Rock;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gem")
	TArray<FString> RockOptions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gem")
	int RockNameIndex;
	FString RockName;
	
	UFUNCTION()
	void TogglePhysics(bool isEnabled);
};