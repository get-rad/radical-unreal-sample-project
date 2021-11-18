// Copyright RADiCAL Solutions, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RadicalLiveLinkRemapAssetBase.h"
#include "LiveToRadRemapAsset.generated.h"

/**
 * 
 */
UCLASS()
class UNREALLIVELINKREMAPPLUGIN_API ULiveToRadRemapAsset : public URadicalLiveLinkRemapAssetBase
{
	GENERATED_BODY()

protected:
	virtual FVector ConvertRootPosition(FVector LLPosition) const override;

	virtual FQuat ConvertRootRotation(FQuat LLRotation) const override;

	virtual FQuat ConvertBoneRotation(FQuat LLRotation) const override;
};
