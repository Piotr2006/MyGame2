#include "HelpSystem.h"
#include "Graphycs.h"

void Helping (HelpType* Help)
    {
    if (Help->Number == 0 &&
        Help->FallingTree == 0)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "�������� ���������� ������");
        };

    if (Help->Number == 1)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "������� ��������� ������");
        };

    if (Help->Number == 2)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "�������� �����");
        };

    if (Help->Number == 3)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "������� ������� ������");
        };

    if (Help->Number == 4)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "������� �����");
        };

    if (Help->Number == 5)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "�������� � ���� ������ � �������� ��� � �����");
        };

    if (Help->Number == 6)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "������ �� ������ ������� � ������!");
        };
    };
