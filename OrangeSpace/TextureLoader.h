#pragma once
#include <GL/glut.h>
#include <string>
#include <sstream>
//#include "TGALoader.h"
#include "Debug.h"
#include "Texture.h"
class TextureLoader
{
public:
	static bool TextureLoader::LoadTexture(Texture* texture, char * filePath);

/*private:
	static bool LoadTGA(Texture *, char *);*/

};

bool LoadTGA(Texture *, char *);								// Function Prototype For LoadTGA ( NEW )

