// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireMainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SpotLightComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Hinode_DevAtlas_Jam2/Controllers/SapphirePlayerController.h"
#include "Hinode_DevAtlas_Jam2/Actors/ProjectileBase.h"
#include "Math/UnrealMathUtility.h"


// Sets default values
ASapphireMainCharacter::ASapphireMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	RootComponent = CapsuleComponent;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(CapsuleComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	SkeletalMesh->SetupAttachment(CapsuleComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle Point"));
	ProjectileSpawnPoint->SetupAttachment(SkeletalMesh);

	LightSource = CreateDefaultSubobject<USpotLightComponent>(TEXT("Spot Light"));
	LightSource->SetupAttachment(CapsuleComponent);
}

// Called when the game starts or when spawned
void ASapphireMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASapphireMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	HandleBatteryTick(DeltaTime);
	PointAtMouse();
}

// Called to bind functionality to input
void ASapphireMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ASapphireMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ASapphireMainCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ASapphireMainCharacter::Fire);
	PlayerInputComponent->BindAction(TEXT("Charging"), IE_Repeat, this, &ASapphireMainCharacter::Charging);
	PlayerInputComponent->BindAction(TEXT("Charging"), IE_Released, this, &ASapphireMainCharacter::DoneCharging);

}

void ASapphireMainCharacter::MoveForward(float AxisValue) 
{
	AddActorLocalOffset(FVector(1.f, 0.f, 0.f) * AxisValue * Speed * GetWorld()->GetDeltaSeconds(), true);
}
void ASapphireMainCharacter::MoveRight(float AxisValue) 
{
	AddActorLocalOffset(FVector(0.f, 1.f, 0.f) * AxisValue * Speed * GetWorld()->GetDeltaSeconds(), true);
}

void ASapphireMainCharacter::PointAtMouse() 
{
    if (Controller == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("ASapphireMainCharacter::PointAtMouse has no reference to Controller."));
		return;
	}

	ASapphirePlayerController* PlayerController = Cast<ASapphirePlayerController>(Controller);
	if (PlayerController == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ASapphireMainCharacter::PointAtMouse has no valid reference to PlayerController."));
		return;
	}
	FVector CharacterPosition = this->GetActorLocation();

	FHitResult MousePositionInWorld;

	bool bDidHit = PlayerController->GetHitResultUnderCursor(ECC_Visibility, true, MousePositionInWorld);

	if(!bDidHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("ASapphireMainCharacter::PointAtMouse could not trace mouse hit."));
		return;
	}

	FRotator TargetRotation = FVector((MousePositionInWorld.Location) - CharacterPosition).Rotation();
	FRotator AdjustedRotation = FRotator(0.f, TargetRotation.Yaw - 90.f, 0.f);

	SkeletalMesh->SetWorldRotation(AdjustedRotation);
}

float ASapphireMainCharacter::GetBatteryPercent() 
{
	return Battery/100.f;
}

void ASapphireMainCharacter::HandleBatteryTick(float DeltaTime) 
{
	if (Battery > 0.f)
	{
		Battery = Battery - FMath::Clamp(((100.f/TotalSecondsInBattery) * DeltaTime), 0.f, 100.f);
	}
	LightSource->SetOuterConeAngle((Battery/100.f) * LargestLightAngle);
	LightSource->SetInnerConeAngle((Battery/100.f) * LargestLightAngle + LightConeDelta);
	UE_LOG(LogTemp, Warning, TEXT("%f"), Battery);
	
}

void ASapphireMainCharacter::Charging() 
{
	CanFire = false;
	UE_LOG(LogTemp, Warning, TEXT("Charging"));
	if (Battery <= 100.f && Battery >= 0.f)
	{
		Battery = Battery + FMath::Clamp(((100.f/TotalSecondsInBattery) * GetWorld()->GetDeltaSeconds() * ChargingMultiplier), 0.f, 100.f);
	}
	LightSource->SetOuterConeAngle((Battery/100.f) * LargestLightAngle);
	LightSource->SetInnerConeAngle((Battery/100.f) * LargestLightAngle + LightConeDelta);
	// UE_LOG(LogTemp, Warning, TEXT("%f"), Battery);

}

void ASapphireMainCharacter::DoneCharging() 
{
	CanFire = true;
}

void ASapphireMainCharacter::Fire() 
{
	if (CanFire == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't fire right now because we are charging."));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Fire"));
		if (ProjectileClass == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("ASapphireMainCharacter::Fire has no valid reference to ProjectileClass."));
			return;
		}
		else
		{
			FRotator ProjectileSpawnPointRotation = ProjectileSpawnPoint->GetComponentRotation();
			FRotator ProjectileSpawnPointAjustedRotation = FRotator(0.f, ProjectileSpawnPointRotation.Yaw - 90.f, 0.f);
			
			AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPointRotation);
			TempProjectile->SetOwner(this);
		}
	}
}