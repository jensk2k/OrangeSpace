#include "Screen.h"

int Screen::width = 1280;
int Screen::height = 720;
float Screen::aspectRatio = Screen::width / Screen::height;
Vector2 Screen::viewportPosition = Vector2(0.0f, 0.0f);

Vector2 Screen::PixelToScreenSpace(Vector2 position)
{
	float x = (((position.x / Screen::width) * 2.0f) - 1.0f) * Screen::aspectRatio;
	float y = ((position.y / Screen::height) * -2.0f) + 1.0f;

	return Vector2(x, y);
}

void Screen::RenderGrid()
{
	Vector2 roundedViewportPosition = Vector2(roundf(viewportPosition.x), roundf(viewportPosition.y));

	float gridResolution = 0.5f;

	for (int y = -10; y < 10; y++)
	{
		for (int x = -10; x < 10; x++)
		{
			Vector2 gridPoint = ((Vector2(x, y) * gridResolution) + roundedViewportPosition) - viewportPosition;
			Screen::RenderGridPoint(gridPoint);
		}
	}
}

void Screen::RenderGridPoint(Vector2 point)
{
	glPushMatrix();
	glTranslatef(point.x, point.y, 0.0f);

	glLineWidth(2.);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-0.02, 0.0, 0.0);
	glVertex3f(0.02, 0, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.02, 0.0);
	glVertex3f(0.0, -0.02, 0);
	glEnd();
	glPopMatrix();
}