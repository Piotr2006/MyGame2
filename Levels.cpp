#include "Levels.h"

void Reading (ManType* Man, BlockType* Blocks[])
    {
    FILE* readingfile = fopen ("Saving.txt", "r");

    int OK = true;

    if (readingfile == 0)
        {
        txMessageBox ("файл Saving.txt нельзя прочитать");
        return;
        };

    // txMessageBox ("Man is reading...");

    OK &= Myfscanf (readingfile, "Man->Point.x = %lf ",             &Man->Point.x);
    OK &= Myfscanf (readingfile, "Man->Point.y = %lf ",             &Man->Point.y);
    OK &= Myfscanf (readingfile, "Man->Health = %lf%% ",            &Man->Health);
    OK &= Myfscanf (readingfile, "Man->Energy = %lf%% ",            &Man->Energy);
    OK &= Myfscanf (readingfile, "Man->Days = %d ",                 &Man->Days);
    OK &= Myfscanf (readingfile, "Man->Inventory.Axe = %d ",        &Man->Inventory.Axe);
    OK &= Myfscanf (readingfile, "Man->Inventory.Wood = %d ",       &Man->Inventory.Wood);
    OK &= Myfscanf (readingfile, "Man->Inventory.Apple = %d ",      &Man->Inventory.Apple);
    OK &= Myfscanf (readingfile, "Man->Inventory.Knife = %d ",      &Man->Inventory.Knife);
    OK &= Myfscanf (readingfile, "Man->Inventory.Stone = %d ",      &Man->Inventory.Stone);
    OK &= Myfscanf (readingfile, "Man->Inventory.Bow = %d ",        &Man->Inventory.Bow);
    OK &= Myfscanf (readingfile, "Man->Inventory.Arrow = %d ",      &Man->Inventory.Arrow);
    OK &= Myfscanf (readingfile, "Man->Inventory.Coin = %d ",       &Man->Inventory.Coin);
    OK &= Myfscanf (readingfile, "Man->Inventory.Fishing = %d ",    &Man->Inventory.Fishing);
    OK &= Myfscanf (readingfile, "Man->Inventory.Fish = %d ",       &Man->Inventory.Fish);
    OK &= Myfscanf (readingfile, "Man->Inventory.CookedFish = %d ", &Man->Inventory.CookedFish);
    OK &= Myfscanf (readingfile, "Man->Inventory.Rope = %d ",       &Man->Inventory.Rope);
    OK &= Myfscanf (readingfile, "Man->Inventory.Gun = %d ",        &Man->Inventory.Gun);

    if (!OK)
        TX_ERROR ("Прoчитаны не все данные человека, выход из цикла");

    // txMessageBox ("Blocks are reading");

    int BlockOK = true;

    for (int i = 0; i < Blocks_Number; i ++)
        {
        int BlockNumber = 0;

        double x = 0;
        double y = 0;
        double Health = 0;

        BlockOK &= Myfscanf (readingfile, "Block [%d] : x = %lf, y = %lf, Health = %lf ",
                                           &BlockNumber, &x, &y, &Health);

        if (!BlockOK)
            {
            TX_ERROR ("Прoчитаны не все данные блоков, выход из цикла, BlockNumber = %d", BlockNumber);
            };

        if (0 <= BlockNumber &&
                 BlockNumber < Blocks_Number)
            {
            Blocks[BlockNumber]->Point.x = x;
            Blocks[BlockNumber]->Point.y = y;
            Blocks[BlockNumber]->Health = Health;
            }
        else
            TX_ERROR ("Hеверный BlockNumber %d \n", BlockNumber);
        };

    // printf ("NumberOfParameters = %d \n", NumberOfParameters);

    //-----------------------------------------------------------------------------

    fclose (readingfile);
    };

