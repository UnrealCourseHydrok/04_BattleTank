// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Public/Tank2.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
		
public:
	ATank2 * GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick( float DeltaTime ) override;

	//start moving barrel toward reticule;
	void AimTowardsCrosshair();

private:
	//return an out paramter, true if hitlandscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
