#pragma once

#if defined(_M_IX86) || defined(_M_ARM)
	#define PLATFORM_32
#elif defined(_M_AMD64) || defined(_M_ARM64)
	#define PLATFORM_64
#endif

#if defined(_M_IX86) || defined(_M_AMD64)
	#define PLATFORM_ARCH_X86
#elif defined(_M_ARM) || defined(_M_ARM64)
	#define PLATFORM_ARCH_ARM
#endif

#define ASAN __declspec(no_sanitize_address)
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#define INLINE __forceinline
#define NOINLINE __declspec(noinline)
#define FASTCALL __fastcall
#define STDCALL __stdcall
#define ALIGN(n) __declspec(align(n))
