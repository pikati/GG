#include "main.h"
#include "Field.h"
#include "texture.h"

void Field::Initialize()
{
	m_texture = LoadTexture("Asset\\Texture\\koyorichan.tga");
}

void Field::Update()
{
	
}

void Field::Draw()
{
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	m_vertex[0].position = Vector3(-20.0f, 0.0f, -10.0f);
	m_vertex[1].position = Vector3(20.0f, 0.0f, -10.0f);
	m_vertex[2].position = Vector3(-20.0f, 0.0f, -110.0f);
	m_vertex[3].position = Vector3(20.0f, 0.0f, -110.0f);
	m_vertex[0].coordinate = Vector2(0.0f, 0.0f);
	m_vertex[1].coordinate = Vector2(0.0f, -1.0f);
	m_vertex[2].coordinate = Vector2(1.0f, 0.0f);
	m_vertex[3].coordinate = Vector2(1.0f, -1.0f);
	m_vertex[0].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	m_vertex[1].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	m_vertex[2].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	m_vertex[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	
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

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_LIGHTING);
}

void Field::Finalize()
{
	UnloadTexture(m_texture);
}