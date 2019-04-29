#pragma once

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"

using namespace sf;

class Engine
{
private:
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	bool mPlaying = false;
	bool mCharcter1 = true;
	bool mSplitScreen = false;
	bool mNewLevelRequired = true;
	int** mArrayLevel = nullptr;
	float mTimeRemaining = 10;
	vector<Vector2f> mFireEmitters;

	TextureHolder mTextureHolder;
	LevelManager mLevelManager;
	SoundManager mSoundManager;
	Thomas mThomas;
	Bob mBob;

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
	Texture mTextureTiles;
	VertexArray mVALevel;
	Time mGameTimeTotal;

	void input();
	void Update(float deltaTimeAsSeconds);
	void draw();
	void LoadLevel();
	bool DetectCollisions(PlayableCharacter& character);
	void PopulateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel);

public:
	Engine();
	
	void run();
};