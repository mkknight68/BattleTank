// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController1.h"
#include "Tank.h"




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

void ATankPlayerController1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTwoardsCrosshair();

	//UE_LOG(LogTemp, Warning, TEXT("player controller tick called every frame"));
}
ATank *ATankPlayerController1::GetControlledTank() const
{
	return  Cast<ATank>(GetPawn());
}

void ATankPlayerController1::AimTwoardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //out parameter

	if(GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}

	
}

bool ATankPlayerController1::GetSightRayHitLocation(FVector &HitLocation) const
{
	// find screen location
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeX * CrosshairXLocation);

	// De-project the screen position
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//linetrace to get point
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}

bool ATankPlayerController1::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

bool ATankPlayerController1::GetLookDirection(FVector2D ScreenLocation, FVector& Lookdirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, Lookdirection);
}



