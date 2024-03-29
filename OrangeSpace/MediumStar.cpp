#include "MediumStar.h"


MediumStar::MediumStar()
{
	//TextureLoader::LoadTexture(texture, "Textures/StarMedium.tga");
	texture = GameSetup::mediumStarTexture;
}


MediumStar::~MediumStar()
{
}

void MediumStar::Render()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, 0.0F);
	glScalef(scale.x, scale.y, 1.0F);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture->texID);

	glBegin(GL_QUADS);
	glVertex2f(0.1f, -0.1f);
	glTexCoord2f(1.0, 0.0);

	glVertex2f(-0.1f, -0.1f);
	glTexCoord2f(0.0, 0.0);

	glVertex2f(-0.1f, 0.1f);
	glTexCoord2f(0.0, 1.0);

	glVertex2f(0.1f, 0.1f);
	glTexCoord2f(1.0, 1.0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
