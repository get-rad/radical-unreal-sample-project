/// @brief Radical Live Client library implementation.
///
/// @copyright "Copyright (C) 2021, Radical
/// All rights reserved.
/// CONFIDENTIAL INFORMATION - DO NOT DISTRIBUTE"

#include "RadicalLiveClient.h"

#include <AudienceImpl.h>

namespace rad::live_client
{

Audience::Audience(std::string uriString, std::string roomId)
    : _audienceImpl(std::make_unique<AudienceImpl>(std::move(uriString), std::move(roomId)))
{
}
Audience::~Audience()
{
}
void Audience::Connect()
{
  _audienceImpl->Connect();
}
void Audience::Disconnect()
{
  _audienceImpl->Disconnect();
}
void Audience::OnData(std::function<void(sio::message::ptr)> callback)
{
  _audienceImpl->OnData(std::move(callback));
}
void Audience::OnConnected(std::function<void()> callback)
{
  _audienceImpl->OnConnected(std::move(callback));
}
void Audience::OnDisconnected(std::function<void()> callback)
{
  _audienceImpl->OnDisconnected(std::move(callback));
}
void Audience::OnError(std::function<void(sio::message::ptr)> callback)
{
  _audienceImpl->OnError(std::move(callback));
}

}