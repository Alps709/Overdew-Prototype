// Copyright Epic Games, Inc. All Rights Reserved.

#include "OverdewGameMode.h"
#include "OverdewPlayerController.h"
#include "OverdewCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOverdewGameMode::AOverdewGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AOverdewPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}