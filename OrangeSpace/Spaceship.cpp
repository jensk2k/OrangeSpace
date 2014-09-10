#include "Spaceship.h"
Spaceship::Spaceship()
{

	texture = Game::spaceshipTexture;
}


Spaceship::~Spaceship()
{
}

void Spaceship::FrameUpdate()
{
	Vector2 cursorInScreenSpace = Screen::PixelToScreenSpace(Game::cursorPosition) + Screen::viewportPosition;

	Vector2 directionToCursor = cursorInScreenSpace - position;
	rotation = Angle(directionToCursor);

	//float acceleration = 0.01f;
	Vector2 acceleration = Vector2(0.f, 0.f);

	if (Input::KeyHold(Key::W))
	{
		//velocity.y += acceleration;
		acceleration.y = 1.f;
	}
	if (Input::KeyHold(Key::A))
	{
		//velocity.x -= acceleration;
		acceleration.x = -1.f;
	}
	if (Input::KeyHold(Key::S))
	{
		//velocity.y -= acceleration;
		acceleration.y = -1.f;
	}
	if (Input::KeyHold(Key::D))
	{
		//velocity.x += acceleration;
		acceleration.x = 1.f;
	}

	acceleration.Normalize();

	acceleration *= 0.01f;

	velocity += acceleration;

	//std::stringstream ss;
	//ss << "velocity: " << velocity.x << "," << velocity.y << std::endl;
	//ss << "acceleration: " << acceleration.x << "," << acceleration.y << std::endl;
	//Debug::Log(ss.str());
	
	position += velocity * Game::deltaTime;

	Screen::viewportPosition = position;
}

void Spaceship::FixedUpdate()
{
	/*std::stringstream ss;
	ss << "W: " << Input::KeyHold(Key::W) << std::endl;
	Debug::Log(ss.str());*/

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

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(0.125f, -0.1f);
	glTexCoord2f(1.0, 0.0);

	glVertex2f(-0.075f, -0.1f);
	glTexCoord2f(0.0, 0.0);

	glVertex2f(-0.075f, 0.1f);
	glTexCoord2f(0.0, 1.0);

	glVertex2f(0.125f, 0.1f);
	glTexCoord2f(1.0, 1.0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}
