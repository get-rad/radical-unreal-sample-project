// Copyright Epic Games, Inc. All Rights Reserved.

#include "RadicalWSSClient.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "RadicalWSSClientLibrary/RadicalLiveClient.h"
#include <iostream>
#include <thread>
#include <utility>

#define LOCTEXT_NAMESPACE "FRadicalWSSClientModule"

void FRadicalWSSClientModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("RadicalWSSClient")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	// LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/RadicalWSSClientLibrary/RadicalLiveClient/RadicalLiveClient.lib"));
#elif PLATFORM_MAC
    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/RadicalWSSClientLibrary/Mac/Release/libExampleLibrary.dylib"));
#endif // PLATFORM_WINDOWS

	ExampleLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (ExampleLibraryHandle)
	{

		// Call the test function in the third party library that opens a message box
		// ExampleLibraryFunction();
	}
	else
	{
		// FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
	}

    std::string liveLinkDllPath = ".";
    std::string serverUrl = "wss://ue.getrad.co:8080";
    std::string roomId = "simulation";
    std::string playerId = "";
    //for (auto i = 0; i < argc; ++i) {
    //    if (0 == strcmp(argv[i], "-l") || 0 == strcmp(argv[i], "--liveLinkLib")) {
    //        liveLinkDllPath = argv[++i];
    //    }
    //    else if (0 == strcmp(argv[i], "-s") || 0 == strcmp(argv[i], "--serverUrl")) {
    //        serverUrl = argv[++i];
    //    }
    //    else if (0 == strcmp(argv[i], "-r") || 0 == strcmp(argv[i], "--roomId")) {
    //        roomId = argv[++i];
    //    }
    //    else if (0 == strcmp(argv[i], "-p") || 0 == strcmp(argv[i], "--playerId")) {
    //        playerId = argv[++i];
    //    }
    // }
    rad::UnrealWSSConnector connector;
    srand(time(NULL));
    int num = rand() % 100;
    std::cout << "pre-connect!" << std::endl;
    //connector.connect(std::move(serverUrl), std::move(roomId), std::move(playerId), std::move(num));
    // connector.run();

}

namespace rad {
	void UnrealWSSConnector::connect(
		std::string serverUrl,
		std::string roomId,
		std::string playerId,
		int num
	) {
		_num = num;
		_playerId = std::move(playerId);
        std::cout << "connect!" << std::endl;
		//initUnrealLiveLink(std::move(unrealLiveLinkDllPath));
		initLiveClient(std::move(serverUrl), std::move(roomId), std::move(num));
	}

    void UnrealWSSConnector::run() {
        _running = true;
        std::cout << "Running once" << std::endl;
        while (_running) {
            // std::cout << "Running..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds{ 100 });
        }
    }

	void UnrealWSSConnector::initLiveClient(std::string serverUrl, std::string roomId, int num) {

		_audience = std::make_unique<rad::live_client::Audience>(std::move(serverUrl), std::move(roomId));
		_audience->OnConnected([]() { std::cout << "Connected" << std::endl; });
		_audience->OnDisconnected([this]() {
			_running = false;
			std::cout << "Disconnected" << std::endl;
			});
		_audience->OnError([this](sio::message::ptr error) {
			_running = false;
			std::cout << "Error occurred" << std::endl;
			this->print(std::move(error));
			});
		_audience->OnData([this](sio::message::ptr message) { this->dataReceived(std::move(message)); });
		_audience->Connect();
	}

    void UnrealWSSConnector::dataReceived(sio::message::ptr message) {
        std::cout << "Data received" << std::endl;
        //if (UNREAL_LIVE_LINK_OK != UnrealLiveLink_IsLoaded()) {
            //return;
        // }

        try {
            if (message->get_flag() != sio::message::flag_object) {
                std::cout << "The received data is not an object" << std::endl;
                return;
            }
            if (message->get_map()["player_id"]->get_flag() != sio::message::flag_string) {
                std::cout << "There is no playerId in data" << std::endl;
                return;
            }
            if (!_playerId.empty()) {
                // if player id is not empty, select only the data that's for the player id
                if (message->get_map()["player_id"]->get_string() != _playerId) {
                    // the data is not for given player id
                    return;
                }
            }
            else {
                // if there's no player id, select the first data and only accept the player id for that
                _playerId = message->get_map()["player_id"]->get_string();
            }
            if (message->get_map()["result"]->get_flag() != sio::message::flag_array) {
                std::cout << "There is no result in data" << std::endl;
                return;
            }
            if (message->get_map()["result"]->get_vector()[0]->get_flag() != sio::message::flag_object) {
                std::cout << "Result does not have object" << std::endl;
                return;
            }
            if (message->get_map()["result"]->get_vector()[0]->get_map()["frame_data"]->get_flag()
                != sio::message::flag_object) {
                std::cout << "Result does not have frame data" << std::endl;
                return;
            }
            // std::cout << "Player id: " << _playerId << std::endl;
            auto frameData = message->get_map()["result"]->get_vector()[0]->get_map()["frame_data"]->get_map();
            
            
            // !!!! apply transforms here

            timeb end_time;
            ftime(&end_time);
            // std::cout << "Updating" << std::endl;
            // UnrealLiveLink_UpdateAnimationFrame(_poseName.c_str(), (end_time.time - start_time.time), nullptr, nullptr, &_animFrame);
        }
        catch (std::exception const e) {
            std::cout << "Error on parsing incoming data" << std::endl;
        }
    }

    void UnrealWSSConnector::print(sio::message::ptr data) {
        std::cout << "Error received" << std::endl;
    }
}
void FRadicalWSSClientModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(ExampleLibraryHandle);
	ExampleLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRadicalWSSClientModule, RadicalWSSClient)
