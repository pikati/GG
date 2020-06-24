#pragma once
#include "Engine.h"

class MyPolygon
{
private:
	Vector3 m_vertex[4];
	unsigned int m_texture;
public:
	void Initialize();
	void Update();
	void Draw();
	void Finalize();

	void SetVertex(Vector3* vec);
};

