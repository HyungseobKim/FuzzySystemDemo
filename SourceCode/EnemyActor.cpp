// Fill out your copyright notice in the Description page of Project Settings.

#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "Components/StaticMeshComponent.h"

#include "GameFramework/Character.h"
#include "EnemyActor.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, text);

// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();

	player = GetWorld()->GetFirstPlayerController()->GetCharacter();

	auto Mesh = FindComponentByClass<UStaticMeshComponent>();
	auto Material = Mesh->GetMaterial(0);

	DynamicMaterial = UMaterialInstanceDynamic::Create(Material, NULL);
	Mesh->SetMaterial(0, DynamicMaterial);
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Setup crisp input.
	const float speed = player->GetVelocity().Size();

	FVector EnemyLocation = GetActorLocation();
	FVector PlayerLocation = player->GetActorLocation();

	auto playerToEnemy = EnemyLocation - PlayerLocation;

	const float distance = playerToEnemy.Size();

	// Get result of fuzzy system.
	const float color = fuzzy.Defuzzyfication(distance, speed);

	// Change color.
	FLinearColor newColor;
	newColor.R = 1.f;
	newColor.G = 1.f - color;
	newColor.B = 1.f - color;

	DynamicMaterial->SetVectorParameterValue(TEXT("Color"), newColor);

	// Change speed.
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	EnemyLocation.X += DeltaHeight * 500.f * color;
	SetActorLocation(EnemyLocation);
}

