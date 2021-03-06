#ifndef CAMTYPE_H
#define CAMTYPE_H

#include "Enums.h"

#include "BaseType.h"

struct CamType
    {
    CamType (double x, double y, double vX, double vY, int Timer);

    void MoveCamera (BaseType* Object);

    double x;
    double y;

    double vX;
    double vY;

    int Timer;
    };

#endif
