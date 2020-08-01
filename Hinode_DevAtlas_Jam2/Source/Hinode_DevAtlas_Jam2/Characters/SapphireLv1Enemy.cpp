// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireLv1Enemy.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Hinode_DevAtlas_Jam2/Characters/SapphireMainCharacter.h"


// Sets default values
ASapphireLv1Enemy::ASapphireLv1Enemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASapphireLv1Enemy::Died() 
{
	Destroy();
}

// Called when the game starts or when spawned
void ASapphireLv1Enemy::BeginPlay()
{
	Super::BeginPlay();
	
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &ASapphireLv1Enemy::OnHit);
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

void ASapphireLv1Enemy::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
{
	if (OtherActor == nullptr || OtherActor == this)
	{
		return;
	}
	ASapphireMainCharacter* PlayerRef = Cast<ASapphireMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if(PlayerRef == nullptr)
	{
		return;
	}
	else
	{
	UGameplayStatics::ApplyDamage(OtherActor, Damage, Controller, this, DamageType);
	Destroy();
	}
}