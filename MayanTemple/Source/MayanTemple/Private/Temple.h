#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Temple.generated.h"

UCLASS()
class MAYANTEMPLE_API ATemple : public AActor
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

private:
	// Root component
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	// StaticMesh component
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* floor_room1;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* floor_room2;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* floor_room3;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* floor_room4;
};
