// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABAnimNotifyState_AttackDash.h"

void UABAnimNotifyState_AttackDash::NotifyTick(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float FrameDeltaTime)
{
	AB_LOG_CALLONLY(Warning);

	AActor* Owner = MeshComp->GetOwner();
	if (Owner != nullptr && Owner->IsValidLowLevel())
	{
		APawn* OwnerPawn = Cast<APawn>(Owner);
		if (OwnerPawn->GetMovementComponent())
		{
			OwnerPawn->GetMovementComponent()->Velocity = OwnerPawn->GetActorForwardVector() * DashPower;
		}
	}
}
