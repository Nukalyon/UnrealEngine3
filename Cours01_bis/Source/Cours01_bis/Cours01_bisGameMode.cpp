// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cours01_bisGameMode.h"
#include "Cours01_bisCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACours01_bisGameMode::ACours01_bisGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
