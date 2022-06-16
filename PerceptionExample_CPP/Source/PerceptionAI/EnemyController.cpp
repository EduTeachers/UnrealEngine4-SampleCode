// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AEnemyController::AEnemyController()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SR Sight Config"));

	SightConfig->SightRadius = 6400.0f;
	SightConfig->PeripheralVisionAngleDegrees = 142.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->SetMaxAge(0);
	
	PerceptionComponent->ConfigureSense(*SightConfig);
	PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Init!"));
	
	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyController::SayHi);
}

void AEnemyController::SayHi(AActor* Actor, FAIStimulus Stimulus)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (Stimulus.IsActive() ? TEXT("I see you!") : TEXT("I don't see you!")));
}
