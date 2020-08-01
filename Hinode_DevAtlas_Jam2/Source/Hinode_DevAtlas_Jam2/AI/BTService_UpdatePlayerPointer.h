// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_UpdatePlayerPointer.generated.h"

/**
 * 
 */
UCLASS()
class HINODE_DEVATLAS_JAM2_API UBTService_UpdatePlayerPointer : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public: 
	UBTService_UpdatePlayerPointer();

protected:
	virtual void TickNode (UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds) override;

};
