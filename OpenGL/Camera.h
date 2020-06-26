#pragma once
#include "Engine.h"
class Camera
{
private:
	Vector3 m_position;
	Vector3 m_target;
public:
	void Initialize();
	void Update();
	void Draw();
	void Finalize();
};

