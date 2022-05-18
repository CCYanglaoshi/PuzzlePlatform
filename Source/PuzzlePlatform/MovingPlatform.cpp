// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	//set up tick
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0)
	{
		// if is server
		if (HasAuthority())
		{
			FVector Location = GetActorLocation();
			// if  
			if (FVector::Dist(Location, GlobalStartLocation) >= FVector::Dist(GlobalTargetLocation, GlobalStartLocation))
			{
				FVector OldGlobalStartLocation = GlobalStartLocation;
				FVector OldGlobalTargetLocation = GlobalTargetLocation;
				GlobalTargetLocation = OldGlobalStartLocation;
				GlobalStartLocation = OldGlobalTargetLocation;
			}
			FVector Diraction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += Diraction * MoveSpeed * DeltaTime;
			SetActorLocation(Location);
		}
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers += 1;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers -= 1;
	}
}

