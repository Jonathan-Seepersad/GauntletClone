// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GauntletGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(
	FOnAllGeneratorsDestroyed
);

/**
 * 
 */
UCLASS()
class GAUNTLET_API UGauntletGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnAllGeneratorsDestroyed OnAllGeneratorsDestroyed;
};
