// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Health.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnDeathCallback,
	AActor*, Causer
);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAUNTLET_API UHealth : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealth();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth = 1000;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentHealth;

	UFUNCTION(BlueprintCallable)
	void Hurt(float Damage, AActor* Causer);

	UFUNCTION(BlueprintCallable)
	void Kill(AActor* Causer);

	UFUNCTION(BlueprintCallable)
	void Heal(float HealAmount);

	UFUNCTION(BlueprintPure, BlueprintCallable)
	bool IsAlive() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable)
	FOnDeathCallback OnDeath;
};
