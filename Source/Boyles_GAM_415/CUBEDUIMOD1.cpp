// Fill out your copyright notice in the Description page of Project Settings.


#include "CUBEDUIMOD1.h"
#include "Boyles_GAM_415/Boyles_GAM_415Character.h"
#include "Boyles_GAM_415Projectile.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h" 
#include "NiagaraComponent.h"


// Sets default values
ACUBEDUIMOD1::ACUBEDUIMOD1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Box Component and Static Mesh Component
	boxComp = CreateDefaultSubobject<UBoxComponent>("Box Component");
	// Set the Box Component as the Root Component
	cubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("Cube Mesh");

	RootComponent = boxComp; 
	cubeMesh->SetupAttachment(boxComp);
}

// Called when the game starts or when spawned
void ACUBEDUIMOD1::BeginPlay()
{
	Super::BeginPlay();
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ACUBEDUIMOD1::OnOverlapBegin); 

	if (baseMat)
	{
		dmiMat = UMaterialInstanceDynamic::Create(baseMat, this);
	}

	if (cubeMesh)
	{
		cubeMesh-> SetMaterial(0, dmiMat);
	}
}

// Called every frame
void ACUBEDUIMOD1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACUBEDUIMOD1::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool BSweep,const FHitResult& SweepResult)
{
	ABoyles_GAM_415Character* overlappedActor = Cast<ABoyles_GAM_415Character>(OtherActor);
	// Check if the overlapped actor is valid and is of the expected type
	if (OtherActor)
	{
		float ranNumX = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
		float ranNumY = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
		float ranNumZ = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);

		// Create a random color vector using the random numbers
		FVector4 randColor = FVector4(ranNumX, ranNumY, ranNumZ);
			if (dmiMat)
			{
				dmiMat->SetVectorParameterValue("Color", FLinearColor( randColor)); 
				dmiMat->SetScalarParameterValue ("Darkness", ranNumX);

				if (colorP)
				{
					// Spawn the Niagara particle system at the location of the OtherComp
					UNiagaraComponent* particleComp = UNiagaraFunctionLibrary::SpawnSystemAttached(colorP, OtherComp, NAME_None, FVector(0.f), FRotator(0.f), EAttachLocation::KeepRelativeOffset, true);

					particleComp->SetNiagaraVariableLinearColor(FString("RandColor"),FLinearColor (randColor));			
				}

			}


	}

}

