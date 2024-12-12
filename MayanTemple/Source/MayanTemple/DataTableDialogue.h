#pragma once

#include "CoreMinimal.h"
#include "DataTableDialogue.generated.h"


USTRUCT(BlueprintType)
struct MAYANTEMPLE_API FDataTableDialogue: public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString text;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<USoundBase> audio;
};