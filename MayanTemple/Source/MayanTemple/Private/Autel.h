// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "PreciousRock.h"
#include "Autel.generated.h"

UCLASS()
class AAutel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:	
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* Root;

	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Altar;
	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* GoldPlace;
	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* JadePlace;
	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* ObsidianPlace;
	// Static mesh component
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* TurquoisePlace;

	
	UPROPERTY(EditAnywhere, Category = "Niagara")
	UNiagaraComponent* NS_Rocks;

	UPROPERTY(EditAnywhere, Category = "Rocks")
	TArray<APreciousRock*> Rocks;

public:
	UFUNCTION()
	void ActivateNiagara(APreciousRock* rock);
	UFUNCTION()
	void SnapThatRock(APreciousRock* rock);
};
