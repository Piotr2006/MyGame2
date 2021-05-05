#include "Levels.h"

void MoveGame (BlockType* ManyBlocks [], int* LevelNumber, ManType* Man, double* AllTemperature, CamType* Camera, ManType Villagers [])
    {
    int StartLevelNumber = *LevelNumber;

    int NumberPicture = 0;

    int Time = GetTickCount();

    ButtonType Pause = {Sign_PauseX - Sign_Pause_Radius, Sign_PauseY - Sign_Pause_Radius, 0};
    ButtonType Restart = {120, 35, 0};

    MouseType Mouse = {GRMouseX(), GRMouseY(), GlobalAllImage.Cursor};

    int t = 0;

    int NumberLevel = *LevelNumber;

    int PauseNumber = Pause_Active;

    COLORREF color = RGB (0, 0, 0);
    COLORREF WaterColor = RGB(255, 255, 255);

    // CreateBlocks (ManyBlocks, AllImage);

    HDC Light = txLoadImage ("Images/Light2.bmp");

    GRBegin ();

    while (true)
        {
        GRSetFillColor (color);
        GRClear ();

        // GRPlaySound ("Music/MyGame2Music.wav");

        if (Man->Time <= 500)
            color = RGB (99, 155, 255);
        else
            color = RGB (18, 18, 33);

        if (Man->Days >= 20 &&
            Man->Days <  30)
            WaterColor = RGB (203, 219, 252);
        else
            WaterColor = RGB (91, 110, 225);

        NumberLevel = *LevelNumber;

        Time = Time + 1;

        int null = 0;
        int six = 6;

        Camera->MoveCamera (Man);

        // DrawTransparentImage (GlobalAllImage.BackGround, 0, 0, &null, &null, FixedCamera);

        // GRSetColor (RGB (143, 86, 59), 0);
        // GRSetFillColor (RGB (143, 86, 59));
        // GRRectangle (130, 700, 2410, 700);

        GRSetColor (RGB (143, 86, 59), 1);
        GRSetFillColor (RGB (143, 86, 59));
        GRRectangle (0 - Camera->Point.x, 700 - Camera->Point.y, 9999999 - Camera->Point.x, 9000 - Camera->Point.y);

        /* GRSetColor (WaterColor, 1);
        GRSetFillColor (WaterColor);
        GRRectangle (-99999 - Camera->Point.x, 720 - Camera->Point.y, 0 - Camera->Point.x, 9000 - Camera->Point.y);
        GRRectangle (11400*World_Size - Camera->Point.x, 720 - Camera->Point.y, 999999 - Camera->Point.x, 9999 - Camera->Point.y); */

        DrawManyBlocks (ManyBlocks, Camera);

        // GRSetColor (GR_RED, 10);
        // GRLine (-1000000, 10000, 1000000, 10000);

        Man->DrawMan (Camera);

        // Villager
        // Villager->Physic ();
        // InteractManWithBlocks (ManyBlocks, Villager, Camera, &Man->NumberCoin, LevelNumber, AllImage);
        // Villager->DrawMan (Camera, AllImage);
        // Villager->VillagerMind (Man, Camera, AllImage);

        // DrawLevelPeople (Villagers, Camera, AllImage);

        // DrawTransparentImage (GlobalAllImage.BlackFrontGround, 0, 268 - Camera->Point.y, &null, &null);

        Man->Crafting ();

        Man->DrawInventory (Camera);

        // CallPeoplePhysic (Villagers, Camera, AllImage, ManyBlocks, Man);

        // DrawTransparentImage (GlobalAllImage.Coin, Sign_CoinX, Sign_CoinY, &null, &null, FixedCamera);

        Man->ManFire (Camera);
        Man->ManHealth (Camera);
        Man->ManTemperature ();

        InteractManWithBlocks (ManyBlocks, Man, Camera, &Man->NumberCoin);

        Man->Physic ();

        Man->ControlMan (Mouse, &t);

        if (Pause.ButtonCheckClick (GRMouseX(), GRMouseY(), Sign_Pause_Radius, Sign_Pause_Radius) == true)
            {
            PauseNumber = Pause_Stopped;
            };

        if (Restart.ButtonCheckClick (GRMouseX(), GRMouseY(), Sign_Pause_Radius, Sign_Pause_Radius) == true)
            {
            Man->Health = 20;
            // Man->Inventory = 0;
            Man->Time = 0;
            Man->Days = 0;
            LevelNumber += 1;
            };

        PointType LevelPoint = {Sign_LevelTextX, Sign_LevelTextY};

        // Text (Sign_CoinTextX, Sign_CoinTextY, Coin_TextSize, Man->NumberCoin, "");

        Text (LevelPoint, Level_TextSize, Man->Days+1, "Day");

        Pause.DrawButton ();
        DrawTransparentImage (GlobalAllImage.Pause, 95, 10, &null, &six);

        DrawHealth (Man->Health);

        Helping (&Man->HelpSystem);

        if (PauseNumber == Pause_Stopped)
            {
            Man->Speed.x = 0;
            Man->Speed.y = 0;

            Pause.Number = Pause_Stopped;

            if (Pause.ButtonCheckClick (GRMouseX(), GRMouseY(), Sign_Pause_Radius, Sign_Pause_Radius) == 1)
                PauseNumber = Pause_Active;
            }
        else
            Pause.Number = 0;

        if (Man->Temperature > *AllTemperature)
            {
            Man->Temperature -= (Man->Temperature - *AllTemperature)*0.001;
            };

        if (Man->Temperature < *AllTemperature)
            {
            Man->Temperature += (*AllTemperature - Man->Temperature)*0.001;
            };

        GRSetColor (RGB (237, 28, 36), 1);
        GRSetFillColor (RGB (237, 28, 36));

        DrawTransparentImage (GlobalAllImage.Termometer, Sign_TermometerX, Sign_TermometerY, &null, &null);
        GRRectangle (Sign_TermometerX + Sign_Term_RectLeftX, Sign_TermometerY + Sign_Term_RectDownY - Man->Temperature,
                     Sign_TermometerX + Sign_Term_RectRightX, Sign_TermometerY + Sign_Term_RectDownY);

        GRAlphaBlend (Man->Point.x, Man->Point.y, 50, 50, Light, 0, 0, 1);

        if (GetAsyncKeyState (VK_SPACE))
            {
            // HelpSystem ();
            };

        Mouse.DrawCursor ();

        if (StartLevelNumber != *LevelNumber)
            {
            break;
            };

        if (GetAsyncKeyState (VK_ESCAPE))
            break;

        GRSleep (Main_Sleep);
        };

    GREnd ();
    };

