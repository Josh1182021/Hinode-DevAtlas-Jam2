// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SapphireGameMode.generated.h"

/**
 * 
 */
UCLASS()
class HINODE_DEVATLAS_JAM2_API ASapphireGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);
};
