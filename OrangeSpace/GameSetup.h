#pragma once
#include "Texture.h"
#include "TextureLoader.h"
#include "Game.h"
#include "Level.h"
#include "StarryBackground.h"
class GameSetup
{
public:
	static Texture * spaceshipTexture;
	static Texture * mediumStarTexture;
	static Texture * bigStarTexture;

	static void Init();

	static void ChangeToMenuLevel();
	static void ChangeToGameLevel();


};

