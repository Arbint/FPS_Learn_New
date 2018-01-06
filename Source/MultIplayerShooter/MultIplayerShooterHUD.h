// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MultIplayerShooterHUD.generated.h"
class UUserWidget;

UCLASS()
class AMultIplayerShooterHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMultIplayerShooterHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	UPROPERTY(EditDefaultsOnly, Category = "UMG")
	TSubclassOf<UUserWidget> UIWidgetToUse;
	UUserWidget* MainUI;
};

