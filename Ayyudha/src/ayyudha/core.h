#pragma once

#if defined AA_PLATFORM_WINDOWS
	#ifdef AA_BUILD_DLL
		#define AYYUDHA_API __declspec(dllexport)
	#else
		#define AYYUDHA_API __declspec(dllimport)
	#endif
#elif defined AA_PLATFORM_LINUX
	#ifdef AA_BUILD_DLL
		#define AYYUDHA_API __attribute__((visibility("default")))
	#else
		#define AYYUDHA_API
	#endif
#else
	#error Unsupported platform!
#endif

#ifdef AA_ENABLE_ASSERTS
	#if defined AA_PLATFORM_WINDOWS
		#define AA_ASSERT(x, ...) { if(!(x)) { AA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
		#define AA_CORE_ASSERT(x, ...) { if(!(x)) { AA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#elif defined AA_PLATFORM_LINUX
		#include <signal.h>
		#define AA_ASSERT(x, ...) { if(!(x)) { AA_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP); } }
		#define AA_CORE_ASSERT(x, ...) { if(!(x)) { AA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP); } }
	#endif
#else
	#define AA_ASSERT(x, ...)
	#define AA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) 