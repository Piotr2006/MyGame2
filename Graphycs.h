#include "TXLib.h"
#include "PointType.h"

void GRSetColor (COLORREF color, int Wide);

void GRSetFillColor (COLORREF color);

void GRCreateWindow (int Wide, int High);

void GRTransparentBlt (double x, double y, double Wide, double Heigh,
                         HDC Image, double FrameX, double FrameY, COLORREF color);

void GRBegin ();

void GREnd ();

void GRAlphaBlend (double x, double y, double Wide, double Heigh,
                         HDC Image, double FrameX, double FrameY, double Alpha);

void GRSleep (int Sleep);

void GRRectangle (int x1, int y1, int x2, int y2);

void GRLine (int x1, int y1, int x2, int y2);

void GRClear ();

int GRMouseX();
int GRMouseY();

void GRDeleteDC (HDC Image);

int GRGetExtentX (HDC Image);
int GRGetExtentY (HDC Image);

void GRSetAlign ();
void GRSelectFont (const char Name [], int Size);
void GRTextOut (PointType Point, const char Str []);

void GRPlaySound (const char Name[]);

HDC GRLoadImage (const char* Picture);
