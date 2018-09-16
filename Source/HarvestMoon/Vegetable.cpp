// Fill out your copyright notice in the Description page of Project Settings.

#include "Vegetable.h"

#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine.h"

// Sets default values
AVegetable::AVegetable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Start in the "growing" state
	bIsReadyToBeHarvested = false;

	//Default value. Actual value should be set by the game designer
	GrowingTime = 10.f;

	VegetableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VegetableMesh"));;

	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VegetableMeshAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (VegetableMeshAsset.Succeeded())
	{
		VegetableMesh->SetStaticMesh(VegetableMeshAsset.Object);
		RootComponent = VegetableMesh;
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> VegetableMaterialAsset(TEXT("Material'/Game/Geometry/Meshes/CubeMaterial.CubeMaterial'"));
	if (VegetableMaterialAsset.Succeeded())
	{
		DynamicMaterial = UMaterialInstanceDynamic::Create(VegetableMaterialAsset.Object, this, "VegetableColor");
		VegetableMesh->SetMaterial(0, DynamicMaterial);
	}
}

// Called when the game starts or when spawned
void AVegetable::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AVegetable::OnReadyToBeHarvested, GrowingTime, false);
}

// Called every frame
void AVegetable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVegetable::OnReadyToBeHarvested()
{
	bIsReadyToBeHarvested = true;

	DynamicMaterial->SetVectorParameterValue("Color", FLinearColor(0.f,1.f,0.f));

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ready to be harvested!"));

}


void AVegetable::DoOnClicked()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Vegetable clicked!"));
}
