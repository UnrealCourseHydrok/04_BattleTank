// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Public/Tank2.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h" 
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

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank){
	UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find PlayerTank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found PlayerTank as: %s"), *(PlayerTank->GetName()));
	}
}

ATank2 * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank2>(GetPawn());
}

ATank2 * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank2>(PlayerPawn);
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TODO move toward player

		//aim at the player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//fire if ready

	}

}