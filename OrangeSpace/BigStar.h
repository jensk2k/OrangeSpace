#pragma once
#include "TextureLoader.h"
#include "Texture.h"
#include "Vector2.h"
#include "GameSetup.h"
class BigStar
{
public:
	Texture * texture;
	Vector2 position;
	Vector2 scale;

	BigStar();
	~BigStar();
	void Render();
};

