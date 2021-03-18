#include "HelpSystem.h"
#include "Graphycs.h"

void Helping (HelpType* Help)
    {
    if (Help->Number == HelpFallingTree)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "�������� ���������� ������");
        };

    if (Help->Number == HelpFindStone)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "������� ��������� ������");
        };

    if (Help->Number == HelpCrafting)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "�������� �����");
        };

    if (Help->Number == HelpDestroyTree)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "������� ������� ������");
        };

    if (Help->Number == HelpFindBonfire)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "������� �����");
        };

    if (Help->Number == HelpAddWood)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "�������� � ���� ������ � �������� ��� � �����");
        };

    if (Help->Number == HelpWarmBonfire)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "������ �� ������ ������� � ������!");
        };
    };
