// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireGameMode.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireMainCharacter.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireLv1Enemy.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireLv2Enemy.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "EngineUtils.h"

void ASapphireGameMode::ActorDied(AActor* DeadActor) 
{
    ASapphireMainCharacter* PlayerRef = Cast<ASapphireMainCharacter>(DeadActor);
    if (PlayerRef != nullptr)
    {
        PlayerRef->MainCharacterDied();
        
        APlayerController* PlayerController = Cast<APlayerController>(PlayerRef->GetController());
        if (PlayerController != nullptr)
        {
            EndGame(false);
            return;
        }
    }

    ASapphireLv1Enemy* Lv1EnemyRef = Cast<ASapphireLv1Enemy>(DeadActor);
    if (Lv1EnemyRef != nullptr)
    {
        Lv1EnemyRef->Died();
    }

    ASapphireLv2Enemy* Lv2EnemyRef = Cast<ASapphireLv2Enemy>(DeadActor);
    if (Lv2EnemyRef != nullptr)
    {
        Lv2EnemyRef->Died();
    }

    // for (AAIController* AIController : TActorRange<ASapphireLv1AIController>(GetWorld()))
    // {
    //     if(!AIController->IsDead())
    // }
}

void ASapphireGameMode::EndGame(bool bIsPlayerWinner) 
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}
