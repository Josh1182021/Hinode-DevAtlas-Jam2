// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireGameMode.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireMainCharacter.h"


void ASapphireGameMode::ActorDied(AActor* DeadActor) 
{
    //cast to enemy
    ASapphireMainCharacter* PlayerRef = Cast<ASapphireMainCharacter>(DeadActor);
    if (PlayerRef != nullptr)
    {
        PlayerRef->MainCharacterDied();
    }
}
