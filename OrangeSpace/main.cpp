/*
* GL10MouseControl.cpp: A mouse-controlled bouncing ball
*/
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <Math.h>     // Needed for sin, cos
#include <iostream>
#include <sstream>
#include <string>
#include "Vector2.h"
#include "Debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Screen.h"
#include "Input.h"
// Global variables

int refreshMillis = 30;      // Refresh period in milliseconds

// Projection clipping area
GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

bool fullScreenMode = false; // Full-screen or windowed mode?

bool printScreenInfo = true;

/* Callback handler for window re-paint event */
void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
	glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix
	glLoadIdentity();              // Reset model-view matrix
	
	Game::Render();

	// Render mouse cursor
	glPushMatrix();
	glBegin(GL_POLYGON);

	Vector2 cursorTopLeft = Screen::PixelToScreenSpace(Vector2(Game::cursorPosition.x - 2, Game::cursorPosition.y - 2));
	Vector2 cursorBottomRight = Screen::PixelToScreenSpace(Vector2(Game::cursorPosition.x + 2, Game::cursorPosition.y + 2));

	glVertex2f(cursorTopLeft.x, cursorTopLeft.y);
	glVertex2f(cursorBottomRight.x, cursorTopLeft.y);
	glVertex2f(cursorBottomRight.x, cursorBottomRight.y);
	glVertex2f(cursorTopLeft.x, cursorBottomRight.y);

	glEnd();
	glPopMatrix();


	Debug::PrintFPS(); // Print frames per second in the upper right corner

	Game::FrameUpdate();

	glutSwapBuffers();  // Swap front and back buffers (of double buffered mode)
}

/* Call back when the windows is re-sized */
void reshape(GLsizei width, GLsizei height) 
{
	if (!fullScreenMode)
	{
		glutReshapeWindow(Screen::width, Screen::height);
	}
	else
	{
		glutFullScreen();
	}

	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0

	Screen::aspectRatio = (float)width / (float)height;

	if (printScreenInfo)
	{
		std::stringstream ss;
		ss << "Screen: AR: " << Screen::aspectRatio << " Res: " << width << "x" << height << std::endl;
		Debug::Log(ss.str());

		printScreenInfo = false;
	}

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset the projection matrix

	clipAreaXLeft = -1.0 * Screen::aspectRatio;
	clipAreaXRight = 1.0 * Screen::aspectRatio;
	clipAreaYBottom = -1.0;
	clipAreaYTop = 1.0;

	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
}

/* Called back when the timer expired */
void timer(int value) {
	glutPostRedisplay();    // Post a paint request to activate display()
	Game::FixedUpdate();
	glutTimerFunc(refreshMillis, timer, 0); // subsequent timer call at milliseconds
}

/* Callback handler for special-key event */
void specialKeys(int key, int x, int y) 
{
	switch (key) 
	{
	case GLUT_KEY_F1:    // F1: Toggle between full-screen and windowed mode
		fullScreenMode = !fullScreenMode;         // Toggle state
		if (fullScreenMode)
		{
			Screen::width = 1920.0f;
			Screen::height = 1200.0f;
		}
		else
		{
			Screen::width = 1280.0f;
			Screen::height = 720.0f;
		}
		printScreenInfo = true;
		break;
	case GLUT_KEY_RIGHT:
		Screen::viewportPosition.x += 0.1f;
		break;
	case GLUT_KEY_LEFT:
		Screen::viewportPosition.x -= 0.1f;
		break;
	case GLUT_KEY_UP:
		Screen::viewportPosition.y += 0.1f;
		break;
	case GLUT_KEY_DOWN:
		Screen::viewportPosition.y -= 0.1f;
		break;
	}

	std::stringstream ss;
	ss << "viewportPosition: " << Screen::viewportPosition.x << ", " << Screen::viewportPosition.y;
	Debug::Log(ss.str());
}

/* Callback handler for mouse event */
void mouse(int button, int state, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
		std::stringstream ss;
		ss << "mouse: " << x << ", " << y << std::endl;
		Debug::Log(ss.str());
	}
}

void mouseMotion(int x, int y)
{
	/*std::stringstream ss;
	ss << "mouse: " << x << ", " << y << std::endl;
	Debug::Log(ss.str());*/

	Game::cursorPosition.Set(x, y);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) 
{
	//Game::cursorPosition = Vector2();

	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(Screen::width, Screen::height);  // Initial window width and height
	glutInitWindowPosition(0.0f, 0.0f); // Initial window top-left corner (x, y)

	glutCreateWindow("Project: Too Much Free Time");      // Create window with given title

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glutDisplayFunc(display);     // Register callback handler for window re-paint
	glutReshapeFunc(reshape);     // Register callback handler for window re-shape
	glutTimerFunc(0, timer, 0);   // First timer call immediately
	glutSpecialFunc(specialKeys); // Register callback handler for special-key event
	glutKeyboardFunc(Input::keyboardDownFunc);   // Register callback handler for special-key event
	glutKeyboardUpFunc(Input::keyboardUpFunc);
	//glutFullScreen();             // Put into full screen
	glutMouseFunc(mouse);   // Register callback handler for mouse event
	glutPassiveMotionFunc(mouseMotion);
	glutMotionFunc(mouseMotion);
	glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
	Game::Init();
	glutMainLoop();               // Enter event-processing loop
	return 0;
}

