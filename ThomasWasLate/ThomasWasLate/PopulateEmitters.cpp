#include "pch.h"
#include "Engine.h"

using namespace std;
using namespace sf;

void Engine::PopulateEmitters(vector<Vector2f>& vSoundEmitters, int ** arrayLevel)
{
	vSoundEmitters.empty();
	FloatRect previousEmitter;

	for (int x = 0; x < (int)mLevelManager.GetLevelSize().x; x++)
	{
		for (int y = 0; y < (int)mLevelManager.GetLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2)
			{
				if (!FloatRect(x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE).intersects(previousEmitter))
				{
					vSoundEmitters.push_back(Vector2f(x*TILE_SIZE, y*TILE_SIZE));
					previousEmitter.left = x * TILE_SIZE;
					previousEmitter.top = y * TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;
				}
			}
		}
	}
}