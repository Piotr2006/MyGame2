#include "ButtonType.h"
#include "AllImageType.h"
#include "ImageFunctions.h"

ButtonType :: ButtonType (int _x, int _y, int _Number) :
    x (_x),
    y (_y),
    Number (_Number)
    {};

void ButtonType :: DrawButton ()
    {
    int null = 0;

    DrawTransparentImage (GlobalAllImage.Pause, x, y, &null, &Number);
    };

int ButtonType :: ButtonCheckClick (int x2, int y2, int DstX, int DstY)
    {
    if (fabs (x - x2) <= DstX)
        if (fabs (y - y2) <= DstY)
            if (GetAsyncKeyState (VK_RBUTTON))
                {
                return 1;
                };
    return 0;
    };

