#pragma once
#include <assert.h>

#if defined(_MSC_VER)
	#if defined(_M_IX86) || defined(_M_ARM)
		#define PLATFORM_32
	#elif defined(_M_AMD64) || defined(_M_ARM64)
		#define PLATFORM_64
	#endif
#elif defined(__clang__) || defined(__GNUC__)
	#if defined(__i386__) || defined(__arm__)
		#define PLATFORM_32
	#elif defined(__x86_64__) || defined(__aarch64__)
		#define PLATFORM_64
	#endif
#endif

#if defined(_MSC_VER)
	#if defined(_M_IX86) || defined(_M_AMD64)
		#define PLATFORM_ARCH_X86
	#elif defined(_M_ARM) || defined(_M_ARM64)
		#define PLATFORM_ARCH_ARM
	#endif
#elif defined(__clang__) || defined(__GNUC__)
	#if defined(__i386__) || defined(__x86_64__)
		#define PLATFORM_ARCH_X86
	#elif defined(__arm__) || defined(__aarch64__)
		#define PLATFORM_ARCH_ARM
	#endif
#endif

#ifdef _DEBUG
	#if defined(PLATFORM_WINDOWS)
		#define IZ_DEBUGBREAK() __debugbreak()
	#elif defined(PLATFORM_LINUX)
		#include <signal.h>
		#define IZ_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error Unsupported platform
	#endif
	#define IZ_ASSERT_ENABLED
#else
	#define IZ_DEBUGBREAK()
#endif

#if defined(_MSC_VER)
	#define ASAN __declspec(no_sanitize_address)
	#define EXPORT __declspec(dllexport)
	#define IMPORT __declspec(dllimport)
	#define INLINE __forceinline
	#define NOINLINE __declspec(noinline)
	#define FASTCALL __fastcall
	#define STDCALL __stdcall
	#define ALIGN(n) __declspec(align(n))
#elif defined(__clang__) || defined(__GNUC__)
	#define ASAN [[gnu::no_sanitize_address]]
	#define EXPORT [[gnu::visibility("default")]]
	#define IMPORT [[gnu::visibility("default")]]
	#define INLINE [[gnu::always_inline]]
	#define NOINLINE [[gnu::noinline]]
	#define ALIGN(n) [[gnu::aligned(n)]]

	#ifdef PLATFORM_32
		#define FASTCALL [[gnu::fastcall]]
	#endif
#else
	#error Unsupported compiler
#endif

#if !defined(PLATFORM_ARCH_X86) && !defined(PLATFORM_ARCH_ARM)
	#error Unsupported architecture
#elif !defined(PLATFORM_32) && !defined(PLATFORM_64)
	#error Unsupported address size
#endif

#define C_EXTERN extern "C"
#define CPP_EXTERN extern "C++"
#define ASM C_EXTERN

#define PLUGIN C_EXTERN EXPORT
#define ENTRY C_EXTERN EXPORT

#ifndef API
	#define API EXPORT
#endif

#ifndef APPLICATION_ID
	#define APPLICATION_ID "izengine"
#endif

#ifndef CMAKE_BINARY_DIR
	#define CMAKE_BINARY_DIR ""
#endif

#ifndef CMAKE_PROJECT_VERSION
	#define CMAKE_PROJECT_VERSION "undefined"
#endif

#define CLASS_DISALLOW_COPY_AND_ASSIGN(type) \
	type(const type&) = delete;              \
	void operator=(const type&) = delete;

#define CLASS_SINGLETON(type) \
public:                       \
	static inline type& Get() \
	{                         \
		static type instance; \
		return instance;      \
	}

#define BIT(n) (1U << (n))
#define IZ_EXPAND(x) x
#define IZ_STRINGIFY(x) #x

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
