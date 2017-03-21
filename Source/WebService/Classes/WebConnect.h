// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "WebConnect.generated.h"

/**
 * 
 */
UCLASS()
class WEBSERVICE_API UWebConnect : public UObject
{
	//UHT�� ��ũ��
	GENERATED_BODY()
	
public :
	UWebConnect();
	
	UPROPERTY()
	FString MyName;

	UFUNCTION()
	FString GetName() { return TEXT("MyName"); }
};
