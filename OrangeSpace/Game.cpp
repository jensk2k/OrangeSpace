#include "Game.h"

std::vector<GameObject*> Game::instantiatedGameObjects;
Vector2 Game::cursorPosition = Vector2();
Texture * Game::spaceshipTexture = new Texture();
Texture * Game::mediumStarTexture = new Texture();
Texture * Game::bigStarTexture = new Texture();
Spaceship spaceship;
Background background;

void Game::Init()
{
	TextureLoader::LoadTexture(spaceshipTexture, "Textures/Spaceship.tga");
	TextureLoader::LoadTexture(mediumStarTexture, "Textures/StarMedium.tga");
	TextureLoader::LoadTexture(bigStarTexture, "Textures/StarBig.tga");

	Random::Seed();
	
	background = Background();
	spaceship = Spaceship();
	
	Instantiate(&spaceship);
}


void Game::FrameUpdate()
{
	for (int i = 0; i < instantiatedGameObjects.size(); i++)
	{
		instantiatedGameObjects[i]->FrameUpdate();
	}
}


void Game::FixedUpdate()
{
	for (int i = 0; i < instantiatedGameObjects.size(); i++)
	{
		instantiatedGameObjects[i]->FixedUpdate();
	}
}

void Game::Render()
{
	background.Render();

	for (int i = 0; i < instantiatedGameObjects.size(); i++)
	{
		glPushMatrix();
		glTranslatef(
			instantiatedGameObjects[i]->position.x - Screen::viewportPosition.x, 
			instantiatedGameObjects[i]->position.y - Screen::viewportPosition.y,
			0.0f);
		glRotatef(
			instantiatedGameObjects[i]->rotation, 
			0.0f, 
			0.0f, 
			1.0f);
		instantiatedGameObjects[i]->Render();
		glPopMatrix();
	}
}

void Game::Instantiate(GameObject* gameObject)
{
	Game::instantiatedGameObjects.push_back(gameObject);
}

//void Game::Destroy(GameObject gameObject)
//{
//	// TODO: Implement
//}
