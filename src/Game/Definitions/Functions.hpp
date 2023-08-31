#pragma once
#include "Declaration.hpp"

using Com_PrintMessage_t = void(*)(int channel, const char* msg, int type);
using RB_EndSceneRendering_t = void(*)(GfxCmdBufInput* input, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf);

void Com_PrintMessage(int channel, const char* msg, int type);
void RB_EndSceneRendering(GfxCmdBufInput* input, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf);
