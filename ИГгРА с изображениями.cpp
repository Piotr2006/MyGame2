#include "TXLib.h"

// 123

enum
    {
    Block_MaxHealth = 1000,
    Block_BaseWide = 25,
    Block_BaseHigh = 25,
    };

enum BlockNumbers
    {
    BT_Start      = -1,
    BT_Finish     = -2,
    BT_BlackSpace = 0,
    BT_Dirt       = 1,
    BT_Box        = 2,
    BT_Stairs     = 3,
    BT_Fire       = 4,
    BT_Water      = 5,
    BT_Stalactite = 7,
    BT_Chest      = 8,
    BT_Pickaxe    = 11,
    BT_Berries    = 21,
    BT_Coin       = 100
    };

enum
    {
    Number_of_Images = 24
    };

enum
    {
    Inventory_TextSize = 40,
    Coin_TextSize      = 40,
    Level_TextSize     = 70,
    Loading_TextSize   = 80
    };

enum Inv
    {
    // LeftArm
    Inv_LeftArm_TextX       = 1402,
    Inv_LeftArm_TextY       = 45,
    Inv_LeftArm_RectLeftX   = 1375,
    Inv_LeftArm_RectLeftY   = 50,
    Inv_LeftArm_RectRightX  = 1425,
    Inv_LeftArm_RectRightY  = 100,

    // RightArm
    Inv_RightArm_TextX      = 1477,
    Inv_RightArm_TextY      = 45,
    Inv_RightArm_RectLeftX  = 1450,
    Inv_RightArm_RectLeftY  = 50,
    Inv_RightArm_RectRightX = 1500,
    Inv_RightArm_RectRightY = 100
    };

enum Man
    {
    Man_x = 0,
    Man_y = 0,
    Man_Health = 20,
    Man_Temperature = 36,
    Man_FastSpeed = 15,
    Man_SlowSpeed = 5,
    Man_DrawingX = 0,
    Man_DrawingY = -48,
    Man_MaxHealth = 20,
    Man_MaxTemperature = 90,
    Man_LeftSide = 1,
    Man_RightSide = 2,
    Man_aX = 0,
    Man_aY = 5,
    Man_JumpSpeed = 30,
    Man_FallingSpeed = 60,
    Man_Wide = 47,
    Man_High = 168,

    // Fire

    Man_Fire1X = 0,
    Man_Fire1Y = 10,
    Man_Fire2X = 50,
    Man_Fire2Y = 4,
    Man_Fire3X = 25,
    Man_Fire3Y = 60,

    Normal_Position = 0,
    Fire_Position = 1,

    // Damage

    Man_FireDamage = 5,
    Man_ColdTempDamage = 5,
    Man_HotTempDamage  = 10,

    Man_TempDamage1 = 1,
    Man_TempDamage2 = 2,
    Man_TempDamage3 = 4
    };

enum
    {
    Man_ColdTemp1 = 20,
    Man_ColdTemp2 = 10,
    Man_ColdTemp3 = 5,

    Man_HotTemp1 = 50,
    Man_HotTemp2 = 70,
    Man_HotTemp3 = 80
    };

enum
    {
    Sign_PauseX = 45,
    Sign_PauseY = 35,
    Sign_Pause_Radius = 25,
    Pause_Active = 2,
    Pause_Stopped = 1,

    Sign_CoinX = 20,
    Sign_CoinY = 70,
    Sign_CoinTextX = 70,
    Sign_CoinTextY = 95,

    Sign_LevelTextX = 180,
    Sign_LevelTextY = 38,

    Sign_TermometerX = 10,
    Sign_TermometerY = 160,
    Sign_Term_RectLeftX = 19,
    Sign_Term_RectRightX = 22,
    Sign_Term_RectDownY = 105,

    Sign_HealthX = 10,
    Sign_HealthY = 113,

    Main_Sleep = 30
    };

enum
    {
    Text1_X = 800,
    Text1_Y = 100,
    Text1_Size = 40,

    Text2_X = 800,
    Text2_Y = 200,
    Text2_Size = 80,
    };

enum
    {
    Load_BigRect_X1 = 200,
    Load_BigRect_Y1 = 500,
    Load_BigRect_X2 = 1350,
    Load_BigRect_Y2 = 550,

    Load_SmallRect_X1 = 200,
    Load_SmallRect_Y1 = 500,
    Load_SmallRect_Y2 = 550,

    Loading_TextX = 750,
    Loading_TextY = 400,

    Loading_Sleep = 20
    };

enum Screen
    {
    Screen_xCenter = 725,
    Screen_yCenter = 425
    };

struct BaseType
    {
    double x;
    double y;

    double Health;
    };

struct ImageType
    {
    const char* FileName;

    int xNumber;
    int yNumber;

    int xMaxAnimationNumber;
    int yMaxAnimationNumber;

    HDC Picture;

    COLORREF color;
    };

struct AllImageType
    {
    ImageType BackGround;
    ImageType Cursor;
    ImageType Dirt;
    ImageType Health;
    ImageType Finish;
    ImageType Start;
    ImageType Pause;
    ImageType Coin;
    ImageType CoinAnimation;
    ImageType Box;
    ImageType Man;
    ImageType Stairs;
    ImageType Fire;
    ImageType GreenFire;
    ImageType BlackSpace;
    ImageType Bat;
    ImageType Stalactite;
    ImageType GameOver;
    ImageType Pickaxe;
    ImageType Termometer;
    ImageType Berries;
    ImageType Chest;
    ImageType IronOre;
    ImageType Water;
    };

struct ManType
    {
    BaseType Base;

    int xNumber;
    int yNumber;

    double vX;
    double vY;

    double aX;
    double aY;

    int Side;
    int Position;

    int LeftArm;
    int RightArm;

    ImageType* LeftArmPicture;
    ImageType* RightArmPicture;

    double Temperature;

    int NumberCoin;

    ImageType* Picture;
    };

