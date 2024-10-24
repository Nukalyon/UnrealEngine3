// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShortTitle : ModuleRules
{
	public ShortTitle(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "Niagara", "Niagara" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara"});
	}
}
