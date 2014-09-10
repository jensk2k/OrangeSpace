#include "Input.h"
bool Input::keyStatuses[4] = {};
bool Input::KeyHold(Key key)
{
	return keyStatuses[key];
}

/* Callback handler for normal-key event */
void Input::keyboardDownFunc(unsigned char key, int x, int y)
{
	//std::stringstream ss;
	//ss << "Key: " << key << std::endl;
	//Debug::Log(ss.str());

	switch (key) 
	{
	case 27:     // ESC key
		exit(EXIT_SUCCESS);
		break;
	case 'w':
		Input::keyStatuses[Key::W] = true;
		break;
	case 'a':
		Input::keyStatuses[Key::A] = true;
		break;
	case 's':
		Input::keyStatuses[Key::S] = true;
		break;
	case 'd':
		Input::keyStatuses[Key::D] = true;
		break;
	}
}

/* Callback handler for normal-key event */
void Input::keyboardUpFunc(unsigned char key, int x, int y)
{
	//std::stringstream ss;
	//ss << "Key: " << key << std::endl;
	//Debug::Log(ss.str());

	switch (key) 
	{
	case 'w':
		Input::keyStatuses[Key::W] = false;
		break;
	case 'a':
		Input::keyStatuses[Key::A] = false;
		break;
	case 's':
		Input::keyStatuses[Key::S] = false;
		break;
	case 'd':
		Input::keyStatuses[Key::D] = false;
		break;
	}
}