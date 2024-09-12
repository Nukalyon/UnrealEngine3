// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cours01_bis/Private/PuzzleManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePuzzleManager() {}

// Begin Cross Module References
COURS01_BIS_API UClass* Z_Construct_UClass_APuzzleManager();
COURS01_BIS_API UClass* Z_Construct_UClass_APuzzleManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Cours01_bis();
// End Cross Module References

// Begin Class APuzzleManager
void APuzzleManager::StaticRegisterNativesAPuzzleManager()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APuzzleManager);
UClass* Z_Construct_UClass_APuzzleManager_NoRegister()
{
	return APuzzleManager::StaticClass();
}
struct Z_Construct_UClass_APuzzleManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PuzzleManager.h" },
		{ "ModuleRelativePath", "Private/PuzzleManager.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APuzzleManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APuzzleManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Cours01_bis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APuzzleManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APuzzleManager_Statics::ClassParams = {
	&APuzzleManager::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APuzzleManager_Statics::Class_MetaDataParams), Z_Construct_UClass_APuzzleManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APuzzleManager()
{
	if (!Z_Registration_Info_UClass_APuzzleManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APuzzleManager.OuterSingleton, Z_Construct_UClass_APuzzleManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APuzzleManager.OuterSingleton;
}
template<> COURS01_BIS_API UClass* StaticClass<APuzzleManager>()
{
	return APuzzleManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APuzzleManager);
APuzzleManager::~APuzzleManager() {}
// End Class APuzzleManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_PuzzleManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APuzzleManager, APuzzleManager::StaticClass, TEXT("APuzzleManager"), &Z_Registration_Info_UClass_APuzzleManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APuzzleManager), 4185441702U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_PuzzleManager_h_1904891695(TEXT("/Script/Cours01_bis"),
	Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_PuzzleManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_PuzzleManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
