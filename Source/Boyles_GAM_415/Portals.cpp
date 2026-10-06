// Fill out your copyright notice in the Description page of Project Settings.


#include "Portals.h"
#include "Boyles_GAM_415Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
class APortals; 
APortals::APortals()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// setup the Mesh 
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh"); 

	// setup the Box Component 
	boxComp = CreateDefaultSubobject<UBoxComponent>("Box Comp"); 

	// setup the Scene Capture and the Attachment and the capture is attached to the mesh
	sceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>("Capture"); 

	rootArrow = CreateDefaultSubobject<UArrowComponent>("Root Arrow"); // Create Default for Root Arrow 

	RootComponent = boxComp; // Spawn Component  
	mesh->SetupAttachment(boxComp); // mesh wil be attached to the box Component 
	sceneCapture->SetupAttachment(mesh); //Setup the Attachment for the scene capture 
	rootArrow->SetupAttachment(RootComponent); // Get Spawn for the root component 

	// this will disable the collision to the mesh 
	mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
}

// Called when the game starts or when spawned
void APortals::BeginPlay()
{
	Super::BeginPlay();

	// make sure that the AddDynamic is assign to the void class 
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &APortals::OnOverlapBegin);
	mesh->SetHiddenInSceneCapture(true); 

	// this will disable shadows in the mesh, the b is a boolean 
	//mesh->bCastStaticShadow(false);
	//mesh->bCastDynamicShadow(false);


	if (Mat)
	{

		// set mesh materials to 0 and verify that material is valid 
		mesh->SetMaterial(0, Mat); 
	}
}

// Called every frame
void APortals::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdatePortals(); // Upadating the Scene Capture Component location in the World 
}

void APortals::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABoyles_GAM_415Character* playerChar = Cast<ABoyles_GAM_415Character>(OtherActor);

	if (playerChar) //Asking if your player Character is valid 
	{
		if (OtherPortal) // Checking if the OtherPortal Character is Valid
		{
			if (!playerChar->isteleporting) // Checking if isteleporting is false 
			{
				playerChar->isteleporting = true; //set playerChar is true, if the bool is false 
				FVector loc = OtherPortal->rootArrow->GetComponentLocation(); //Where ever my root arrow is located, the character will teleport at
				playerChar->SetActorLocation(loc); // infinite loop that will crash the engine, so we're setting the character's location 

				FTimerHandle TimerHandle; 
				FTimerDelegate TimerDelegate; 
				TimerDelegate.BindUFunction(this, "SetBool", playerChar);
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 1, false);// this a timer set for l second then false, if its true it will loop 
			}
		}
	}
}

void APortals::SetBool(ABoyles_GAM_415Character* playerChar)
{
	if (playerChar)
	{
		playerChar->isteleporting = false; // this will allow you to teleport again S
	}
}

void APortals::UpdatePortals()
{
	

	FVector Location = this->GetActorLocation() - OtherPortal->GetActorLocation(); //It's gonna get the difference from the ActorPortal and the ActorLocation
	FVector camLocation = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetTransformComponent()->GetComponentLocation(); // 0 is the Players Index, add #include "Kismet/GameplayStatics.h" to use the camera 
	FRotator CameraLocation = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetTransformComponent()->GetComponentRotation(); // Allow the camera to rotate or O in 
	FVector CombinedLocation = camLocation + Location; // Adding the camlocation to the Location 

	sceneCapture->SetWorldLocationAndRotation(CombinedLocation, CameraLocation);


}

