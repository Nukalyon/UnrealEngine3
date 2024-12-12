#pragma once

#include "CoreMinimal.h"
#include "DataRock.generated.h"


USTRUCT(BlueprintType)
struct MAYANTEMPLE_API FDataRock: public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText RockName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UStaticMesh> RockModel;
};