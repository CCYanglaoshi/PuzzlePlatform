// Fill out your copyright notice in the Description page of Project Settings.


#include "../MenuSystem/InGameMenuWidget.h"
#include <Components/Button.h>

bool UInGameMenuWidget::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (CancelButton == nullptr) 
	{
		UE_LOG(LogTemp, Warning, TEXT("CancelButton is null"));
		return false;
	}
	//AddDynamic must be a UFUNCTION
	CancelButton->OnClicked.AddDynamic(this, &UInGameMenuWidget::CancelPressed);
	if (QuitButton == nullptr) return false;
	//AddDynamic must be a UFUNCTION
	QuitButton->OnClicked.AddDynamic(this, &UInGameMenuWidget::QuitPressed);
	return true;
}

void UInGameMenuWidget::CancelPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("CancelButton is pressed"));
	Teardown();
}

void UInGameMenuWidget::QuitPressed()
{
	if (InMenuInterface != nullptr)
	{
		Teardown();
		InMenuInterface->LoadMainMenu();
	}
}
