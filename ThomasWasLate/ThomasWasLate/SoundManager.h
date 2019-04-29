#pragma once

#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager
{
private:
	SoundBuffer mFireBuffer;
	SoundBuffer mFallInFireBuffer;
	SoundBuffer mFallInWaterBuffer;
	SoundBuffer mJumpBuffer;
	SoundBuffer mReachGoalBuffer;

	Sound mFire1Sound;
	Sound mFire2Sound;
	Sound mFire3Sound;
	Sound mFallInFireSound;
	Sound mFallInWaterSound;
	Sound mJumpSound;
	Sound mReachGoalSound;

	int mNextSound = 1;

public:
	SoundManager();

	void PlayFire(Vector2f emitterLocation, Vector2f listenerLocation);
	void PlayFallInFire();
	void PlayFallInWater();
	void PlayJump();
	void PlayReachGoal();
};