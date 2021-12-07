// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RadicalLiveLinkWSS/Private/RadicalLiveLinkSourceFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRadicalLiveLinkSourceFactory() {}
// Cross Module References
	RADICALLIVELINKWSS_API UClass* Z_Construct_UClass_URadicalLiveLinkSourceFactory_NoRegister();
	RADICALLIVELINKWSS_API UClass* Z_Construct_UClass_URadicalLiveLinkSourceFactory();
	LIVELINKINTERFACE_API UClass* Z_Construct_UClass_ULiveLinkSourceFactory();
	UPackage* Z_Construct_UPackage__Script_RadicalLiveLinkWSS();
// End Cross Module References
	void URadicalLiveLinkSourceFactory::StaticRegisterNativesURadicalLiveLinkSourceFactory()
	{
	}
	UClass* Z_Construct_UClass_URadicalLiveLinkSourceFactory_NoRegister()
	{
		return URadicalLiveLinkSourceFactory::StaticClass();
	}
	struct Z_Construct_UClass_URadicalLiveLinkSourceFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URadicalLiveLinkSourceFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULiveLinkSourceFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_RadicalLiveLinkWSS,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URadicalLiveLinkSourceFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RadicalLiveLinkSourceFactory.h" },
		{ "ModuleRelativePath", "Private/RadicalLiveLinkSourceFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URadicalLiveLinkSourceFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URadicalLiveLinkSourceFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URadicalLiveLinkSourceFactory_Statics::ClassParams = {
		&URadicalLiveLinkSourceFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_URadicalLiveLinkSourceFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URadicalLiveLinkSourceFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URadicalLiveLinkSourceFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URadicalLiveLinkSourceFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URadicalLiveLinkSourceFactory, 398678010);
	template<> RADICALLIVELINKWSS_API UClass* StaticClass<URadicalLiveLinkSourceFactory>()
	{
		return URadicalLiveLinkSourceFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URadicalLiveLinkSourceFactory(Z_Construct_UClass_URadicalLiveLinkSourceFactory, &URadicalLiveLinkSourceFactory::StaticClass, TEXT("/Script/RadicalLiveLinkWSS"), TEXT("URadicalLiveLinkSourceFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URadicalLiveLinkSourceFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
