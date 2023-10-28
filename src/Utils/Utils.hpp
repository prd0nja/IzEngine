#pragma once

namespace IW3SR
{
	/// <summary>
	/// Utility class.
	/// </summary>
	class Utils
	{
	public:
		/// <summary>
		/// Is debug build.
		/// </summary>
		/// <returns></returns>
		static bool IsDebug();

		/// <summary>
		/// Is private build.
		/// </summary>
		/// <returns></returns>
		static bool IsPrivate();
	};
}
