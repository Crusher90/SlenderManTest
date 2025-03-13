// Copyright Rahul Vallecha.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TCharacterBase.generated.h"

UCLASS()
class SLENDERMAN_API ATCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};