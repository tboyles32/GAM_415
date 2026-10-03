// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/BoxComponent.h"
#include "Portals.generated.h"

/*Allows you access the Player Character, and local variables to transfer "Set Player Character to another function"*/

class Boyles_GAM_415Character; // Accesss the player character
class APortal; 
UCLASS()
class BOYLES_GAM_415_API APortals : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortals();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// static component for the mesh 
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;

	// Setup for the sceneCapture 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneCaptureComponent2D* sceneCapture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextureRenderTarget2D* renderTarget;

	UPROPERTY(EditAnywhere) // its for teleport
		UBoxComponent* boxComp;


	// So the Teleportation is work properly 
	UPROPERTY(EditAnywhere)
		APortal* OtherPortal;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* Mat;


	// It overlooks the boxComp compnent, and adding up, we're able to call our teleport
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void SetBool(ABoyles_GAM_415Character* playerChar); 

	UFUNCTION()
		void UpdatePortals(); 
};
