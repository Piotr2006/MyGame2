#ifndef ANIMATIONTYPE_H
#define ANIMATIONTYPE_H

#include "ImageType.h"
#include "Graphycs.h"
#include "AllImageType.h"

struct AnimationType
    {
    AnimationType (int xFrame, int yFrame, const ImageType* Picture);

    AnimationType ();

    double GetFrameSizeX ();
    double GetFrameSizeY ();

    int xFrame;
    int yFrame;

    const ImageType* Picture;
    };

//-----------------------------------------------------------------------------

void IncreaseAnimationNumber (AnimationType* Animation);

//-----------------------------------------------------------------------------

#endif
