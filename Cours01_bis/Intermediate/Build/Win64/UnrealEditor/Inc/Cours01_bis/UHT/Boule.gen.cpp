// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cours01_bis/Private/Boule.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoule() {}

// Begin Cross Module References
COURS01_BIS_API UClass* Z_Construct_UClass_ABoule();
COURS01_BIS_API UClass* Z_Construct_UClass_ABoule_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Cours01_bis();
// End Cross Module References

// Begin Class ABoule
void ABoule::StaticRegisterNativesABoule()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoule);
UClass* Z_Construct_UClass_ABoule_NoRegister()
{
	return ABoule::StaticClass();
}
struct Z_Construct_UClass_ABoule_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Boule.h" },
		{ "ModuleRelativePath", "Private/Boule.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoule>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABoule_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Cours01_bis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoule_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoule_Statics::ClassParams = {
	&ABoule::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoule_Statics::Class_MetaDataParams), Z_Construct_UClass_ABoule_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABoule()
{
	if (!Z_Registration_Info_UClass_ABoule.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoule.OuterSingleton, Z_Construct_UClass_ABoule_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABoule.OuterSingleton;
}
template<> COURS01_BIS_API UClass* StaticClass<ABoule>()
{
	return ABoule::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABoule);
ABoule::~ABoule() {}
// End Class ABoule

// Begin Registration
struct Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_Boule_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABoule, ABoule::StaticClass, TEXT("ABoule"), &Z_Registration_Info_UClass_ABoule, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoule), 4277393191U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_Boule_h_815210251(TEXT("/Script/Cours01_bis"),
	Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_Boule_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_Boule_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
