#pragma once

#ifdef _DEBUG
	#if defined(PLATFORM_WINDOWS)
		#define IZ_DEBUGBREAK() __debugbreak()
	#elif defined(PLATFORM_LINUX)
		#include <signal.h>
		#define IZ_DEBUGBREAK() raise(SIGTRAP)
	#else
		#define IZ_DEBUGBREAK()
	#endif
	#define IZ_ASSERT_ENABLED
#else
	#define IZ_DEBUGBREAK()
#endif

#ifdef IZ_ASSERT_ENABLED
	#define IZ_ASSERT_INTERNAL(check, msg, ...)               \
		if (!(check))                                         \
		{                                                     \
			Log::WriteLine(Channel::Error, msg, __VA_ARGS__); \
			IZ_DEBUGBREAK();                                  \
		}

	#define IZ_ASSERT_MESSAGE(check, ...) IZ_ASSERT_INTERNAL(check, "Assertion failed: {0}", __VA_ARGS__)
	#define IZ_ASSERT_VALUE(check) \
		IZ_ASSERT_INTERNAL(check, "Assertion '{0}' failed at {1}:{2}", IZ_STRINGIFY(check), __FILE__, __LINE__)

	#define IZ_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define IZ_ASSERT_GET_MACRO(...) \
		IZ_EXPAND(IZ_ASSERT_GET_MACRO_NAME(__VA_ARGS__, IZ_ASSERT_MESSAGE, IZ_ASSERT_VALUE))

	#define IZ_ASSERT(...) IZ_EXPAND(IZ_ASSERT_GET_MACRO(__VA_ARGS__)(__VA_ARGS__))
#else
	#define IZ_ASSERT(...)
#endif
