// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdatePlayerPointer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"



UBTService_UpdatePlayerPointer::UBTService_UpdatePlayerPointer() 
{
    NodeName = TEXT("Update Player Pointer");
}


void UBTService_UpdatePlayerPointer::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds) 
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
 
    if(PlayerPawn == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("UBTService_PlayerLocation::TickNode has no valid reference to UGameplayStatics::GetPlayerPawn(GetWorld(), 0) aka PlayerPawn"));
        return;
    }

    OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn); 
}