// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCours01_bis_init() {}
	COURS01_BIS_API UFunction* Z_Construct_UDelegateFunction_Cours01_bis_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Cours01_bis;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Cours01_bis()
	{
		if (!Z_Registration_Info_UPackage__Script_Cours01_bis.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Cours01_bis_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Cours01_bis",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x733AFBDB,
				0xA1827E16,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Cours01_bis.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Cours01_bis.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Cours01_bis(Z_Construct_UPackage__Script_Cours01_bis, TEXT("/Script/Cours01_bis"), Z_Registration_Info_UPackage__Script_Cours01_bis, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x733AFBDB, 0xA1827E16));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
