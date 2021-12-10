// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeA.h"

// Sets default values
ACubeA::ACubeA()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(StaticMeshComponent);
}

// Called when the game starts or when spawned
void ACubeA::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(StaticMeshComponent))
	{
		StaticMeshComponent->AddImpulse(FVector(0, 0, 1000));
		StaticMeshComponent->AddAngularImpulseInDegrees(FVector(0, 10000, 0));
	}
}

// Called every frame
void ACubeA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
