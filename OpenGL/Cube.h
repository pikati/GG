#pragma once
#include "Engine.h"

class Cube
{
private:
	Vertex2D m_vertex[22];
	unsigned int m_texture;
public:
	void Initialize();
	void Update();
	void Draw();
	void Finalize();

	void CreateCube();
};

