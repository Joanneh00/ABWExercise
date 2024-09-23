#include "pch.h"
#include "thresholding.h"

extern "C" THRESHOLDING_API void thresholdFunc(unsigned char* imageData, int width, int height, int thresholdValue)
{
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = y * width + x;
            // Apply simple thresholding
            imageData[index] = (imageData[index] > thresholdValue) ? 255 : 0;  // Convert to binary
        }
    }
}
