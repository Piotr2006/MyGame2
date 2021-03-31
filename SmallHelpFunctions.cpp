#include "SmallHelpFunctions.h"

void StrCpy (char Name [], char _Name [])
    {
    for (int i = 0; i < NameSize; i += 1)
        {
        Name [i] = _Name [i];
        };
    };

int Distance (int a, int b, int Dst)
    {
    if (fabs (a - b) <= Dst)
        return 1;

    return 0;
    };

void HelpSystem ()
    {
    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", Text1_Size);
    txTextOut (Text1_X, Text1_Y, "Для передвижения нажмите клавиши вправо и влево, для ускорения нажмите Shift");

    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", Text2_Size);
    txTextOut (Text2_X, Text2_Y, "Удачной игры!");
    };

void Text (PointType Point, int Size, int Number, char Name [])
    {
    char str [50] = "";

    sprintf (str, "%s %d", Name, Number);

    GRSetAlign ();
    GRSetColor (TX_WHITE, 1);
    GRSelectFont ("Comic Sans MS", Size);
    GRTextOut (Point, str);
    };

int ModuleDistance (PointType Point1, PointType Point2, int Distance)
    {
    if (fabs (Point1.x - Point2.x) <= Distance)
        {
        if (fabs (Point1.y - Point2.y) <= Distance)
            {
            return 1;
            };
        };

    return 0;
    };

void DrawHealth (int Health, AllImageType AllImage)
    {
    int null = 0;
    int one  = 1;

    DrawTransparentImage (AllImage.Coin, Sign_HealthX, Sign_HealthY, &one, &null);

    GRSetColor (TX_BLACK, 2);
    GRSetFillColor (TX_TRANSPARENT);
    GRRectangle (60, 120, 160, 140);
    GRSetFillColor (RGB (237, 28, 36));
    GRRectangle (60, 120, 60+(Health*5), 140);
    };

int BlockCheckClick (BlockType* Block, CamType* Camera)
    {
    int xDst = GRGetExtentX (Block->Animation.Picture->Picture)/Block->Animation.Picture->xMaxAnimationNumber;
    int yDst = GRGetExtentY (Block->Animation.Picture->Picture)/Block->Animation.Picture->yMaxAnimationNumber;

    if (fabs (Block->Point.x - Camera->Point.x + xDst - GRMouseX()) <= xDst &&
        fabs (Block->Point.y - Camera->Point.y + yDst - GRMouseY()) <= yDst &&
        GetAsyncKeyState (VK_LBUTTON))
                return true;

    return false;
    };

int InBorders (double smaller, double x, double bigger)
    {
    if (smaller <= x &&
                   x <= bigger)
                   return true;

    return false;
    };
