// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_Blackboard.h"
#include "BTDecorator_IsObjectWithinRadius.generated.h"

/**
 * 
 */
UCLASS()
class HINODE_DEVATLAS_JAM2_API UBTDecorator_IsObjectWithinRadius : public UBTDecorator_Blackboard
{
	GENERATED_BODY()

public: 
	UBTDecorator_IsObjectWithinRadius();

protected:
	virtual void TickNode (UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds) override;

};
