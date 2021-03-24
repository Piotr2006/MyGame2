#ifndef BASETYPE_H
#define BASETYPE_H

#include "PointType.h"
#include "AnimationType.h"

struct BaseType
    {
    BaseType (PointType Point, double Health, AnimationType Animation);

    PointType Point;

    double SizeX;
    double SizeY;

    double Health;

    AnimationType Animation;
    };

#endif
