// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Tank2.h"
#include "Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();

	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller has not found a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing %s"), *(AIControlledTank->GetName()));
	}
}

ATank2 * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank2>(GetPawn());
}