/// @brief Radical Live Client library.
///
/// @copyright "Copyright (C) 2021, Radical
/// All rights reserved.
/// CONFIDENTIAL INFORMATION - DO NOT DISTRIBUTE"

#pragma once

#include <string>
#include <memory>
#include <functional>
//#include <sio_message.h>
#include "include/sio_message.h"


namespace rad
{
	namespace live_client
	{
		class AudienceImpl;

		class Audience
		{
		public:
			Audience(std::string uriString, std::string roomId);
			~Audience();

			void Connect();
			void Disconnect();
			void OnData(std::function<void(sio::message::ptr)> callback);
			void OnConnected(std::function<void()> callback);
			void OnDisconnected(std::function<void()> callback);
			void OnError(std::function<void(sio::message::ptr)> callback);

		private:
			std::unique_ptr<AudienceImpl> _audienceImpl;
		};
	}
}
