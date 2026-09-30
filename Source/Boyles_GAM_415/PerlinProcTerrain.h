// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerlinProcTerrain.generated.h"


class UProceduralMeshComponent;
class UMaterialInterace; 

UCLASS()
class BOYLES_GAM_415_API APerlinProcTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerlinProcTerrain();

	UPROPERTY(EditAnywhere, Meta = (Clampmin = 0))
		int XSize = 0; 


	UPROPERTY(EditAnywhere, Meta = (Clampmin = 0))
		int YSize = 0;
 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (Clampmin = 0))
		float Zmuiltplier = 1.0f; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (Clampmin = 0))
		float NoiseScale = 1.0f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (Clampmin = 0))
		float Scale = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (Clampmin = 0))
		float UVScale = 0;


	UPROPERTY(EditAnywhere)
		float radius;

	UPROPERTY(EditAnywhere)
		float Depth;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* Mat; 


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	UFUNCTION(BlueprintCallable)
		void AlterMesh(FVector impactPoint);

private: 
	UProceduralMeshComponent* ProcMesh; 
	TArray<FVector> Vertices; 
	TArray<int> Triangles;
	TArray<FVector2D> UV0;
	TArray<FVector> Normals;
	TArray<FColor> UpVertexColors; 

	int sectionID = 0; 

	void CreateVertices(); 
	void CreateTriangles(); 



};
