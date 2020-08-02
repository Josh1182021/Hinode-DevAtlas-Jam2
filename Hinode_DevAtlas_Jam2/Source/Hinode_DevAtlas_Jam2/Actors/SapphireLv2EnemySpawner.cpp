// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireLv2EnemySpawner.h"
#include "Components/BoxComponent.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireLv2Enemy.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
ASapphireLv2EnemySpawner::ASapphireLv2EnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;


}

// Called when the game starts or when spawned
void ASapphireLv2EnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnEnemyCPP();
	// Spawn();
}

// Called every frame
void ASapphireLv2EnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASapphireLv2EnemySpawner::SpawnEnemyCPP() 
{
	SpawnEnemy();
}

// void ASapphireLv2EnemySpawner::Spawn() 
// {
	
// 	if (EnemyClass != nullptr)
// 	{
// 		FRotator BoxComponentRotation = BoxComponent->GetComponentRotation();
// 		FRotator EnemySpawnRotation = FRotator(0.f, BoxComponentRotation.Yaw, 0.f);
// 		FVector EnemySpawnLocation = BoxComponent->GetComponentLocation();

// 		ASapphireLv2Enemy* CurrentEnemy = GetWorld()->SpawnActor<ASapphireLv2Enemy>(EnemyClass, EnemySpawnLocation, EnemySpawnRotation);
// 		CurrentEnemy->SetOwner(this);
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("ASapphireLv2EnemySpawner::SpawnEnemy has no reference to the EnemyClass"));
// 	}
// }

