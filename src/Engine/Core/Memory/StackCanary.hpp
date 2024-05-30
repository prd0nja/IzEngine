#pragma once

namespace IzEngine
{
	/// <summary>
	/// Stack corruption detection.
	/// </summary>
	class StackCanary
	{
	public:
		/// <summary>
		/// Initialize buffer.
		/// </summary>
		StackCanary()
		{
			for (int i = 0; i < 50; i++)
				Buffer[i] = 0xCE;
		}

		/// <summary>
		/// Check stack corruption.
		/// </summary>
		~StackCanary() noexcept(false)
		{
			for (int i = 0; i < 50; i++)
				if (Buffer[i] != 0xCE)
					throw "Stack corruption";
		}

	private:
		unsigned char Buffer[50];
	};
}
