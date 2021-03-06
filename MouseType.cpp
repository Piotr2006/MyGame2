#include "MouseType.h"

MouseType :: MouseType (int _x, int _y, ImageType _Picture) :
    x (_x),
    y (_y),
    Picture (_Picture)
    {};


void MouseType :: DrawCursor (CamType* Camera)
    {


    x = txMouseX ();

    y = txMouseY ();

    int null = 0;

    DrawTransparentImage (&Picture, x, y, &null, &null, Camera);
    };
