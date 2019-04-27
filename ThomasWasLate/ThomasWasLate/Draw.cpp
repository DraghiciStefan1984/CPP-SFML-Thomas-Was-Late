#include "pch.h"
#include "Engine.h"

void Engine::draw()
{
	mWindow.clear(Color::White);

	if (!mSplitScreen)
	{
		mWindow.setView(mBGMainView);
		mWindow.draw(mBGSprite);
		mWindow.setView(mMainView);
	}
	else
	{
		mWindow.setView(mBGLeftView);
		mWindow.draw(mBGSprite);
		mWindow.setView(mLeftView);

		mWindow.setView(mBGRightView);
		mWindow.draw(mBGSprite);
		mWindow.setView(mRightView);
	}

	mWindow.setView(mHudView);
	mWindow.display();
}