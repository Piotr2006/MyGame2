#include "SmallHelpFunctions.h"

void StrCpy (char ToName [], const char FromName [])
    {
    for (int i = 0; i < NameSize; i += 1)
        {
        ToName [i] = FromName [i];
        };
    };

int GetNumberOfSymbols (const char str[], const char Symbol)
    {
    int Number = 0;

    int Position = 0;

    while (str [Position] != 0)
        {
        if (str [Position] == Symbol)
            Number += 1;

        Position += 1;
        };

    return Number;
    };

int NewGetNumberOfStr (const char Allstr[], const char Smallstr [])
    {
    int Number = 0;

    int Position = 0;

    while (Allstr [Position] != 0)
        {
        // printf ("Position = %d, Allstr [Position] = %c, Smallstr [0] = %c, Smallstr [1] = %c \n", Position, Allstr [Position], Smallstr [0], Smallstr [1]);

        int nMatchingSymbols = 0;

        for (int i = 0; Smallstr [i] != 0 && Allstr [Position + i] != 0; i ++)
            {
            if (Allstr [Position + i] == Smallstr [i])
                nMatchingSymbols += 1;
            };

        if (Smallstr [nMatchingSymbols] == 0)       // "123"
            Number += 1;

        Position += 1;
        };

    return Number;
    };

int GetNumberOfStr (const char Allstr[], const char Smallstr [2])
    {
    int Number = 0;

    int Position = 0;

    while (Allstr [Position] != 0)
        {
        if (Allstr [Position]     == Smallstr [0] &&
            Allstr [Position + 1] == Smallstr [1])
            Number += 1;

        Position += 1;
        };

    return Number;
    };

int Myfscanf (FILE* file, const char str [], ...)
    {
    va_list Arg {};

    va_start (Arg, str);

    int NumberOfArg = GetNumberOfSymbols (str, '%') - 2 * NewGetNumberOfStr (str, "%%") -
                                                          NewGetNumberOfStr (str, "%*");

                            // Man->Point.x = 10%
    // Myfscanf (readingfile, "Man->Point.x = %d %% ", &Man->Point.x);

    // Myfscanf (readingfile, "Man->Point.x = %d %*d ", &Man->Point.x, &Man->Point.y);


    // Myfscanf (readingfile, "Man->Health = %% ", &Man->Health);
    // Myfscanf (readingfile, "Man->Point.y = %d ", &Man->Point.y);

    int OK = 0;

    if (vfscanf (file, str, Arg) < NumberOfArg)
        OK = false;
    else
        OK = true;

    va_end (Arg);

    if (OK == true)
        return true;
    else
        return false;
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

void TextWithEnd (PointType Point, int Size, int Number, char Text1 [], char Text2 [])
    {
    char str [50] = "";

    sprintf (str, "%s %d %s", Text1, Number, Text2);

    GRSetAlign ();
    // GRSetColor (TX_WHITE, 1);
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

void DrawHealth (PointType Point, int Health)
    {
    int null = 0;
    int one  = 1;

    DrawTransparentImage (GlobalAllImage.Coin, Point.x - 71, Point.y - 27, &one, &null);

    GRSetColor (TX_BLACK, 2);
    GRSetFillColor (TX_TRANSPARENT);
    GRRectangle (Point.x - 30, Point.y - 20, Point.x + 70, Point.y);
    GRSetFillColor (RGB (237, 28, 36));
    GRRectangle (Point.x - 30, Point.y - 20, Point.x - 30 + Health, Point.y);
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

int RectAiming (double x1, double y1, double x2, double y2, CamType* Camera)
    {
    double xDst = x2 - x1;
    double yDst = y2 - y1;

    if (fabs (x1 + xDst - Camera->Point.x - GRMouseX()) <= xDst &&
        fabs (y1 + yDst - Camera->Point.y - GRMouseY()) <= yDst)
                return true;

    return false;
    };

int RectCheckClick (double x1, double y1, double x2, double y2, CamType* Camera)
    {
    double xDst = x2 - x1;
    double yDst = y2 - y1;

    if (fabs (x1 + xDst - Camera->Point.x - GRMouseX()) <= xDst &&
        fabs (y1 + yDst - Camera->Point.y - GRMouseY()) <= yDst &&
        GetAsyncKeyState (VK_LBUTTON))
                return true;

    return false;
    };

bool HaveInventory (int Selected, int Type, int HaveNumber, int MinNumber)
    {
    if (Selected == Type &&
        HaveNumber >= MinNumber)
        return true;

    return false;
    };
