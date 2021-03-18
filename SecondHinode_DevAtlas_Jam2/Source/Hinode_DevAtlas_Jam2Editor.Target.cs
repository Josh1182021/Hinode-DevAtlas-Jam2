// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Hinode_DevAtlas_Jam2EditorTarget : TargetRules
{
	public Hinode_DevAtlas_Jam2EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("Hinode_DevAtlas_Jam2");
	}
}
