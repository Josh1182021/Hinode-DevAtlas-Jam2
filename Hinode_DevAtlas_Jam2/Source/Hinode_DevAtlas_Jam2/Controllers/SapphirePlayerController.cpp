// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphirePlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"


ASapphirePlayerController::ASapphirePlayerController()
{
    PrimaryActorTick.bCanEverTick = true;

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

void ASapphirePlayerController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner) 
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
    if (LoseScreen != nullptr)
    {
        LoseScreen->AddToViewport();
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
