// Fill out your copyright notice in the Description page of Project Settings.

#include "ExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "MultIplayerShooterCharacter.h"
#include "MultIplayerShooterGameMode.h"
// Sets default values
AExtractionZone::AExtractionZone()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlayComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(200.0f));
	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal Component"));
	DecalComp->SetupAttachment(RootComponent);
	DecalComp->DecalSize = FVector(200.0f, 200.0f, 200.0f);
	SetRootComponent(OverlapComp);

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AExtractionZone::HandleBeginOverlap);
	OverlapComp->SetHiddenInGame(false);

}

void AExtractionZone::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMultIplayerShooterCharacter* PlayerCharacter = Cast<AMultIplayerShooterCharacter>(OtherActor);
	if (ensure(PlayerCharacter))
	{
		if (PlayerCharacter->HasObjective())
		{
			AMultIplayerShooterGameMode* CurrentGameMode = Cast<AMultIplayerShooterGameMode>(GetWorld()->GetAuthGameMode());
			if (CurrentGameMode)
			{
				CurrentGameMode->GameComplete(PlayerCharacter);
			}
		}
	}
}

