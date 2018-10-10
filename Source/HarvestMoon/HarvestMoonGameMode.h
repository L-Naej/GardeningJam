// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "HarvestMoonGameMode.generated.h"

UCLASS(minimalapi)
class AHarvestMoonGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AHarvestMoonGameMode();

	virtual void StartPlay() override;

	// This function should be used to do anything you want the gamemode to do before
	// AGameModeBase::StartPlay() is called.
	// Indeed, you don't know when the BeginPlay of the GameMode will be called, so
	// if you need some stuff to be done before any Actor BeginPlay() call, this is
	// the place to do it in Blueprint (StartPlay is not blueprint overridable).
	//
	// This function is called by AHarvestMoonGameMode::StartPlay()
	UFUNCTION(BlueprintImplementableEvent, Category=Game)
	void BP_StartPlay();

	/** Tries to spawn the player's pawn at the specified actor's location */
	virtual void RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot) override;
};



