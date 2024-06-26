// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FPS_BaptisteCOUTU : ModuleRules
{
	public FPS_BaptisteCOUTU(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
