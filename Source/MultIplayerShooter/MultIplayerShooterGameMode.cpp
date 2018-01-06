// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MultIplayerShooterGameMode.h"
#include "MultIplayerShooterHUD.h"
#include "MultIplayerShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultIplayerShooterGameMode::AMultIplayerShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMultIplayerShooterHUD::StaticClass();
}

void AMultIplayerShooterGameMode::GameComplete(APawn* InstigatorPawn)
{
	if (InstigatorPawn)
	{
		InstigatorPawn->DisableInput(nullptr);
	}
	OnGameComplete(InstigatorPawn);
}
