#include "Game.h"

//std::vector<GameObject*> Game::instantiatedGameObjects;
Vector2 Game::cursorPosition = Vector2();
//Level * Game::currentLevel = NULL;
//Background background;
float Game::time = .0f;
float Game::deltaTime = .0f;

void Game::Init()
{

	Random::Seed();
	GameSetup::Init();
}


void Game::FrameUpdate()
{
	for (int i = 0; i < currentLevel->instantiatedGameObjects.size(); i++)
	{
		currentLevel->instantiatedGameObjects[i]->FrameUpdate();
	}
}


void Game::FixedUpdate()
{
	for (int i = 0; i < currentLevel->instantiatedGameObjects.size(); i++)
	{
		currentLevel->instantiatedGameObjects[i]->FixedUpdate();
	}
}

void Game::Render()
{
	// Update
	Game::deltaTime = (glutGet(GLUT_ELAPSED_TIME) / 1000.f) - Game::time;
	Game::time = time = glutGet(GLUT_ELAPSED_TIME) / 1000.f;

	//std::stringstream ss;
	//ss << "Delta time: " << Game::deltaTime << std::endl;
	//Debug::Log(ss.str());


	//background.Render();
	Game::currentLevel->background->Render();

	for (int i = 0; i < currentLevel->instantiatedGameObjects.size(); i++)
	{
		glPushMatrix();
		glTranslatef(
			currentLevel->instantiatedGameObjects[i]->position.x - Screen::viewportPosition.x,
			currentLevel->instantiatedGameObjects[i]->position.y - Screen::viewportPosition.y,
			0.0f);
		glRotatef(
			currentLevel->instantiatedGameObjects[i]->rotation,
			0.0f, 
			0.0f, 
			1.0f);
		currentLevel->instantiatedGameObjects[i]->Render();
		glPopMatrix();
	}

	Screen::RenderGrid();
}

void Game::Instantiate(GameObject* gameObject)
{
	currentLevel->instantiatedGameObjects.push_back(gameObject);
}

//void Game::Destroy(GameObject gameObject)
//{
//	// TODO: Implement
//}
