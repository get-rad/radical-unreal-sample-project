// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealLiveLinkRemapPlugin/Public/RadToRadRemapAsset.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRadToRadRemapAsset() {}
// Cross Module References
	UNREALLIVELINKREMAPPLUGIN_API UClass* Z_Construct_UClass_URadToRadRemapAsset_NoRegister();
	UNREALLIVELINKREMAPPLUGIN_API UClass* Z_Construct_UClass_URadToRadRemapAsset();
	UNREALLIVELINKREMAPPLUGIN_API UClass* Z_Construct_UClass_URadicalLiveLinkRemapAssetBase();
	UPackage* Z_Construct_UPackage__Script_UnrealLiveLinkRemapPlugin();
// End Cross Module References
	void URadToRadRemapAsset::StaticRegisterNativesURadToRadRemapAsset()
	{
	}
	UClass* Z_Construct_UClass_URadToRadRemapAsset_NoRegister()
	{
		return URadToRadRemapAsset::StaticClass();
	}
	struct Z_Construct_UClass_URadToRadRemapAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URadToRadRemapAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_URadicalLiveLinkRemapAssetBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealLiveLinkRemapPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URadToRadRemapAsset_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "RadToRadRemapAsset.h" },
		{ "ModuleRelativePath", "Public/RadToRadRemapAsset.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URadToRadRemapAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URadToRadRemapAsset>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URadToRadRemapAsset_Statics::ClassParams = {
		&URadToRadRemapAsset::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_URadToRadRemapAsset_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URadToRadRemapAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URadToRadRemapAsset()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URadToRadRemapAsset_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URadToRadRemapAsset, 2707558750);
	template<> UNREALLIVELINKREMAPPLUGIN_API UClass* StaticClass<URadToRadRemapAsset>()
	{
		return URadToRadRemapAsset::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URadToRadRemapAsset(Z_Construct_UClass_URadToRadRemapAsset, &URadToRadRemapAsset::StaticClass, TEXT("/Script/UnrealLiveLinkRemapPlugin"), TEXT("URadToRadRemapAsset"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URadToRadRemapAsset);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
