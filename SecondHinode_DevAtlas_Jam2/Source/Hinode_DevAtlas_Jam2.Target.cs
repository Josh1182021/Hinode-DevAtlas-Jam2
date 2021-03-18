// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Hinode_DevAtlas_Jam2Target : TargetRules
{
	public Hinode_DevAtlas_Jam2Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("Hinode_DevAtlas_Jam2");
	}
}
