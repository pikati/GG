#pragma once
class CRenderer
{
private:
	static HWND m_hwnd;
	static HDC m_dc;
	static HGLRC m_rc;
public:
	static void Init();
	static void Uninit();
	static void Begin();
	static void End();
};
