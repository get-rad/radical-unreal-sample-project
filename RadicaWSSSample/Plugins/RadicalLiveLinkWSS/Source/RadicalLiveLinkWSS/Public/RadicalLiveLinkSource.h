// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ILiveLinkSource.h"
#include "HAL/Runnable.h"
#include "HAL/ThreadSafeBool.h"
#include "IMessageContext.h"
#include <array>
#include <atomic>
#include <memory>

#ifdef WIN32
#include <windows.h>
#endif
#include <sys\timeb.h>
// #include "Interfaces/IPv4/IPv4Endpoint.h"

class FRunnableThread;
class FSocket;
class ILiveLinkClient;
class ISocketSubsystem;

/* transformation
 * rotation is quaternion, w is 4th field
 */
struct UnrealLiveLink_Transform
{
	float rotation[4];
	float translation[3];
	float scale[3];
};

struct UnrealLiveLink_Animation
{
	/* bone transforms */
	struct UnrealLiveLink_Transform* transforms;
	int transformCount;
};

class RADICALLIVELINK_API FRadicalLiveLinkSource : public ILiveLinkSource, public FRunnable
{

public:
	FRadicalLiveLinkSource(); // FIPv4Endpoint Endpoint);
	virtual ~FRadicalLiveLinkSource();
	//~UnrealLiveLinkConnector();
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
	UnrealLiveLink_Transform _boneXforms[_boneCount];
	UnrealLiveLink_Animation _animFrame{ _boneXforms, _boneCount };
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

//	FRadicalLiveLinkSource(FIPv4Endpoint Endpoint);
//
//	virtual ~FRadicalLiveLinkSource();
//
//	// Begin ILiveLinkSource Interface
//	
//	virtual void ReceiveClient(ILiveLinkClient* InClient, FGuid InSourceGuid) override;
//
//	virtual bool IsSourceStillValid() const override;
//
//	virtual bool RequestSourceShutdown() override;
//
//	virtual FText GetSourceType() const override { return SourceType; };
//	virtual FText GetSourceMachineName() const override { return SourceMachineName; }
//	virtual FText GetSourceStatus() const override { return SourceStatus; }
//
//	// End ILiveLinkSource Interface
//
//	// Begin FRunnable Interface
//
//	virtual bool Init() override { return true; }
//	virtual uint32 Run() override;
//	void Start();
//	virtual void Stop() override;
//	virtual void Exit() override { }
//
//	// End FRunnable Interface
//
//	void HandleReceivedData(TSharedPtr<TArray<uint8>, ESPMode::ThreadSafe> ReceivedData);
//
//private:
//
//	ILiveLinkClient* Client;
//
//	// Our identifier in LiveLink
//	FGuid SourceGuid;
//
//	FMessageAddress ConnectionAddress;
//
//	FText SourceType;
//	FText SourceMachineName;
//	FText SourceStatus;
//
//	FIPv4Endpoint DeviceEndpoint;
//
//	// Socket to receive data on
//	FSocket* Socket;
//
//	// Subsystem associated to Socket
//	ISocketSubsystem* SocketSubsystem;
//
//	// Threadsafe Bool for terminating the main thread loop
//	FThreadSafeBool Stopping;
//
//	// Thread to run socket operations on
//	FRunnableThread* Thread;
//
//	// Name of the sockets thread
//	FString ThreadName;
//
//	// Time to wait between attempted receives
//	FTimespan WaitTime;
//
//	// List of subjects we've already encountered
//	TSet<FName> EncounteredSubjects;
//
//	// Buffer to receive socket data into
//	TArray<uint8> RecvBuffer;
//};
