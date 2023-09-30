#include "Functions.hpp"
#include "Game/Game.hpp"

Hook<void(int channel, const char* msg, int type)> 
	Com_PrintMessage_h(0x4FCA50, Com_PrintMessage);
Hook<void(GfxCmdBufInput* input, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf)> 
	RB_EndSceneRendering_h(0x6496EC, RB_EndSceneRendering);
Hook<IDirect3D9* STDCALL(UINT sdk)>
	direct3d_create9_h(0x69142C, direct3d_create9);

void Com_PrintMessage(int channel, const char* msg, int type)
{
	Log::Write(channel, type, msg);
	Com_PrintMessage_h(channel, msg, type);
}

void RB_EndSceneRendering(GfxCmdBufInput* input, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf)
{
	// RB_DrawDebug(viewParms);
	RB_EndSceneRendering_h(input, viewInfo, src, buf);
}

IDirect3D9* STDCALL direct3d_create9(UINT sdk)
{
	IDirect3D9Ex* d3d9ex_device = nullptr;

	if (SUCCEEDED(Direct3DCreate9Ex(sdk, &d3d9ex_device)))
	{
		return (new D3D9EX(d3d9ex_device));
	}
	Log::WriteLine("Direct3D9Ex failed to initialize. Defaulting to Direct3D9.");

	return (new D3D9(Direct3DCreate9(sdk)));
}
