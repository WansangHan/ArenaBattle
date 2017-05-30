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

void UABAnimInstance::AnimNotify_NextAttack(UAnimNotify* Notify)
{
	bCanDoNextAttack = false;
	if (bInputReservedForNextAttack)
	{
		PlayNormalAttack(++CurrentNormalAttackIndex);
	}
}

void UABAnimInstance::ReceiveNormalAttackInput()
{
	AB_LOG_CALLONLY(Warning);

	if (CurrentNormalAttackIndex == -1)
	{
		PlayNormalAttack(1);
	}
	else
	{
		if (bCanDoNextAttack)
		{
			bInputReservedForNextAttack = true;
		}
	}
}

void UABAnimInstance::PlayNormalAttack(int32 NewIndex)
{
	if (!Montage_IsPlaying(NormalAttackMontage))
	{
		Montage_Play(NormalAttackMontage, 1.5F);
	}
	FName MontageSectionToJump(*FString::Printf(TEXT("Attack%d"), NewIndex));
	Montage_JumpToSection(MontageSectionToJump, NormalAttackMontage);
	CurrentNormalAttackIndex = NewIndex;
	bCanDoNextAttack = true;
	bInputReservedForNextAttack = false;
}
