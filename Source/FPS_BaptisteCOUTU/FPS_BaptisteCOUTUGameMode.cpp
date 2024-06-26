// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS_BaptisteCOUTUGameMode.h"
#include "FPS_BaptisteCOUTUCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPS_BaptisteCOUTUGameMode::AFPS_BaptisteCOUTUGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Script/FPS_BaptisteCOUTU.AFPSCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
