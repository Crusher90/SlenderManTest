// Copyright Rahul Vallecha.


#include "TEnemy.h"


// Sets default values
ATEnemy::ATEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
