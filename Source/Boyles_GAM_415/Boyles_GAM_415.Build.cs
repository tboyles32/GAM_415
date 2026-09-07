// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Boyles_GAM_415 : ModuleRules
{
	public Boyles_GAM_415(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Boyles_GAM_415",
			"Boyles_GAM_415/Variant_Horror",
			"Boyles_GAM_415/Variant_Horror/UI",
			"Boyles_GAM_415/Variant_Shooter",
			"Boyles_GAM_415/Variant_Shooter/AI",
			"Boyles_GAM_415/Variant_Shooter/UI",
			"Boyles_GAM_415/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
