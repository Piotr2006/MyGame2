#ifndef MOUSETYPE_H
#define MOUSETYPE_H

#include "ImageFunctions.h"

struct CamType;
struct ImageType;

struct MouseType
    {
    MouseType (int x, int y, ImageType Picture);

    void DrawCursor ();

    int x;
    int y;

    ImageType Picture;
    };

#endif
