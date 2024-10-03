// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Cours01_bis : ModuleRules
{
	public Cours01_bis(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara" });
	}
}
