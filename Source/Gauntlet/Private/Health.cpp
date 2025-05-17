// Fill out your copyright notice in the Description page of Project Settings.


#include "Health.h"

// Sets default values for this component's properties
UHealth::UHealth()
{
	// ...
}


// Called when the game starts
void UHealth::BeginPlay()
{
	Super::BeginPlay();

	// ...

	CurrentHealth = MaxHealth;
}

void UHealth::Hurt(float Damage, AActor* Causer)
{
	if (Damage > MaxHealth) Damage = MaxHealth;
	CurrentHealth -= Damage;
	if (CurrentHealth <= 0) OnDeath.Broadcast(Causer);
}

void UHealth::Kill(AActor* Causer)
{
	CurrentHealth = 0;
	OnDeath.Broadcast(Causer);
}

void UHealth::Heal(float HealAmount)
{
	CurrentHealth += HealAmount;
	if (CurrentHealth > MaxHealth) CurrentHealth = MaxHealth;
}

bool UHealth::IsAlive() const
{
	return CurrentHealth > 0;
}

