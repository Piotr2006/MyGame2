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

void Text (int x, int y, int Size, int Number, char Name [])
    {
    char str [50] = "";

    sprintf (str, "%s %d", Name, Number);

    txSetTextAlign ();
    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", Size);
    txTextOut (x, y, str);
    };

int ModuleDistance (int x1, int y1, int x2, int y2, int Distance)
    {
    if (fabs (x1 - x2) <= Distance)
        {
        if (fabs (y1 - y2) <= Distance)
            {
            return 1;
            };
        };

    return 0;
    };

void DrawHealth (int Health, CamType* Camera, AllImageType AllImage)
    {
    int null = 0;
    int one  = 1;

    DrawTransparentImage (&AllImage.Coin, Sign_HealthX, Sign_HealthY, &one, &null, Camera);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (60, 120, 160, 140);
    txSetFillColor (RGB (237, 28, 36));
    txRectangle (60, 120, 60+(Health*5), 140);
    };

