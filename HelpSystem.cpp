#include "HelpSystem.h"
#include "Graphycs.h"

void Helping (HelpType* Help)
    {
    if (Help->Number == HelpFallingTree)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Возьмите поваленное дерево");
        };

    if (Help->Number == HelpFindStone)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Найдите небольшой камень");
        };

    if (Help->Number == HelpCrafting)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Сделайте топор");
        };

    if (Help->Number == HelpDestroyTree)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Срубите топором дерево");
        };

    if (Help->Number == HelpFindBonfire)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Найдите костёр");
        };

    if (Help->Number == HelpAddWood)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Возьмите в руки дерево и положите его в костёр");
        };

    if (Help->Number == HelpWarmBonfire)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Теперь вы можете греться у костра!");
        };
    };
