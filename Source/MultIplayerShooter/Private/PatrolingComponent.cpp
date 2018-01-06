// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolingComponent.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "MultIplayerShooterCharacter.h"
#include "Kismet/GameplayStatics.h"
// Sets default values for this component's properties
UPatrolingComponent::UPatrolingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPatrolingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPatrolingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Patroling();
	// ...
}

void UPatrolingComponent::Patroling()
{
	if (!bShouldPatrol || PatrolPoints.Num() == 0 || !GetOwner())
	{
		return;
	}
	if (CurrentDestination)
	{
		float DistanceToCurrentDistination = (CurrentDestination->GetActorLocation() - GetOwner()->GetActorLocation()).Size();
		if (DistanceToCurrentDistination > 200.0f)
		{
			return;
		}
	}
	CurrentDestination = PatrolPoints[CurrentDestinationIndex];
	++CurrentDestinationIndex;
	CurrentDestinationIndex = CurrentDestinationIndex%PatrolPoints.Num();
	ACharacter* OwnningCharacter = Cast<ACharacter>(GetOwner());
	if (OwnningCharacter)
	{
		AAIController* AIC = Cast<AAIController>(OwnningCharacter->GetController());
		if (AIC)
		{
			AIC->MoveToActor(CurrentDestination);
		}
	}
}

