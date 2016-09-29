// Fill out your copyright notice in the Description page of Project Settings.

#include "LastTankStanding.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	AimingComponent->AimAt(HitLocation, ProjectileSpeed);
}

void ATank::Fire()
{
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeSecs;

	if (IsReloaded && TankBarrel)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s fires a shell!"), *GetName())
		AProjectile* SpawnedProjectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
																			 TankBarrel->GetSocketLocation("Projectile"),
																			 TankBarrel->GetSocketRotation("Projectile")
																			);
		SpawnedProjectile->LaunchProjectile(ProjectileSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

void ATank::SetBarrelReference(UTankBarrel* Barrel)
{
	if (AimingComponent)
	{
		AimingComponent->SetBarrelReference(Barrel);
	}

	TankBarrel = Barrel;
}

void ATank::SetTurretReference(UTankTurret* Turret)
{
	if (AimingComponent)
	{
		AimingComponent->SetTurretReference(Turret);
	}
}
