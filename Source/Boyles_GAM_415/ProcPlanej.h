// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProcPlanej.generated.h"

class UProceduralMeshComponent; 

UCLASS()
class BOYLES_GAM_415_API AProcPlanej : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcPlanej();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// this two virtual void will call the Createmesh function before loading or play the game 

	virtual void PostActorCreated() override; 

	virtual void PostLoad() override; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Array of Vertices 

	UPROPERTY(EditAnyWhere)
		TArray<FVector> Vertices; 

	// Array integers of Triangles 

	UPROPERTY(EditAnyWhere)
		TArray<int> Triangles;

	// Material Interface for the PlaneMat UPROPERTY

	UPROPERTY(EditAnyWhere)
		UMaterialInterface* PlaneMat; 

	// Array of FVector for UV0 UPROPERTY

	UPROPERTY(EditAnyWhere)
		TArray<FVector2D> UV0;

	//Function for CreateMesh Delcaration 

	UFUNCTION()
		void CreateMesh(); 

private: 
	UProceduralMeshComponent* procMesh; 
	UProceduralMeshComponent* baseMesh; 

};
