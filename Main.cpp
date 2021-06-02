#include "Graphycs.h"
#include "HelpSystem.h"

#include "AnimationType.h"
#include "BaseType.h"
#include "CamType.h"
#include "MouseType.h"
#include "ButtonType.h"
#include "ManType.h"
#include "BlockType.h"
// #include "RoomType.h"
#include "Levels.h"
#include "SmallHelpFunctions.h"

void Cycle ();

AllImageType GlobalAllImage = {};

CamType Camera {{0, 0}, {0, 0}, 0};

int main ()
    {
    GRCreateWindow (1550, 850);

    Cycle ();

    return 0;
    };

void Cycle ()
    {
    LoadAllImages ();

    txPlaySound ("Music/MyGame2Music.wav", SND_NOSTOP);

    int LevelNumber = 0;

    int null = 0;

    // double AllTemperature = 10;

    CamType Camera {{Man_x - Screen_xCenter, Man_y - Screen_yCenter}, {0.3, 0.3}, 0};

    ManType Man {{5500*World_Size + double (rand() % 600) * World_Size, Man_y}, Man_Health, {0, 0, &GlobalAllImage.Man},
                 {0, 0}, {Man_aX, 2},
                 0, 0, Man_Temperature,
                 0, 0, 0, "", 0, {ST_Weapon, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                 0, 0, Man_x, Man_y, 0, 0, {}};

    BlockType* ManyBlocks [Blocks_Number] = {};

    /* for (int i = 0; i < Blocks_Number; i += 1)
        {
        ManyBlocks [i] = new TreeType ();
        }; */

    /*BlockType* Rooms [Rooms_Number] = {};

    for (int i = 0; i < Rooms_Number; i += 1)
        {
        Rooms [i] = new RoomType ();
        };

    CreateRooms (Rooms);    */

    CreateBlocks (ManyBlocks);

    /* while (true)
        {
        DrawTransparentImage (GlobalAllImage.LoadQuestion, 587, 293, &null, &null, &Camera);

        if (RectCheckClick (640, 482, 724, 349, &Camera) == true)
            {
            Reading (&Man, ManyBlocks);
            break;
            };

        if (RectCheckClick (811, 482, 895, 349, &Camera) == true)
            {
            break;
            };
        }; */

    Reading (&Man, ManyBlocks);

    while (true)
        {
        GRSetFillColor (RGB (72, 72, 72));
        GRClear ();

        if (Level1 (&LevelNumber, &Man, &Camera, ManyBlocks) == Exit)
            {
            // txMessageBox ("выход из функции Cycle");
            break;
            };

        if (LevelNumber == 0)
            {
            TestLevel (&LevelNumber, &Man, &Camera, ManyBlocks);
            };
        };

    Saving (&Man, ManyBlocks);

    DeleteAllImage ();
    };





