// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController1.h"
#include "Tank.h"




ATank *ATankPlayerController1::GetControlledTank() const
{
	return  Cast<ATank>(GetPawn());
}

void ATankPlayerController1::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possesing the tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controlling tank: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController1::AimTwoardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //out parameter

	if(GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString());
	}

	
}

bool ATankPlayerController1::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	OutHitLocation = FVector(1.f);
	return true;
}

void ATankPlayerController1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTwoardsCrosshair();

	//UE_LOG(LogTemp, Warning, TEXT("player controller tick called every frame"));
}

