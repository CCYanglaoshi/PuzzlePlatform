// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
// 1. setup Interface.h and setup the pure function.
// 2. In GameInstance, inherit the Interface, and setup the interface.
class PUZZLEPLATFORM_API IMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// =0 means this is a pure function, no need implementation.
	virtual void Host() = 0;

	// here function need same with gameinstance.h
	virtual void JoinServer(const FString& address) = 0;

	virtual void LoadMainMenu() = 0;

};


