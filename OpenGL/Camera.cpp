#include "Camera.h"
#include "main.h"
void Camera::Initialize()
{
	m_position = Vector3(0.0f, 25.0f, -200.0f);
	m_target = Vector3(0.0f, 0.0f, 0.0f);
}

void Camera::Update()
{

}

void Camera::Draw()
{
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)SCREEN_WIDTH / (double)SCREEN_HEIGHT, 1.0, 200.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt((double)m_position.x, (double)m_position.y, (double)m_position.z, (double)m_target.x, (double)m_target.y, (double)m_target.z, 0.0, 1.0, 0.0);
}

void Camera::Finalize()
{

}