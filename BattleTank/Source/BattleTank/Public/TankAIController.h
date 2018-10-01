// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Public/Tank2.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;	

private:
	ATank2 * GetAIControlledTank() const;
	ATank2 * GetPlayerTank() const;

	
};
