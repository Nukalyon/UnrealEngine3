#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stairs.generated.h"

class UBoxComponent;

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

	// Function to move the stairs to their target positions
	UFUNCTION(BlueprintCallable, Category = "Stairs")
	void Rise();

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
	TArray<UStaticMeshComponent*> Stairs;

	// Pop-up variables
	FVector StartLocation;
	FVector EndLocation;
	float PopProgress;
	bool bIsPopping;
	float PopDuration;
};