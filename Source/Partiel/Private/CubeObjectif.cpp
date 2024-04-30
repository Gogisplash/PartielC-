// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeObjectif.h"
#include "../PartielProjectile.h"
#include "../PartielGameMode.h"

// Sets default values
ACubeObjectif::ACubeObjectif()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = SceneComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneComponent);

	StaticMesh->OnComponentHit.AddDynamic(this, &ACubeObjectif::OnObstacleHit);
}

// Called when the game starts or when spawned
void ACubeObjectif::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubeObjectif::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeObjectif::OnObstacleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	APartielProjectile* projectile = Cast<APartielProjectile>(OtherActor);
	APartielGameMode* gameMode = GetWorld()->GetAuthGameMode<APartielGameMode>();
	if (projectile) {
		gameMode->IncreaseScore(2);
		int32 score = gameMode->TotalScore;
		FString ScoreString = FString::FromInt(score);

		// Display the score using AddOnScreenDebugMessage
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString(TEXT("Score: ")) + ScoreString);

		Destroy();
		
	}
		
}

