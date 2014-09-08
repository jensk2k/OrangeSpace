#pragma once
#include "GameObject.h"
#include "TextureLoader.h"
#include "Game.h"
class BigStar :
	public GameObject
{
public:
	BigStar();
	~BigStar();
	virtual void Render();
};

