// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"
class USuckerComponent;
class UDestroyerComponent;
UCLASS()
class MULTIPLAYERSHOOTER_API ABlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuckerComp")
		USuckerComponent* SuckerComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuckerComp")
		UDestroyerComponent* DestroyerComp;

};
