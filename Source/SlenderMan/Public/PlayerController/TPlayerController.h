// Copyright Rahul Vallecha.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "TPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class SLENDERMAN_API ATPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// Begin play
	virtual void BeginPlay() override;

	// setup input for player
	virtual void SetupInputComponent() override;

private:
	// input mapping for enhanced input
	UPROPERTY(EditDefaultsOnly, Category="Inputs")
	TObjectPtr<UInputMappingContext> InputMapping;
	
	// player move input
	UPROPERTY(EditDefaultsOnly, Category="Inputs")
	TObjectPtr<UInputAction> MoveAction;

	// player look input
	UPROPERTY(EditDefaultsOnly, Category="Inputs")
	TObjectPtr<UInputAction> LookAction;

	// player jump input
	UPROPERTY(EditDefaultsOnly, Category="Inputs")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category="Inputs")
	float GameSensitivity = 45.f;

private:
	// Logic that actually moves the player
	void Move(const FInputActionValue& Value);

	// Logic that actually moves the camera
	void Look(const FInputActionValue& Value);

	// Logic that actually jumps the player
	void Jump();
};