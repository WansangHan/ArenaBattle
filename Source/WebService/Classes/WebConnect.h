// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "WebConnect.generated.h"

/**
 * 
 */
 //�𸮾� ������Ʈ�� ����ϱ� ���Ͽ� Ŭ���� �̸� �տ� U�� �־�� ��.
UCLASS()
class WEBSERVICE_API UWebConnect : public UObject
{
	//UHT�� ��ũ��
	GENERATED_BODY()
	
public :
	UWebConnect();

	UPROPERTY()
	FString Host;

	UPROPERTY()
	FString URI;

	UFUNCTION()
	void RequestToken();
};
