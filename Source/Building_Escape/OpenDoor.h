// Copyright Dan Stevenson 2022

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindAudioComponent();
	void FindPressurePlate();
	bool OpenDoorSound = 0;
	bool CloseDoorSound = 1;

private:
	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	float MassToOpenDoors = 10;

	UPROPERTY(EditAnywhere)
	float OpenAngle = 90;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = .25f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 2.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 4.f;

	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;
};
