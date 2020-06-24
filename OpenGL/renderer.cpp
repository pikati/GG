#include "main.h"
#include "renderer.h"
#include <io.h>

HDC CRenderer::m_dc = nullptr;
HWND CRenderer::m_hwnd = nullptr;
HGLRC CRenderer::m_rc = nullptr;

void CRenderer::Init()
{
	/* PIXEL FORMAT */
	PIXELFORMATDESCRIPTOR descriptor;

	// Clear all structure fields to zero first
	ZeroMemory(&descriptor, sizeof(descriptor));

	// Describe our pixel format
	descriptor.nSize = sizeof(descriptor);
	descriptor.nVersion = 1;
	descriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DRAW_TO_BITMAP | PFD_SUPPORT_OPENGL | PFD_GENERIC_ACCELERATED | PFD_DOUBLEBUFFER | PFD_SWAP_LAYER_BUFFERS;
	descriptor.iPixelType = PFD_TYPE_RGBA;
	descriptor.cColorBits = 32;
	descriptor.cRedBits = 8;
	descriptor.cGreenBits = 8;
	descriptor.cBlueBits = 8;
	descriptor.cAlphaBits = 8;
	descriptor.cDepthBits = 32;
	descriptor.cStencilBits = 8;

	// Ask for a similar supported format and set it
	m_hwnd = GetWindow();
	m_dc = GetDC(m_hwnd);
	int pixel_format = ChoosePixelFormat(m_dc, &descriptor);
	SetPixelFormat(m_dc, pixel_format, &descriptor);

	m_rc = wglCreateContext(m_dc);
	
	wglMakeCurrent(m_dc, m_rc);

	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
}



void CRenderer::Uninit()
{
	wglMakeCurrent(nullptr, nullptr);
	if (m_dc)
	{
		ReleaseDC(m_hwnd, m_dc);
		m_dc = NULL;
	}
	if (m_rc)
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_rc);
		m_rc = NULL;
	}
}



void CRenderer::Begin()
{
	glClearColor(0, 1, 0, 1);
	glClearDepth(1.0f);
	glClearStencil( 0 );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}



void CRenderer::End()
{
	SwapBuffers(m_dc);
}