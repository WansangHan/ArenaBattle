// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABGameInstance.h"

UABGameInstance::UABGameInstance()
{
	AB_LOG(Warning, TEXT("ABGameInstance Constructor!"));

	//�Ű������� ���� TEXT�� ���������Ʈ�� �����ϱ����� ���� �ؽ���.
	WebConnect = CreateDefaultSubobject<UWebConnect>(TEXT("WebConnect"));
}

void UABGameInstance::Init()
{
	AB_LOG_CALLONLY(Warning);

	Super::Init();
	WebConnect2 = NewObject<UWebConnect>(this);

	AB_LOG(Warning, TEXT("Outer of NewObject : %s"), *WebConnect2->GetOuter()->GetClass()->GetName());
	AB_LOG(Warning, TEXT("Outer of NewObject : %s"), *WebConnect2->GetOuter()->GetClass()->GetFullName());

	UClass* ClassInfo1 = WebConnect->GetClass();
	UClass* ClassInfo2 = UWebConnect::StaticClass();

	if (ClassInfo1 == ClassInfo2)
	{
		AB_LOG(Warning, TEXT("ClassInfo1 is same with ClassInfo2"));
	}

	//TFieldIterator�� UProperty�� ��ϵ� Property���� ��ȸ��.
	for (TFieldIterator<UProperty> It(ClassInfo2); It; ++It)
	{
		AB_LOG(Warning, TEXT("Field : %s, Type : %s"), *It->GetName(), *It->GetClass()->GetName());

		//���ڿ� ������Ƽ�� ã��.
		UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *It->GetName());
		if (StrProp)
		{
			AB_LOG(Warning, TEXT("Value = %s"), *StrProp->GetPropertyValue_InContainer(WebConnect));
		}
	}
	
	//��ϵ� �Լ� ���̺��� ��ȸ�ϸ� ��� �Լ��� ȣ��.
	for (const auto& Entry : ClassInfo1->NativeFunctionLookupTable)
	{
		AB_LOG(Warning, TEXT("Function = %s"), *Entry.Name.ToString());

		UFunction* Func1 = ClassInfo1->FindFunctionByName(Entry.Name);
		if (Func1->ParmsSize == 0)
		{
			WebConnect->ProcessEvent(Func1, NULL);
		}
	}

	//�̸����� ã�� ȣ��
	UFunction* Func2 = ClassInfo1->FindFunctionByName(FName("RequestToken"));
	WebConnect->ProcessEvent(Func2, NULL);
}
