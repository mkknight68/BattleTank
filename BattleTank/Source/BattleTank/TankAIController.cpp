// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"





void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai Controller not possesing the tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank found Player: %s"), *(PlayerTank->GetName()));
	}
}

ATank *ATankAIController::GetAiControlledTank() const
{
	return  Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		GetAiControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}





