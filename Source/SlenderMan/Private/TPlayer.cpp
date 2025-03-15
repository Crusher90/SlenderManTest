// Copyright Rahul Vallecha.


#include "TPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ATPlayer::ATPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// initialize spring arm component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArmComponent->SetupAttachment(GetMesh());
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->bUsePawnControlRotation = true;

	// initialize camera component
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// set default properties
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// set default movement properties
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	Health = MaxHealth;
	Battery = MaxBattery;
}

float ATPlayer::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	if (Health - DamageAmount <= 0.f)
	{
		Health = 0.f;
		SetHUDHealth();
		Death();
	}
	else
	{
		Health -= DamageAmount;
		SetHUDHealth();
	}
	return DamageAmount;
}

void ATPlayer::BatteryPickup_Implementation(const float AmountToSet)
{
	ITPlayerInterface::BatteryPickup_Implementation(AmountToSet);
	Battery += AmountToSet;
	Battery = FMath::Clamp(Battery, 0.f, MaxBattery);
}

// Called when the game starts or when spawned
void ATPlayer::BeginPlay()
{
	Super::BeginPlay();
}