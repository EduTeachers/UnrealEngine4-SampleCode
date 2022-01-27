// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

#include "SMainMenuWidget.h"
#include "Widgets/SWeakWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerOwner)
	{
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
	
	if (GEngine && GEngine->GameViewport)
	{
		InGameWidget = SNew(SMainMenuWidget)
		.OnPlayClicked_UObject(this, &AGameHUD::OnPlayClicked);

		GEngine->GameViewport->AddViewportWidgetContent(
			SAssignNew(MainMenuContainer, SWeakWidget).PossiblyNullContent(InGameWidget.ToSharedRef())
		);
	}
}

// Lepší způsob jak provolávat button na clicked
FReply AGameHUD::OnPlayClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Play Clicked!"))

	if(IsValid(GEngine) && InGameWidget.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MainMenuContainer.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}

	return FReply::Handled();
}
