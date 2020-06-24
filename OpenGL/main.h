#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <assert.h>



#pragma warning(push)
#pragma warning(disable:4005)

#include <GL/gl.h>
#include <GL/glu.h>

#pragma warning(pop)

#pragma comment (lib, "winmm.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")


#define SCREEN_WIDTH	(960)			// ウインドウの幅
#define SCREEN_HEIGHT	(540)			// ウインドウの高さ

#define SAFE_RELEASE(p) do { if(p){ (p)->Release(); (p) = NULL;} } while(0)


HWND GetWindow();
