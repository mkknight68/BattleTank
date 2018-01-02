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

	ATank *GetControlledTank() const;

	void BeginPlay() override;
	
};
