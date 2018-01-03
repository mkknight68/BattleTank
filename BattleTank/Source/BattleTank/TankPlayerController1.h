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

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	
};
