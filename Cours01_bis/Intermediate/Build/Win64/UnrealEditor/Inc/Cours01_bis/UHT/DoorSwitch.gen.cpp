// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cours01_bis/Private/DoorSwitch.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDoorSwitch() {}

// Begin Cross Module References
COURS01_BIS_API UClass* Z_Construct_UClass_ADoorSwitch();
COURS01_BIS_API UClass* Z_Construct_UClass_ADoorSwitch_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Cours01_bis();
// End Cross Module References

// Begin Class ADoorSwitch
void ADoorSwitch::StaticRegisterNativesADoorSwitch()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADoorSwitch);
UClass* Z_Construct_UClass_ADoorSwitch_NoRegister()
{
	return ADoorSwitch::StaticClass();
}
struct Z_Construct_UClass_ADoorSwitch_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DoorSwitch.h" },
		{ "ModuleRelativePath", "Private/DoorSwitch.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADoorSwitch>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ADoorSwitch_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Cours01_bis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADoorSwitch_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADoorSwitch_Statics::ClassParams = {
	&ADoorSwitch::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADoorSwitch_Statics::Class_MetaDataParams), Z_Construct_UClass_ADoorSwitch_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADoorSwitch()
{
	if (!Z_Registration_Info_UClass_ADoorSwitch.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADoorSwitch.OuterSingleton, Z_Construct_UClass_ADoorSwitch_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADoorSwitch.OuterSingleton;
}
template<> COURS01_BIS_API UClass* StaticClass<ADoorSwitch>()
{
	return ADoorSwitch::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADoorSwitch);
ADoorSwitch::~ADoorSwitch() {}
// End Class ADoorSwitch

// Begin Registration
struct Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_DoorSwitch_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADoorSwitch, ADoorSwitch::StaticClass, TEXT("ADoorSwitch"), &Z_Registration_Info_UClass_ADoorSwitch, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADoorSwitch), 2551899758U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_DoorSwitch_h_1861605302(TEXT("/Script/Cours01_bis"),
	Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_DoorSwitch_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_DoorSwitch_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
