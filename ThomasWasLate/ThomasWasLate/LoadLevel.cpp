#include "pch.h"
#include "Engine.h"

void Engine::LoadLevel()
{
	mPlaying = false;
	for (int i = 0; i < mLevelManager.GetLevelSize().y; ++i) { delete[]mArrayLevel[i]; }
	delete[] mArrayLevel;
	
	mArrayLevel = mLevelManager.NextLevel(mVALevel);
	PopulateEmitters(mFireEmitters, mArrayLevel);
	mTimeRemaining = mLevelManager.GetTimeLimit();
	mThomas.Spawn(mLevelManager.GetStartPosition(), GRAVITY);
	mBob.Spawn(mLevelManager.GetStartPosition(), GRAVITY);
	mNewLevelRequired = false;
}