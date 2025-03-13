// Copyright Rahul Vallecha.

#pragma once

#include "CoreMinimal.h"
#include "TCharacterBase.h"
#include "TPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class SLENDERMAN_API ATPlayer : public ATCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
};