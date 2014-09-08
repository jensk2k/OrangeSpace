#pragma once
#include "GameObject.h"
#include "TextureLoader.h"
#include "Game.h"
class MediumStar :
	public GameObject
{
public:
	MediumStar();
	~MediumStar();
	virtual void Render();
};

