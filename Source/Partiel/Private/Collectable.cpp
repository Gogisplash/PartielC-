// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable.h"
#include "../PartielCharacter.h"
#include "../PartielGameMode.h"
#include "Components/SphereComponent.h"

// Sets default values
ACollectable::ACollectable()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = SceneComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneComponent);

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));

	SphereCollider->SetupAttachment(SceneComponent);

	//SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ABonus::OnSphereOverlap);

}

void ACollectable::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APartielCharacter* character = Cast<APartielCharacter>(OtherActor);
	APartielGameMode* gameMode = GetWorld()->GetAuthGameMode<APartielGameMode>();
	if (character) {

		gameMode->IncreaseScore(1);
		Destroy();
	}

}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

