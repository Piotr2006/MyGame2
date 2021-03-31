#include "PointType.h"

PointType operator + (PointType Point, PointType Size)
    {
    double X = Point.x + Size.x;
    double Y = Point.y + Size.y;

    PointType Result = {X, Y};

    return Result;
    };

PointType operator - (PointType Point, PointType Size)
    {
    double X = Point.x - Size.x;
    double Y = Point.y - Size.y;

    PointType Result = {X, Y};

    return Result;
    };

void operator += (PointType& Point, PointType Speed)
    {
    Point.x += Speed.x;
    Point.y += Speed.y;
    };

