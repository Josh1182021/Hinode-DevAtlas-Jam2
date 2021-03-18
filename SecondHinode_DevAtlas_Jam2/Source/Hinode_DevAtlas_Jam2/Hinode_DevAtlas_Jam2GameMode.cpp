// Copyright Epic Games, Inc. All Rights Reserved.

#include "Hinode_DevAtlas_Jam2GameMode.h"
#include "Hinode_DevAtlas_Jam2PlayerController.h"
#include "Hinode_DevAtlas_Jam2Character.h"
#include "UObject/ConstructorHelpers.h"

AHinode_DevAtlas_Jam2GameMode::AHinode_DevAtlas_Jam2GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHinode_DevAtlas_Jam2PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}