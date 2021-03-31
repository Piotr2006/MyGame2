#ifndef CAMTYPE_H
#define CAMTYPE_H

#include "Enums.h"

#include "BaseType.h"
#include "PointType.h"

struct CamType
    {
    CamType (PointType Point, PointType Speed, int Timer);

    void MoveCamera (BaseType* Object);

    PointType Point;

    PointType Speed;

    int Timer;
    };

#endif
