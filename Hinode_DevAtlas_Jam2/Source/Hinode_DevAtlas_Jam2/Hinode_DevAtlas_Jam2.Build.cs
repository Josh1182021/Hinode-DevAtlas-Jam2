// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Hinode_DevAtlas_Jam2 : ModuleRules
{
	public Hinode_DevAtlas_Jam2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "UMG" });
    }
}
