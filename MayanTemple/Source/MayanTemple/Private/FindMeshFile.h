#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FindMeshFile.generated.h"

class UStaticMesh;

UCLASS()
class MAYANTEMPLE_API UFindMeshFile : public UObject
{
	GENERATED_BODY()

public:
	// Load all static meshes into the manager
	static void InitializeMeshManager();

	// Get a static mesh by name from the manager
	static UStaticMesh* GetStaticMeshByName(const FString& MeshName);
	
    // Find and assign a mesh to the given static mesh component	
	static void FindAndAssignMesh(const char* str, UStaticMeshComponent* staticComponent);

private:
	static TMap<FString, UStaticMesh*> LoadedMeshes;

	// Existing functions
	static void GetMeshFilesInDirectory(TArray<FString>& OutMeshFileNames);
	static bool FindMeshByName(const FString& MeshName, FString& OutFoundMeshPath);
};
