#include "MyPolygon.h"
#include "texture.h"
#include "main.h"
#include <iostream>

void MyPolygon::Initialize()
{
	m_texture = LoadTexture("Asset\\Texture\\texture.tga");
}

void MyPolygon::Update()
{

}

void MyPolygon::Draw()
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-1.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glBindTexture(GL_TEXTURE_2D, m_texture);

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < 4; i++)
	{
		glTexCoord2f(m_vertex[i].coordinate.x, m_vertex[i].coordinate.y);
		glColor4f(m_vertex[i].color.x, m_vertex[i].color.y, m_vertex[i].color.z, m_vertex[i].color.w);
		glVertex3f(m_vertex[i].position.x, m_vertex[i].position.y, m_vertex[i].position.z);
	}
	glEnd();

	glBindTexture(GL_TEXTURE_2D, NULL);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_LIGHTING);
}

void MyPolygon::Finalize()
{
	UnloadTexture(m_texture);
}

void MyPolygon::SetVertex(Vertex2D vec[4])
{
	m_vertex[0] = vec[0];
	m_vertex[1] = vec[1];
	m_vertex[2] = vec[2];
	m_vertex[3] = vec[3];
}