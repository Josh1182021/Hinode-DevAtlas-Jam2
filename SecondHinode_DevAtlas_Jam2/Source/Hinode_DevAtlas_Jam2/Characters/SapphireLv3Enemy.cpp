// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireLv3Enemy.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireMainCharacter.h"
#include "Hinode_DevAtlas_Jam2/Actors/SapphireLv3EnemySpawner.h"

// Sets default values
ASapphireLv3Enemy::ASapphireLv3Enemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASapphireLv3Enemy::Died() 
{
	if(GetOwner())
	{
		ASapphireLv3EnemySpawner* Spawner = Cast<ASapphireLv3EnemySpawner>(GetOwner());
		if(Spawner)
		{
			UE_LOG(LogTemp, Warning, TEXT("got here"));
			Spawner->SpawnEnemyCPP();
		}
	}
	Destroy();
}

// Called when the game starts or when spawned
void ASapphireLv3Enemy::BeginPlay()
{
	Super::BeginPlay();
	
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ASapphireLv3Enemy::OnHit);
}

// Called every frame
void ASapphireLv3Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASapphireLv3Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASapphireLv3Enemy::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
{
	if (OtherActor == nullptr || OtherActor == this)
	{
		return;
	}
	ASapphireMainCharacter* PlayerRef = Cast<ASapphireMainCharacter>(OtherActor);
	if(PlayerRef == nullptr)
	{
		return;
	}
	else
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, Controller, this, DamageType);
		UGameplayStatics::ApplyDamage(this , Damage, Controller, this, DamageType);
	}
}