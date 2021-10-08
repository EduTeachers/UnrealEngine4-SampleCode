// Fill out your copyright notice in the Description page of Project Settings.


#include "Cube.h"

// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Get/Set ActorLocation
	// FVector ActorLocation = GetActorLocation();
	// ActorLocation.X += 20;
	// SetActorLocation(ActorLocation);

	// Get/Set ActorRotation
	FRotator ActorRotation = GetActorRotation();
	ActorRotation.Yaw += 1;
	SetActorRotation(ActorRotation);
}

