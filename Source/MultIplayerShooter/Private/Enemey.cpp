// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemey.h"
#include "PatrolingComponent.h"


// Sets default values
AEnemey::AEnemey()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PatrolComp = CreateDefaultSubobject<UPatrolingComponent>(TEXT("Patrol Comp"));
}

// Called when the game starts or when spawned
void AEnemey::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemey::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

