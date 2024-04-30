// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeObjectif.generated.h"

UCLASS()
class PARTIEL_API ACubeObjectif : public AActor
{
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this actor's properties
	ACubeObjectif();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component)
	class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component)
	class UStaticMeshComponent* StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnObstacleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


};
