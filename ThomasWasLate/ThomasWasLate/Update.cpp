#include "pch.h"
#include "Engine.h"

using namespace sf;

void Engine::update(float deltaTimeAsSeconds)
{
	if (mPlaying)
	{
		mTimeRemaining -= deltaTimeAsSeconds;
		if (mTimeRemaining <= 0) mNewLevelRequired = true;
	}
}