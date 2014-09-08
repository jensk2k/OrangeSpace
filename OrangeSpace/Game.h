#pragma once
#include <vector>
#include "GameObject.h"
#include "Spaceship.h"
#include "Vector2.h"
#include "Background.h"
#include "TextureLoader.h"
class Game
{
public:
	static std::vector<GameObject*> instantiatedGameObjects;
	static Vector2 cursorPosition;
	static Texture * spaceshipTexture;
	static Texture * mediumStarTexture;
	static Texture * bigStarTexture;
	static void Init();
	static void FrameUpdate();
	static void FixedUpdate();
	static void Render();
	static void Instantiate(GameObject* gameObject);
	static void Destroy(GameObject gameObject);
};

