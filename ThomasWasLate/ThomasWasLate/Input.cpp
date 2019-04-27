#include "pch.h"
#include "Engine.h"

void Engine::input()
{
	Event event;

	while (mWindow.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape)) mWindow.close();
			if (Keyboard::isKeyPressed(Keyboard::Return)) mPlaying = true;
			if (Keyboard::isKeyPressed(Keyboard::Q)) mCharcter1 = !mCharcter1;
			if (Keyboard::isKeyPressed(Keyboard::E)) mSplitScreen = !mSplitScreen;
		}
	}
}