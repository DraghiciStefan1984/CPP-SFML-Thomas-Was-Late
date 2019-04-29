#include "pch.h"
#include "Engine.h"

bool Engine::DetectCollisions(PlayableCharacter & character)
{
	bool reachGoal = false;
	FloatRect detectionZone = character.GetPosition();
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;
	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;
	if (endX >= mLevelManager.GetLevelSize().x) endX = mLevelManager.GetLevelSize().x;
	if (endY >= mLevelManager.GetLevelSize().y) endY = mLevelManager.GetLevelSize().y;

	FloatRect level(0, 0, 0 + mLevelManager.GetLevelSize().x*TILE_SIZE, 0 + mLevelManager.GetLevelSize().y*TILE_SIZE);
	if (!character.GetPosition().intersects(level)) character.Spawn(mLevelManager.GetStartPosition(), GRAVITY);

	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			if (mArrayLevel[y][x] == 2 || mArrayLevel[y][x] == 3)
			{
				if (mArrayLevel[y][x] == 2) mSoundManager.PlayFallInFire();
				else mSoundManager.PlayFallInWater();
			}

			if (mArrayLevel[y][x] == 1)
			{
				if (character.GetRight().intersects(block)) character.StopRight(block.left);
				if (character.GetLeft().intersects(block)) character.StopLeft(block.left);
				if (character.GetFeet().intersects(block)) character.StopFalling(block.top);
				if (character.GetHead().intersects(block)) character.StopJump();
			}

			if (mArrayLevel[y][x] == 4) reachGoal = true;
		}
	}
	return reachGoal;
}