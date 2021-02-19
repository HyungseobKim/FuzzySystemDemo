// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FuzzySystem.h"

#include "UObject/ConstructorHelpers.h"
#include "Components/SphereComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

class UMaterialInstanceDynamic;

UCLASS()
class MAT367PROJECT1_API AEnemyActor : public AActor
{
public:	
	GENERATED_BODY()

	// Sets default values for this actor's properties
	AEnemyActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

private:
	ACharacter* player;
	FuzzySystem fuzzy;

	UMaterialInstanceDynamic* DynamicMaterial;
};
