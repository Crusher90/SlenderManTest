// Copyright Rahul Vallecha.


#include "PlayerController/TPlayerController.h"

#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"

void ATPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(InputMapping, 0);
	}
}

void ATPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(InputComponent))
	{
		InputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
		InputComp->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
		InputComp->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::Jump);
		InputComp->BindAction(SprintAction, ETriggerEvent::Triggered, this, &ThisClass::StartSprint);
		InputComp->BindAction(SprintAction, ETriggerEvent::Completed, this, &ThisClass::StopSprint);
	}
}

void ATPlayerController::Move(const FInputActionValue& Value)
{
	check(MoveAction);
	const FVector2D MoveVector = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation = FRotator(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	check(GetCharacter());
	GetCharacter()->AddMovementInput(ForwardDirection, MoveVector.X);
	GetCharacter()->AddMovementInput(RightDirection, MoveVector.Y);
}

void ATPlayerController::Look(const FInputActionValue& Value)
{
	check(LookAction);
	check(GetCharacter());
	const FVector2D LookVector = Value.Get<FVector2D>();
	GetCharacter()->AddControllerYawInput(LookVector.X * GetWorld()->GetDeltaSeconds() * GameSensitivity);
	GetCharacter()->AddControllerPitchInput(LookVector.Y * GetWorld()->GetDeltaSeconds() * GameSensitivity);
}

void ATPlayerController::Jump()
{
	check(JumpAction);
	check(GetCharacter());
	GetCharacter()->Jump();
}

void ATPlayerController::StartSprint()
{
	check(SprintAction);
	check(GetCharacter());
	GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = 700.f;
}

void ATPlayerController::StopSprint()
{
	check(SprintAction);
	check(GetCharacter());
	GetCharacter()->GetCharacterMovement()->MaxWalkSpeed = 450.f;
}
