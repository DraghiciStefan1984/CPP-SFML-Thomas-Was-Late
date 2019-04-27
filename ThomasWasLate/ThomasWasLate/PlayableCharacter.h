#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
private:
	float mGravity;
	float mSpeed = 400;

	Vector2f mPosition;
	FloatRect mFeet;
	FloatRect mHead;
	FloatRect mRight;
	FloatRect mLeft;
	Texture mTexture;

protected:
	Sprite mSprite;

	float mJumpDuration;
	float mTimeThisJump;
	bool mIsJumping;
	bool mIsFalling;
	bool mLeftPressed;
	bool mRightPressed;
	bool mJustJumped = false;

public:
	void Spawn(Vector2f startPosition, float gravity);
	bool virtual HandleInput() = 0;
	FloatRect GetPosition();
	FloatRect GetFeet();
	FloatRect GetHead();
	FloatRect GetRight();
	FloatRect GetLeft();
	Sprite GetSprite();
	void StopFalling(float position);
	void StopRight(float position);
	void StopLeft(float position);
	void StopJump();
	Vector2f GetCenter();
	void Update(float elpasedTime);
};