// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealLiveLinkRemapPlugin/Public/RadicalLiveLinkRemapAssetBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRadicalLiveLinkRemapAssetBase() {}
// Cross Module References
	UNREALLIVELINKREMAPPLUGIN_API UClass* Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_NoRegister();
	UNREALLIVELINKREMAPPLUGIN_API UClass* Z_Construct_UClass_URadicalLiveLinkRemapAssetBase();
	LIVELINK_API UClass* Z_Construct_UClass_ULiveLinkRemapAsset();
	UPackage* Z_Construct_UPackage__Script_UnrealLiveLinkRemapPlugin();
// End Cross Module References
	void URadicalLiveLinkRemapAssetBase::StaticRegisterNativesURadicalLiveLinkRemapAssetBase()
	{
	}
	UClass* Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_NoRegister()
	{
		return URadicalLiveLinkRemapAssetBase::StaticClass();
	}
	struct Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULiveLinkRemapAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealLiveLinkRemapPlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "RadicalLiveLinkRemapAssetBase.h" },
		{ "ModuleRelativePath", "Public/RadicalLiveLinkRemapAssetBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URadicalLiveLinkRemapAssetBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_Statics::ClassParams = {
		&URadicalLiveLinkRemapAssetBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URadicalLiveLinkRemapAssetBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URadicalLiveLinkRemapAssetBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URadicalLiveLinkRemapAssetBase, 1489090372);
	template<> UNREALLIVELINKREMAPPLUGIN_API UClass* StaticClass<URadicalLiveLinkRemapAssetBase>()
	{
		return URadicalLiveLinkRemapAssetBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URadicalLiveLinkRemapAssetBase(Z_Construct_UClass_URadicalLiveLinkRemapAssetBase, &URadicalLiveLinkRemapAssetBase::StaticClass, TEXT("/Script/UnrealLiveLinkRemapPlugin"), TEXT("URadicalLiveLinkRemapAssetBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URadicalLiveLinkRemapAssetBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
