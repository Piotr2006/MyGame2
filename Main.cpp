#include "TXLib.h"

#include "AnimationType.cpp"
#include "BaseType.cpp"
#include "CamType.cpp"
#include "MouseType.cpp"
#include "ButtonType.cpp"
#include "ManType.cpp"
#include "BlockType.cpp"
#include "Levels.cpp"
#include "SmallHelpFunctions.cpp"

void Cycle ();

int main ()
    {
    txCreateWindow (1550, 850);

    Cycle ();

    return 0;
    };


void Cycle ()
    {
    AllImageType AllImage = {};

    LoadAllImages (&AllImage);

    int LevelNumber = 1;

    // double AllTemperature = 10;

    CamType Camera {Man_x - Screen_xCenter, Man_y - Screen_yCenter, 0.3, 0.3, 0};

    CamType FixedCamera {0, 0, 0, 0, 0};

    ManType Man {0, Man_y, Man_Health, {0, 0, &AllImage.Man},
                 0, 0, Man_aX, 2,
                 0, 0, Man_Temperature,
                 0, 0, 0, "", 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 0, 0, Man_x, Man_y, 0, 0};

    while (true)
        {
        txSetFillColor (RGB (72, 72, 72));
        txClear ();

        /* if (LevelNumber == 0)
            Menu (&LevelNumber, AllImage, &FixedCamera); */

        if (LevelNumber == 1)
            {
            Level1 (&LevelNumber, &Man, AllImage, &Camera, &FixedCamera);
            };

        if (LevelNumber == 2)
            {
            Level2 (&LevelNumber, &Man, AllImage, &Camera, &FixedCamera);
            };

        if (GetAsyncKeyState (VK_ESCAPE))
            break;
        };
    };




