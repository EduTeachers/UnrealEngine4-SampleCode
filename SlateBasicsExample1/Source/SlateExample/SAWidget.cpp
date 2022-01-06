// Fill out your copyright notice in the Description page of Project Settings.


#include "SAWidget.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SAWidget::Construct(const FArguments& InArgs)
{
	OwningHUD = InArgs._OwningHUD;
	// InArgs._DummyArgument1;
	// InArgs._DummyArgument2;
	// ...

	FSlateFontInfo TextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	TextStyle.Size = 40.f;
	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		  .HAlign(HAlign_Center) // Popř. HAlign_Fill, HAlign_Left, HAlign_Right
		  .VAlign(VAlign_Center)
		[
			SAssignNew(TextBlock, STextBlock)
			.Font(TextStyle)
			.Text(FText::FromString("Player speed: 0"))
		]
	];
}

void SAWidget::SetPlayerSpeed(float Speed)
{
	TextBlock->SetText(FText::Format(FTextFormat::FromString("Player speed: {0}"), Speed));
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
