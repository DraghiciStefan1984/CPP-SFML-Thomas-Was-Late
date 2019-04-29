#include "pch.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
	mFireBuffer.loadFromFile("sound/fire1.wav");
	mFallInFireBuffer.loadFromFile("sound/fallinfire.wav");
	mFallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
	mJumpBuffer.loadFromFile("sound/jump.wav");
	mReachGoalBuffer.loadFromFile("sound/reachgoal.wav");

	mFire1Sound.setBuffer(mFireBuffer);
	mFire2Sound.setBuffer(mFireBuffer);
	mFire3Sound.setBuffer(mFireBuffer);
	mFallInFireSound.setBuffer(mFallInFireBuffer);
	mFallInWaterSound.setBuffer(mFallInWaterBuffer);
	mJumpSound.setBuffer(mJumpBuffer);

	float minDistance = 150;
	float attenuation = 15;

	mFire1Sound.setAttenuation(attenuation);
	mFire1Sound.setMinDistance(minDistance);
	mFire1Sound.setLoop(true);
	mFire2Sound.setAttenuation(attenuation);
	mFire2Sound.setMinDistance(minDistance);
	mFire2Sound.setLoop(true);
	mFire3Sound.setAttenuation(attenuation);
	mFire3Sound.setMinDistance(minDistance);
	mFire3Sound.setLoop(true);
}

void SoundManager::PlayFire(Vector2f emitterLocation, Vector2f listenerLocation)
{
	Listener::setPosition(listenerLocation.x, listenerLocation.y, 0.0f);

	switch (mNextSound)
	{
	case 1:
		mFire1Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
		if (mFire1Sound.getStatus() == Sound::Status::Stopped) mFire1Sound.play();
		break;
	case 2:
		mFire2Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
		if (mFire2Sound.getStatus() == Sound::Status::Stopped) mFire2Sound.play();
		break;
	case 3:
		mFire3Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);
		if (mFire3Sound.getStatus() == Sound::Status::Stopped) mFire3Sound.play();
		break;
	}

	mNextSound++;
	if (mNextSound > 3) mNextSound = 1;
}

void SoundManager::PlayFallInFire()
{
	mFallInFireSound.setRelativeToListener(true);
	mFallInFireSound.play();
}

void SoundManager::PlayFallInWater()
{
	mFallInWaterSound.setRelativeToListener(true);
	mFallInWaterSound.play();
}

void SoundManager::PlayJump()
{
	mJumpSound.setRelativeToListener(true);
	mJumpSound.play();
}

void SoundManager::PlayReachGoal()
{
	mReachGoalSound.setRelativeToListener(true);
	mReachGoalSound.play();
}