#include "Spaceship.h"

//bool LoadTGA(Texture *, char *);								// Function Prototype For LoadTGA ( NEW )
Spaceship::Spaceship()
{
	//position.x = 0.5f;
	//texture = ImageLoader::LoadPNG("D:/Asteroids/Spaceship.tga", 16, 16);
	
	/*bool loadedTexture = LoadTGA(&texture, "D:/Asteroids/Spaceship.tga");
	std::stringstream ss;
	ss << "Texture loaded: " << loadedTexture << std::endl;

	Debug::Log(ss.str());

	// Typical Texture Generation Using Data From The TGA ( CHANGE )
	glGenTextures(1, &texture.texID);				// Create The Texture ( CHANGE )
	glBindTexture(GL_TEXTURE_2D, texture.texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.width, texture.height, 0, texture.type, GL_UNSIGNED_BYTE, texture.imageData);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width, tex.height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, tex.imageData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (texture.imageData)						// If Texture Image Exists ( CHANGE )
	{
		free(texture.imageData);					// Free The Texture Image Memory ( CHANGE )
	}*/
	//texture = &Game::spaceshipTex;
	//texture = new Texture();
	//TextureLoader::LoadTexture(texture, "Textures/Spaceship.tga");

	texture = Game::spaceshipTexture;
}


Spaceship::~Spaceship()
{
}

void Spaceship::FrameUpdate()
{
	Vector2 cursorInScreenSpace = Screen::PixelToScreenSpace(Game::cursorPosition);

	Vector2 directionToCursor = cursorInScreenSpace - position;
	rotation = Angle(directionToCursor);
	//rotation += 1.0f;
}

void Spaceship::FixedUpdate()
{
	
}

void Spaceship::Render()
{
	//Debug::Log("Spaceship render");
	/*glBegin(GL_POLYGON); // These vertices form a closed polygon
	glColor3f(1.0f, 1.0f, 1.0f); // Yellow
	glVertex2f(-0.1f, 0.1f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(-0.1f, -0.1f);
	glEnd();*/

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture->texID);

	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
	glVertex2f(0.2f, -0.2f);
	glTexCoord2f(1.0, 0.0);

	glVertex2f(-0.2f, -0.2f);
	glTexCoord2f(0.0, 0.0);

	glVertex2f(-0.2f, 0.2f);
	glTexCoord2f(0.0, 1.0);

	glVertex2f(0.2f, 0.2f);
	glTexCoord2f(1.0, 1.0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}
