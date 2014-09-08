#include "Debug.h"

int frame = 0;
int time = 0;
int timebase = 0;
float fps = 0;

void Debug::PrintOnScreen(Vector2 pos, float r, float g, float b, std::string string)
{
	glColor3f(r, g, b);
	glRasterPos2f(pos.x, pos.y);
	int len, i;
	len = (int)strlen(string.c_str());
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}


void Debug::PrintFPS()
{
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 500)
	{
		fps = frame * 1000.0 / (time - timebase);
		timebase = time;
		frame = 0.0f;

		fps = roundf(fps * 10) / 10;  // Get one decimal
	}

	std::stringstream ss;
	ss << fps << " FPS";

	float aspectRatio = 16.0f / 9.0f; // Redundant

	Vector2 screenPosition(0.85f * aspectRatio, 0.95f);

	PrintOnScreen(screenPosition, 1.0f, 1.0f, 1.0f, ss.str());
}

void Debug::Log(std::string message)
{
	std::cout << message << std::endl;
}
