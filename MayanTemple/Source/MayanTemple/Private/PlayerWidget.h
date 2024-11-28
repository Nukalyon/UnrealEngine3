// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintImplementableEvent)
		void setPromptF(bool IsVisisible);
		UFUNCTION(BlueprintImplementableEvent)
		void setPromptR(bool IsVisisible);
		UFUNCTION(BlueprintImplementableEvent)
		void togglePrompts(bool IsVisisible);
};
