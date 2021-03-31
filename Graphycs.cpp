#include "Graphycs.h"

void GRSetColor (COLORREF color, int Wide)
    {
    txSetColor (color, Wide);
    };

void GRSetFillColor (COLORREF color)
    {
    txSetFillColor (color);
    };

void GRCreateWindow (int Wide, int High)
    {
    txCreateWindow (Wide, High);
    };

void GRTransparentBlt (double x, double y, double Wide, double Heigh, HDC Image, double FrameX, double FrameY, COLORREF color)
    {
    txTransparentBlt (txDC(), x, y, Wide, Heigh, Image, FrameX, FrameY, color);
    };

void GRBegin ()
    {
    txBegin();
    };

void GREnd ()
    {
    txEnd();
    };

void GRSleep (int Sleep)
    {
    txSleep (Sleep);
    };

void GRRectangle (int x1, int y1, int x2, int y2)
    {
    txRectangle (x1, y1, x2, y2);
    };

void GRLine (int x1, int y1, int x2, int y2)
    {
    txLine (x1, y1, x2, y2);
    };

void GRClear ()
    {
    txClear();
    };

int GRMouseX ()
    {
    return txMouseX();
    };

int GRMouseY ()
    {
    return txMouseY();
    };

void GRDeleteDC (HDC Image)
    {
    txDeleteDC (Image);
    };

void GRAlphaBlend (double x, double y, double Wide, double Heigh,
                         HDC Image, double FrameX, double FrameY, double Alpha)
    {
    txAlphaBlend (txDC(), x, y, Wide, Heigh, Image, FrameX, FrameY, Alpha);
    };

int GRGetExtentX (HDC Image)
    {
    return txGetExtentX(Image);
    };

int GRGetExtentY (HDC Image)
    {
    return txGetExtentY(Image);
    };

void GRSetAlign ()
    {
    txSetTextAlign ();
    };

void GRSelectFont (const char Name [], int Size)
    {
    txSelectFont (Name, Size);
    };

void GRTextOut (PointType Point, const char Str [])
    {
    txTextOut (Point.x, Point.y, Str);
    };

void GRPlaySound (const char Name[])
    {
    txPlaySound (Name);
    };

HDC GRLoadImage (const char* Picture)
    {
    return txLoadImage (Picture);
    };
