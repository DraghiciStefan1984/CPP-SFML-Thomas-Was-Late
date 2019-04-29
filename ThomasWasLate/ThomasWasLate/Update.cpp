#include "pch.h"
#include "Engine.h"

using namespace sf;

void Engine::Update(float deltaTimeAsSeconds)
{
	if (mNewLevelRequired) LoadLevel();

	if (mPlaying)
	{
		mThomas.Update(deltaTimeAsSeconds);
		mBob.Update(deltaTimeAsSeconds);

		if (DetectCollisions(mThomas) && DetectCollisions(mBob)) mNewLevelRequired = true;
		else DetectCollisions(mBob);
		if (mBob.GetFeet().intersects(mThomas.GetHead())) mBob.StopFalling(mThomas.GetHead().top);
		if (mThomas.GetFeet().intersects(mBob.GetHead())) mThomas.StopFalling(mBob.GetHead().top);

		mTimeRemaining -= deltaTimeAsSeconds;
		if (mTimeRemaining <= 0) mNewLevelRequired = true;
	}

	if (mSplitScreen)
	{
		mLeftView.setCenter(mThomas.GetCenter());
		mRightView.setCenter(mBob.GetCenter());
	}
	else
	{
		if (mCharcter1) mMainView.setCenter(mThomas.GetCenter());
		else mMainView.setCenter(mBob.GetCenter());
	}
}