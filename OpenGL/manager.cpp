
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "MyPolygon.h"

MyPolygon* g_polygon;

void CManager::Init()
{

	CRenderer::Init();
	g_polygon = new MyPolygon();
	Vector3 vec[4];
	vec[0] = Vector3(100.f, 100.0f, 0);
	vec[1] = Vector3(100.0f, 300.0f, 0);
	vec[2] = Vector3(300.0f, 100.0f, 0);
	vec[3] = Vector3(300.0f, 300.0f, 0);
	g_polygon->SetVertex(vec);
}

void CManager::Uninit()
{
	delete g_polygon;
	CRenderer::Uninit();
}

void CManager::Update()
{
	
}

void CManager::Draw()
{
	CRenderer::Begin();

	
	g_polygon->Draw();

	
	CRenderer::End();
}
