#include "GameSetup.h"


Texture * GameSetup::spaceshipTexture = new Texture();
Texture * GameSetup::mediumStarTexture = new Texture();
Texture * GameSetup::bigStarTexture = new Texture();

//Level * Game::currentLevel = new Level("Default");
Level * Game::currentLevel = NULL;

void GameSetup::Init()
{
	TextureLoader::LoadTexture(spaceshipTexture, "Textures/Spaceship.tga");
	TextureLoader::LoadTexture(mediumStarTexture, "Textures/StarMedium.tga");
	TextureLoader::LoadTexture(bigStarTexture, "Textures/StarBig.tga");

	ChangeToGameLevel();
	//ChangeToMenuLevel();
}

void GameSetup::ChangeToMenuLevel()
{
	Game::currentLevel = new Level("Menu");
	Game::currentLevel->background = new StarryBackground();
}

void GameSetup::ChangeToGameLevel()
{
	//Background * background = new StarryBackground();
	Game::currentLevel = new Level("Game");
	Game::currentLevel->background = new StarryBackground();
	//Game::currentLevel->
	Spaceship * spaceship = new Spaceship();

	Game::Instantiate(spaceship);
}

