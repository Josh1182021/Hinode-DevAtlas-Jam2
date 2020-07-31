// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireLv1Enemy.h"

// Sets default values
ASapphireLv1Enemy::ASapphireLv1Enemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASapphireLv1Enemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASapphireLv1Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASapphireLv1Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

