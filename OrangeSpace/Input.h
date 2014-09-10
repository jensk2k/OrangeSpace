#pragma once
#include <stdlib.h>     /* exit, EXIT_FAILURE */
enum Key
{
	W, 
	A,
	S,
	D
};

class Input
{
public:
	static void keyboardDownFunc(unsigned char key, int x, int y);
	static void keyboardUpFunc(unsigned char key, int x, int y);
	static bool KeyHold(Key key);
//private:
	static bool keyStatuses[4];
};

