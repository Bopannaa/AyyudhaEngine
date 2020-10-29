#pragma once

#ifdef AA_PLATFORM_WINDOWS
	#ifdef AA_BUILD_DLL
		#define AYYUDHA_API __declspec(dllexport)
	#else
		#define AYYUDHA_API __declspec(dllimport)
	#endif
#elif AA_PLATFORM_LINUX
	#ifdef AA_BUILD_SHARED

	#elif AA_BUILD_STATIC
		#define AYYUDHA_API
	#endif
#endif