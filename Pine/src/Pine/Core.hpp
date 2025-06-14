#pragma once

#ifdef PINE_PLATFORM_WINDOWS
	#ifdef PINE_BUILD_SHARED
		#define PINE_API __declspec(dllexport)
	#else
		#define PINE_API __declspec(dllimport)
	#endif
#else
	#ifdef PINE_BUILD_SHARED
		#define PINE_API __attribute__((visibility("default")))
	#else
		#define PINE_API
	#endif
#endif