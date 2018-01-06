// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MultIplayerShooterGameMode.generated.h"

UCLASS(minimalapi)
class AMultIplayerShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMultIplayerShooterGameMode();
public:
	void GameComplete(APawn* InstigatorPawn);
	UFUNCTION(BlueprintImplementableEvent, category = "Game Mode")
	void OnGameComplete(APawn* InstigatorPawn);
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Spectating")
	TSubclassOf<AActor> SpectatingActorClass;
};



