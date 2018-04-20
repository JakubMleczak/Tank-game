// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank1.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
		 {
		UE_LOG(LogTemp, Warning, TEXT("No player Tank"));
		}
	else
		 {
		UE_LOG(LogTemp, Warning, TEXT("Mam gracza %s"), *(PlayerTank->GetName()));
		}
}

ATank1* ATankAIController::GetControlledTank() const
{
	return Cast<ATank1>(GetPawn());
}

ATank1* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}

	return Cast<ATank1>(PlayerPawn);
	
}
