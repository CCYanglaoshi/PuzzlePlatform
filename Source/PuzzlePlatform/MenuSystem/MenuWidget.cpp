// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "MenuInterface.h"
#include <Blueprint/UserWidget.h>
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

void UMenuWidget::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->InMenuInterface = MenuInterface;
}

void UMenuWidget::Setup()
{
	this->AddToViewport();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController == nullptr)
	{
		return;
	}


	FInputModeUIOnly InData;
	InData.SetWidgetToFocus(this->TakeWidget());
	InData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InData);

	PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::Teardown()
{

	UE_LOG(LogTemp, Warning, TEXT("TEARDONW!!!"));

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController == nullptr)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT(" get PlayerController!!!"))
	PlayerController->bShowMouseCursor = false;

	FInputModeGameOnly InData;
	UE_LOG(LogTemp, Warning, TEXT("RemoveFromViewport!!!"))
	this->RemoveFromViewport();
	PlayerController->SetInputMode(InData);

}
