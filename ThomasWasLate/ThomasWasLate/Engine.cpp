#include "pch.h"
#include "Engine.h"

Engine::Engine()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	mWindow.create(VideoMode(resolution.x, resolution.y), "Thomas was late...", Style::Fullscreen);
	mMainView.setSize(resolution);
	mHudView.reset(FloatRect(0, 0, resolution.x, resolution.y));
	mLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	mBGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	mRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	mBGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	if (!sf::Shader::isAvailable()) mWindow.close();

	mBGTexture = TextureHolder::GetTexture("graphics/background.png");
	mBGSprite.setTexture(mBGTexture);
}

void Engine::run()
{
	Clock clock;

	while (mWindow.isOpen())
	{
		Time deltaTime = clock.restart();
		mGameTimeTotal += deltaTime;
		float deltaTimeAsSeconds = deltaTime.asSeconds();

		input();
		update(deltaTimeAsSeconds);
		draw();
	}
}