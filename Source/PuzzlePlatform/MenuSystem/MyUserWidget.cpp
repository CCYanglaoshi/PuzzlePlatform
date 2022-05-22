// Fill out your copyright notice in the Description page of Project Settings.


#include "../MenuSystem/MyUserWidget.h"
#include <Components/Button.h>
#include <Components/WidgetSwitcher.h>
#include "Components/EditableTextBox.h"

void UMyUserWidget::SetMenuInterface(IMenuInterface* InMenuInterface)
{
	this->MenuInterface = InMenuInterface;
}

void UMyUserWidget::Setup()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		return;
	}

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (PlayerController == nullptr)
	{
		return;
	}

	FInputModeUIOnly InData;
	InData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InData.SetWidgetToFocus(this->TakeWidget());
	PlayerController->SetInputMode(InData);

	PlayerController->bShowMouseCursor = true;
}

void UMyUserWidget::Teardown()
{
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		return;
	}
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (PlayerController == nullptr)
	{
		return;
	}
	PlayerController->bShowMouseCursor = false;

	FInputModeGameOnly InData;
	PlayerController->SetInputMode(InData);

	this->RemoveFromViewport();
}

bool UMyUserWidget::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if( HostButton == nullptr) return false;
	HostButton->OnClicked.AddDynamic(this, &UMyUserWidget::HostServer);
	if (JoinButton == nullptr) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMyUserWidget::OpenJoinMenu);
	if (BackButton == nullptr) return false;
	BackButton->OnClicked.AddDynamic(this, &UMyUserWidget::OpenHostMenu);
	if (JoinGameButton == nullptr) return false;
	JoinGameButton->OnClicked.AddDynamic(this, &UMyUserWidget::JoinServer);
	return true;
}

void UMyUserWidget::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}


void UMyUserWidget::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("JoinServer Starting"));
	if (MenuInterface != nullptr)
	{
		MenuInterface->JoinServer(IPAddressField->GetText().ToString());
	}

}

void UMyUserWidget::OpenJoinMenu()
{
	if (MenuSwitcher == nullptr)
	{
		return;
	}
	if (JoinMenu == nullptr)
	{
		return;
	}
	MenuSwitcher->SetActiveWidget(JoinMenu);

}

void UMyUserWidget::OpenHostMenu()
{
	if (MenuSwitcher == nullptr)
	{
		return;
	}
	if (HostMenu == nullptr)
	{
		return;
	}
	MenuSwitcher->SetActiveWidget(HostMenu);
}

