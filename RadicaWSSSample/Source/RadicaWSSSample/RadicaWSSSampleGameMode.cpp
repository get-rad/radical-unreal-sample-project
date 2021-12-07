// Copyright Epic Games, Inc. All Rights Reserved.

#include "RadicaWSSSampleGameMode.h"
#include "RadicaWSSSampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARadicaWSSSampleGameMode::ARadicaWSSSampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
