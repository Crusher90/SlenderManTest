// Copyright Rahul Vallecha.


#include "AI/TAIController.h"


// Sets default values
ATAIController::ATAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

