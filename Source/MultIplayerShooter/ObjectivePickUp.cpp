// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectivePickUp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "MultIplayerShooterCharacter.h"
// Sets default values
AObjectivePickUp::AObjectivePickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);
	VisalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual mesh"));
	DetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Detection Sphere"));
	VisalMesh->SetupAttachment(RootComp);
	DetectionSphere->SetupAttachment(RootComp);
	
	DetectionSphere->SetSphereRadius(300.0f);
	VisalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DetectionSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	DetectionSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	//setup collision
	DetectionSphere->bGenerateOverlapEvents = true;
	DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &AObjectivePickUp::Detected);
}

// Called when the game starts or when spawned
void AObjectivePickUp::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObjectivePickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObjectivePickUp::Detected(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ensure(OtherActor))
	{
		AMultIplayerShooterCharacter* PC = Cast<AMultIplayerShooterCharacter>(OtherActor);
		if (ensure(PC))
		{
			PC->SetHasObjective(true);
		}
	}
	Destroy();
}

