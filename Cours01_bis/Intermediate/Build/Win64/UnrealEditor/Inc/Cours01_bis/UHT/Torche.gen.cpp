// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cours01_bis/Private/Torche.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTorche() {}

// Begin Cross Module References
COURS01_BIS_API UClass* Z_Construct_UClass_ATorche();
COURS01_BIS_API UClass* Z_Construct_UClass_ATorche_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Cours01_bis();
// End Cross Module References

// Begin Class ATorche
void ATorche::StaticRegisterNativesATorche()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATorche);
UClass* Z_Construct_UClass_ATorche_NoRegister()
{
	return ATorche::StaticClass();
}
struct Z_Construct_UClass_ATorche_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Torche.h" },
		{ "ModuleRelativePath", "Private/Torche.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATorche>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATorche_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Cours01_bis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATorche_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATorche_Statics::ClassParams = {
	&ATorche::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATorche_Statics::Class_MetaDataParams), Z_Construct_UClass_ATorche_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATorche()
{
	if (!Z_Registration_Info_UClass_ATorche.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATorche.OuterSingleton, Z_Construct_UClass_ATorche_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATorche.OuterSingleton;
}
template<> COURS01_BIS_API UClass* StaticClass<ATorche>()
{
	return ATorche::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATorche);
ATorche::~ATorche() {}
// End Class ATorche

// Begin Registration
struct Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_Torche_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATorche, ATorche::StaticClass, TEXT("ATorche"), &Z_Registration_Info_UClass_ATorche, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATorche), 1701196316U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_Torche_h_4094054060(TEXT("/Script/Cours01_bis"),
	Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_Torche_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_Torche_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
