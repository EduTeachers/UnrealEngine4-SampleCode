// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeB.h"

#include "DrawDebugHelpers.h"

// Sets default values
ACubeB::ACubeB()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(StaticMeshComponent);
}

// Called when the game starts or when spawned
void ACubeB::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACubeB::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (IsValid(StaticMeshComponent))
	{
		StaticMeshComponent->AddForce(FVector(0, 0, 1000));
	}
}
