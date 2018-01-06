// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExtractionZone.generated.h"
class UBoxComponent;
class UDecalComponent;
UCLASS()
class MULTIPLAYERSHOOTER_API AExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExtractionZone();
public:	
	UPROPERTY(VisibleAnywhere, Category = "Function")
	UBoxComponent* OverlapComp;
	UPROPERTY(VisibleAnywhere, Category = "Function")
	UDecalComponent* DecalComp;
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(EditDefaultsOnly, Category = "Function")
	USoundBase* ObjectiveMissingSound;
};
