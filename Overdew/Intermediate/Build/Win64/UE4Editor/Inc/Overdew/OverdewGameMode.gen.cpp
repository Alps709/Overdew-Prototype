// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Overdew/OverdewGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOverdewGameMode() {}
// Cross Module References
	OVERDEW_API UClass* Z_Construct_UClass_AOverdewGameMode_NoRegister();
	OVERDEW_API UClass* Z_Construct_UClass_AOverdewGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Overdew();
// End Cross Module References
	void AOverdewGameMode::StaticRegisterNativesAOverdewGameMode()
	{
	}
	UClass* Z_Construct_UClass_AOverdewGameMode_NoRegister()
	{
		return AOverdewGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AOverdewGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOverdewGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Overdew,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOverdewGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "OverdewGameMode.h" },
		{ "ModuleRelativePath", "OverdewGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOverdewGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOverdewGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AOverdewGameMode_Statics::ClassParams = {
		&AOverdewGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AOverdewGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOverdewGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOverdewGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AOverdewGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AOverdewGameMode, 3615560046);
	template<> OVERDEW_API UClass* StaticClass<AOverdewGameMode>()
	{
		return AOverdewGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AOverdewGameMode(Z_Construct_UClass_AOverdewGameMode, &AOverdewGameMode::StaticClass, TEXT("/Script/Overdew"), TEXT("AOverdewGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOverdewGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
