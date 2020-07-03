#include "Cube.h"
#include "main.h"
#include "texture.h"

void Cube::Initialize()
{
	m_texture = LoadTexture("Asset\\Texture\\koyorichan.tga");
}

void Cube::Update()
{

}

void Cube::Draw()
{
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, m_texture);
	static float count = 0;
	glRotated(count += 2.0f, 1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);

	for (int i = 0; i < 22; i++)
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

void Cube::Finalize()
{
	UnloadTexture(m_texture);
}

void Cube::CreateCube()
{
	m_vertex[0].position = Vector3(0.0f, 0.0f, 0.0f);
	m_vertex[0].normal = Vector3(0.0f, 0.0f, -1.0f);
	m_vertex[0].coordinate = Vector2(0.0f, 0.0f);
	m_vertex[0].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	m_vertex[1].position = Vector3(0.0f, 50.0f, 0.0f);
	m_vertex[1].normal = Vector3(0.0f, 0.0f, -1.0f);
	m_vertex[1].coordinate = Vector2(0.0f, 1.0f);
	m_vertex[1].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	m_vertex[2].position = Vector3(50.0f, 0.0f, 0.0f);
	m_vertex[2].normal = Vector3(0.0f, 0.0f, -1.0f);
	m_vertex[2].coordinate = Vector2(1.0f, 0.0f);
	m_vertex[2].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	m_vertex[3].position = Vector3(50.0f, 50.0f, 0.0f);
	m_vertex[3].normal = Vector3(0.0f, 0.0f, -1.0f);
	m_vertex[3].coordinate = Vector2(1.0f, 1.0f);
	m_vertex[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	m_vertex[4].position = Vector3(50.0f, 0.0f, 50.0f);
	m_vertex[4].normal = Vector3(0.0f, 0.0f, -1.0f);
	m_vertex[4].coordinate = Vector2(0.0f, 0.0f);
	m_vertex[4].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	m_vertex[5].position = Vector3(50.0f, 50.0f, 50.0f);
	m_vertex[5].normal = Vector3(0.0f, 0.0f, -1.0f);
	m_vertex[5].coordinate = Vector2(0.0f, 1.0f);
	m_vertex[5].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	m_vertex[6].position = Vector3(0.0f, 0.0f, 50.0f);
	m_vertex[6].normal = Vector3(0.0f, 0.0f, -1.0f);
	m_vertex[6].coordinate = Vector2(1.0f, 0.0f);
	m_vertex[6].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	m_vertex[7].position = Vector3(0.0f, 50.0f, 50.0f);
	m_vertex[7].normal = Vector3(0.0f, 0.0f, -1.0f);
	m_vertex[7].coordinate = Vector2(1.0f, 1.0f);
	m_vertex[7].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	m_vertex[8] = m_vertex[0];

	m_vertex[9] = m_vertex[1];
	
	m_vertex[10] = m_vertex[1];
	
	m_vertex[11] = m_vertex[3];

	m_vertex[12] = m_vertex[3];
	m_vertex[12].coordinate = Vector2(0.0f, 1.0f);

	m_vertex[13] = m_vertex[1];
	m_vertex[13].coordinate = Vector2(0.0f, 0.0f);

	m_vertex[14] = m_vertex[5];
	m_vertex[14].coordinate = Vector2(1.0f, 1.0f);

	m_vertex[15] = m_vertex[7];
	m_vertex[15].coordinate = Vector2(1.0f, 0.0f);
	
	m_vertex[16] = m_vertex[7];

	m_vertex[17] = m_vertex[0];
	
	m_vertex[18] = m_vertex[0];
	m_vertex[18].coordinate = Vector2(0.0f, 0.0f);

	m_vertex[19] = m_vertex[2];
	m_vertex[19].coordinate = Vector2(0.0f, 1.0f);

	m_vertex[20] = m_vertex[6];
	m_vertex[20].coordinate = Vector2(1.0f, 0.0f);

	m_vertex[21] = m_vertex[4];
	m_vertex[21].coordinate = Vector2(1.0f, 1.0f);
}