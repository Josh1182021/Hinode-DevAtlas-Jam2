// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SapphireMainCharacter.generated.h"

class AProjectileBase;

UCLASS()
class HINODE_DEVATLAS_JAM2_API ASapphireMainCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASapphireMainCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MainCharacterDied();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//Character Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light", meta = (AllowPrivateAccess = "true"))
	class USpotLightComponent* LightSource;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* ProjectileSpawnPoint;
	//End of Character Components

	//Movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Speed = 300.f;
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void PointAtMouse();
	//End of Movement

	//Light
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light", meta = (AllowPrivateAccess = "true"))
	float Battery = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light", meta = (AllowPrivateAccess = "true"))
	float LargestLightAngle = 50.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light", meta = (AllowPrivateAccess = "true"))
	float LightConeDelta = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light", meta = (AllowPrivateAccess = "true"))
	float TotalSecondsInBattery = 60.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light", meta = (AllowPrivateAccess = "true"))
	float ChargingMultiplier = 6.f;
	UFUNCTION(BlueprintPure)
	float GetBatteryPercent();
	void HandleBatteryTick(float DeltaTime);
	void Charging();
	void DoneCharging();

	//End of Light

	//Combat
	void Fire();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"));
	TSubclassOf<AProjectileBase> ProjectileClass;
	bool IsCharging = false;
	void CheckIfDead();
	//End of Combat
};
