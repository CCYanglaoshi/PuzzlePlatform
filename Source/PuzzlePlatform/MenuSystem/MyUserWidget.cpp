// Fill out your copyright notice in the Description page of Project Settings.


#include "../MenuSystem/MyUserWidget.h"
#include <Components/Button.h>
#include <Components/WidgetSwitcher.h>
#include "Components/EditableTextBox.h"


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
	if (InMenuInterface != nullptr)
	{
		InMenuInterface->Host();
	}
}


void UMyUserWidget::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("JoinServer Starting"));
	if (InMenuInterface != nullptr)
	{
		InMenuInterface->JoinServer(IPAddressField->GetText().ToString());
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

