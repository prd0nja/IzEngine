#pragma once
#include "ImGUI/Base.hpp"

namespace IzEngine
{
	/// <summary>
	/// Notification center.
	/// </summary>
	class API Notifications
	{
	private:
		/// <summary>
		/// Notification data.
		/// </summary>
		struct Notification
		{
			std::string message;
			double time;
		};

	public:
		static inline std::vector<Notification> List;

		/// <summary>
		/// Create a notification.
		/// </summary>
		/// <param name="msg">The message.</param>
		static void Push(const std::string& msg);

		/// <summary>
		/// Render the notifications.
		/// </summary>
		static void Render();
	};
}
