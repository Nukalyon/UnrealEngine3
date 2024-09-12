// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cours01_bis/Cours01_bisGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCours01_bisGameMode() {}

// Begin Cross Module References
COURS01_BIS_API UClass* Z_Construct_UClass_ACours01_bisGameMode();
COURS01_BIS_API UClass* Z_Construct_UClass_ACours01_bisGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Cours01_bis();
// End Cross Module References

// Begin Class ACours01_bisGameMode
void ACours01_bisGameMode::StaticRegisterNativesACours01_bisGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACours01_bisGameMode);
UClass* Z_Construct_UClass_ACours01_bisGameMode_NoRegister()
{
	return ACours01_bisGameMode::StaticClass();
}
struct Z_Construct_UClass_ACours01_bisGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Cours01_bisGameMode.h" },
		{ "ModuleRelativePath", "Cours01_bisGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACours01_bisGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACours01_bisGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Cours01_bis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACours01_bisGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACours01_bisGameMode_Statics::ClassParams = {
	&ACours01_bisGameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACours01_bisGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACours01_bisGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACours01_bisGameMode()
{
	if (!Z_Registration_Info_UClass_ACours01_bisGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACours01_bisGameMode.OuterSingleton, Z_Construct_UClass_ACours01_bisGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACours01_bisGameMode.OuterSingleton;
}
template<> COURS01_BIS_API UClass* StaticClass<ACours01_bisGameMode>()
{
	return ACours01_bisGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACours01_bisGameMode);
ACours01_bisGameMode::~ACours01_bisGameMode() {}
// End Class ACours01_bisGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Cours01_bisGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACours01_bisGameMode, ACours01_bisGameMode::StaticClass, TEXT("ACours01_bisGameMode"), &Z_Registration_Info_UClass_ACours01_bisGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACours01_bisGameMode), 2829301005U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Cours01_bisGameMode_h_2991892116(TEXT("/Script/Cours01_bis"),
	Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Cours01_bisGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Cours01_bisGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
