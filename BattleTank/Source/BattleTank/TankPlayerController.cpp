// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController has not found a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *(ControlledTank->GetName()));
	}
}


// Tick
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController is ticking"));
}

ATank2 * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank2>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) {
		return;
	}
	
	FVector OutHitLocation; //Out parameter
	if (GetSightRayHitLocation(OutHitLocation)) {

		UE_LOG(LogTemp, Warning, TEXT("OutHitLocation: %s"), *OutHitLocation.ToString());
		//if it hits the land
			//TODO then tell controlled tank to aim at this point
	}
}

//Get world location through crosshair (linetrace) (=true)
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
	//Get world location through crosshair (linetrace)
	OutHitLocation = FVector(1.0);
	return true;

}