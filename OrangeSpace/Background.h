#pragma once
#include <GL/glut.h>
#include <sstream>
#include "Texture.h"
#include "TextureLoader.h"
#include "Random.h"
#include "Screen.h"
#include "BigStar.h"
#include "MediumStar.h"

class MediumStar;
class BigStar;

class Background
{
public:
	MediumStar * smallStars; 
	MediumStar * mediumStars;
	BigStar * bigStars;
	int nSmallStars;
	int nMediumStars;
	int nBigStars;

	Background();
	void Render();
};

