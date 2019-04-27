#include "pch.h"
#include "PlayableCharacter.h"

void PlayableCharacter::Spawn(Vector2f startPosition, float gravity)
{
	mPosition.x = startPosition.x;
	mPosition.y = startPosition.y;
	mGravity = gravity;
	mSprite.setPosition(mPosition);
}

Vector2f PlayableCharacter::GetCenter() { return Vector2f(mPosition.x + mSprite.getGlobalBounds().width / 2, mPosition.y + mSprite.getGlobalBounds().height / 2); }

void PlayableCharacter::Update(float elapsedTime)
{
	if (mRightPressed) mPosition.x += mSpeed * elapsedTime;
	if (mLeftPressed) mPosition.x -= mSpeed * elapsedTime;

	if (mIsJumping)
	{
		mTimeThisJump += elapsedTime;
		if (mTimeThisJump < mJumpDuration) mPosition.y -= mGravity * 2 * elapsedTime;
		else
		{
			mIsJumping = false;
			mIsFalling = true;
		}
	}

	if (mIsFalling) mPosition.y += mGravity * elapsedTime;
	FloatRect r = GetPosition();

	mFeet.left = r.left + 3;
	mFeet.top = r.top + r.height - 1;
	mFeet.width = r.width - 6;
	mFeet.height = 1;

	mHead.left = r.left;
	mHead.top = r.top + (r.height * .3);
	mHead.width = r.width;
	mHead.height = 1;

	mRight.left = r.left + r.width - 2;
	mRight.top = r.top + (r.height * .35);
	mRight.width = 1;
	mRight.height = r.height * .3;

	mLeft.left = r.left;
	mLeft.top = r.top + (r.height * .5);
	mLeft.width = 1;
	mLeft.height = r.height * .3;

	mSprite.setPosition(mPosition);
}

FloatRect PlayableCharacter::GetPosition() { return mSprite.getGlobalBounds(); }

FloatRect PlayableCharacter::GetFeet() { return mFeet; }

FloatRect PlayableCharacter::GetHead() { return mHead; }

FloatRect PlayableCharacter::GetRight() { return mRight; }

FloatRect PlayableCharacter::GetLeft() { return mLeft; }

Sprite PlayableCharacter::GetSprite() { return mSprite; }

void PlayableCharacter::StopFalling(float position)
{
	mPosition.y = position - GetPosition().height;
	mSprite.setPosition(mPosition);
	mIsFalling = false;
}

void PlayableCharacter::StopRight(float position)
{
	mPosition.x = position - mSprite.getGlobalBounds().width;
	mSprite.setPosition(mPosition);
}

void PlayableCharacter::StopLeft(float position)
{
	mPosition.x = position + mSprite.getGlobalBounds().width;
	mSprite.setPosition(mPosition);
}

void PlayableCharacter::StopJump()
{
	mIsJumping = false;
	mIsFalling = true;
}