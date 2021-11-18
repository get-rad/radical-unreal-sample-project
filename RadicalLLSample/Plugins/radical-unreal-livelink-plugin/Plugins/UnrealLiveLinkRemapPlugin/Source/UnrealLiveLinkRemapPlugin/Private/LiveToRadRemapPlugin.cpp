// Copyright RADiCAL Solutions, LLC. All Rights Reserved.

#include "RadToRadRemapAsset.h"

FVector ULiveToRadRemapAsset::ConvertRootPosition(FVector LLPosition) const
{
	// Unreal uses cm, so apply x100 conversion factor
	return 100 * FVector(
		LLPosition.X,
		-LLPosition.Y,
		LLPosition.Z
	);
}

FQuat ULiveToRadRemapAsset::ConvertRootRotation(FQuat LLRotation) const
{
	return FQuat(
		LLRotation.X,
		LLRotation.Y,
		LLRotation.Z,
		LLRotation.W
	);
}

FQuat ULiveToRadRemapAsset::ConvertBoneRotation(FQuat LLRotation) const
{
	return FQuat(
		LLRotation.X,
		LLRotation.Y,
		LLRotation.Z,
		LLRotation.W
	);
}
