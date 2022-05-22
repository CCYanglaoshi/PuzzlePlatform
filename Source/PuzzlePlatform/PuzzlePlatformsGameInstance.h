// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
// Inherit the Interface.
UCLASS()
class PUZZLEPLATFORM_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public: 
	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);
	
	virtual void Init();

	UFUNCTION(Exec, BlueprintCallable)
	void LoadMenu();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void JoinServer(const FString& address);

private:
	TSubclassOf<class UUserWidget> MenuClass;

	class UMyUserWidget* Menu;
};
