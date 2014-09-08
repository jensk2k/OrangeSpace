#pragma once
#include <vector>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include "Debug.h"
#include "Vector2.h"
#include "Component.h"
#include "Texture.h"

class GameObject
{
public:
	std::vector<Component> components;
	Texture * texture;
	Vector2 position;
	Vector2 scale;
	float rotation;

	GameObject();
	~GameObject();
	
	virtual void FrameUpdate();
	virtual void FixedUpdate();
	virtual void Render();
};

