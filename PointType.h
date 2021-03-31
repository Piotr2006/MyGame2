#ifndef POINTTYPE_H
#define POINTTYPE_H

struct PointType
    {
    double x;
    double y;
    };

PointType operator + (PointType Point, PointType Size);

PointType operator - (PointType Point, PointType Size);

void operator += (PointType& Point, PointType Speed);

#endif
