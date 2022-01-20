// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"

#include "GameHUD.h"
#include "SAWidget.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHero::AHero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
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

	GameHUD = Cast<AGameHUD>(UGameplayStatics::GetPlayerController(this->GetOwner(), 0)->GetHUD());
}

// Called every frame
void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// !!!!! NENÍ NEJVHODNĚJŠÍ PROVOLÁVAT HUD TŘÍDU Z AKTÉRA !!!!!
	// !!!!! ZDE JE TO POUZE PRO UKÁZKU PŘÍKLADU !!!!
	if (IsValid(GameHUD))
	{
		GameHUD->InGameWidget->SetPlayerSpeed(GetVelocity().Size());
	}
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
	AddMovementInput(GetActorForwardVector() * Scale);
}

void AHero::MoveSideways(float Scale)
{
	AddMovementInput(GetActorRightVector() * Scale);
}

