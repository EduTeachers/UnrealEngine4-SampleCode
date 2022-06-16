// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISense_Sight.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class PERCEPTIONAI_API AEnemyController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY()
	UAISenseConfig_Sight* SightConfig;
	
	AEnemyController();

	UFUNCTION()
	void SayHi(AActor* Actor, FAIStimulus Stimulus);
	
	virtual void BeginPlay() override;
};
