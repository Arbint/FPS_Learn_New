// Fill out your copyright notice in the Description page of Project Settings.

#include "DestroyerComponent.h"


// Sets default values for this component's properties
UDestroyerComponent::UDestroyerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetNotifyRigidBodyCollision(true);
	OnComponentHit.AddDynamic(this,&UDestroyerComponent::HitDestory);
	// ...
}


// Called when the game starts
void UDestroyerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDestroyerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDestroyerComponent::HitDestory(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor)
	{
		OtherActor->Destroy();
	}
}

