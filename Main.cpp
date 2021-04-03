#include "Graphycs.h"
#include "HelpSystem.h"

#include "AnimationType.h"
#include "BaseType.h"
#include "CamType.h"
#include "MouseType.h"
#include "ButtonType.h"
#include "ManType.h"
#include "BlockType.h"
#include "Levels.h"
#include "SmallHelpFunctions.h"

void Cycle ();

int main ()
    {
    GRCreateWindow (1550, 850);

    Cycle ();

    return 0;
    };

void Cycle ()
    {
    AllImageType AllImage = {};

    LoadAllImages (&AllImage);

    int LevelNumber = 0;

    // double AllTemperature = 10;

    CamType Camera {{Man_x - Screen_xCenter, Man_y - Screen_yCenter}, {0.3, 0.3}, 0};

    ManType Man {{(rand()%11200) * World_Size, Man_y}, Man_Health, {0, 0, &AllImage.Man},
                 {0, 0}, {Man_aX, 2},
                 0, 0, Man_Temperature,
                 0, 0, 0, "", 0, {ST_Weapon, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                 0, 0, Man_x, Man_y, 0, 0, {}};

    while (true)
        {
        GRSetFillColor (RGB (72, 72, 72));
        GRClear ();

        /* if (LevelNumber == 0)
            Menu (&LevelNumber, AllImage, &FixedCamera); */

        Level1 (&LevelNumber, &Man, AllImage, &Camera);

        if (LevelNumber == 0)
            {
            TestLevel (&LevelNumber, &Man, AllImage, &Camera);
            };

        if (GetAsyncKeyState (VK_ESCAPE))
            break;
        };

    DeleteAllImage (&AllImage);
    };





