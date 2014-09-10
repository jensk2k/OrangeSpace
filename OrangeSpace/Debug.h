#pragma once
#include <string>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <sstream>
#include "Vector2.h"

class Debug
{
public:
	static void Init();
	static void PrintOnScreen(Vector2 pos, float r, float g, float b, std::string string);
	static void PrintFPS();
	static void Log(std::string message);
	static void Debug::Log(char * message);
	static void Log(std::stringstream message);
	// FPS counter
	//static int frame, time, timebase, fps;
};

