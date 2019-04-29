#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class LevelManager
{
private:
	const int NUM_LEVELS = 4;

	Vector2i mLevelSize;
	Vector2f mStartPosition;
	float mTimeModifier = 1;
	float mBaseTimeLimit = 0;
	int mCurrentLevel = 0;

public:
	LevelManager();

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	float GetTimeLimit();
	Vector2f GetStartPosition();
	int** NextLevel(VertexArray& rVaLevel);
	Vector2i GetLevelSize();
	int GetCurrentLevel();
};