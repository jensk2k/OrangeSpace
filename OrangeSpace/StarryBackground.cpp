#include "StarryBackground.h"


StarryBackground::StarryBackground()
{
	glClearColor(0.8, 0.2, 0.0, 1.0); // Set background (clear) color to black

	nSmallStars = 2000;

	smallStars = new MediumStar[nSmallStars];
	for (int i = 0; i < nSmallStars; i++)
	{
		smallStars[i] = MediumStar();
		smallStars[i].position = Vector2(Random::Range(-1.8f, 1.8f), Random::Range(-1.0, 1.0));

		float scale = Random::Range(0.01F, 0.05F);
		smallStars[i].scale = Vector2(scale, scale);
	}


	nMediumStars = 100;

	mediumStars = new MediumStar[nMediumStars];
	for (int i = 0; i < nMediumStars; i++)
	{
		mediumStars[i] = MediumStar();
		mediumStars[i].position = Vector2(Random::Range(-1.8f, 1.8f), Random::Range(-1.0, 1.0));

		float scale = Random::Range(0.1F, 0.2F);
		mediumStars[i].scale = Vector2(scale, scale);
	}


	nBigStars = 25;

	bigStars = new BigStar[nBigStars];
	for (int i = 0; i < nBigStars; i++)
	{
		bigStars[i] = BigStar();
		bigStars[i].position = Vector2(Random::Range(-1.8f, 1.8f), Random::Range(-1.0, 1.0));

		float scale = Random::Range(0.3F, 0.6F);
		bigStars[i].scale = Vector2(scale, scale);
	}
}


StarryBackground::~StarryBackground()
{
}

void StarryBackground::Render()
{
	for (int i = 0; i < nSmallStars; i++)
	{
		smallStars[i].Render();
	}

	for (int i = 0; i < nMediumStars; i++)
	{
		mediumStars[i].Render();
	}

	for (int i = 0; i < nBigStars; i++)
	{
		bigStars[i].Render();
	}
}
