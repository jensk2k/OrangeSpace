#pragma once
#include "Background.h"
#include <GL/glut.h>
#include <sstream>
#include "Texture.h"
#include "TextureLoader.h"
#include "Random.h"
#include "Screen.h"
#include "BigStar.h"
#include "MediumStar.h"

class BigStar;
class MediumStar;

class StarryBackground :
	public Background
{
public:
	int nSmallStars;
	int nMediumStars;
	int nBigStars;
	MediumStar * smallStars;
	MediumStar * mediumStars;
	BigStar * bigStars;

	StarryBackground();
	~StarryBackground();

	virtual void Render();
};

