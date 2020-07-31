// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireGameMode.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireMainCharacter.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireLv1Enemy.h"


void ASapphireGameMode::ActorDied(AActor* DeadActor) 
{
    ASapphireLv1Enemy* Lv1EnemyRef = Cast<ASapphireLv1Enemy>(DeadActor);
    if (Lv1EnemyRef != nullptr)
    {
        Lv1EnemyRef->Died();
    }
    ASapphireMainCharacter* PlayerRef = Cast<ASapphireMainCharacter>(DeadActor);
    if (PlayerRef != nullptr)
    {
        PlayerRef->MainCharacterDied();
        return;
    }
}
