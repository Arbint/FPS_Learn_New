// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MultIplayerShooterGameMode.h"
#include "MultIplayerShooterHUD.h"
#include "MultIplayerShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
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
	if (!InstigatorPawn)
	{
		return;
	}
	InstigatorPawn->DisableInput(nullptr);
	APlayerController* PCtrl = Cast<APlayerController>(InstigatorPawn->GetController());
	if (PCtrl != nullptr)
	{
		TArray<AActor*> NewViewTargetActors;
		if (SpectatingActorClass)
		{
			UGameplayStatics::GetAllActorsOfClass(this, SpectatingActorClass, NewViewTargetActors);
			if (NewViewTargetActors.Num()>0)
			{
				AActor* SpectatingActor = NewViewTargetActors[0];
				PCtrl->SetViewTargetWithBlend(SpectatingActor, 1.0f, EViewTargetBlendFunction::VTBlend_Cubic);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Cannot find spectating class in game mode, please specify in game mode. Cannot change view target for the controller after winning"));
		}
	}	
	OnGameComplete(InstigatorPawn);
}
