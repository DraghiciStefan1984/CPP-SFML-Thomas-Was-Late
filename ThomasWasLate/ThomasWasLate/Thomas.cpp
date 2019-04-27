#include "pch.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	mSprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));
	mJumpDuration = .45;
}

bool Thomas::handleInput()
{
	mJustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (!mIsJumping && !mIsFalling)
		{
			mIsJumping = true;
			mTimeThisJump = 0;
			mJustJumped = true;
		}
	}
	else
	{
		mIsJumping = false;
		mIsFalling = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) mLeftPressed = true;
	else mLeftPressed = false;

	if (Keyboard::isKeyPressed(Keyboard::D)) mRightPressed = true;
	else mRightPressed = false;
	
	return mJustJumped;
}