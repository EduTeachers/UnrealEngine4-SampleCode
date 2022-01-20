// Fill out your copyright notice in the Description page of Project Settings.


#include "SAWidget.h"

#include "SlateOptMacros.h"
#include "Widgets/Layout/SGridPanel.h"

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
		/*SNew(SOverlay)
		+ SOverlay::Slot()
		  .HAlign(HAlign_Center) // Popř. HAlign_Fill, HAlign_Left, HAlign_Right
		  .VAlign(VAlign_Center)
		[
			SAssignNew(TextBlock, STextBlock)
			.Font(TextStyle)
			.Text(FText::FromString("Player speed: 0"))
		]*/

		/*
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
					.Font(TextStyle)
					.Text(FText::FromString("Skákal"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
					.Font(TextStyle)
					.Text(FText::FromString("Pes"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Bottom)
			[
				SNew(STextBlock)
					.Font(TextStyle)
					.Text(FText::FromString("Přes"))
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
					.Font(TextStyle)
					.Text(FText::FromString("Oves"))
			]*/

		// Funguje stejně jako SHorizontalBox
		//SNew(SVerticalBox)
		//SNew(SScrollBox)

		SNew(SGridPanel)
		+ SGridPanel::Slot(0, 0)
		[
			SNew(STextBlock)
				.Font(TextStyle)
				.Text(FText::FromString("Educanet"))
		]
		+ SGridPanel::Slot(0, 1)
		[
			SNew(STextBlock)
				.Font(TextStyle)
				.Text(FText::FromString("Educanet"))
		]
		+ SGridPanel::Slot(1, 0)
		[
			SNew(STextBlock)
				.Font(TextStyle)
				.Text(FText::FromString("Educanet"))
		]
		+ SGridPanel::Slot(1, 1)
		[
			SNew(STextBlock)
				.Font(TextStyle)
				.Text(FText::FromString("Educanet"))
		]
	];
}

void SAWidget::SetPlayerSpeed(float Speed)
{
	//TextBlock->SetText(FText::Format(FTextFormat::FromString("Player speed: {0}"), Speed));
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
