// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABAnimInstance.h"

UABAnimInstance::UABAnimInstance()
{
	VelocityAnim = 0.0F;
	CurrentStateAnim = EPlayerState::PEACE;
}

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	APawn* OwnerPawn = TryGetPawnOwner();

	if (OwnerPawn != nullptr)
	{
		if (OwnerPawn->IsValidLowLevel())
		{
			VelocityAnim = OwnerPawn->GetVelocity().Size();
			AABPawn* ABPawn = Cast<AABPawn>(OwnerPawn);
			if (ABPawn)
			{
				CurrentStateAnim = ABPawn->CurrentState;
			}
		}
	}
}

void UABAnimInstance::AnimNotify_AttackEnd(UAnimNotify * Notify)
{
	APawn* OwnerPawn = TryGetPawnOwner();

	if (OwnerPawn != nullptr)
	{
		if (OwnerPawn->IsValidLowLevel())
		{
			AABPawn* ABPawn = Cast<AABPawn>(OwnerPawn);
			if (ABPawn)
			{
				ABPawn->OnNormalAttackEnd();
			}
		}
	}
}
