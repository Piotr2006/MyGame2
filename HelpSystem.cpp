#include "HelpSystem.h"
#include "Graphycs.h"

void Helping (HelpType* Help)
    {
    PointType TextPoint = {400, 30};

    if (Help->Number == HelpFallingTree)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (TextPoint, "Возьмите поваленное дерево");
        };

    if (Help->Number == HelpFindStone)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (TextPoint, "Найдите небольшой камень");
        };

    if (Help->Number == HelpCrafting)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (TextPoint, "Сделайте топор");
        };

    if (Help->Number == HelpDestroyTree)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (TextPoint, "Срубите топором дерево");
        };

    if (Help->Number == HelpFindBonfire)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (TextPoint, "Найдите костёр");
        };

    if (Help->Number == HelpAddWood)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (TextPoint, "Возьмите в руки дерево и положите его в костёр");
        };

    if (Help->Number == HelpWarmBonfire)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (TextPoint, "Теперь вы можете греться у костра!");
        };
    };
