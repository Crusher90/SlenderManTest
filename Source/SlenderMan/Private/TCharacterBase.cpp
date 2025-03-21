// Copyright Rahul Vallecha.


#include "TCharacterBase.h"

// Sets default values
ATCharacterBase::ATCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}