struct ButtonType
    {
    int x;
    int y;

    int Number;
    };

struct MouseType
    {
    int x;
    int y;

    ImageType Picture;
    };

struct BlockType
    {
    BaseType Base;

    int xNumber;
    int yNumber;

    int Number;

    ImageType* Picture;
    };

struct CamType
    {
    double x;
    double y;
    };

void Cycle ();

void MoveGame (BlockType ManyBlocks [], AllImageType AllImage, int* LevelNumber, ManType* Man, double* AllTemperature, CamType* Camera, CamType* FixedCamera);

void DeleteImage (AllImageType AllImage);

void DrawLevelBlocks (BlockType ManyBlocks[], CamType* Camera, AllImageType AllImage);

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man, int* NumberCoin);

void Level1 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera);

void Level2 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera);

void DrawManyBlocks (BlockType ManyBlocks [], CamType* Camera, AllImageType AllImage);

void InteractManWithBlocks (BlockType ManyBlocks [], ManType* Man, int* NumberCoin, int* LevelNumber);

void LoadGameImage (ImageType* Image, const char* Picture, int xNumber, int yNumber, int xMaxNumber, int yMaxNumber, COLORREF color,
                    int* Procent, double Number);

void DrawMan (ManType* Man, CamType* Camera, AllImageType AllImage);

void ManFire (ManType* Man, CamType* Camera, AllImageType AllImage);

void ManHealth (ManType* Man, CamType* Camera, AllImageType AllImage);

void ManTemperature (ManType* Man);

void DrawInventory (ManType* Man, CamType* Camera, CamType* FixedCamera, AllImageType AllImage);

void DrawButton (ButtonType Button, CamType* Camera, AllImageType AllImage);

void DrawBlock (BlockType* Block, CamType* Camera, AllImageType AllImage);

int Collision (BlockType* Block, ManType* Man);

void ChangeAnimationNumber (BlockType* Block, ManType* Man, AllImageType AllImage);

void ControlMan (ManType* Man, MouseType Mouse, int* t);

int ButtonCheckClick (int x1, int y1, int x2, int y2, int DstX, int DstY);

void DrawButton (ButtonType Button, CamType* Camera);

void DrawCursor (MouseType* Mouse, CamType* Camera);

void Physic (ManType* Man);

void BlockCollision (ManType* Man, BlockType* Block);

void CoinCollision (ManType* Man, BlockType* Coin, int* NumberCoin);

int ModuleDistance (int x1, int y1, int x2, int y2, int Distance);

int Distance (int a, int b, int Distance);

void DrawHealth (int Health, CamType* Camera, AllImageType AllImage);

void BlockCalling (BlockType* Block, ManType* Man);

void DrawLoading (int Procents);

void LoadImage (AllImageType* AllImage);

void Text (int x, int y, int Size, int Number, char Name []);

void DrawTransparentImage (ImageType* Image, CamType* Camera, int x, int y, int* xAnimationNumber, int* yAnimationNumber);

void LoadImages (AllImageType* AllImages);

void HelpSystem ();

void MoveCamera (CamType* Camera, ManType* Man);

int main ()
    {
    txCreateWindow (1550, 850);

    Cycle ();

    return 0;
    };

