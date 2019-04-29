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

		if (DetectCollisions(mThomas) && DetectCollisions(mBob))
		{
			mNewLevelRequired = true;
			mSoundManager.PlayReachGoal();
		}
		else DetectCollisions(mBob);
		if (mBob.GetFeet().intersects(mThomas.GetHead())) mBob.StopFalling(mThomas.GetHead().top);
		if (mThomas.GetFeet().intersects(mBob.GetHead())) mThomas.StopFalling(mBob.GetHead().top);

		mTimeRemaining -= deltaTimeAsSeconds;
		if (mTimeRemaining <= 0) mNewLevelRequired = true;
	}

	for (vector<Vector2f>::iterator it = mFireEmitters.begin(); it != mFireEmitters.end(); it++)
	{
		float positionX = (*it).x;
		float positionY = (*it).y;
		FloatRect localRect(positionX - 250, positionY - 250, 500, 500);
		if (mThomas.GetPosition().intersects(localRect)) mSoundManager.PlayFire(Vector2f(positionX, positionY), mThomas.GetCenter());
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