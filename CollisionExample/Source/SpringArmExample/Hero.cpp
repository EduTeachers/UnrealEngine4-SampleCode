// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"

#include "Components/CapsuleComponent.h"

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

	// Kontrola kolize CapsuleComponent
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AHero::OnCollide);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AHero::OnStopCollision);

	// Kontrola kolize SkeletalMeshComponent
	//GetMesh()->OnComponentBeginOverlap.AddDynamic(this, &AHero::OnCollide);
}

// Called every frame
void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Kdybych chtěl projet všechny Actory se kterými koliduji
	/*TArray<AActor*> Result;
	GetOverlappingActors(Result,AActor::StaticClass());
	for (auto Actor : Result)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor: %s"), *Actor->GetFullName())
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

void AHero::OnCollide(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Colliding with: %s"), *OtherActor->GetFullName());
}

void AHero::OnStopCollision(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Collision stopped with: %s"), *OtherActor->GetFullName());
}


