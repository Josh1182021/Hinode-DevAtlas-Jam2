// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireLv2AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"


void ASapphireLv2AIController::BeginPlay() 
{
    Super::BeginPlay();

    if(AIBehavior == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("ASapphireLv1AIController::BeginPlay has no reference to AIBehaviorTree."));
        return;
    }
    RunBehaviorTree(AIBehavior);

    //GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetCharacter()->GetActorLocation());
}
