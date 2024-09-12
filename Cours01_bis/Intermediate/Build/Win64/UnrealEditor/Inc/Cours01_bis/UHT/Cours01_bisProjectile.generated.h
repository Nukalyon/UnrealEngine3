// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Cours01_bisProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef COURS01_BIS_Cours01_bisProjectile_generated_h
#error "Cours01_bisProjectile.generated.h already included, missing '#pragma once' in Cours01_bisProjectile.h"
#endif
#define COURS01_BIS_Cours01_bisProjectile_generated_h

#define FID_Cours01_bis_Source_Cours01_bis_Cours01_bisProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_Cours01_bis_Source_Cours01_bis_Cours01_bisProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACours01_bisProjectile(); \
	friend struct Z_Construct_UClass_ACours01_bisProjectile_Statics; \
public: \
	DECLARE_CLASS(ACours01_bisProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Cours01_bis"), NO_API) \
	DECLARE_SERIALIZER(ACours01_bisProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Cours01_bis_Source_Cours01_bis_Cours01_bisProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACours01_bisProjectile(ACours01_bisProjectile&&); \
	ACours01_bisProjectile(const ACours01_bisProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACours01_bisProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACours01_bisProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACours01_bisProjectile) \
	NO_API virtual ~ACours01_bisProjectile();


#define FID_Cours01_bis_Source_Cours01_bis_Cours01_bisProjectile_h_12_PROLOG
#define FID_Cours01_bis_Source_Cours01_bis_Cours01_bisProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Cours01_bis_Source_Cours01_bis_Cours01_bisProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Cours01_bis_Source_Cours01_bis_Cours01_bisProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_Cours01_bis_Source_Cours01_bis_Cours01_bisProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COURS01_BIS_API UClass* StaticClass<class ACours01_bisProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Cours01_bis_Source_Cours01_bis_Cours01_bisProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
