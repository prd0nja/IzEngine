#pragma once
#include "Game/Plugin.hpp"

namespace IW3SR::Addons
{
	/// <summary>
	/// Draw lagometer.
	/// </summary>
	class Lagometer : public Module
	{
	public:
		vec4 PingColor;
		vec4 PacketColor;
		int Ping;
		int Packet;

		CircularBuffer<int, 1000> PingBuffer;
		CircularBuffer<int, 1000> PacketBuffer;
		Plots Graph;

		bool ShowPing;
		bool ShowPacket;
		bool ShowGraph;

		/// <summary>
		/// Create the module.
		/// </summary>
		Lagometer();
		virtual ~Lagometer() = default;

		/// <summary>
		/// Menu drawing.
		/// </summary>
		void OnMenu() override;

		/// <summary>
		/// Frame callback.
		/// </summary>
		void OnRender() override;

		NLOHMANN_SERIALIZE_POLY(Lagometer, Module, PingColor, PacketColor, Graph, ShowGraph);
	};
}
