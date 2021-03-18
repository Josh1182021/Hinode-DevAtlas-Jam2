// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireLv3EnemySpawner.h"
#include "Components/BoxComponent.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireLv3Enemy.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
ASapphireLv3EnemySpawner::ASapphireLv3EnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;


}

// Called when the game starts or when spawned
void ASapphireLv3EnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnEnemyCPP();
	// Spawn();
}

// Called every frame
void ASapphireLv3EnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASapphireLv3EnemySpawner::SpawnEnemyCPP() 
{
	SpawnEnemy();
}

// void ASapphireLv3EnemySpawner::Spawn() 
// {
	
// 	if (EnemyClass != nullptr)
// 	{
// 		FRotator BoxComponentRotation = BoxComponent->GetComponentRotation();
// 		FRotator EnemySpawnRotation = FRotator(0.f, BoxComponentRotation.Yaw, 0.f);
// 		FVector EnemySpawnLocation = BoxComponent->GetComponentLocation();

// 		ASapphireLv3Enemy* CurrentEnemy = GetWorld()->SpawnActor<ASapphireLv3Enemy>(EnemyClass, EnemySpawnLocation, EnemySpawnRotation);
// 		CurrentEnemy->SetOwner(this);
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("ASapphireLv3EnemySpawner::SpawnEnemy has no reference to the EnemyClass"));
// 	}
// }

