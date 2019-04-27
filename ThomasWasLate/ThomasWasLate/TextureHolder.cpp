#include "pch.h"
#include "TextureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::mInstance = nullptr;

TextureHolder::TextureHolder()
{
	assert(mInstance == nullptr);
	mInstance = this;
}

Texture& TextureHolder::GetTexture(std::string const& filename)
{
	auto& m = mInstance->mTextures;
	auto keyValuePair = m.find(filename);

	if (keyValuePair != m.end())
	{
		return keyValuePair->second;
	}
	else
	{
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}