// Copyright Rahul Vallecha.


#include "AnimInstance/TCharacterAnim.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UTCharacterAnim::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	MyCharacter = Cast<ACharacter>(TryGetPawnOwner());
}

void UTCharacterAnim::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if(MyCharacter == nullptr)
		return;
	FVector Velocity = MyCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = MyCharacter->GetCharacterMovement()->IsFalling();
	bIsAccelerating = MyCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
}
