#include "AnimationType.h"

AnimationType :: AnimationType (int _xFrame, int _yFrame, ImageType* _Picture) :
    xFrame (_xFrame),
    yFrame (_yFrame),
    Picture (_Picture)
    {};

void IncreaseAnimationNumber (AnimationType* Animation)
    {
    Animation->xFrame += 1;

    if (Animation->xFrame >= Animation->Picture->xMaxAnimationNumber)
        Animation->xFrame = 0;
    };

