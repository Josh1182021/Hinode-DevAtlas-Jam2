// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SapphirePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HINODE_DEVATLAS_JAM2_API ASapphirePlayerController : public APlayerController
{
	GENERATED_BODY()

public: 
    ASapphirePlayerController();

    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;
};
