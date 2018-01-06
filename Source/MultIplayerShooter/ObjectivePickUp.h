// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectivePickUp.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class USceneComponent;
UCLASS()
class MULTIPLAYERSHOOTER_API AObjectivePickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectivePickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	public:
		UPROPERTY(EditDefaultsOnly, Category = "Visual")
			USceneComponent* RootComp;
		UPROPERTY(EditDefaultsOnly, Category = "Visual")
			UStaticMeshComponent* VisalMesh;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Function")
			USphereComponent* DetectionSphere;
private:
UFUNCTION()
	void Detected(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		
};
