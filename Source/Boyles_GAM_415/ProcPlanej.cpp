// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcPlanej.h"
#include "ProceduralMeshComponent.h"

// Sets default values
AProcPlanej::AProcPlanej()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	procMesh = CreateDefaultSubobject<UProceduralMeshComponent>("Proc Mesh"); 
	
}

// Called when the game starts or when spawned
void AProcPlanej::BeginPlay()
{
	Super::BeginPlay();


	
}

//Declaration for AProcPlanej::PostActorCreated()

void AProcPlanej::PostActorCreated()
{
	Super::PostActorCreated();

	// if statement for PlaneMat UProperty, with the procMesh Material is set to O ,and PlaneMat property  

	CreateMesh(); 
	if (PlaneMat)
	{
		procMesh->SetMaterial(0, PlaneMat);
	}
}

//Declaration for AProcPlanej:: PostLoad()
void AProcPlanej::PostLoad()
{
	Super::PostLoad();

	// if statement for PlaneMat UProperty, with the procMesh Material is set to O ,and PlaneMat property  

	CreateMesh();
	if (PlaneMat)
	{
		procMesh->SetMaterial(0, PlaneMat);
	}
}

// Called every frame
void AProcPlanej::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Declaration for AProcPlanej::CreateMeshs()

void AProcPlanej::CreateMesh()
{
	// This will create a Mesh Section for the following Meshes

	procMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), UV0, TArray<FColor>(), TArray<FProcMeshTangent>(), true);

}



