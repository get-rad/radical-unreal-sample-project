// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RadicaWSSSample : ModuleRules
{
	public RadicaWSSSample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
		PrivateIncludePathModuleNames.AddRange(new string[] { "RadicalWSSClient" });

	}
}
