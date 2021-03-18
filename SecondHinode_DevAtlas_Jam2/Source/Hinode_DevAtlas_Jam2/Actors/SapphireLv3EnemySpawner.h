// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SapphireLv3EnemySpawner.generated.h"

class ASapphireLv3Enemy;

UCLASS()
class HINODE_DEVATLAS_JAM2_API ASapphireLv3EnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASapphireLv3EnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnEnemy();

	UFUNCTION()
	void SpawnEnemyCPP();
	
	// UFUNCTION()
	// void Spawn();

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ASapphireLv3Enemy> EnemyClass;

	// float EnemySpawnDelay = 3;
};
