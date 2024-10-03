// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "GameFramework/Actor.h"
#include "Slot_Machine.generated.h"

// Pour que le header sache que c'est valide ? ref:
// https://dev.epicgames.com/community/learning/tutorials/Gx5j/using-niagara-in-c
class UNiagaraComponent;

UCLASS()
class ASlot_Machine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlot_Machine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpinAllReels();
	int Spin(UStaticMeshComponent* bobine);
	void ChangeMaterial(UMaterialInterface* Material);
	void isWinner();
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	                       FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

private:
	UPROPERTY(EditAnywhere)
	USceneComponent* Root;
	UPROPERTY(EditAnywhere)
	USceneComponent* Cube;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	USceneComponent* Levier;
	UPROPERTY(EditAnywhere)
	USceneComponent* Reels;
	UPROPERTY(EditAnywhere, Category= "Niagara")
	UNiagaraComponent* Confetti;
	
	//Parent Levier
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Junction;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Arm;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Hand;

	//Parent Bobines
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UStaticMeshComponent* BobineGauche;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UStaticMeshComponent* BobineCentre;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UStaticMeshComponent* BobineDroite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UStaticMeshComponent* Ligne;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UAudioComponent* Speaker;
	UPROPERTY(EditAnywhere, Category="Sound")
	USoundBase* spinning;
	UPROPERTY(EditAnywhere, Category="Sound")
	USoundBase* winning;
	UPROPERTY(EditAnywhere, Category="Material")
	UMaterialInterface* mat_win;
	UPROPERTY(EditAnywhere, Category="Material")
	UMaterialInterface* mat_casual;
	
	float leverAngle;
	TArray<UStaticMeshComponent*> bobines;
	TArray<int> indexes;
};
