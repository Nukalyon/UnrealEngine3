// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MayanTemple : ModuleRules
{
	public MayanTemple(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//https://dev.epicgames.com/community/learning/tutorials/Gx5j/using-niagara-in-c
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara" });
	}
}
