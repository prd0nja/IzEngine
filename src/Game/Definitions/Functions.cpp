#include "Functions.hpp"
#include "Game/Game.hpp"

Hook<void(int channel, const char* msg, int type)> 
	Com_PrintMessage_h(0x4FCA50, Com_PrintMessage);
Hook<void(bool isScoreboardVisible)>
	CG_DrawCrosshair_h(0x42F6B5, CG_DrawCrosshair);
Hook<void(GfxCmdBufInput* input, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf)> 
	RB_EndSceneRendering_h(0x6496EC, RB_EndSceneRendering);
Hook<IDirect3D9* STDCALL(UINT sdk)>
	R_Direct3DCreate9_h(0x670284, R_Direct3DCreate9);

void Com_PrintMessage(int channel, const char* msg, int type)
{
	Log::Write(channel, type, msg);
	Com_PrintMessage_h(channel, msg, type);
}

void CG_DrawCrosshair(bool isScoreboardVisible)
{
	SR->Render->Draw(isScoreboardVisible);
	CG_DrawCrosshair_h(isScoreboardVisible);
}

void RB_EndSceneRendering(GfxCmdBufInput* input, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf)
{
	SR->Render->Frame();
	RB_EndSceneRendering_h(input, viewInfo, src, buf);
}

IDirect3D9* STDCALL R_Direct3DCreate9(UINT sdk)
{
	IDirect3D9Ex* d3d9ex_device = nullptr;
	Log::WriteLine("Getting Direct3D 9 EX interface...");

	if (SUCCEEDED(Direct3DCreate9Ex(sdk, &d3d9ex_device)))
		return (new D3D9EX(d3d9ex_device));

	Log::WriteLine("Direct3D 9 EX failed to initialize. Defaulting to Direct3D 9.");
	return (new D3D9(Direct3DCreate9(sdk)));
}

void CG_AdjustFrom640(float* x, float* y, float* w, float* h)
{
	const float scaleX = static_cast<float>(cgs->refdef.width) / 640.0f;

	*x *= scaleX;
	*y *= scaleX;
	*w *= scaleX;
	*h *= scaleX;
}

void CG_FillRect(float x, float y, float w, float h, float color[4])
{
	if (!w || !h)
		return;

	CG_AdjustFrom640(&x, &y, &w, &h);

	const auto material = Material_RegisterHandle("white", 3);
	R_AddCmdDrawStretchPic(material, x, y, w, h, 0.0f, 0.0f, 0.0f, 0.0f, color);
}

void CG_FillAngleYaw(float start, float end, float yaw, float y, float h, float color[4])
{
	const range_t range = AnglesToRange(start, end, yaw);
	if (!range.split)
		CG_FillRect(range.x1, y, range.x2 - range.x1, h, color);
	else
	{
		CG_FillRect(0, y, range.x1, h, color);
		CG_FillRect(range.x2, y, SCREEN_WIDTH - range.x2, h, color);
	}
}

void CG_DrawLineYaw(float angle, float yaw, float y, float w, float h, float color[4])
{
	angle = angle_normalize_pi(angle - yaw);
	if (!AngleInFov(angle))
		return;

	float const x = AngleScreenProjection(angle);
	CG_FillRect(x - w / 2, y, w, h, color);
}

bool AngleInFov(float angle)
{
	float const half_fov_x = atanf(cgs->refdef.tanHalfFovX);
	return angle > -half_fov_x && angle < half_fov_x;
}

float AngleScreenProjection(float angle)
{
	float const half_fov_x = atanf(cgs->refdef.tanHalfFovX);

	if (angle >= half_fov_x)
		return 0;
	if (angle <= -half_fov_x)
		return SCREEN_WIDTH;

	return SCREEN_WIDTH / 2 * (1 - tanf(angle) / tanf(half_fov_x));
}

range_t AnglesToRange(float start, float end, float yaw)
{
	if (fabsf(end - start) > 2 * M_PI)
		return { 0, SCREEN_WIDTH, false };
	bool split = end > start;

	start = angle_normalize_pi(start - yaw);
	end = angle_normalize_pi(end - yaw);

	if (end > start)
	{
		split = !split;
		float const tmp = start;

		start = end;
		end = tmp;
	}
	return { AngleScreenProjection(start), AngleScreenProjection(end), split };
}
