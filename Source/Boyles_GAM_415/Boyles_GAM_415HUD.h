// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Boyles_GAM_415HUD.generated.h"

UCLASS()
class ABoyles_GAM_415HUD : public AHUD
{
	GENERATED_BODY()

public:
	ABoyles_GAM_415HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

