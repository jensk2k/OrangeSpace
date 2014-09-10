#pragma once
#include <GL/glut.h>
#include <math.h>
#include <sstream>
#include "Vector2.h"
#include "Debug.h"
class Screen
{
public:
	static int width, height;
	static float aspectRatio;
	static Vector2 viewportPosition;

	static Vector2 PixelToScreenSpace(Vector2 position);
	static void RenderGrid();
	static void RenderGridPoint(Vector2 point);
};

