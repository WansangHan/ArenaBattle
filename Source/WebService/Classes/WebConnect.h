// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "WebConnect.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FTokenCompleteSignature, const FString&);

/**
 * 
 */
 //언리얼 오브젝트를 사용하기 위하여 클래스 이름 앞에 U가 있어야 함.
UCLASS()
class WEBSERVICE_API UWebConnect : public UObject
{
	//UHT의 매크로
	GENERATED_BODY()
	
public :
	UWebConnect();

	UPROPERTY()
	FString Host;

	UPROPERTY()
	FString URI;

	UFUNCTION()
	void RequestToken(const FString& UserID);

	FTokenCompleteSignature TokenCompleteDelegate;
};
