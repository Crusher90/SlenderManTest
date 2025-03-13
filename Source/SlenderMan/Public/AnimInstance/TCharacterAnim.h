// Copyright Rahul Vallecha.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TCharacterAnim.generated.h"

/**
 * 
 */
UCLASS()
class SLENDERMAN_API UTCharacterAnim : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fields", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ACharacter> MyCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fields", meta = (AllowPrivateAccess = "true"))
	double Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fields", meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fields", meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating;
};
