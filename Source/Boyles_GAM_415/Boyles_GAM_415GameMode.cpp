// Copyright Epic Games, Inc. All Rights Reserved.

#include "Boyles_GAM_415GameMode.h"
#include "Boyles_GAM_415HUD.h"
#include "Boyles_GAM_415Character.h"
#include "UObject/ConstructorHelpers.h"

ABoyles_GAM_415GameMode::ABoyles_GAM_415GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ABoyles_GAM_415HUD::StaticClass();
}
