#pragma once
#include "Texture.h"
#include "GameSetup.h"
#include "Vector2.h"
class MediumStar
{
public:
	Texture * texture;
	Vector2 position;
	Vector2 scale;

	MediumStar();
	~MediumStar();
	void Render();
};

