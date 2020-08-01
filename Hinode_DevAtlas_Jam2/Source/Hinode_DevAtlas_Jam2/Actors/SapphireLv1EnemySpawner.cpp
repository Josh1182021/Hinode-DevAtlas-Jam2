// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireLv1EnemySpawner.h"
#include "Components/BoxComponent.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireLv1Enemy.h"
#include "Engine/World.h"
#include "TimerManager.h"

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

	SpawnEnemyCPP();
	// Spawn();
}

// Called every frame
void ASapphireLv1EnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASapphireLv1EnemySpawner::SpawnEnemyCPP() 
{
	SpawnEnemy();
}

// void ASapphireLv1EnemySpawner::Spawn() 
// {
	
// 	if (EnemyClass != nullptr)
// 	{
// 		FRotator BoxComponentRotation = BoxComponent->GetComponentRotation();
// 		FRotator EnemySpawnRotation = FRotator(0.f, BoxComponentRotation.Yaw, 0.f);
// 		FVector EnemySpawnLocation = BoxComponent->GetComponentLocation();

// 		ASapphireLv1Enemy* CurrentEnemy = GetWorld()->SpawnActor<ASapphireLv1Enemy>(EnemyClass, EnemySpawnLocation, EnemySpawnRotation);
// 		CurrentEnemy->SetOwner(this);
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("ASapphireLv1EnemySpawner::SpawnEnemy has no reference to the EnemyClass"));
// 	}
// }

