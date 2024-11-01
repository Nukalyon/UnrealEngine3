// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FindMeshFile.generated.h"

UCLASS()
class MAYANTEMPLE_API UFindMeshFile : public UObject
{
	GENERATED_BODY()

public:
	// Static method to search for a specific mesh by name in the directory
	static bool FindMeshByName(const FString& MeshName, FString& OutFoundMeshPath);

private:
	// Helper method to retrieve mesh files from the directory
	static void GetMeshFilesInDirectory(TArray<FString>& OutMeshFileNames);
};