// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(
	UInputComponent* PlayerInputComponent
)
{
	// Set up enhanced input subsystem
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController =
		Cast<APlayerController>(GetController());

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
			PlayerController->GetLocalPlayer()
		);

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	// Set up input actions
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(
		PlayerInputComponent);

	Input->BindAction(
		WalkAction,
		ETriggerEvent::Triggered,
		this,
		&ABasePlayer::Walk
	);
}

void ABasePlayer::Walk(const FInputActionValue& value)
{
	FVector2D Direction = value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("Walking in direction: %s"), *Direction.ToString());
}