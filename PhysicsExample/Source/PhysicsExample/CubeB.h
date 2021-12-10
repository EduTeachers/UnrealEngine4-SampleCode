// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeB.generated.h"

UCLASS()
class PHYSICSEXAMPLE_API ACubeB : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;
	
	// Sets default values for this actor's properties
	ACubeB();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
