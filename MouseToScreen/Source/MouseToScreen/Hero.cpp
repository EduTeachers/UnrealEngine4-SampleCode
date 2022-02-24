// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"

#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AHero::AHero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHero::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->GravityScale = 0;
	SetActorRotation(FRotator(-30, 0, 0));

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	PlayerController->bShowMouseCursor = true;
	PlayerController->SetInputMode(FInputModeGameAndUI());
}

// Called every frame
void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAction("Click", IE_Pressed, this, &AHero::DrawLine);
}

void AHero::DrawLine()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	FVector Location, Direction;
	PlayerController->DeprojectMousePositionToWorld(Location, Direction);

	FVector Start = GetActorLocation();
	FVector End = (Location + Direction * 2000.0f);

	DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 30);
}

