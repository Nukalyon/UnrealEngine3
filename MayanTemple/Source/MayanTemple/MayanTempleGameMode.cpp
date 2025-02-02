// Copyright Epic Games, Inc. All Rights Reserved.

#include "MayanTempleGameMode.h"
#include "FindMeshFile.h"
#include "MayanTempleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMayanTempleGameMode::AMayanTempleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void AMayanTempleGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the mesh manager
	//UFindMeshFile::InitializeMeshManager();
}
