#pragma once
#include "Engine.h"

class MyPolygon
{
private:
	Vertex2D m_vertex[4];
	unsigned int m_texture;
public:
	void Initialize();
	void Update();
	void Draw();
	void Finalize();

	void SetVertex(Vertex2D* vec);
};

