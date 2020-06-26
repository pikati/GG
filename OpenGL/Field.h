#pragma once
#include "Engine.h"

class Field
{
private :
	int m_texture;
	Vertex2D m_vertex[4];
public:
	void Initialize();
	void Update();
	void Draw();
	void Finalize();
};

