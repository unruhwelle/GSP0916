#pragma once

#include <Windows.h>
#include "d3dinclude.h"

class System
{
public:

	void Init();
	int Run();

private:
	void InitWindow();
	void InitGraphics();

	// Window
	HWND m_Window;

	// DirectX
	IDXGISwapChain* m_pSwapChain;

	ID3D11Device* m_pGraphicsDevice; // Buffer erstellen/Meshes generieren
	ID3D11DeviceContext* m_pDeviceContext; // W�rfel Rendern

	ID3D11RenderTargetView* m_pScreen;
};
