// Fill out your copyright notice in the Description page of Project Settings.

#include "BlackHole.h"
#include "SuckerComponent.h"
#include "DestroyerComponent.h"

// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SuckerComp = CreateDefaultSubobject<USuckerComponent>(TEXT("Suck Comp"));
	DestroyerComp = CreateDefaultSubobject<UDestroyerComponent>(TEXT("Destoryer Comp"));
	SetRootComponent(DestroyerComp);
}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

