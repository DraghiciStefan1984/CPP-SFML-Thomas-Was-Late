#include "pch.h"
#include "Engine.h"

using namespace sf;

void Engine::Update(float deltaTimeAsSeconds)
{
	if (mNewLevelRequired)
	{
		mThomas.Spawn(Vector2f(0, 0), GRAVITY);
		mBob.Spawn(Vector2f(100, 0), GRAVITY);

		mTimeRemaining = 10;
		mNewLevelRequired = false;
	}

	if (mPlaying)
	{
		mThomas.Update(deltaTimeAsSeconds);
		mBob.Update(deltaTimeAsSeconds);

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