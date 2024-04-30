// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PartielGameMode.generated.h"

UCLASS(minimalapi)
class APartielGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = Config)
	int32 TotalScore = 0;

	UPROPERTY(EditAnywhere, Category = Config)
	int32 ScoreLimit = 10;

	UPROPERTY(EditAnywhere, Category = Config)
	int32 CubeToSpawn = 10;

	UPROPERTY(EditAnywhere, Category = Config)
	float timeLimit = 300;

	UPROPERTY(EditAnywhere, Category = Config)
	float currentTime = 0;

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void IncreaseScore(int amount);
	
	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void SpawnNewCube();

	virtual void Tick(float DeltaSeconds) override;

	APartielGameMode();

	
};



