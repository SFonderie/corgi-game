#include "CorgiGameLibrary.h"

bool UCorgiGameLibrary::GetGameInstanceFlag(const UGameInstance* GameInstance, const FName FlagName, bool& FlagValue)
{
	// Iterate through all boolean fields in the Game Instance class reflection. Since GetClass
	// is overriden by child classes, it will return any variables defined on child types passed
	// into the Game Instance.
	for (TFieldIterator<FBoolProperty> Iterator(GameInstance->GetClass()); Iterator; ++Iterator)
	{
		// Filter for all fields with the given
		// Flag Name. There will be only one.
		if ((*Iterator)->GetFName() == FlagName)
		{
			// Store the address of the boolean Flag variable as a pointer. Since this address 
			// is accessed via pointer math (Game Instance pointer plus the field offset from 
			// the Iterator) it might be invalid, so a check is needed.
			const bool* FlagVariable = (*Iterator)->ContainerPtrToValuePtr<bool>(GameInstance);

			// There's no reason this should ever be a null pointer while the Game Instance
			// is not itself a null pointer, but there's no harm in checking.
			if (FlagVariable)
			{
				// Read out the Flag Value.
				FlagValue = (*FlagVariable);

				// If the access was successful, return true
				// to indicate a successful call.
				return true;
			}
		}
	}

	// If the search was unsuccessful, return false
	// to alert the system of the failed access.
	return false;
}

bool UCorgiGameLibrary::SetGameInstanceFlag(UGameInstance* GameInstance, const FName FlagName, bool NewValue)
{
	// Iterate through all boolean fields in the Game Instance class reflection. Since GetClass
	// is overriden by child classes, it will return any variables defined on child types passed
	// into the Game Instance.
	for (TFieldIterator<FBoolProperty> Iterator(GameInstance->GetClass()); Iterator; ++Iterator)
	{
		// Filter for all fields with the given
		// Flag Name. There will be only one.
		if ((*Iterator)->GetFName() == FlagName)
		{
			// Store the address of the boolean Flag variable as a pointer. Since this
			// address is accessed via pointer math (Game Instance pointer plus the field
			// offset from the Iterator) it might be invalid, so a check is needed.
			bool* FlagVariable = (*Iterator)->ContainerPtrToValuePtr<bool>(GameInstance);

			// There's no reason this should ever be a null pointer while the Game Instance
			// is not itself a null pointer, but there's no harm in checking.
			if (FlagVariable)
			{
				// Load in the New Value.
				(*FlagVariable) = NewValue;

				// If the assignment was successful, return true
				// to indicate a successful call.
				return true;
			}
		}
	}

	// If the search was unsuccessful, return false
	// to alert the system of the failed assignment.
	return false;
}