void LoadAllImages (AllImageType* AllImages)
    {
    int Procent = 1;

    LoadGameImage (&AllImages->BackGround,    "Images/Dungeon.bmp",                1, 1, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    // printf ("1:LoadAllImages(): File = %s , HDC = %d \n", AllImages->BackGround.FileName, AllImages->BackGround.Picture);

    LoadGameImage (&AllImages->Cursor,        "Images/GameCursor.bmp",             1, 1, 1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Dirt,          "Images/DirtAnimation.bmp",          4, 3, 1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Health,        "Images/GameHeart.bmp",              1, 1, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Finish,        "Images/Finish.bmp",                 1, 1, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Start,         "Images/Start.bmp",                  1, 1, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Pause,         "Images/GamePause.bmp",              2, 1, 1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Coin,          "Images/GameCoin.bmp",               1, 1, 1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->CoinAnimation, "Images/CoinAnimation.bmp",          4, 1, 4, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Box,           "Images/WoodBoxAnimation.bmp",       4, 3, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Man,           "Images/AllAnimationGamePeople.bmp", 9, 2, 9, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Stairs,        "Images/Stairs.bmp",                 4, 3, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Fire,          "Images/FireAnimation.bmp",          8, 1, 5, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->GreenFire,     "Images/GreenFire.bmp",              4, 1, 5, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->BlackSpace,    "Images/Black.bmp",                  4, 3, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bat,           "Images/Bat.bmp",                    4, 2, 4, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Stalactite,    "Images/Stalactite.bmp",             4, 3, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->GameOver,      "Images/GameOver.bmp",               1, 1, 1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Pickaxe,       "Images/Pickaxe.bmp",                4, 3, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Termometer,    "Images/termometer.bmp",             1, 1, 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Berries,       "Images/Berries.bmp",                4, 5, 1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Chest,         "Images/Chest.bmp",                  4, 3, 1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->IronOre,       "Images/IronOre.bmp",                4, 3, 1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Water,         "Images/Water2.bmp",                 4, 1, 1, 1, TX_BLACK, &Procent, Number_of_Images);
    };

void Cycle ()
    {
    AllImageType AllImage = {};

    LoadAllImages (&AllImage);

    int LevelNumber = 1;

    // double AllTemperature = 10;

    CamType Camera = {Man_x - Screen_xCenter, Man_y - Screen_yCenter};

    CamType FixedCamera = {Man_x, Man_y};

    ManType Man = {{Man_x, Man_y, Man_Health}, 0, 0, 0, 0, Man_aX, 2, 0, 0, BT_BlackSpace, BT_BlackSpace, &AllImage.BlackSpace, &AllImage.BlackSpace, Man_Temperature, 0, &AllImage.Man};

    while (true)
        {
        txSetFillColor (RGB (72, 72, 72));
        txClear ();

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

void DrawInventory (ManType* Man, CamType* Camera, CamType* FixedCamera, AllImageType AllImage)
    {
    int null = 0;

    txSetColor (TX_DARKGREY, 5);
    txSetFillColor (TX_TRANSPARENT);

    txSelectFont ("Comic Sans MS", Inventory_TextSize);
    txTextOut (Inv_LeftArm_TextX, Inv_LeftArm_TextY, "Left");
    txTextOut (Inv_RightArm_TextX, Inv_RightArm_TextY, "Right");

    txRectangle  (Inv_LeftArm_RectLeftX, Inv_LeftArm_RectLeftY, Inv_LeftArm_RectRightX, Inv_LeftArm_RectRightY);
    txRectangle  (Inv_RightArm_RectLeftX, Inv_RightArm_RectLeftY, Inv_RightArm_RectRightX, Inv_RightArm_RectRightY);

    if (Man->LeftArm != BT_BlackSpace)
        DrawTransparentImage (Man->LeftArmPicture, FixedCamera, Inv_LeftArm_RectLeftX, Inv_LeftArm_RectLeftY, &null, &null);

    if (Man->RightArm != BT_BlackSpace)
        DrawTransparentImage (Man->RightArmPicture, FixedCamera, Inv_RightArm_RectLeftX, Inv_RightArm_RectLeftY, &null, &null);

    if (Man->Side == 1)
            {
            if (Man->LeftArm != BT_BlackSpace)
                DrawTransparentImage (Man->LeftArmPicture, Camera, Man->Base.x + 40, Man->Base.y + 35, &null, &null);
            if (Man->RightArm != BT_BlackSpace)
                DrawTransparentImage (Man->RightArmPicture, Camera, Man->Base.x - 40, Man->Base.y + 25, &null, &null);
            };

    if (Man->Side == 2)
            {
            if (Man->LeftArm != BT_BlackSpace)
                DrawTransparentImage (Man->LeftArmPicture, Camera, Man->Base.x + 80, Man->Base.y + 25, &null, &null);
            if (Man->RightArm != BT_BlackSpace)
                DrawTransparentImage (Man->RightArmPicture, Camera, Man->Base.x + 5, Man->Base.y + 35, &null, &null);
            };

    if (Man->LeftArm == 0)
        Man->LeftArmPicture = &AllImage.BlackSpace;

    if (Man->RightArm == 0)
        Man->RightArmPicture = &AllImage.BlackSpace;
    };

void DrawBlock (BlockType* Block, CamType* Camera, AllImageType AllImage)
    {
    Block->xNumber += 1;

    if (Block->xNumber >= Block->Picture->xMaxAnimationNumber)
        Block->xNumber = 0;

    if (Block->Base.Health > 0)
        DrawTransparentImage (Block->Picture, Camera, Block->Base.x + Block_BaseWide*2, Block->Base.y, &Block->xNumber, &Block->yNumber);
    };

int Collision (BlockType* Block, ManType* Man)
    {
    if (fabs (Man->Base.x - (Block->Base.x + Block_BaseWide)) <= Block_BaseWide + Man_Wide &&
        fabs (Man->Base.y - (Block->Base.y + Block_BaseHigh)) <= Block_BaseHigh + Man_High)
    return 1;

    return 0;
    };

void DrawMan (ManType* Man, CamType* Camera, AllImageType AllImage)
    {
    Man->xNumber += 1;

    if (Man->xNumber >= Man->Picture->xMaxAnimationNumber)
        Man->xNumber = 0;

    if (Man->vX > 0)
        {
        Man->yNumber = 1;
        };

    if (Man->vX < 0)
        {
        Man->yNumber = 0;
        };

    int null = 0;

    if (Man->Base.Health > 0)
        DrawTransparentImage (Man->Picture, Camera, Man->Base.x, Man->Base.y, &Man->xNumber, &Man->yNumber);

    // printf ("Man->x = %lf, Man->y = %lf, Camera->x = %d, Camera->y = %d \n", Man->Base.x, Man->Base.y, Camera->x, Camera->y);
    };

void ManFire (ManType* Man, CamType* Camera, AllImageType AllImage)
    {
    BlockType Fire1 = {{0 - txGetExtentX (Man->Picture->Picture)/2 + Man_Fire1X, 0 - txGetExtentY (Man->Picture->Picture)/2 + Man_Fire1Y, 4}, rand() % 4, 0, 0, &AllImage.Fire};
    BlockType Fire2 = {{0 - txGetExtentX (Man->Picture->Picture)/2 + Man_Fire2X, 0 - txGetExtentY (Man->Picture->Picture)/2 + Man_Fire2Y, 4}, rand() % 4, 0, 0, &AllImage.Fire};
    BlockType Fire3 = {{0 - txGetExtentX (Man->Picture->Picture)/2 + Man_Fire3X, 0 - txGetExtentY (Man->Picture->Picture)/2 + Man_Fire3Y, 4}, rand() % 4, 0, 0, &AllImage.Fire};

    if (Man->Position == Fire_Position)
        {
        Man->Base.Health -= Man_FireDamage/100;
        Man->Temperature += 1;
        DrawBlock (&Fire1, Camera, AllImage);
        DrawBlock (&Fire2, Camera, AllImage);
        DrawBlock (&Fire3, Camera, AllImage);
        };
    };

void ManHealth (ManType* Man, CamType* Camera, AllImageType AllImage)
    {
    int null = 0;

    if (Man->Base.Health < 0)
        {
        Man->Base.Health = 0;
        };

    if (Man->Base.Health == 0)
        {
        DrawTransparentImage (&AllImage.GameOver, Camera, Man->Base.x, Man->Base.y, &null, &null);
        Man->vX = 0;
        Man->vY = 0;
        Man->Position = 0;
        Man->LeftArm = 0;
        Man->LeftArmPicture = &AllImage.BlackSpace;
        Man->RightArm = 0;
        Man->RightArmPicture = &AllImage.BlackSpace;
        };

    if (Man->Base.Health > Man_MaxHealth)
        Man->Base.Health = Man_MaxHealth;
    };

void ManTemperature (ManType* Man)
    {
    if (Man->Temperature < 0)
        {
        Man->Temperature = 0;
        };

    if (Man->Temperature > Man_MaxTemperature)
        {
        Man->Temperature = Man_MaxTemperature;
        };

    if (Man->Temperature <= Man_ColdTemp1)
        Man->Base.Health -= Man_ColdTempDamage/1000*Man_TempDamage1;

    if (Man->Temperature <= Man_ColdTemp2)
        Man->Base.Health -= Man_ColdTempDamage/1000*Man_TempDamage2;

    if (Man->Temperature <= Man_ColdTemp3)
        Man->Base.Health -= Man_ColdTempDamage/1000*Man_TempDamage3;

    if (Man->Temperature >= Man_HotTemp1)
        Man->Base.Health -= Man_HotTempDamage/1000*Man_TempDamage1;

    if (Man->Temperature >= Man_HotTemp2)
        Man->Base.Health -= Man_HotTempDamage/1000*Man_TempDamage2;

    if (Man->Temperature >= Man_HotTemp3)
        Man->Base.Health -= Man_HotTempDamage/1000*Man_TempDamage3;
    };

int Distance (int a, int b, int Dst)
    {
    if (fabs (a - b) <= Dst)
        return 1;

    return 0;
    };

void DrawButton (ButtonType Button, CamType* Camera, AllImageType AllImage)
    {
    int null = 0;

    DrawTransparentImage (&AllImage.Pause, Camera, Button.x, Button.y, &Button.Number, &null);
    };

void DrawCursor (MouseType* Mouse, CamType* Camera)
    {
    Mouse->x = txMouseX ();

    Mouse->y = txMouseY ();

    int null = 0;

    DrawTransparentImage (&Mouse->Picture, Camera, Mouse->x, Mouse->y, &null, &null);
    };

void DeleteAllImage (AllImageType AllImages)
    {
    txDeleteDC (AllImages.BackGround.Picture);
    txDeleteDC (AllImages.Cursor.Picture);
    txDeleteDC (AllImages.Dirt.Picture);
    txDeleteDC (AllImages.Health.Picture);
    txDeleteDC (AllImages.Finish.Picture);
    txDeleteDC (AllImages.Start.Picture);
    txDeleteDC (AllImages.Pause.Picture);
    txDeleteDC (AllImages.Coin.Picture);
    txDeleteDC (AllImages.CoinAnimation.Picture);
    txDeleteDC (AllImages.Box.Picture);
    txDeleteDC (AllImages.Man.Picture);
    txDeleteDC (AllImages.Stairs.Picture);
    txDeleteDC (AllImages.Fire.Picture);
    txDeleteDC (AllImages.GreenFire.Picture);
    txDeleteDC (AllImages.Water.Picture);
    txDeleteDC (AllImages.Bat.Picture);
    txDeleteDC (AllImages.Stalactite.Picture);
    txDeleteDC (AllImages.GameOver.Picture);
    txDeleteDC (AllImages.Pickaxe.Picture);
    };

void MoveGame (BlockType ManyBlocks [], AllImageType AllImage, int* LevelNumber, ManType* Man, double* AllTemperature, CamType* Camera, CamType* FixedCamera)
    {
    int StartLevelNumber = *LevelNumber;

    int NumberPicture = 0;

    int Time = GetTickCount();

    ButtonType Pause = {Sign_PauseX - Sign_Pause_Radius, Sign_PauseY - Sign_Pause_Radius, 0};

    MouseType Mouse = {txMouseX(), txMouseY(), AllImage.Cursor};

    int t = 0;

    int NumberLevel = *LevelNumber;

    int PauseNumber = Pause_Active;

    txBegin ();

    while (true)
        {
        txSetFillColor (RGB (72, 72, 72));
        txClear ();

        NumberLevel = *LevelNumber;

        Time = Time + 1;

        int null = 0;

        MoveCamera (Camera, Man);

        DrawTransparentImage (&AllImage.BackGround, FixedCamera, 0, 0, &null, &null);

        DrawManyBlocks (ManyBlocks, Camera, AllImage);

        DrawMan (Man, Camera, AllImage);

        DrawTransparentImage (&AllImage.Coin, FixedCamera, Sign_CoinX, Sign_CoinY, &null, &null);

        ManFire (Man, Camera, AllImage);
        ManHealth (Man, Camera, AllImage);
        ManTemperature (Man);

        DrawInventory (Man, Camera, FixedCamera, AllImage);

        InteractManWithBlocks (ManyBlocks, Man, &Man->NumberCoin, LevelNumber);

        Physic (Man);

        ControlMan (Man, Mouse, &t);

        if (ButtonCheckClick (Sign_PauseX, Sign_PauseY, txMouseX(), txMouseY(), Sign_Pause_Radius, Sign_Pause_Radius) == true)
            {
            PauseNumber = Pause_Stopped;
            };

        Text (Sign_CoinTextX, Sign_CoinTextY, Coin_TextSize, Man->NumberCoin, "");

        Text (Sign_LevelTextX, Sign_LevelTextY, Level_TextSize, NumberLevel, "Level");

        DrawButton (Pause, FixedCamera, AllImage);

        DrawHealth (Man->Base.Health, FixedCamera, AllImage);

        if (PauseNumber == Pause_Stopped)
            {
            Man->vX = 0;
            Man->vY = 0;

            Pause.Number = Pause_Stopped;

            if (ButtonCheckClick (Sign_PauseX, Sign_PauseY, txMouseX(), txMouseY(), Sign_Pause_Radius, Sign_Pause_Radius) == 1)
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

        txSetColor (TX_RED);
        txSetFillColor (TX_RED);

        DrawTransparentImage (&AllImage.Termometer, FixedCamera, Sign_TermometerX, Sign_TermometerY, &null, &null);
        txRectangle (Sign_TermometerX + Sign_Term_RectLeftX, Sign_TermometerY + Sign_Term_RectDownY - Man->Temperature,
                     Sign_TermometerX + Sign_Term_RectRightX, Sign_TermometerY + Sign_Term_RectDownY);

        if (GetAsyncKeyState (VK_SPACE))
            {
            HelpSystem ();
            };

        DrawCursor (&Mouse, FixedCamera);

        if (StartLevelNumber != *LevelNumber)
            {
            break;
            };

        if (GetAsyncKeyState (VK_ESCAPE))
            break;

        txSleep (Main_Sleep);
        };
    txEnd ();

    DeleteAllImage (AllImage);
    };

void MoveCamera (CamType* Camera, ManType* Man)
    {
    /* if (GetAsyncKeyState (VK_RIGHT))
            {
            Camera->x += 5;
            };

    if (GetAsyncKeyState (VK_LEFT))
            {
            Camera->x -= 5;
            };

    if (GetAsyncKeyState (VK_CONTROL) &&
        GetAsyncKeyState (VK_UP))
            {
            Camera->y -= 10;
            };

    if (GetAsyncKeyState (VK_CONTROL) &&
        GetAsyncKeyState (VK_DOWN))
            {
            Camera->y += 10;
            }; */

    if (GetKeyState (VK_CAPITAL))
        printf ("Camera->x = %lf, Camera->y = %lf, Man->x = %lf, Man->y = %lf \n", Camera->x, Camera->y, Man->Base.x, Man->Base.y);
    else
        txClearConsole ();

    double CameraTime = 0.3;

    Camera->x -= (Camera->x + Screen_xCenter - Man->Base.x) * CameraTime;
    Camera->y -= (Camera->y + Screen_yCenter - Man->Base.y) * CameraTime;
    };

void HelpSystem ()
    {
    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", Text1_Size);
    txTextOut (Text1_X, Text1_Y, "��� ������������ ������� ������� ������ � �����, ��� ��������� ������� Shift");

    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", Text2_Size);
    txTextOut (Text2_X, Text2_Y, "������� ����!");
    };

void Text (int x, int y, int Size, int Number, char Name [])
    {
    char str [50] = "";

    sprintf (str, "%s %d", Name, Number);

    txSetTextAlign ();
    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", Size);
    txTextOut (x, y, str);
    };

void DrawLoading (int Procents)
    {
    txSetColor (RGB (72, 72, 72));
    txSetFillColor (RGB (72, 72, 72));
    txRectangle (0, 0, 2000, 2000);
    txSetColor (TX_BLACK, 3);
    txRectangle (Load_BigRect_X1, Load_BigRect_Y1, Load_BigRect_X2, Load_BigRect_Y2);
    txSetFillColor (TX_GREEN);
    txRectangle (Load_SmallRect_X1, Load_SmallRect_Y1, 200+(11.50*Procents), Load_SmallRect_Y2);

    char str [50] = "";

    sprintf (str, "Loading: %d%%", Procents);

    txSetTextAlign ();
    txSetColor (TX_BLACK);
    txSelectFont ("Comic Sans MS", Loading_TextSize);
    txTextOut (Loading_TextX, Loading_TextY, str);
    };

void Level1 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera)
    {
    double AllTemperature = 10;

    BlockType ManyBlocks [] = {// Ground
                               {{ -75,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ -25,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 25,   675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 75,   675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 125,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 175,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 225,  675, 6}, rand() % 4, 0, BT_Water, &AllImage.Water},
                               {{ 275,  675, 6}, rand() % 4, 0, BT_Water, &AllImage.Water},
                               {{ 325,  675, 6}, rand() % 4, 0, BT_Water, &AllImage.Water},
                               {{ 375,  675, 6}, rand() % 4, 0, BT_Water, &AllImage.Water},
                               {{ 425,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 475,  675, 6}, 0, 0, BT_Dirt, &AllImage.IronOre},
                               {{ 525,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 575,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 625,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 675,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 725,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 775,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 825,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 875,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 925,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 975,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1025,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1075,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1125,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1175,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1225,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1275,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1325,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1375,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1425,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1475,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1525,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},

                               {{ -75,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ -25,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{  25,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{  75,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 125,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 175,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 225,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 275,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 325,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 375,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 425,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 475,  725, 6}, 0, 0, BT_Dirt, &AllImage.IronOre},
                               {{ 525,  725, 6}, 0, 0, BT_Dirt, &AllImage.IronOre},
                               {{ 575,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 625,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 725,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 725,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 775,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 825,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 875,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 925,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 975,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1025,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1075,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1125,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1175,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1225,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1275,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1325,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1375,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1425,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1475,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1525,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               // Platforms
                               {{ 100,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 150,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 200,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 250,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 300,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 350,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 200,  500, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 250,  500, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 300,  500, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 350,  500, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 450,  400, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 500,  400, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 550,  400, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 550,  100, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 600,  100, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 650,  100, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 700,  100, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 850,  300, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 900,  300, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 950,  300, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1050,  150, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1100,  150, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1150,  150, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1300,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1350,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1400,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1450,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1500,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1550,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               // Boxes
                               {{ 100,  625, 2}, 0, 0,  BT_Box, &AllImage.Box},
                               {{  50,  625, 2}, 0, 0,  BT_Box, &AllImage.Box},
                               {{ 100,  575, 2}, 0, 0,  BT_Box, &AllImage.Box},
                               // Fire
                               {{ 900,  615, 4}, 1, 0,  BT_Fire, &AllImage.Fire},
                               {{ 800,  615, 4}, 3, 0,  BT_Fire, &AllImage.Fire},
                               // Stalactites
                               {{ 100,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 150,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 200,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 250,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 300,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 350,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 200,  550, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 250,  550, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 300,  550, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 350,  550, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 450,  450, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 500,  450, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 550,  450, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 550,  150, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 600,  150, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 650,  150, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 700,  150, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 850,  350, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 900,  350, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 950,  350, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1050,  200, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1100,  200, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1150,  200, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1300,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1350,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1400,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1450,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1500,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1550,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               // Stairs
                               {{ 700,  592, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  509, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  426, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  343, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  260, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  177, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,   94, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               // Berries
                               {{1100,  625, 1000}, 0, 0, BT_Berries, &AllImage.Berries},
                               // Chests
                               {{1300,  625, 6}, 0, 0,  BT_Chest, &AllImage.Chest},
                               // Things
                               {{1175,  625, 16}, 0, 0, BT_Pickaxe, &AllImage.Pickaxe},
                               {{ 250,  450, 16}, 0, 0, BT_Pickaxe, &AllImage.Pickaxe},
                               // Coins
                               {{160,  165, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{310,  165, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{260,  465, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{310,  465, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{510,  365, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{560,  65,  1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{710,  65,  1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{910,  265, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{1110, 115, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{1360, 215, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               // Start
                               {{-100, -1000000, 1}, 0, 0, BT_Start, &AllImage.Start},
                               // Finish
                               {{1450, -1000000, 1}, 0, 0, BT_Finish, &AllImage.Finish},
                               // End
                               {{  -1,   -6}}};

    MoveGame (ManyBlocks, AllImage, LevelNumber, Man, &AllTemperature, Camera, FixedCamera);
    };

void Level2 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera)
    {
    double AllTemperature = 10;


    BlockType ManyBlocks [] = {// Ground
                               {{ -75,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ -25,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 25,   675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 75,   675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 125,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 175,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 225,  675, 6}, rand() % 4, 0, BT_Water, &AllImage.Water},
                               {{ 275,  675, 6}, rand() % 4, 0, BT_Water, &AllImage.Water},
                               {{ 325,  675, 6}, rand() % 4, 0, BT_Water, &AllImage.Water},
                               {{ 375,  675, 6}, rand() % 4, 0, BT_Water, &AllImage.Water},
                               {{ 425,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 475,  675, 6}, 0, 0, BT_Dirt, &AllImage.IronOre},
                               {{ 525,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 575,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 625,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 675,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 725,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 775,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 825,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 875,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 925,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 975,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1025,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1075,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1125,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1175,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1225,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1275,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1325,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1375,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1425,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1475,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1525,  675, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},

                               {{ -75,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ -25,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{  25,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{  75,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 125,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 175,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 225,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 275,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 325,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 375,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 425,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 475,  725, 6}, 0, 0, BT_Dirt, &AllImage.IronOre},
                               {{ 525,  725, 6}, 0, 0, BT_Dirt, &AllImage.IronOre},
                               {{ 575,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 625,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 725,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 725,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 775,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 825,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 875,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 925,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 975,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1025,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1075,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1125,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1175,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1225,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1275,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1325,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1375,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1425,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1475,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1525,  725, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               // Platforms
                               {{ 100,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 150,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 200,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 250,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 300,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 350,  200, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 200,  500, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 250,  500, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 300,  500, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 350,  500, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 450,  400, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 500,  400, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 550,  400, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 550,  100, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 600,  100, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 650,  100, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 700,  100, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 850,  300, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 900,  300, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{ 950,  300, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1050,  150, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1100,  150, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1150,  150, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1300,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1350,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1400,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1450,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1500,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               {{1550,  250, 6}, 0, 0, BT_Dirt, &AllImage.Dirt},
                               // Boxes
                               {{ 100,  625, 2}, 0, 0,  BT_Box, &AllImage.Box},
                               {{  50,  625, 2}, 0, 0,  BT_Box, &AllImage.Box},
                               {{ 100,  575, 2}, 0, 0,  BT_Box, &AllImage.Box},
                               // Fire
                               {{ 900,  615, 4}, 1, 0,  BT_Fire, &AllImage.Fire},
                               {{ 800,  615, 4}, 3, 0,  BT_Fire, &AllImage.Fire},
                               // Stalactites
                               {{ 100,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 150,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 200,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 250,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 300,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 350,  250, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 200,  550, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 250,  550, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 300,  550, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 350,  550, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 450,  450, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 500,  450, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 550,  450, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 550,  150, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 600,  150, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 650,  150, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 700,  150, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 850,  350, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 900,  350, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{ 950,  350, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1050,  200, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1100,  200, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1150,  200, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1300,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1350,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1400,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1450,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1500,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               {{1550,  300, 7}, 0, 0,  BT_Stalactite, &AllImage.Stalactite},
                               // Stairs
                               {{ 700,  592, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  509, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  426, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  343, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  260, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,  177, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               {{ 700,   94, 3}, 0, 0,  BT_Stairs, &AllImage.Stairs},
                               // Berries
                               {{1100,  625, 1000}, 0, 0, BT_Berries, &AllImage.Berries},
                               // Chests
                               {{1300,  625, 6}, 0, 0,  BT_Chest, &AllImage.Chest},
                               // Things
                               {{1175,  625, 16}, 0, 0, BT_Pickaxe, &AllImage.Pickaxe},
                               {{ 250,  450, 16}, 0, 0, BT_Pickaxe, &AllImage.Pickaxe},
                               // Coins
                               {{160,  165, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{310,  165, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{260,  465, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{310,  465, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{510,  365, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{560,  65,  1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{710,  65,  1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{910,  265, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{1110, 115, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               {{1360, 215, 1}, 0, 0, BT_Coin, &AllImage.CoinAnimation},
                               // Start
                               {{-100, -1000000, 1}, 0, 0, BT_Start, &AllImage.Start},
                               // Finish
                               {{1450, -1000000, 1}, 0, 0, BT_Finish, &AllImage.Finish},
                               // End
                               {{  -1,   -6}}};

    MoveGame (ManyBlocks, AllImage, LevelNumber, Man, &AllTemperature, Camera, FixedCamera);
    };

void DrawManyBlocks (BlockType ManyBlocks [], CamType* Camera, AllImageType AllImage)
    {
    DrawLevelBlocks (ManyBlocks, Camera, AllImage);
    };

void InteractManWithBlocks (BlockType ManyBlocks [], ManType* Man, int* NumberCoin,
                            int* LevelNumber)
    {
    CallLevelPhysic (ManyBlocks, Man, NumberCoin);
    };

void CoinCollision (ManType* Man, BlockType* Coin, int* NumberCoin)
    {
    if (Coin->Base.Health > 0 &&
        Coin->Number == BT_Coin)
    {
    if (Collision (Coin, Man) == true)
        {
        *NumberCoin += 1;
        Coin->Base.Health = 0;
        };
    };
    };

void LoadGameImage (ImageType* Image, const char* Picture, int xNumber, int yNumber, int xMaxNumber, int yMaxNumber, COLORREF color,
                        int* Procent, double Number)
    {
    *Procent += 100.0/Number;

    DrawLoading (*Procent);

    // printf ("LoadGameImage(): Picture = \"%s\" \n", Picture);

    // *Image = {Picture, xNumber, yNumber, xMaxNumber, yMaxNumber, txLoadImage (Picture), color};

    Image->FileName = Picture;

    Image->xNumber = xNumber;

    Image->yNumber = yNumber;

    Image->xMaxAnimationNumber = xMaxNumber;

    Image->yMaxAnimationNumber = yMaxNumber;

    Image->Picture = txLoadImage (Picture);

    Image->color = color;

    if (Image->Picture == 0)
        {
        // printf ("FileName = \"%s\" \n", Image->FileName);
        };

    // printf ("LoadGameImage(): FileName = \"%s\", HDC = \"%p\" \n", Image->FileName, Image->Picture);

    txSleep (Loading_Sleep);
    };

void DrawTransparentImage (ImageType* Image, CamType* Camera, int x, int y, int* xAnimationNumber, int* yAnimationNumber)
    {
    // printf ("DrawTransparentImage(): FileName = \"%s\", HDC = \"%p\" \n", Image.FileName, Image.Picture);

    int xSize = txGetExtentX (Image->Picture)/Image->xNumber;
    int ySize = txGetExtentY (Image->Picture)/Image->yNumber;

    txTransparentBlt (txDC (), x - Camera->x, y - Camera->y, xSize, ySize, Image->Picture, *xAnimationNumber*xSize, *yAnimationNumber*ySize, Image->color);

    if (*xAnimationNumber >= Image->xMaxAnimationNumber)
        {
        *xAnimationNumber = 0;
        };

    if (*yAnimationNumber >= Image->yMaxAnimationNumber)
        {
        *yAnimationNumber = 0;
        };
    };

void DrawLevelBlocks (BlockType ManyBlocks[], CamType* Camera, AllImageType AllImage)
    {
    int i = 0;

    while (ManyBlocks[i].Base.x != -1 && ManyBlocks[i].Base.y != -1)
        {
        DrawBlock (&ManyBlocks [i], Camera, AllImage);

        i = i + 1;
        };
    };

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man, int* NumberCoin)
    {
    int i = 0;

    while (ManyBlocks[i].Base.x != -1 && ManyBlocks[i].Base.y != -1)
        {
        BlockCollision (Man, &ManyBlocks [i]);

        CoinCollision (Man, &ManyBlocks [i], NumberCoin);

        i = i + 1;
        };
    };



void BlockCalling (BlockType* Block, ManType* Man)
    {
    BlockCollision (Man, Block);
    };

void ControlMan (ManType* Man, MouseType Mouse, int* t)
    {
    if (GetAsyncKeyState (VK_RIGHT))
        {
        Man->vX = Man_SlowSpeed;
        Man->Side = Man_RightSide;
        };

    if (GetAsyncKeyState (VK_LEFT))
        {
        Man->vX = -Man_SlowSpeed;
        Man->Side = Man_LeftSide;
        };

    if (Man->vX > 0)
        {
        if (GetAsyncKeyState (VK_SHIFT))
            {
            Man->vX = Man_FastSpeed;
            };
        };

    if (Man->vX < 0)
        {
        if (GetAsyncKeyState (VK_SHIFT))
            {
            Man->vX = -Man_FastSpeed;
            };
        };
    };

void Physic (ManType* Man)
    {
    Man->Base.x = Man->Base.x + Man->vX;
    Man->Base.y = Man->Base.y + Man->vY;

    Man->vX = Man->vX + Man->aX;
    Man->vY = Man->vY + Man->aY;

    Man->vX = Man->vX*0.5;

    Man->aY = Man_aY;
    };

void BlockCollision (ManType* Man, BlockType* Block)
    {
    if (Block->Number != BT_Coin)
    {

    // Physic
    if (Block->Base.Health  >= 1 &&
        Block->Number != BT_Fire &&
        Block->Number != BT_Water &&
        Block->Number != BT_Stalactite &&
        Block->Number < BT_Pickaxe)
    {
    if (fabs (Block->Base.x + Block_BaseWide - Man->Base.x) <= Block_BaseWide + Man_Wide &&
        Block->Base.y + Block_BaseHigh - Man->Base.y <= Block_BaseHigh + Man_High &&
        Block->Base.y + Block_BaseHigh - Man->Base.y  >=  0)
            {
            if (GetAsyncKeyState (VK_UP))
                {
                Man->vY = -Man_JumpSpeed;
                };

            if (Man->vY > 0)
                {
                Man->vY = 0;
                Man->Base.y = Block->Base.y - Man_High;
                };
            };
        };

    // Destroying
    if (Block->Base.Health > 0 &&
        Block->Base.Health < 50 &&
        Block->Number != BT_Fire &&
        Block->Number != BT_Berries &&
        Block->Number != BT_Chest)
    {
    if (ModuleDistance (Block->Base.x + Block_BaseWide + Man->Base.x, Block->Base.y + Block_BaseHigh + Man->Base.x, txMouseX(), txMouseY(), Block_BaseWide) == true)
        if (GetAsyncKeyState (VK_LBUTTON) &&
            Man->LeftArm == BT_Pickaxe &&
            Block->Base.Health > 1)
               Block->Base.Health -= 1;

    if (ModuleDistance (Block->Base.x + Block_BaseWide + Man->Base.x, Block->Base.y + Block_BaseHigh + Man->Base.x, txMouseX(), txMouseY(), Block_BaseWide) == true)
        if (GetAsyncKeyState (VK_RBUTTON) &&
            Man->RightArm == BT_Pickaxe &&
            Block->Base.Health > 1)
               Block->Base.Health -= 1;

    };

    // Boxes
    if (Block->Number == BT_Box)
        {
        if (Collision (Block, Man) == true)
            {
            Block->Base.Health = Block->Base.Health - Man->vY*0.0005;
            };
        };

    // Fire
    if (Block->Number == BT_Fire)
        {
        if (Collision (Block, Man) == true)
            {
            Man->Position = Fire_Position;
            Man->Temperature += 0.5;
            };
        };

    // Water
    if (Block->Number == BT_Water)
        {
        if (Collision (Block, Man) == true)
            {
            Man->Position = Normal_Position;
            };
        };

    // High
    if (Block->Base.x + Block_BaseWide - Man->Base.x >= Block_BaseWide + Man_Wide &&
        Block->Base.x + Block_BaseWide - Man->Base.x <= 0   &&
        Block->Base.y + Block_BaseHigh - Man->Base.y <= Block_BaseHigh + Man_High &&
        Block->Base.y + Block_BaseHigh - Man->Base.y > 0    &&
        Man->vY >= Man_FallingSpeed)
            {
            Man->Base.Health -= 3;
            };

    // Things
    if (Block->Number > BT_Pickaxe &&
        Block->Number <= BT_Berries &&
        Block->Base.Health > 0)
            {
            if (ModuleDistance (Block->Base.x+Block_BaseWide, Block->Base.y+Block_BaseHigh, txMouseX(), txMouseY(), Block_BaseWide) == true &&
                GetAsyncKeyState (VK_MBUTTON))
                    {
                    if (Man->LeftArm == BT_BlackSpace)
                        {
                        Man->LeftArm = Block->Number;
                        Man->LeftArmPicture = Block->Picture;
                        Block->Base.Health = 0;
                        }
                else
                if (Man->RightArm == BT_BlackSpace)
                    {
                    Man->RightArm = Block->Number;
                    Man->RightArmPicture = Block->Picture;
                    Block->Base.Health = 0;
                    };
            };
            };

    // Food
    if (Man->LeftArm >= BT_Berries &&
        GetAsyncKeyState (VK_NUMPAD1))
            {
            Man->LeftArm = BT_BlackSpace;
            Man->Base.Health += 4;
            };

    if (Man->RightArm >= BT_Berries &&
        GetAsyncKeyState (VK_NUMPAD2))
            {
            Man->RightArm = BT_BlackSpace;
            Man->Base.Health += 4;
            };

    if (ModuleDistance (Block->Base.x+Block_BaseWide, Block->Base.y+Block_BaseHigh, txMouseX(), txMouseY(), Block_BaseWide) == true &&
        Block->Number > BT_Berries &&
        Block->Base.Health == Block_MaxHealth &&
        GetAsyncKeyState (VK_RETURN))
        {
        if (Man->LeftArm == 0)
            {
            Man->LeftArm = Block->Number;
            Man->LeftArmPicture = Block->Picture;
            Block->Base.Health = 1;
            }
        else
        if (Man->RightArm == 0)
            {
            Man->RightArm = Block->Number;
            Man->RightArmPicture = Block->Picture;
            Block->Base.Health = 1;
            };
        };

    // Berries

    if (Block->Number > BT_Berries &&
        Block->Base.Health < Block_MaxHealth)
            {
            Block->Base.Health += 1;
            };

    };
    };

int ModuleDistance (int x1, int y1, int x2, int y2, int Distance)
    {
    if (fabs (x1 - x2) <= Distance)
        {
        if (fabs (y1 - y2) <= Distance)
            {
            return 1;
            };
        };

    return 0;
    };

int ButtonCheckClick (int x1, int y1, int x2, int y2, int DstX, int DstY)
    {
    if (fabs (x1 - x2) <= DstX)
        if (fabs (y1 - y2) <= DstY)
            if (GetAsyncKeyState (VK_LBUTTON))
                {
                return 1;
                };
    return 0;
    };

void DrawHealth (int Health, CamType* Camera, AllImageType AllImage)
    {
    int null = 0;

    DrawTransparentImage (&AllImage.Health, Camera, Sign_HealthX, Sign_HealthY, &null, &null);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (60, 120, 160, 140);
    txSetFillColor (TX_RED);
    txRectangle (60, 120, 60+(Health*5), 140);
    };



