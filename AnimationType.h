#ifndef ANIMATIONTYPE_H
#define ANIMATIONTYPE_H

#include "ImageType.h"
#include "Graphycs.h"

struct AnimationType
    {
    AnimationType (int xFrame, int yFrame, ImageType* Picture);

    double GetFrameSizeX ();
    double GetFrameSizeY ();

    int xFrame;
    int yFrame;

    ImageType* Picture;
    };

//-----------------------------------------------------------------------------

void IncreaseAnimationNumber (AnimationType* Animation);

//-----------------------------------------------------------------------------

#endif
