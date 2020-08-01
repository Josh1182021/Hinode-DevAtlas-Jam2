// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireLv1EnemySpawner.h"
#include "Components/BoxComponent.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireLv1Enemy.h"
#include "Engine/World.h"

// Sets default values
ASapphireLv1EnemySpawner::ASapphireLv1EnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

}

// Called when the game starts or when spawned
void ASapphireLv1EnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnEnemy(0.f);
}

// Called every frame
void ASapphireLv1EnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

