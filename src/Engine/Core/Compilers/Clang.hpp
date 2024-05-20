#pragma once

#if defined(__i386__) || defined(__arm__)
	#define PLATFORM_32
	#define FASTCALL [[gnu::fastcall]]
#elif defined(__x86_64__) || defined(__aarch64__)
	#define PLATFORM_64
	#define FASTCALL
#endif

#if defined(__i386__) || defined(__x86_64__)
	#define PLATFORM_ARCH_X86
#elif defined(__arm__) || defined(__aarch64__)
	#define PLATFORM_ARCH_ARM
#endif

#define ASAN [[gnu::no_sanitize_address]]
#define EXPORT [[gnu::visibility("default")]]
#define IMPORT [[gnu::visibility("default")]]
#define INLINE [[gnu::always_inline]]
#define NOINLINE [[gnu::noinline]]
#define ALIGN(n) [[gnu::aligned(n)]]
