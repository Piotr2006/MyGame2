#include "AnimationType.h"

AnimationType :: AnimationType (int _xFrame, int _yFrame, ImageType* _Picture) :
    xFrame (_xFrame),
    yFrame (_yFrame),
    Picture (_Picture)
    {};

double AnimationType :: GetFrameSizeX ()
    {
    return GRGetExtentX (Picture->Picture) / Picture->xMaxAnimationNumber;
    };

double AnimationType :: GetFrameSizeY ()
    {
    return GRGetExtentY (Picture->Picture) / Picture->yMaxAnimationNumber;
    };

void IncreaseAnimationNumber (AnimationType* Animation)
    {
    Animation->xFrame += 1;

    if (Animation->xFrame >= Animation->Picture->xMaxAnimationNumber)
        Animation->xFrame = 0;
    };

