// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cours01_bis/Private/LasorTrap.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLasorTrap() {}

// Begin Cross Module References
COURS01_BIS_API UClass* Z_Construct_UClass_ALasorTrap();
COURS01_BIS_API UClass* Z_Construct_UClass_ALasorTrap_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Cours01_bis();
// End Cross Module References

// Begin Class ALasorTrap
void ALasorTrap::StaticRegisterNativesALasorTrap()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALasorTrap);
UClass* Z_Construct_UClass_ALasorTrap_NoRegister()
{
	return ALasorTrap::StaticClass();
}
struct Z_Construct_UClass_ALasorTrap_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "LasorTrap.h" },
		{ "ModuleRelativePath", "Private/LasorTrap.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LasorBase_MetaData[] = {
		{ "Category", "LasorTrap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/LasorTrap.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LasorBeam_MetaData[] = {
		{ "Category", "LasorTrap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/LasorTrap.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LasorBase;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LasorBeam;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALasorTrap>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALasorTrap_Statics::NewProp_LasorBase = { "LasorBase", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALasorTrap, LasorBase), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LasorBase_MetaData), NewProp_LasorBase_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALasorTrap_Statics::NewProp_LasorBeam = { "LasorBeam", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ALasorTrap, LasorBeam), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LasorBeam_MetaData), NewProp_LasorBeam_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALasorTrap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALasorTrap_Statics::NewProp_LasorBase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALasorTrap_Statics::NewProp_LasorBeam,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALasorTrap_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ALasorTrap_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Cours01_bis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ALasorTrap_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ALasorTrap_Statics::ClassParams = {
	&ALasorTrap::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ALasorTrap_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ALasorTrap_Statics::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ALasorTrap_Statics::Class_MetaDataParams), Z_Construct_UClass_ALasorTrap_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ALasorTrap()
{
	if (!Z_Registration_Info_UClass_ALasorTrap.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALasorTrap.OuterSingleton, Z_Construct_UClass_ALasorTrap_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ALasorTrap.OuterSingleton;
}
template<> COURS01_BIS_API UClass* StaticClass<ALasorTrap>()
{
	return ALasorTrap::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ALasorTrap);
ALasorTrap::~ALasorTrap() {}
// End Class ALasorTrap

// Begin Registration
struct Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_LasorTrap_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ALasorTrap, ALasorTrap::StaticClass, TEXT("ALasorTrap"), &Z_Registration_Info_UClass_ALasorTrap, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALasorTrap), 968061694U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_LasorTrap_h_3643021920(TEXT("/Script/Cours01_bis"),
	Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_LasorTrap_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_LasorTrap_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
