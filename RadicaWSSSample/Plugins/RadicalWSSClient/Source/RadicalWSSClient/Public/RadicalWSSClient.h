// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

#ifdef WIN32
//#include <windows.h>
#endif
//#include "CoreMinimal.h"
#include <sys\timeb.h>
#include <array>
#include <atomic>
#include <memory>
#include "../../../Source/ThirdParty/RadicalWSSClientLibrary/RadicalLiveClient.h"
//#include <RadicalLiveClient.h>


class FRadicalWSSClientModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** Handle to the test dll we will load */
	void*	ExampleLibraryHandle;
};



namespace rad {

    class UnrealWSSConnector {
    public:
        void connect(std::string serverUrl, std::string roomId, std::string playerId, int num);
        void run();

    private:
        std::atomic_bool _running{ false };
        std::unique_ptr<rad::live_client::Audience> _audience;
        std::string _playerId;
        int _num{ rand() % 100 };
        void initLiveClient(std::string serverUrl, std::string roomId, int num);
        void initUnrealLiveLink(std::string unrealLiveLinkDllPath);
        void dataReceived(sio::message::ptr message);
        void print(sio::message::ptr data);

        std::string _poseName = "RadicalPose";
        static constexpr int _boneCount{ 26 };
        // static constexpr auto _poseName{poseName};
        // UnrealLiveLink_Transform _boneXforms[_boneCount];
        // UnrealLiveLink_Animation _animFrame{ _boneXforms, _boneCount };
        timeb start_time;
        std::array<std::string, 26> _indexBoneMap{
            "root_r",
            "LeftUpLegDummy_r",
            "LeftUpLeg_r",
            "LeftLeg_r",
            "LeftFoot_r",
            "RightUpLegDummy_r",
            "RightUpLeg_r",
            "RightLeg_r",
            "RightFoot_r",
            "SpineDummy_r",
            "Spine_r",
            "Spine1_r",
            "Spine2_r",
            "NeckDummy_r",
            "Neck_r",
            "Head_r",
            "RightShoulderDummy_r",
            "RightShoulder_r",
            "RightArm_r",
            "RightForeArm_r",
            "RightHand_r",
            "LeftShoulderDummy_r",
            "LeftShoulder_r",
            "LeftArm_r",
            "LeftForeArm_r",
            "LeftHand_r"
        };
    };

}