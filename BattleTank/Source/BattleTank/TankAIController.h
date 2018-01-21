// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:



private:
	void Tick(float DeltaSeconds) override;

	ATank *GetAiControlledTank() const;

	void BeginPlay() override;
	
	ATank *GetPlayerTank() const;
};
