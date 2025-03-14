// Copyright Rahul Vallecha.


#include "TEnemy.h"

#include "Components/CapsuleComponent.h"
#include "Interface/TPlayerInterface.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ATEnemy::ATEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ATEnemy::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnCapsuleOverlap);
}

// Called every frame
void ATEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATEnemy::OnCapsuleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->Implements<UTPlayerInterface>())
	{
		UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, GetController(), this, UDamageType::StaticClass());
	}
}
