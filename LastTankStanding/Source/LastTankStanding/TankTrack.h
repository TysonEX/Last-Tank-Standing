// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LASTTANKSTANDING_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Max force per track in newtons.
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float TrackMaxDrivingForce = 400000.0f; // Assume a tank with a mass 40000 kg, with 10 m/s^2 acceleration

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SetThrottle(float Throttle);

private:
	// Sets default values for this component's properties
	UTankTrack();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
