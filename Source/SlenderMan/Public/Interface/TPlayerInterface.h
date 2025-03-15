// Copyright Rahul Vallecha.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TPlayerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTPlayerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SLENDERMAN_API ITPlayerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void BatteryPickup(const float AmountToSet);
};
