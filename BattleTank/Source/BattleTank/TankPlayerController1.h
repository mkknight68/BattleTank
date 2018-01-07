// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController1.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController1 : public APlayerController
{
	GENERATED_BODY()


public:	

	virtual void Tick(float DeltaSeconds) override;

	ATank *GetControlledTank() const;

	void BeginPlay() override;

private:

	//tank barrel should follow  the crosshair
	void AimTwoardsCrosshair();

	bool GetSightRayHitLocation(FVector &HitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& Lookdirection) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};
