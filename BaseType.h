#ifndef BASETYPE_H
#define BASETYPE_H


#include "AnimationType.h"

struct BaseType
    {
    BaseType (double x, double y, double Health, AnimationType Animation);

    double x;
    double y;

    double Health;

    AnimationType Animation;
    };

#endif
