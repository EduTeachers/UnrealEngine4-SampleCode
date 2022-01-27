// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameHUD.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SLATEEXAMPLE_API SMainMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuWidget){}
	SLATE_EVENT(FOnClicked, OnPlayClicked)
	SLATE_END_ARGS()
	
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnLoadClicked();
};
