#pragma once
#include "GameObject.h"
#include "Game.h"
#include "Screen.h"
//#include "Tga.h"
#include "Texture.h"
#include "TextureLoader.h"
//#include "TGALoader.h"

class Spaceship :
	public GameObject
{
public:
	Spaceship();
	~Spaceship();

	void FrameUpdate();
	void FixedUpdate();
	virtual void Render();
};

