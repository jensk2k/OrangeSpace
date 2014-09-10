#pragma once
class Component
{
public:
	Component();
	~Component();

	virtual void FixedUpdate();
	virtual void FrameUpdate();
};

