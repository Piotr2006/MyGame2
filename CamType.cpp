#include "CamType.h"

CamType :: CamType (double _x, double _y, double _vX, double _vY, int _Timer) :
    x (_x),
    y (_y),
    vX (_vX),
    vY (_vY),
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

    int xDst = fabs (fabs (x - Object->Point.x) - Screen_xCenter);
    int yDst = fabs (fabs (y - Object->Point.y) - Screen_yCenter);

    /* if (xDst >= 500)
        vX = 0.02;
    else
        vX = 0;

    if (yDst >= 100)
        vY = 0.05;
    else
        vY = 0; */

    // $i printf ("Object->x = %lf, Object->y = %lf, Cam->x = %lf, Cam->y = %lf, xDst = %d, yDst = %d, vX = %lf, vY = %lf \n", Object->x, Object->y, x, y, xDst, yDst, vX, vY); $d

    x -= (x + Screen_xCenter - Object->Point.x) * vX;
    y -= (y + Screen_yCenter - Object->Point.y) * vY;
    };

