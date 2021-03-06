#include "TXLib.h"

void SetColor (COLORREF color, int Wide);

void SetFillColor (COLORREF color);

void GRCreateWindow (int Wide, int High);

void DrawTransparentBlt (double x, double y, double Wide, double Heigh,
                         HDC Image, double FrameX, double FrameY, COLORREF color);
