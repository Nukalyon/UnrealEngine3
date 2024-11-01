// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FindMeshFile.h"
#include "Temple.generated.h"

UCLASS()
class ATemple : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATemple();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Function to find and assign the mesh
	static void FindAndAssignMesh(const FString& MeshName, UStaticMeshComponent* staticComponent);


private:
	// Root component
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* Root;

	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* meshTemple;
	
};
