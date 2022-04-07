// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCController.h"

void ANPCController::BeginPlay()
{
	Super::BeginPlay();

	if(BTAsset)
	{
		UE_LOG(LogTemp, Warning, TEXT("Running BT"));
		RunBehaviorTree(BTAsset);
	}
}
