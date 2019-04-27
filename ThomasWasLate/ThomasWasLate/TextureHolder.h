#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder
{
private:
	std::map<std::string, sf::Texture> mTextures;
	static TextureHolder* mInstance;

public:
	TextureHolder();
	static sf::Texture& GetTexture(std::string const& filename);
};