#include "Feature.hpp"

namespace IW3SR::Game
{
	Feature::Feature(const std::string& id, const std::string& name, const std::string& group)
	{
		ID = id;
		Name = name;
		Group = group;
		Menu = Window(name);
	}

	Feature::~Feature()
	{
		Release();
	}

	void Feature::Initialize() { }
	void Feature::Release() { }

	void Feature::OnMenu() { }
	void Feature::OnDraw3D() { }
	void Feature::OnDraw3D(GfxCmdBufInput* cmd, GfxViewInfo* viewInfo, GfxCmdBufSourceState* src, GfxCmdBufState* buf) { }
	void Feature::OnDraw2D() { }
	void Feature::OnRender() { }
}
