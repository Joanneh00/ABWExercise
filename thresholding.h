#pragma once

#ifdef THRESHOLDING_EXPORTS
#define THRESHOLDING_API __declspec(dllexport)
#else
#define THRESHOLDING_API __declspec(dllimport)
#endif

extern "C" THRESHOLDING_API void thresholdingFunc(unsigned char* imageData, int width, int height, int thresholdValue);