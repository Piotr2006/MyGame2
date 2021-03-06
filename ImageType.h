#ifndef IMAGETYPE_H
#define IMAGETYPE_H

#include "Graphycs.h"

struct ImageType
    {
    // ImageType (const char* FileName, int xMaxAnimationNumber, int yMaxAnimationNumber, HDC Picture, COLOREF color);

    const char* FileName;

    // int xFrame;
    // int yFrame;

    int xMaxAnimationNumber;
    int yMaxAnimationNumber;

    HDC Picture;

    COLORREF color;
    };

#endif
