// Fill out your copyright notice in the Description page of Project Settings.


#include "SapphireMainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SpotLightComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Hinode_DevAtlas_Jam2/Controllers/SapphirePlayerController.h"


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

	MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle Point"));
	MuzzlePoint->SetupAttachment(SkeletalMesh);

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
}

void ASapphireMainCharacter::MoveForward(float AxisValue) 
{
	AddActorLocalOffset(FVector(1, 0, 0) * AxisValue * Speed * GetWorld()->GetDeltaSeconds(), true);
}
void ASapphireMainCharacter::MoveRight(float AxisValue) 
{
	AddActorLocalOffset(FVector(0, 1, 0) * AxisValue * Speed * GetWorld()->GetDeltaSeconds(), true);
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
	FRotator AdjustedRotation = FRotator(0, TargetRotation.Yaw - 90, 0);

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
		Battery = Battery - (1.f) * DeltaTime;
	}
	LightSource->SetOuterConeAngle((Battery/100) * LargestLightAngle);
	LightSource->SetInnerConeAngle((Battery/100) * LargestLightAngle + LightConeDelta);
	UE_LOG(LogTemp, Warning, TEXT("%f"), Battery);
	
}