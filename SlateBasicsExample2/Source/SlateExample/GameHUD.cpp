// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

#include "SAWidget.h"
#include "Widgets/SWeakWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine && GEngine->GameViewport)
	{
		InGameWidget = SNew(SAWidget)
			.OwningHUD(this);
			//.DummyArgument1(...);

		GEngine->GameViewport->AddViewportWidgetContent(
			SAssignNew(InGameWidgetContainer, SWeakWidget).PossiblyNullContent(InGameWidget.ToSharedRef())
		);
	}
}
