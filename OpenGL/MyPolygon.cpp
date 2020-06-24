#include "MyPolygon.h"
#include "texture.h"
#include "main.h"
#include <iostream>

void MyPolygon::Initialize()
{
	m_texture = LoadTexture("Asset\\Texture\\exture.tga");
}

void MyPolygon::Update()
{

}

void MyPolygon::Draw()
{

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-1.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glBindTexture(GL_TEXTURE_2D, m_texture);
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0, 0, 1);

	for (int i = 0; i < 4; i++)
	{
		glVertex3f(m_vertex[i].x, m_vertex[i].y, m_vertex[i].z);
	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, NULL);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void MyPolygon::Finalize()
{
	UnloadTexture(m_texture);
}

void MyPolygon::SetVertex(Vector3 vec[4])
{
	m_vertex[0] = vec[0];
	m_vertex[1] = vec[1];
	m_vertex[2] = vec[2];
	m_vertex[3] = vec[3];
}