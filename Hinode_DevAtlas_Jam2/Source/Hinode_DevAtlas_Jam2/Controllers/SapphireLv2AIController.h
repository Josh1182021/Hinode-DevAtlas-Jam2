// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SapphireLv2AIController.generated.h"

/**
 * 
 */
UCLASS()
class HINODE_DEVATLAS_JAM2_API ASapphireLv2AIController : public AAIController
{
	GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
