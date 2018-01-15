// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent, hidecategories = "Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

		void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, category ="Setup")
	float MaxDegreesPerSecond = 20.0f;

	UPROPERTY(EditAnywhere, category = "Setup")
	float MaxElevationDegrees = 40.0f;

	UPROPERTY(EditAnywhere, category = "Setup")
	float MinElevationDegrees = 0;


	
};
