// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireLv1AIController.h"


void ASapphireLv1AIController::BeginPlay() 
{
    Super::BeginPlay();

    if(AIBehavior == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("ASapphireLv1AIController::BeginPlay has no reference to AIBehaviorTree."));
        return;
    }
    RunBehaviorTree(AIBehavior);
}
