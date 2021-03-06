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
	//엔진 초기화시 호출하여 CDO 생성.
	UABGameInstance();

	//Runtime 시작시 호출
	virtual void Init() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "WebService")
	class UWebConnect* WebConnect;
	UPROPERTY()
	class UWebConnect* WebConnect2;

	UPROPERTY()
	class UWebConnect* WebConnectionNew;

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
