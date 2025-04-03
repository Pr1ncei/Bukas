#pragma once
#ifdef BK_PLATFORM_WINDOWS
	#ifdef BK_BUILD_DLL
		#define BUKAS_API __declspec(dllexport)
	#else 
		#define BUKAS_API __declspec(dllimport)
	#endif
#else
	#error Bukas only supports Windows.
#endif 