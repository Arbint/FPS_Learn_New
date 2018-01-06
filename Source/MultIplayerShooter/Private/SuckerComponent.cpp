// Fill out your copyright notice in the Description page of Project Settings.

#include "SuckerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
// Sets default values for this component's properties
USuckerComponent::USuckerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USuckerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USuckerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Suck();
	// ...
}

void USuckerComponent::Suck()
{
	TArray<AActor*> Meshes;
	UGameplayStatics::GetAllActorsOfClass(this, AStaticMeshActor::StaticClass(),Meshes);
	if (Meshes.Num() != 0)
	{
		for (AActor* ActorItem : Meshes)
		{
			if (ActorItem->GetRootComponent()->IsSimulatingPhysics())
			{
				UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(ActorItem->GetComponentByClass(UStaticMeshComponent::StaticClass()));
				if (Mesh)
				{
					Mesh->AddRadialForce(GetOwner()->GetActorLocation(), SuckingRadius, SuckingStrength, ERadialImpulseFalloff::RIF_Constant);
				}
			}
		}
	}
}
