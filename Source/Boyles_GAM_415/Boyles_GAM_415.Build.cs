// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Boyles_GAM_415 : ModuleRules
{
	public Boyles_GAM_415(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","Niagara", "ProceduralMeshComponent"});
	}
}
