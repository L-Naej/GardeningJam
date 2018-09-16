// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vegetable.generated.h"

/** Let's plant some Vegetables!
 * A vegetable is an item the player can plant in the ground.
 * After some time elapsed, the vegetable is ready to get harvested.
 * Note: A vegetable starts its lifecycle in the "growing" state.
*/
UCLASS()
class HARVESTMOON_API AVegetable : public AActor
{
	GENERATED_BODY()

public:

	//True if this vegetable is ready to be harvested by the player
	UPROPERTY()
	bool bIsReadyToBeHarvested;

	//Amount of time in seconds needed for this vegetable to become ready to harvest by the player
	UPROPERTY()
	float GrowingTime;

	UPROPERTY()
	UStaticMeshComponent* VegetableMesh;

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;
	
public:	
	// Sets default values for this actor's properties
	AVegetable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnReadyToBeHarvested();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void DoOnClicked();
	

	
	
};
