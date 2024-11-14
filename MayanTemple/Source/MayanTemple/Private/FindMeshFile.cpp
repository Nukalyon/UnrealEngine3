#include "FindMeshFile.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "Engine/StaticMesh.h"
#include "Engine/AssetManager.h"

// Static member initialization
TMap<FString, UStaticMesh*> UFindMeshFile::LoadedMeshes;

void UFindMeshFile::GetMeshFilesInDirectory(TArray<FString>& OutMeshFileNames)
{
    FString Directory = FPaths::ProjectContentDir() + TEXT("Temple/Base/");
    TArray<FString> FileNames;

    // Get all files in the directory
    IFileManager::Get().FindFiles(FileNames, *Directory, TEXT("*.uasset"));

    // Store the found mesh file names
    for (const FString& FileName : FileNames)
    {
        OutMeshFileNames.Add(FileName);
        UE_LOG(LogTemp, Log, TEXT("Found mesh file: %s"), *FileName);
    }
}

bool UFindMeshFile::FindMeshByName(const FString& MeshName, FString& OutFoundMeshPath)
{
    TArray<FString> MeshFileNames;
    GetMeshFilesInDirectory(MeshFileNames);

    for (const FString& FileName : MeshFileNames)
    {
        // Check if the file name contains the mesh name (case insensitive)
        if (FileName.Contains(MeshName, ESearchCase::IgnoreCase))
        {
            OutFoundMeshPath = FileName;
            return true; // Mesh found
        }
    }
    return false; // Mesh not found
}

void UFindMeshFile::InitializeMeshManager()
{
    TArray<FString> MeshFileNames;
    GetMeshFilesInDirectory(MeshFileNames);
    
    for (const FString& FileName : MeshFileNames)
    {
        FStringAssetReference MeshRef(FileName);
        UStaticMesh* LoadedMesh = Cast<UStaticMesh>(MeshRef.TryLoad());

        if (LoadedMesh)
        {
            LoadedMeshes.Add(FPaths::GetBaseFilename(FileName), LoadedMesh);
            UE_LOG(LogTemp, Log, TEXT("Loaded static mesh: %s"), *FileName);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to load static mesh: %s"), *FileName);
        }
    }
}

UStaticMesh* UFindMeshFile::GetStaticMeshByName(const FString& MeshName)
{
    if (UStaticMesh** MeshPtr = LoadedMeshes.Find(MeshName))
    {
        return *MeshPtr;
    }
    return nullptr;
}

void UFindMeshFile::FindAndAssignMesh(const char* str, UStaticMeshComponent* staticComponent)
{
    FString meshToFindString(str);
    FString FoundMeshPath;

    if (FindMeshByName(meshToFindString, FoundMeshPath))
    {
        // Remove the .uasset extension if it's included
        FString extension = TEXT(".uasset");
        if (FoundMeshPath.EndsWith(extension))
        {
            FoundMeshPath = FoundMeshPath.LeftChop(extension.Len()); // Remove ".uasset"
        }

        // Construct the correct load path
        FString CorrectPath = FString::Printf(TEXT("StaticMesh'/Game/Temple/Base/%s.%s'"), *FoundMeshPath, *FoundMeshPath);

        // Log the constructed path for debugging
        UE_LOG(LogTemp, Log, TEXT("Attempting to load mesh from path: %s"), *CorrectPath);

        // Load the static mesh from the found path
        UStaticMesh* LoadedMesh = LoadObject<UStaticMesh>(nullptr, *CorrectPath);
        
        if (LoadedMesh)
        {
            staticComponent->SetStaticMesh(LoadedMesh);
            UE_LOG(LogTemp, Log, TEXT("Successfully assigned mesh: %s"), *CorrectPath);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to load static mesh from path: %s"), *CorrectPath);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Mesh not found containing: %s"), *meshToFindString);
    }
}