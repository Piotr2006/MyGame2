#include "Graphycs.h"

void SetColor (COLORREF color, int Wide)
    {
    txSetColor (color, Wide);
    };

void SetFillColor (COLORREF color)
    {
    txSetFillColor (color);
    };

void GRCreateWindow (int Wide, int High)
    {
    txCreateWindow (Wide, High);
    };

void DrawTransparentBlt (double x, double y, double Wide, double Heigh, HDC Image, double FrameX, double FrameY, COLORREF color)
    {
    txTransparentBlt (txDC(), x, y, Wide, Heigh, Image, FrameX, FrameY, color);
    };
