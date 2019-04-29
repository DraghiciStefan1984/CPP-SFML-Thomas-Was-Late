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
		mWindow.draw(mVALevel, &mTextureTiles);

		mWindow.draw(mThomas.GetSprite());
		mWindow.draw(mBob.GetSprite());
	}
	else
	{
		mWindow.setView(mBGLeftView);
		mWindow.draw(mBGSprite);
		mWindow.setView(mLeftView);
		mWindow.draw(mVALevel, &mTextureTiles);
		mWindow.draw(mBob.GetSprite());
		mWindow.draw(mThomas.GetSprite());

		mWindow.setView(mBGRightView);
		mWindow.draw(mBGSprite);
		mWindow.setView(mRightView);
		mWindow.draw(mVALevel, &mTextureTiles);
		mWindow.draw(mThomas.GetSprite());
		mWindow.draw(mBob.GetSprite());
	}

	mWindow.setView(mHudView);
	mWindow.display();
}