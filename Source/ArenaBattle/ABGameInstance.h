// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "WebConnect.h"
#include "ABGameInstance.generated.h"

class FHouse
{
public: 
	TSharedPtr<FHouse> OthersDeed;
	TWeakPtr<FHouse> AccessHouse;
	int32 Size = 10;

	void RequestTokenComplete(const FString& Token)
	{
		UE_LOG(LogClass, Warning, TEXT("Test..."));
	}
};

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public :
	//���� �ʱ�ȭ�� ȣ���Ͽ� CDO ����.
	UABGameInstance();

	//Runtime ���۽� ȣ��
	virtual void Init() override;

	UPROPERTY()
	class UWebConnect* WebConnect;
	// UPROPERTY()
	class UWebConnect* WebConnect2;

	UPROPERTY()
	FStreamableManager AssetLoader;


	FTimerHandle ObjectCheckTimer;

	UFUNCTION()
	void CheckUObjectAlive();

	UFUNCTION()
	void RequestTokenComplete(const FString& Token);


	UFUNCTION()
	void RequestTokenComplete2(const FString& Token);
};