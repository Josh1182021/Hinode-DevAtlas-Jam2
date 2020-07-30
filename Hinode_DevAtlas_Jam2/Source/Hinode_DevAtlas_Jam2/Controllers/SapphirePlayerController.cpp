// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphirePlayerController.h"

ASapphirePlayerController::ASapphirePlayerController()
{
    PrimaryActorTick.bCanEverTick = false;

}


void ASapphirePlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    bShowMouseCursor = true;

}


void ASapphirePlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}
