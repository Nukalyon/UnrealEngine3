// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Cours01_bis/Private/JumpPad.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJumpPad() {}

// Begin Cross Module References
COURS01_BIS_API UClass* Z_Construct_UClass_AJumpPad();
COURS01_BIS_API UClass* Z_Construct_UClass_AJumpPad_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Cours01_bis();
// End Cross Module References

// Begin Class AJumpPad
void AJumpPad::StaticRegisterNativesAJumpPad()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AJumpPad);
UClass* Z_Construct_UClass_AJumpPad_NoRegister()
{
	return AJumpPad::StaticClass();
}
struct Z_Construct_UClass_AJumpPad_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "JumpPad.h" },
		{ "ModuleRelativePath", "Private/JumpPad.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJumpPad>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AJumpPad_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Cours01_bis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJumpPad_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJumpPad_Statics::ClassParams = {
	&AJumpPad::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJumpPad_Statics::Class_MetaDataParams), Z_Construct_UClass_AJumpPad_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AJumpPad()
{
	if (!Z_Registration_Info_UClass_AJumpPad.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJumpPad.OuterSingleton, Z_Construct_UClass_AJumpPad_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJumpPad.OuterSingleton;
}
template<> COURS01_BIS_API UClass* StaticClass<AJumpPad>()
{
	return AJumpPad::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AJumpPad);
AJumpPad::~AJumpPad() {}
// End Class AJumpPad

// Begin Registration
struct Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_JumpPad_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJumpPad, AJumpPad::StaticClass, TEXT("AJumpPad"), &Z_Registration_Info_UClass_AJumpPad, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJumpPad), 1475316878U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_JumpPad_h_3077093626(TEXT("/Script/Cours01_bis"),
	Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_JumpPad_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Cours01_bis_Source_Cours01_bis_Private_JumpPad_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
