// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"

#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SGridPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	FSlateFontInfo TextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	TextStyle.Size = 40.f;

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)
		]
		+ SOverlay::Slot()
		.Padding(600, 300)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.Padding(0, 10)
			[
				SNew(SButton)
				.OnClicked(InArgs._OnPlayClicked)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(TextStyle)
					.Text(FText::FromString("Play"))
				]
			]
			+ SVerticalBox::Slot()
			.Padding(0, 10)
			[
				SNew(SButton)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.OnClicked(this, &SMainMenuWidget::OnLoadClicked)
				[
					SNew(STextBlock)
					.Font(TextStyle)
					.Text(FText::FromString("Load Game"))
				]
			]
			+ SVerticalBox::Slot()
			.Padding(0, 10)
			[
				SNew(SButton)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Font(TextStyle)
					.Text(FText::FromString("Quit"))
				]
			]
		]
	];
}

// Volání kliknutí přímo z Widgetu... !!!!!NOT IDEAL!!!!!
FReply SMainMenuWidget::OnLoadClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Load Game Clicked!"))

	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
