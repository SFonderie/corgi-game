#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CorgiGameLibrary.generated.h"

/**
 * Provides utility methods for the Corgi Game.
 */
UCLASS()
class CORGIGAME_API UCorgiGameLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/**
	 * Attempts to read the value of the given Game Instance Flag boolean
	 * from the given Game Instance. Game Instance Flags can be used to
	 * store data across levels. The active Game Instance can be accessed
	 * via the Get Game Instance global method.
	 * @param GameInstance Game Instance from which to read the Game Instance Flag.
	 * @param FlagName Name of the Game Instance Flag to read.
	 * @param FlagValue Value of the Game Instance Flag.
	 * @return Whether the read was successful.
	 */
	UFUNCTION(BlueprintPure, Category = "Corgi Game")
	static bool GetGameInstanceFlag(const UGameInstance* GameInstance, const FName FlagName, bool& FlagValue);

	/**
	 * Attempts to set the value of the given Game Instance Flag boolean
	 * in the given Game Instance. Game Instance Flags can be used to
	 * store data across levels. The active Game Instance can be accessed
	 * via the Get Game Instance global method.
	 * @param GameInstance Game Instance in which to set the Game Instance Flag.
	 * @param FlagName Name of the Game Instance Flag to set.
	 * @param NewValue New value for the Game Instance Flag.
	 * @return Whether the assignment was successful.
	 */
	UFUNCTION(BlueprintCallable, Category = "Corgi Game")
	static bool SetGameInstanceFlag(UGameInstance* GameInstance, const FName FlagName, bool NewValue);
};
