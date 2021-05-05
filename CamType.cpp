#include "CamType.h"

CamType :: CamType (PointType _Point, PointType _Speed, int _Timer) :
    Point (_Point),
    Speed (_Speed),
    Timer (_Timer)
    {};

void CamType :: MoveCamera (BaseType* Object)
    {
    /* if (GetAsyncKeyState (VK_RIGHT))
            {
            x += 5;
            };

    if (GetAsyncKeyState (VK_LEFT))
            {
            x -= 5;
            };

    if (GetAsyncKeyState (VK_CONTROL) &&
        GetAsyncKeyState (VK_UP))
            {
            y -= 10;
            };

    if (GetAsyncKeyState (VK_CONTROL) &&
        GetAsyncKeyState (VK_DOWN))
            {
            y += 10;
            }; */

    /* if (GetKeyState (VK_CAPITAL))
        printf ("x = %lf, y = %lf, Object->x = %lf, Object->y = %lf \n", x, y, Object->x, Object->y);
    else
        txClearConsole (); */

    // double xDst = fabs (fabs (Point.x - Object->Point.x) - Screen_xCenter);
    // double yDst = fabs (fabs (Point.y - Object->Point.y) - Screen_yCenter);

    /* if (xDst >= 500)
        Speed.x = 0.02;
    else
        Speed.x = 0;

    if (yDst >= 100)
        Speed.y = 0.05;
    else
        Speed.y = 0; */

    // $i printf ("Object->x = %lf, Object->y = %lf, Cam->x = %lf, Cam->y = %lf, xDst = %d, yDst = %d, Speed.x = %lf, Speed.y = %lf \n", Object->x, Object->y, x, y, xDst, yDst, Speed.x, Speed.y); $d

    Point.x -= (Point.x + Screen_xCenter - Object->Point.x) * Speed.x;
    Point.y -= (Point.y + Screen_yCenter - Object->Point.y) * Speed.y;
    };