void Level1 (int* LevelNumber, ManType* Man, CamType* Camera)
    {
    double AllTemperature = 10;

    if (Man->Days >= 0 &&
        Man->Days < 10)
            AllTemperature = 0;

    if (Man->Days >= 10 &&
        Man->Days < 20)
            AllTemperature = -20;

    if (Man->Days >= 20 &&
        Man->Days < 30)
            AllTemperature = 0;

    if (Man->Days >= 30 &&
        Man->Days < 40)
            AllTemperature = 40;

    TreeType Trees [1] = {{{1, 1}, 1, {0, 0, &GlobalAllImage.Finish}, BT_Finish, AirInteraction}};

    BlockType Blocks [Blocks_Number] = {{{1, 1}, 1, {0, 0, &GlobalAllImage.Finish}, BT_Finish, AirInteraction}};

    // Blocks [Blocks_Number - 1]       = {{-1, -1}, 1, {0, 0, &AllImage.Finish}, BT_Finish, AirInteraction};

    BlockType* ManyBlocks [Blocks_Number] = {};

    for (int i = 0; i < Blocks_Number; i += 1)
        {
        ManyBlocks [i] = &Blocks [i];
        };



    CreateBlocks (ManyBlocks);

    // BlockFunction (ManyBlocks, -1);

    ManType Villagers [1] = {{{0, 0}, 20, {0, 0, &GlobalAllImage.Boat},
                            {0, 0}, {Man_aX, 2},
                            0, 0, Man_Temperature,
                            0, 0, 0, "", MT_Boat, {}, 0, 0,
                            0, 0, 0, 0, {}}};

    // Villagers [1].Point.x = -1;

    CreateVillagers (Villagers);

    MoveGame (ManyBlocks, LevelNumber, Man, &AllTemperature, Camera, Villagers);
    };

void TestLevel (int* LevelNumber, ManType* Man, CamType* Camera)
    {
    double AllTemperature = 10;


    if (Man->Days >= 0 &&
        Man->Days < 10)
            AllTemperature = 10;

    if (Man->Days >= 10 &&
        Man->Days < 20)
            AllTemperature = 0;

    if (Man->Days >= 20 &&
        Man->Days < 30)
            AllTemperature = 10;

    if (Man->Days >= 30 &&
        Man->Days < 40)
            AllTemperature = 40;

    BlockType Blocks [] = {{{ -75,  675}, 6,   {0, 0, &GlobalAllImage.Dirt}, BT_Dirt, AirInteraction},
                            {{0, 0}, 1, {0, 0, &GlobalAllImage.Finish}, BT_Finish, AirInteraction}
                            };

    BlockType* ManyBlocks [] = {};

    // int i = 0;

    for (int i = 0; i < Blocks_Number; i ++)
        {
        ManyBlocks [i] = &Blocks [i];

        // i += 1;
        };


    ManType Villagers [] = {{{0, 0}, 20, {0, 0, &GlobalAllImage.Boat},
                            {0, 0}, {Man_aX, 2},
                            0, 0, Man_Temperature,
                            0, 0, 0, "", MT_Boat, {}, 0, 0,
                            0, 0, 0, 0, {}}};

    MoveGame (ManyBlocks, LevelNumber, Man, &AllTemperature, Camera, Villagers);
    };

