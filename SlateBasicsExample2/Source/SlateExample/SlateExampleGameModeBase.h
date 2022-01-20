// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameHUD.h"
#include "GameFramework/GameModeBase.h"
#include "SlateExampleGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SLATEEXAMPLE_API ASlateExampleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
};