void Saving (ManType* Man, BlockType* Blocks[])
    {
    txMessageBox ("Man is saving...");

    FILE* file = fopen ("Saving.txt", "w");

    if (file == NULL)
        {
        txMessageBox ("файл не может сохраниться");
        return;
        };

    fprintf (file, "Man->Point.x = %lf \n",             Man->Point.x);
    fprintf (file, "Man->Point.y = %lf \n",             Man->Point.y);
    fprintf (file, "Man->Health = %lf%% \n",            Man->Health);
    fprintf (file, "Man->Energy = %lf%% \n",            Man->Energy);
    fprintf (file, "Man->Days = %d \n",                 Man->Days);
    fprintf (file, "Man->Inventory.Axe = %d \n",        Man->Inventory.Axe);
    fprintf (file, "Man->Inventory.Wood = %d \n",       Man->Inventory.Wood);
    fprintf (file, "Man->Inventory.Apple = %d \n",      Man->Inventory.Apple);
    fprintf (file, "Man->Inventory.Knife = %d \n",      Man->Inventory.Knife);
    fprintf (file, "Man->Inventory.Stone = %d \n",      Man->Inventory.Stone);
    fprintf (file, "Man->Inventory.Bow = %d \n",        Man->Inventory.Bow);
    fprintf (file, "Man->Inventory.Arrow = %d \n",      Man->Inventory.Arrow);
    fprintf (file, "Man->Inventory.Coin = %d \n",       Man->Inventory.Coin);
    fprintf (file, "Man->Inventory.Fishing = %d \n",    Man->Inventory.Fishing);
    fprintf (file, "Man->Inventory.Fish = %d \n",       Man->Inventory.Fish);
    fprintf (file, "Man->Inventory.CookedFish = %d \n", Man->Inventory.CookedFish);
    fprintf (file, "Man->Inventory.Rope = %d \n",       Man->Inventory.Rope);
    fprintf (file, "Man->Inventory.Gun = %d \n\n",      Man->Inventory.Gun);

    //-----------------------------------------------------------------------------

    // txMessageBox ("Blocks are saving...");

    // FILE* file = fopen ("Saving.txt", "w");

    for (int i = 0; i < Blocks_Number; i ++)
        {
        fprintf (file, "Block[%d] : x = %lf, y = %lf, Health = %lf \n", i, Blocks[i]->Point.x, Blocks[i]->Point.y, Blocks[i]->Health);
        };

    fclose (file);
    };

//-----------------------------------------------------------------------------

int MoveGame (BlockType* ManyBlocks [], int* LevelNumber, ManType* Man, double* AllTemperature, CamType* Camera, ManType Villagers [])
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

    int RunStatus = Continue;

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

        GRSetColor (RGB (5, 14, 12), 1);
        GRSetFillColor (RGB (5, 14, 12));
        GRRectangle (0, 0, 2000, 1000);

        DrawManyBlocks (ManyBlocks, Camera);
        // DrawManyRooms (Rooms, Camera);

        Man->ManFire (Camera);
        Man->ManHealth (Camera);
        Man->ManTemperature ();

        InteractManWithBlocks (ManyBlocks, Man, Camera, &Man->NumberCoin);

        Man->DrawMan (Camera);

        Man->Crafting ();

        Man->DrawInventory (Camera);

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


        Helping (&Man->HelpSystem);

        /* if (PauseNumber == Pause_Stopped)
            {
            Man->Speed.x = 0;
            Man->Speed.y = 0;

            Pause.Number = Pause_Stopped;

            if (Pause.ButtonCheckClick (GRMouseX(), GRMouseY(), Sign_Pause_Radius, Sign_Pause_Radius) == 1)
                PauseNumber = Pause_Active;
            }
        else
            Pause.Number = 0; */

        if (Man->Temperature > *AllTemperature)
            {
            Man->Temperature -= (Man->Temperature - *AllTemperature)*0.001;
            };

        if (Man->Temperature < *AllTemperature)
            {
            Man->Temperature += (*AllTemperature - Man->Temperature)*0.001;
            };

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
            {
            RunStatus = Exit;
            break;
            };

        GRSleep (Main_Sleep);
        };

    // txMessageBox ("выход из функции MoveGame");

    GREnd ();

    return RunStatus;
    };

int Level1 (int* LevelNumber, ManType* Man, CamType* Camera, BlockType* Blocks[])
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

    // Blocks [Blocks_Number - 1]       = {{-1, -1}, 1, {0, 0, &AllImage.Finish}, BT_Finish, AirInteraction};

    /* BlockType* ManyBlocks [Blocks_Number] = {};

    for (int i = 0; i < Blocks_Number; i += 1)
        {
        ManyBlocks [i] = new TreeType ();
        };

    CreateBlocks (ManyBlocks); */

    // BlockFunction (ManyBlocks, -1);

    ManType Villagers [1] = {{{0, 0}, 20, {0, 0, &GlobalAllImage.Boat},
                            {0, 0}, {Man_aX, 2}, 100,
                            0, 0, Man_Temperature,
                            0, 0, 0, "", MT_Boat, {}, 0, 0,
                            0, 0, 0, 0, {}}};

    // Villagers [1].Point.x = -1;

    CreateVillagers (Villagers);

    return MoveGame (Blocks, LevelNumber, Man, &AllTemperature, Camera, Villagers);
    };

void TestLevel (int* LevelNumber, ManType* Man, CamType* Camera, BlockType* Blocks[])
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

    // BlockType Blocks [] = {};

    // BlockType* ManyBlocks [] = {};

    // int i = 0;

    /* for (int i = 0; i < Blocks_Number; i ++)
        {
        ManyBlocks [i] = new TreeType ();

        // i += 1;
        }; */


    ManType Villagers [] = {{{0, 0}, 20, {0, 0, &GlobalAllImage.Boat},
                            {0, 0}, {Man_aX, 2}, 100,
                            0, 0, Man_Temperature,
                            0, 0, 0, "", MT_Boat, {}, 0, 0,
                            0, 0, 0, 0, {}}};

    // MoveGame (Blocks, LevelNumber, Man, &AllTemperature, Camera, Villagers);
    };

