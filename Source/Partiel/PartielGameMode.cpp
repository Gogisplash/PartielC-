// Copyright Epic Games, Inc. All Rights Reserved.

#include "PartielGameMode.h"
#include "PartielCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

void APartielGameMode::IncreaseScore(int amount)
{
	TotalScore += amount;
}

void APartielGameMode::SpawnNewCube()
{

	
}

void APartielGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	currentTime += DeltaSeconds;

	if (TotalScore >= ScoreLimit) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Win"));
	}

	if (currentTime >= timeLimit) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Loose"));
		UGameplayStatics::OpenLevel(GetWorld(), FName(*GetWorld()->GetName()), false);
	}


}



APartielGameMode::APartielGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}


