// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABGameInstance.h"

UABGameInstance::UABGameInstance()
{
	AB_LOG(Warning, TEXT("ABGameInstance Constructor!"));

	//매개변수에 들어가는 TEXT는 서브오브젝트를 관리하기위한 내부 해쉬값.
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

	//TFieldIterator가 UProperty로 등록된 Property들을 순회함.
	for (TFieldIterator<UProperty> It(ClassInfo2); It; ++It)
	{
		AB_LOG(Warning, TEXT("Field : %s, Type : %s"), *It->GetName(), *It->GetClass()->GetName());

		//문자열 프로퍼티를 찾음.
		UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *It->GetName());
		if (StrProp)
		{
			AB_LOG(Warning, TEXT("Value = %s"), *StrProp->GetPropertyValue_InContainer(WebConnect));
		}
	}
	
	//등록된 함수 테이블을 순회하며 모든 함수를 호출.
	for (const auto& Entry : ClassInfo1->NativeFunctionLookupTable)
	{
		AB_LOG(Warning, TEXT("Function = %s"), *Entry.Name.ToString());

		UFunction* Func1 = ClassInfo1->FindFunctionByName(Entry.Name);
		if (Func1->ParmsSize == 0)
		{
			WebConnect->ProcessEvent(Func1, NULL);
		}
	}

	//이름으로 찾아 호출
	UFunction* Func2 = ClassInfo1->FindFunctionByName(FName("RequestToken"));
	WebConnect->ProcessEvent(Func2, NULL);
}
