#include "HelpSystem.h"
#include "Graphycs.h"

void Helping (HelpType* Help)
    {
    if (Help->Number == 0 &&
        Help->FallingTree == 0)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Возьмите поваленное дерево");
        };

    if (Help->Number == 1)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Найдите небольшой камень");
        };

    if (Help->Number == 2)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Сделайте топор");
        };

    if (Help->Number == 3)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Срубите топором дерево");
        };

    if (Help->Number == 4)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Найдите костёр");
        };

    if (Help->Number == 5)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Возьмите в руки дерево и положите его в костёр");
        };

    if (Help->Number == 6)
        {
        GRSetColor (RGB (255, 255, 255), 1);
        GRSelectFont ("Comic Sans MS", 20);
        GRTextOut (400, 30, "Теперь вы можете греться у костра!");
        };
    };
