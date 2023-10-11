#include "Functions.hpp"
#include "Game/Game.hpp"

Hook<HWND STDCALL(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName,
	DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu,
	HINSTANCE hInstance, LPVOID lpParam)>
	CreateWindowExA_h(CreateWindowExA, GUI::CreateMainWindow);

Hook<LRESULT CALLBACK(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)>
	MainWndProc_h(0x57BB20, GUI::MainWndProc);

Hook<void(int channel, const char* msg, int type)> 
	Com_PrintMessage_h(0x4FCA50, Log::Write);

Hook<void(bool scoreboard)>
	CG_DrawCrosshair_h(0x42F6B5, Render::Draw2D);

Hook<void(GfxCmdBufInput* input, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf)> 
	RB_EndSceneRendering_h(0x6496EC, Render::Draw3D);

Hook<IDirect3D9* STDCALL(UINT sdk)> 
	R_Direct3DCreate9_h(0x670284, D3D9::Direct3DCreate9);

void ScrPlace_ApplyRect(float& x, float& y, float& w, float& h,
	RectAlignHorizontal_t horizontal, RectAlignVertical_t vertical)
{
	switch (horizontal)
	{
	case HORIZONTAL_ALIGN_SUBLEFT:
		x = scr_place->scaleVirtualToReal[0] * x + scr_place->subScreenLeft;
		w = scr_place->scaleVirtualToReal[0] * w;
		break;
	case HORIZONTAL_ALIGN_LEFT:
		x = scr_place->scaleVirtualToReal[0] * x + scr_place->realViewableMin[0];
		w = scr_place->scaleVirtualToReal[0] * w;
		break;
	case HORIZONTAL_ALIGN_CENTER:
		x = scr_place->scaleVirtualToReal[0] * x + scr_place->realViewportSize[0] * 0.5f;
		w = scr_place->scaleVirtualToReal[0] * w;
		break;
	case HORIZONTAL_ALIGN_RIGHT:
		x = scr_place->scaleVirtualToReal[0] * x + scr_place->realViewableMax[0];
		w = scr_place->scaleVirtualToReal[0] * w;
		break;
	case HORIZONTAL_ALIGN_FULLSCREEN:
		x = scr_place->scaleVirtualToFull[0] * x;
		w = scr_place->scaleVirtualToFull[0] * w;
		break;
	case HORIZONTAL_ALIGN_TO640:
		x = scr_place->scaleRealToVirtual[0] * x;
		w = scr_place->scaleRealToVirtual[0] * w;
		break;
	case HORIZONTAL_ALIGN_CENTER_SAFEAREA:
		x = (scr_place->realViewableMax[0] + scr_place->realViewableMin[0]) * 0.5f 
			+ scr_place->scaleVirtualToReal[0] * x;
		w = scr_place->scaleVirtualToReal[0] * w;
		break;
	}
	switch (vertical)
	{
	case VERTICAL_ALIGN_TOP:
		y = scr_place->scaleVirtualToReal[1] * y + scr_place->realViewableMin[1];
		h = scr_place->scaleVirtualToReal[1] * h;
		break;
	case VERTICAL_ALIGN_CENTER:
		y = scr_place->scaleVirtualToReal[1] * y + scr_place->realViewportSize[1] * 0.5f;
		h = scr_place->scaleVirtualToReal[1] * h;
		break;
	case VERTICAL_ALIGN_BOTTOM:
		y = scr_place->scaleVirtualToReal[1] * y + scr_place->realViewableMax[1];
		h = scr_place->scaleVirtualToReal[1] * h;
		break;
	case VERTICAL_ALIGN_FULLSCREEN:
		y = scr_place->scaleVirtualToFull[1] * y;
		h = scr_place->scaleVirtualToFull[1] * h;
		break;
	case VERTICAL_ALIGN_TO480:
		y = scr_place->scaleRealToVirtual[1] * y;
		h = scr_place->scaleRealToVirtual[1] * h;
		break;
	case VERTICAL_ALIGN_CENTER_SAFEAREA:
		y = scr_place->scaleVirtualToReal[1] * y + (scr_place->realViewableMax[1] 
			+ scr_place->realViewableMin[1]) * 0.5f;
		h = scr_place->scaleVirtualToReal[1] * h;
		break;
	case VERTICAL_ALIGN_SUBTOP:
		y = scr_place->scaleVirtualToReal[1] * y;
		h = scr_place->scaleVirtualToReal[1] * h;
		break;
	}
}
