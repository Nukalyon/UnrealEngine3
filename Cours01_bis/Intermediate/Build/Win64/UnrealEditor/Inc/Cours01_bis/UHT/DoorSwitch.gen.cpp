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
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_doorToOpen_MetaData[] = {
		{ "Category", "DoorSwitch" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//* = pointeur\n" },
#endif
		{ "ModuleRelativePath", "Private/DoorSwitch.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "/ = pointeur" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_doorToOpen;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADoorSwitch>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADoorSwitch_Statics::NewProp_doorToOpen = { "doorToOpen", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADoorSwitch, doorToOpen), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_doorToOpen_MetaData), NewProp_doorToOpen_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADoorSwitch_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADoorSwitch_Statics::NewProp_doorToOpen,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADoorSwitch_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_ADoorSwitch_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ADoorSwitch_Statics::PropPointers),
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
		{ Z_Construct_UClass_ADoorSwitch, ADoorSwitch::StaticClass, TEXT("ADoorSwitch"), &Z_Registration_Info_UClass_ADoorSwitch, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADoorSwitch), 2881301916U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_DoorSwitch_h_2547557233(TEXT("/Script/Cours01_bis"),
	Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_DoorSwitch_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_DoorSwitch_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
