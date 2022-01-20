// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class SLATEEXAMPLE_API AGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	TSharedPtr<class SAWidget> InGameWidget;
	TSharedPtr<class SWidget> InGameWidgetContainer;
	
	virtual void BeginPlay() override;
};
