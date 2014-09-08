#include "TextureLoader.h"

bool TextureLoader::LoadTexture(Texture* texture, char * filePath)
{
	std::stringstream ss;
	bool loadedTexture = LoadTGA(texture, filePath);
	if (loadedTexture)
	{
		ss << "Texture loaded: " << filePath << std::endl;
		Debug::Log(ss.str());
	}
	else
	{
		ss << "Texture didn't load: " << filePath << std::endl;
		Debug::Log(ss.str());
	}


	// Typical Texture Generation Using Data From The TGA ( CHANGE )
	glGenTextures(1, &texture->texID);				// Create The Texture ( CHANGE )
	glBindTexture(GL_TEXTURE_2D, texture->texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, texture->type, GL_UNSIGNED_BYTE, texture->imageData);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.width, tex.height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, tex.imageData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (texture->imageData)						// If Texture Image Exists ( CHANGE )
	{
		free(texture->imageData);					// Free The Texture Image Memory ( CHANGE )
	}

	return loadedTexture;
}