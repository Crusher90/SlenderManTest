// Copyright Rahul Vallecha.

#pragma once

#include "CoreMinimal.h"
#include "TCharacterBase.h"
#include "TEnemy.generated.h"

UCLASS()
class SLENDERMAN_API ATEnemy : public ATCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATEnemy();

protected:
	UFUNCTION()
	virtual void OnCapsuleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Enemy Fields")
	float DamageAmount = 20.f;
};
