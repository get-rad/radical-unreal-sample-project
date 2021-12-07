// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#include "RadicalLiveLinkSourceFactory.h"
#include "RadicalLiveLinkSource.h"
#include "RadicalLiveLinkSourceFactory.h"

#define LOCTEXT_NAMESPACE "RadicalLiveLinkSourceFactory"

FText URadicalLiveLinkSourceFactory::GetSourceDisplayName() const
{
	return LOCTEXT("SourceDisplayName", "Radical LiveLink");
}

FText URadicalLiveLinkSourceFactory::GetSourceTooltip() const
{
	return LOCTEXT("SourceTooltip", "Creates a connection to a Radical Websocket Stream");
}

TSharedPtr<SWidget> URadicalLiveLinkSourceFactory::BuildCreationPanel(FOnLiveLinkSourceCreated InOnLiveLinkSourceCreated) const
{
	return SNew(SRadicalLiveLinkSourceFactory)
		.OnOkClicked(SRadicalLiveLinkSourceFactory::FOnOkClicked::CreateUObject(this, &URadicalLiveLinkSourceFactory::OnOkClicked, InOnLiveLinkSourceCreated));
}

TSharedPtr<ILiveLinkSource> URadicalLiveLinkSourceFactory::CreateSource(const FString& InConnectionString) const
{
	FIPv4Endpoint DeviceEndPoint;
	if (!FIPv4Endpoint::Parse(InConnectionString, DeviceEndPoint))
	{
		return TSharedPtr<ILiveLinkSource>();
	}

	return MakeShared<FRadicalLiveLinkSource>(DeviceEndPoint);
}

void URadicalLiveLinkSourceFactory::OnOkClicked(FIPv4Endpoint InEndpoint, FOnLiveLinkSourceCreated InOnLiveLinkSourceCreated) const
{
	InOnLiveLinkSourceCreated.ExecuteIfBound(MakeShared<FRadicalLiveLinkSource>(InEndpoint), InEndpoint.ToString());
}

#undef LOCTEXT_NAMESPACE