#include "GameObject.h"


GameObject::GameObject()
{
	rotation = 0.0f;
	scale = Vector2(1.0f, 1.0f);
}


GameObject::~GameObject()
{
}

void GameObject::FrameUpdate()
{

}

void GameObject::FixedUpdate()
{

}

void GameObject::Render()
{
	Debug::Log("Rendering game object");
}