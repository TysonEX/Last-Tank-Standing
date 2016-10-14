// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class LASTTANKSTANDING_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	void LaunchProjectile(float Speed);

private:
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Visuals")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UProjectileMovementComponent* MovementComponent = nullptr;

	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
};
