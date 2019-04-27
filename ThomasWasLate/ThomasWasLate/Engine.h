#pragma once

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Engine
{
private:
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	TextureHolder textureHolder;
	RenderWindow mWindow;
	View mMainView;
	View mLeftView;
	View mRightView;
	View mBGMainView;
	View mBGLeftView;
	View mBGRightView;
	View mHudView;
	Sprite mBGSprite;
	Texture mBGTexture;
	Time mGameTimeTotal;

	bool mPlaying = false;
	bool mCharcter1 = true;
	bool mSplitScreen = false;
	bool mNewLevelRequired = true;
	float mTimeRemaining = 10;

	void input();
	void update(float deltaTimeAsSeconds);
	void draw();

public:
	Engine();
	
	void run();
};