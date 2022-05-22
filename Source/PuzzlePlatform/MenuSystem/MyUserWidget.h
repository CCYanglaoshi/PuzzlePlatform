// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../MenuSystem/MenuWidget.h"
#include "MenuInterface.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API UMyUserWidget : public UMenuWidget
{
	GENERATED_BODY()
	
//public:
//	// Interface injection
//	void SetMenuInterface(IMenuInterface* MenuInterface);
//
//	void Setup();
//
//	void Teardown();

protected:
	virtual bool Initialize();

private:
	// In widget designm, should setup the BTN same name, then will bind.
	UPROPERTY(meta=(BindWidget))
	class UButton*  HostButton;

	// In widget designm, should setup the BTN same name, then will bind.
	UPROPERTY(meta = (BindWidget))
	class UButton*  JoinButton;

	// In widget designm, should setup the BTN same name, then will bind.
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* HostMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinGameButton;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressField;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenHostMenu();

	//IMenuInterface* MenuInterface;
};
