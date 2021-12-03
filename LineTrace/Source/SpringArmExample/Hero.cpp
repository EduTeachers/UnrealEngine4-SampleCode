// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"

#include "DrawDebugHelpers.h"
#include "TraceChannelDefinitions.h"

// Sets default values
AHero::AHero()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("Arm");
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 300;
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void AHero::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation() + (GetActorForwardVector() * 100);
	FVector ForwardVector = CameraComponent->GetForwardVector() * 1000;

	UE_LOG(LogTemp, Warning, TEXT("Tick!"))

	DrawDebugLine(GetWorld(), Location, ForwardVector, FColor::Purple);
	
	TArray<FHitResult> HitResults;
	bool result = GetWorld()->LineTraceMultiByChannel(
		HitResults, Location, ForwardVector, ECC_LookAt
	);
	UE_LOG(LogTemp, Warning, TEXT("%d"), (result ? 1 : 0))
	UE_LOG(LogTemp, Warning, TEXT("Array size: %d"), HitResults.Num())
/*
	FHitResult HitResult;
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult, Location,
		ForwardVector, ECC_WorldStatic
	))
	{
		FString FullName = HitResult.Actor->GetFullName();
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *FullName)
	}*/
}

// Called to bind functionality to input
void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AHero::MoveForward);
	PlayerInputComponent->BindAxis("Sideways", this, &AHero::MoveSideways);
	PlayerInputComponent->BindAxis("MouseMovementX", this, &AHero::AddControllerYawInput);
	PlayerInputComponent->BindAxis("MouseMovementY", this, &AHero::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

void AHero::MoveForward(float Scale)
{
	AddMovementInput(GetActorForwardVector(), Scale);
}

void AHero::MoveSideways(float Scale)
{
	AddMovementInput(GetActorRightVector(), Scale);
}
