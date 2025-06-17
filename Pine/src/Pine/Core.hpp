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

#ifdef PINE_ENABLE_ASSERTS
	#define PINE_ASSERT(x, ...) { if(!(x)) { PINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PINE_CORE_ASSERT(x, ...) { if(!(x)) { PINE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PINE_ASSERT(x, ...)
	#define PINE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)