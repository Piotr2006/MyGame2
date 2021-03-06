#ifndef ANIMATIONTYPE_H
#define ANIMATIONTYPE_H

#include "ImageType.h"

struct AnimationType
    {
    AnimationType (int xFrame, int yFrame, ImageType* Picture);

    int xFrame;
    int yFrame;

    ImageType* Picture;
    };

//-----------------------------------------------------------------------------

void IncreaseAnimationNumber (AnimationType* Animation);

//-----------------------------------------------------------------------------

#endif
