// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CUBEDUIMOD1.generated.h"

// Forward declaration of UNiagaraSystem to avoid including the entire header
class UNiagaraSystem;

UCLASS()
class BOYLES_GAM_415_API ACUBEDUIMOD1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACUBEDUIMOD1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Components
	UPROPERTY(EditAnywhere)
		UBoxComponent* boxComp; 

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* cubeMesh;


	UPROPERTY(EditAnywhere)
		UMaterialInterface* baseMat;

	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* dmiMat;

	UPROPERTY(EditAnywhere)
		UNiagaraSystem* colorP;


	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool BSweep, const FHitResult& SweepResult); 
};
