// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "HarvestMoonGameMode.h"
#include "HarvestMoonPlayerController.h"
#include "HarvestMoonCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AHarvestMoonGameMode::AHarvestMoonGameMode()
	: AGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHarvestMoonPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AHarvestMoonGameMode::StartPlay()
{
	BP_StartPlay();

	Super::StartPlay();	
}

void AHarvestMoonGameMode::RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot)
{
	if(NewPlayer->GetPawn() != nullptr)
	{
		APawn* Pawn = NewPlayer->GetPawn();
		Pawn->SetActorLocation(StartSpot->GetActorLocation());
	}

	Super::RestartPlayerAtPlayerStart(NewPlayer, StartSpot);
}