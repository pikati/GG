
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "MyPolygon.h"

MyPolygon* g_polygon;

void CManager::Init()
{

	CRenderer::Init();
	g_polygon = new MyPolygon();
	g_polygon->Initialize();

	Vertex2D ver[4];
	ver[0].position = Vector3(100.f, 100.0f, 0);
	ver[0].coordinate = Vector2(0.0f, 0.0f);
	ver[0].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	ver[1].position = Vector3(100.0f, 300.0f, 0);
	ver[1].coordinate = Vector2(0.0f, -1.0f);
	ver[1].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	ver[2].position = Vector3(300.0f, 100.0f, 0);
	ver[2].coordinate = Vector2(1.0f, 0.0f);
	ver[2].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	ver[3].position = Vector3(300.0f, 300.0f, 0);
	ver[3].coordinate = Vector2(1.0f, -1.0f);
	ver[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	
	g_polygon->SetVertex(ver);
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
