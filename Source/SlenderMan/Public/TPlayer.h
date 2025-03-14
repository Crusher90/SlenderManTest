// Copyright Rahul Vallecha.

#pragma once

#include "CoreMinimal.h"
#include "TCharacterBase.h"
#include "Interface/TPlayerInterface.h"
#include "TPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class SLENDERMAN_API ATPlayer : public ATCharacterBase, public ITPlayerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPlayer();
	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	                         class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintImplementableEvent, Category="Player Field")
	void Death();

	UFUNCTION(BlueprintImplementableEvent, Category="Player Field")
	void SetHUDHealth();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Attributes", meta = (AllowPrivateAccess = "true"))
	float Health = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes", meta = (AllowPrivateAccess = "true"))
	float MaxHealth = 100.0f;
};