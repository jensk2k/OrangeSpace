#pragma once
#include <vector>
#include <string>
#include "GameObject.h"
#include "Background.h"
#include "StarryBackground.h"
class Level
{
public:
	std::string title;
	std::vector<GameObject*> instantiatedGameObjects;
	Background * background;
	Level(std::string);
	~Level();
};

