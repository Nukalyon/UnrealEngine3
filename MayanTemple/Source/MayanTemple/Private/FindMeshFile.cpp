// Fill out your copyright notice in the Description page of Project Settings.

#include "FindMeshFile.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "Engine/StaticMesh.h"

void UFindMeshFile::GetMeshFilesInDirectory(TArray<FString>& OutMeshFileNames)
{
	//F:/Unreal_projects/UnrealEngine3/MayanTemple/Content/Temple/Base/MayanTemple_MASTER_Temple_Floor_L_MayanTemple_blocking_v004_blend_Dupli_.uasset
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
		// Check if the file name contains the mesh name
		if (FileName.Contains(MeshName, ESearchCase::IgnoreCase))
		{
			OutFoundMeshPath = FileName;
			return true; // Mesh found
		}
	}
	return false; // Mesh not found
}