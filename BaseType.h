#ifndef BASETYPE_H
#define BASETYPE_H

#include "PointType.h"
#include "AnimationType.h"
#include "AllImageType.h"

struct BaseType
    {
    BaseType ();

    BaseType (PointType Point, double Health, AnimationType Animation);

    virtual ~BaseType () {};

    PointType Point;

    double SizeX;
    double SizeY;

    double Health;

    AnimationType Animation;
    };

#endif
