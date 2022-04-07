// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCController.generated.h"

/**
 * 
 */
UCLASS()
class BT_CPP_API ANPCController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UBehaviorTree* BTAsset;

	virtual void BeginPlay() override;
};
