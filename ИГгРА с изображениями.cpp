#include "TXLib.h"

// 123

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
    ImageType Water;
    ImageType Bat;
    ImageType Stalactite;
    ImageType GameOver;
    ImageType Pickaxe;
    ImageType Termometer;
    ImageType Berries;
    ImageType Chest;
    ImageType IronOre;
    };

struct ManType
    {
    BaseType Base;

    double vX;
    double vY;

    double aX;
    double aY;

    int Side;
    int Position;
    int Speed;

    int LeftArm;
    int RightArm;

    ImageType LeftArmPicture;
    ImageType RightArmPicture;

    double Temperature;
    };

struct EnemyType
    {
    int x;
    int y;

    int vX;
    int vY;

    int Side;
    double Health;

    ImageType LPicture;
    ImageType RPicture;
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

struct CoinType
    {
    BaseType Base;
    };

struct BlockType
    {
    BaseType Base;

    int Number;

    ImageType Picture;
    };

void Cycle ();

void MoveGame (BlockType ManyBlocks [], CoinType Coins [], BlockType* Start, BlockType* Finish, AllImageType AllImage, int* LevelNumber, ManType* Man, double* AllTemperature);

void DeleteImage (AllImageType AllImage);

void DrawLevelBlocks (BlockType ManyBlocks[], AllImageType AllImage, int AnimationNumber);

void DrawLevelCoins (CoinType Coins[], AllImageType AllImage, int AnimationNumber);

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man);

void CallCoinPhysic (CoinType Coins[], ManType* Man, int* NumberCoin);

void Level1 (int* LevelNumber, ManType* Man, AllImageType AllImage);

void Level2 (int* LevelNumber, ManType* Man, AllImageType AllImage);

void DrawManyBlocks (BlockType ManyBlocks [], CoinType Coins [], int AnimationNumber,
                     AllImageType AllImage, BlockType* Start, BlockType* Finish);

void InteractManWithBlocks (BlockType ManyBlocks [], CoinType Coins [], ManType* Man,
                            int* NumberCoin, int* LevelNumber, BlockType* Start, BlockType* Finish);

void LoadGameImage (ImageType* Image, const char* Picture, int xNumber, int yNumber, int xMaxNumber, int yMaxNumber, COLORREF color,
                    int* Procent, double Number);

void DrawMan (ManType* Man, AllImageType AllImage, int Number, int AnimationNumber, double StarsNumber);

void DrawInventory (ManType Man);

void DrawEnemy (EnemyType Enemy, AllImageType AllImage, int Number);

void DrawButton (ButtonType Button, AllImageType AllImage);

void DrawBlock (BlockType Block, int AnimationNumber, AllImageType AllImage);

void ControlMan (ManType* Man, MouseType Mouse, int* t);

void ControlBlock (BlockType* Block);

void PrintfBlocks (BlockType Blocks [], int NumberBlock);

int ButtonCheckClick (int x1, int y1, int x2, int y2, int DstX, int DstY);

void DrawButton (ButtonType Button);

void DrawCursor (MouseType Mouse);

void Menu (MouseType Mouse);

void Physic (ManType* Man);

void BlockPhysic (BlockType* Block);

void BlockCollision (ManType* Man, BlockType* Block);

void CoinCollision (ManType* Man, CoinType* Coin, int* NumberCoin);

int ModuleDistance (int x1, int y1, int x2, int y2, int Distance);

int Distance (int a, int b, int Distance);

void DrawHealth (int Health, AllImageType AllImage);

void Run (ManType* Man, HDC LeftLeg, HDC RightLeg);

void EnemyMind (ManType* Man, EnemyType* Enemy);

void DrawCoin (CoinType Coin, int AnimationNumber, AllImageType AllImage);

void DrawFinish (BlockType* Block);

void FinishCollision (ManType* Man, BlockType* Block, int* Level, int Number);

void BlockCalling (BlockType* Block, ManType* Man);

void DrawLoading (int Procents);

void LoadImage (AllImageType* AllImage);

void Text (int x, int y, int Size, int Number, char Name []);

void DrawTransparentImage (ImageType Image, int x, int y, int* xAnimationNumber, int* yAnimationNumber);

void LoadImages (AllImageType* AllImages);

int main ()
    {
    txCreateWindow (1550, 850);

    int Procent = 1;
    int Number = 1;

    Cycle ();

    return 0;
    };

void LoadAllImages (AllImageType* AllImages)
    {
    int Number = 19;
    int Procent = 1;

    LoadGameImage (&AllImages->BackGround,    "Images/Dungeon.bmp",                1, 1, 1, 1, TX_BLACK, &Procent, Number);

    // printf ("1:LoadAllImages(): File = %s , HDC = %d \n", AllImages->BackGround.FileName, AllImages->BackGround.Picture);

    LoadGameImage (&AllImages->Cursor,        "Images/GameCursor.bmp",             1, 1, 1, 1, TX_WHITE, &Procent, Number);

    LoadGameImage (&AllImages->Dirt,          "Images/DirtAnimation.bmp",          3, 1, 1, 1, TX_WHITE, &Procent, Number);

    LoadGameImage (&AllImages->Health,        "Images/GameHeart.bmp",              1, 1, 1, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Finish,        "Images/Finish.bmp",                 1, 1, 1, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Start,         "Images/Start.bmp",                  1, 1, 1, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Pause,         "Images/GamePause.bmp",              2, 1, 1, 1, TX_WHITE, &Procent, Number);

    LoadGameImage (&AllImages->Coin,          "Images/GameCoin.bmp",               1, 1, 1, 1, TX_WHITE, &Procent, Number);

    LoadGameImage (&AllImages->CoinAnimation, "Images/CoinAnimation.bmp",          4, 1, 4, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Box,           "Images/WoodBoxAnimation.bmp",       3, 1, 1, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Man,           "Images/AllAnimationGamePeople.bmp", 9, 2, 9, 1, TX_WHITE, &Procent, Number);

    LoadGameImage (&AllImages->Stairs,        "Images/Stairs.bmp",                 3, 1, 1, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Fire,          "Images/FireAnimation.bmp",          5, 1, 5, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->GreenFire,     "Images/GreenFire.bmp",              5, 1, 5, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Water,         "Images/Water.bmp",                  3, 1, 1, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Bat,           "Images/Bat.bmp",                    4, 2, 4, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Stalactite,    "Images/Stalactite.bmp",             3, 1, 1, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->GameOver,      "Images/GameOver.bmp",               1, 1, 1, 1, TX_WHITE, &Procent, Number);

    LoadGameImage (&AllImages->Pickaxe,       "Images/Pickaxe.bmp",                3, 1, 1, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Termometer,    "Images/termometer.bmp",             1, 1, 1, 1, TX_BLACK, &Procent, Number);

    LoadGameImage (&AllImages->Berries,       "Images/Berries.bmp",                5, 1, 1, 1, TX_WHITE, &Procent, Number);

    LoadGameImage (&AllImages->Chest,         "Images/Chest.bmp",                  3, 1, 1, 1, TX_WHITE, &Procent, Number);

    LoadGameImage (&AllImages->IronOre,       "Images/IronOre.bmp",                3, 1, 1, 1, TX_WHITE, &Procent, Number);
    };

void Cycle ()
    {
    AllImageType AllImage = {};

    LoadAllImages (&AllImage);

    int LevelNumber = 1;

    // double AllTemperature = 10;

    BaseType Base = {0, 0, 20};

    ManType Man = {Base, 0, 0, 0, 5, 2, 0, 0, 0, 0, AllImage.Water, AllImage.Water, 36.6};

    while (true)
        {
        txSetFillColor (RGB (72, 72, 72));
        txClear ();

        if (LevelNumber == 1)
            {
            Level1 (&LevelNumber, &Man, AllImage);
            };

        if (LevelNumber == 2)
            {
            Level2 (&LevelNumber, &Man, AllImage);
            };
        };
    };

void DrawInventory (ManType* Man)
    {
    int null = 0;

    txSetColor (TX_DARKGREY, 5);
    txSetFillColor (TX_TRANSPARENT);

    txSelectFont ("Comic Sans MS", 40);
    txTextOut (1402, 45, "Left");
    txTextOut (1477, 45, "Right");

    txRectangle  (1375, 50, 1425, 100);
    txRectangle  (1450, 50, 1500, 100);

    int x1 = 1;
    int x2 = 2;

    int y = 0;

    DrawTransparentImage (Man->LeftArmPicture, 1375, 50, &x1, &y);

    DrawTransparentImage (Man->RightArmPicture, 1450, 50, &x2, &y);

    if (Man->Side == 1)
            {
            DrawTransparentImage (Man->LeftArmPicture, Man->Base.x + 40, Man->Base.y + 35, &x1, &y);
            DrawTransparentImage (Man->RightArmPicture, Man->Base.x - 40, Man->Base.y + 25, &x1, &y);
            };

    if (Man->Side == 2)
            {
            DrawTransparentImage (Man->LeftArmPicture, Man->Base.x + 80, Man->Base.y + 25, &x2, &y);
            DrawTransparentImage (Man->RightArmPicture, Man->Base.x + 5, Man->Base.y + 35, &x2, &y);
            };
    };

void DrawBlock (BlockType Block, int AnimationNumber, AllImageType AllImage)
    {
    int xNumber = 0;

    int null = 0;

    int three = 3;

    int four = 4;

    if (Block.Base.Health <= 4 &&
        Block.Base.Health > 2)
        xNumber = 1;

    if (Block.Base.Health <= 2)
        xNumber = 2;

    if (Block.Base.Health > 0 &&
        Block.Number != 4     &&
        Block.Number != 21)
        DrawTransparentImage (Block.Picture, Block.Base.x, Block.Base.y, &null, &null);

    if (Block.Base.Health > 0 &&
        Block.Number == 4)
        DrawTransparentImage (Block.Picture, Block.Base.x, Block.Base.y, &AnimationNumber, &null);

    if (Block.Base.Health > 0 &&
        Block.Number == 21)
            {
            if (Block.Base.Health < 500 &&
                Block.Base.Health > 0)
                DrawTransparentImage (Block.Picture, Block.Base.x, Block.Base.y, &three, &null);

            if (Block.Base.Health >= 500 &&
                Block.Base.Health < 1000)
                DrawTransparentImage (Block.Picture, Block.Base.x, Block.Base.y, &four, &null);

            if (Block.Base.Health == 1000)
                DrawTransparentImage (Block.Picture, Block.Base.x, Block.Base.y, &null, &null);
            };

    if (Block.Number == 2)
    {
    };
    };

void DrawCoin (CoinType Coin, int AnimationNumber, AllImageType AllImage)
    {
    int null = 0;

    if (Coin.Base.Health > 0)
    DrawTransparentImage (AllImage.CoinAnimation, Coin.Base.x, Coin.Base.y, &AnimationNumber, &null);

    /*char str [50] = "";

    sprintf (str, "%d", Coin.Base.Health);

    txSetTextAlign ();
    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", 40);
    txTextOut (Coin.Base.x, Coin.Base.y - 20, str);*/
    };

void DrawMan (ManType* Man, AllImageType AllImage, int Number, int AnimationNumber, double StarsNumber)
    {
    int AnimateNumber = 0;

    int null = 0;

    BlockType Fire1 = {Man->Base.x, Man->Base.y + 10, 4, 6, AllImage.Fire};
    BlockType Fire2 = {Man->Base.x + 50, Man->Base.y + 10, 4, 6, AllImage.Fire};
    BlockType Fire3 = {Man->Base.x + 25, Man->Base.y + 60, 4, 6, AllImage.Fire};

    BlockType GreenFire1 = {Man->Base.x, Man->Base.y + 10, 4, 6, AllImage.GreenFire};
    BlockType GreenFire2 = {Man->Base.x + 50, Man->Base.y + 10, 4, 6, AllImage.GreenFire};
    BlockType GreenFire3 = {Man->Base.x + 25, Man->Base.y + 60, 4, 6, AllImage.GreenFire};

    if (Man->vX > 0)
        {
        Man->Speed = 2;
        if (GetAsyncKeyState (VK_SHIFT))
            {
            Man->vX = 15;
            };
        };

    if (Man->vX < 0)
        {
        Man->Speed = 1;
        if (GetAsyncKeyState (VK_SHIFT))
            {
            Man->vX = -15;
            };
        };

    if (Man->vX == 0)
        {
        Man->Speed = 0;
        }

    if (Man->vX != 0)
        {
        AnimateNumber = Number;
        }
    else
        AnimateNumber = 0;

    if (Man->Side == 1)
        {
        //txTransparentBlt (txDC (), Man->Base.x, Man->Base.y - 48, 95.2, 168, AllImage.Man, Number*95.2, 0, TX_WHITE);
        };

    if (Man->Side == 2)
        {
        //txTransparentBlt (txDC (), Man->Base.x, Man->Base.y - 48, 95.2, 168, AllImage.Man, 761.7 - Number*95.2, 0, TX_WHITE);
        };

    int yNumber = Man->Side-1;

    if (Man->Base.Health > 0)
        DrawTransparentImage (AllImage.Man, Man->Base.x, Man->Base.y - 48, &Number, &yNumber);

    if (Man->Position == 1)
        {
        Man->Base.Health -= 0.05;
        Man->Temperature += 1;
        DrawBlock (Fire1, AnimationNumber, AllImage);
        DrawBlock (Fire2, AnimationNumber, AllImage);
        DrawBlock (Fire3, AnimationNumber, AllImage);
        };

    /* if (Man->Position == 2)
        {
        Man->Base.Health -= 0.08;
        DrawBlock (GreenFire1, AllImage, AnimationNumber);
        DrawBlock (GreenFire2, AllImage, AnimationNumber);
        DrawBlock (GreenFire3, AllImage, AnimationNumber);
        }; */

    if (Man->Base.Health < 0)
        {
        Man->Base.Health = 0;
        };

    if (Man->Base.Health == 0)
        {
        DrawTransparentImage (AllImage.GameOver, Man->Base.x, Man->Base.y, &null, &null);
        Man->vX = 0;
        Man->vY = 0;
        Man->Position = 0;
        Man->LeftArm = 0;
        Man->LeftArmPicture = AllImage.Water;
        Man->RightArm = 0;
        Man->RightArmPicture = AllImage.Water;
        };

    if (Man->Base.Health > 20)
        Man->Base.Health = 20;

    if (Man->Temperature < 0)
        {
        Man->Temperature = 0;
        };

    if (Man->Temperature > 90)
        {
        Man->Temperature = 90;
        };

    if (Man->Temperature <= 20)
        Man->Base.Health -= 0.005;

    if (Man->Temperature <= 10)
        Man->Base.Health -= 0.01;

    if (Man->Temperature <= 5)
        Man->Base.Health -= 0.02;

    if (Man->Temperature >= 50)
        Man->Base.Health -= 0.01;

    if (Man->Temperature >= 70)
        Man->Base.Health -= 0.02;

    if (Man->Temperature >= 80)
        Man->Base.Health -= 0.04;

    if (Man->LeftArm == 0)
        Man->LeftArmPicture = AllImage.Water;

    if (Man->RightArm == 0)
        Man->RightArmPicture = AllImage.Water;
    };

void DrawEnemy (EnemyType Enemy, AllImageType AllImage, int Number)
    {
    if (Enemy.vX > 0)
        {
        Enemy.Side = 2;
        };

    if (Enemy.vX < 0)
        {
        Enemy.Side = 1;
        };

    int null = 0;

    if (Enemy.Side == 1)
        {
        DrawTransparentImage (Enemy.LPicture, Enemy.x, Enemy.y, &Number, &null);
        };

    if (Enemy.Side == 2)
        {
        DrawTransparentImage (Enemy.RPicture, Enemy.x, Enemy.y, &Number, &null);
        };
    };

void DrawButton (ButtonType Button, AllImageType AllImage)
    {
    int null = 0;

    DrawTransparentImage (AllImage.Pause, Button.x, Button.y, &Button.Number, &null);
    };

void DrawCursor (MouseType Mouse)
    {
    Mouse.x = txMouseX ();

    Mouse.y = txMouseY ();

    int null = 0;

    DrawTransparentImage (Mouse.Picture, Mouse.x, Mouse.y, &null, &null);
    };

void DrawFinish (BlockType* Block)
    {
    int null = 0;

    DrawTransparentImage (Block->Picture, Block->Base.x - 40, Block->Base.y + 14, &null, &null);
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

void MoveGame (BlockType ManyBlocks [], CoinType Coins [], BlockType* Start, BlockType* Finish, AllImageType AllImage, int* LevelNumber, ManType* Man, double* AllTemperature)
    {
    int StartLevelNumber = *LevelNumber;

    int NumberPicture = 0;

    int Time = GetTickCount();

    int NumberCoin = 0;

    const int NumberBlock = 300;

    int Sleep = 30;

    int ChooseMan = 2;

    CoinType Coin = {200, 100, 1};

    ButtonType Pause = {20, 10, 0};

    MouseType Mouse = {100, 100, AllImage.Cursor};

    // CoinType Coin1 = {400, 630, 1};

    EnemyType Bat = {1000, 300, 0, 0, 2, 6, AllImage.Bat};

    int t = 0;

    int NumberLevel = *LevelNumber;

    double AnimationNumber  = 0;
    int ManAnimationNumber  = 0;
    int AllImageNumber      = 4;

    int EnemyNumber = 0;

    int MenuNumber = 2;
    int PauseNumber = 2;

    double StarsNumber = 0;

    txBegin ();

    while (true)
        {
        txSetFillColor (RGB (72, 72, 72));
        txClear ();

        StarsNumber += 0.5;

        if (StarsNumber >= 2)
            {
            StarsNumber = 0;
            };

        NumberLevel = *LevelNumber;

        ManAnimationNumber += 1;

        AnimationNumber += 0.9;

        EnemyNumber += 1;

        if (EnemyNumber > 3)
            {
            EnemyNumber = 0;
            };

        Time = Time + 1;

        if (AnimationNumber >= AllImageNumber)
            AnimationNumber = 0;

        if (ManAnimationNumber >= 9)
            ManAnimationNumber = 0;

        int null = 0;

        DrawTransparentImage (AllImage.BackGround, 0, 0, &null, &null);

        DrawTransparentImage (AllImage.Coin, 20, 70, &null, &null);

        DrawManyBlocks (ManyBlocks, Coins, AnimationNumber, AllImage, Start, Finish);

        DrawMan (Man, AllImage, ManAnimationNumber, AnimationNumber, StarsNumber);

        DrawInventory (Man);

        InteractManWithBlocks (ManyBlocks, Coins, Man, &NumberCoin, LevelNumber, Start, Finish);

        // DrawEnemy (Bat, AllImage, EnemyNumber);

        // EnemyMind (&Man, &Bat);

        Physic (Man);

        ControlMan (Man, Mouse, &t);

        if (ButtonCheckClick (45, 15, txMouseX(), txMouseY(), 25, 25) == 1)
            {
            PauseNumber = 1;
            };

        Text (70, 95, 40, NumberCoin, "");

        Text (180, 38, 70, NumberLevel, "Level");

        DrawButton (Pause, AllImage);

        DrawHealth (Man->Base.Health, AllImage);

        if (PauseNumber == 1)
            {
            Man->vX = 0;
            Man->vY = 0;

            Pause.Number = 1;

            // DrawButton (PlayButton);

            if (ButtonCheckClick (65, 55, txMouseX(), txMouseY(), 25, 25) == 1)
                PauseNumber = 2;
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
        // txSetFillColor (RGB (25 + 2.5*Man->Temperature, 0, 255 - 2.5*Man->Temperature));
        // txRectangle (60, 160, 90, 250);

        // txLine (60, 250-Man->Temperature, 90, 250-Man->Temperature);

        DrawTransparentImage (AllImage.Termometer, 10, 160, &null, &null);
        txRectangle (29, 265 - Man->Temperature, 32, 265);

        /* if (GetAsyncKeyState (VK_UP))
            {
            Man->Temperature += 1;
            };

        if (GetAsyncKeyState (VK_DOWN))
            {
            Man->Temperature -= 1;
            }; */

        DrawCursor (Mouse);

        if (StartLevelNumber != *LevelNumber)
            {
            break;
            };

        txSleep (Sleep);
        };
    txEnd ();

    DeleteAllImage (AllImage);
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
    txRectangle (0, 0, 1550, 850);
    txSetColor (TX_BLACK, 3);
    txRectangle (200, 500, 1350, 550);
    txSetFillColor (TX_GREEN);
    txRectangle (200, 500, 200+(11.50*Procents), 550);

    char str [50] = "";

    sprintf (str, "Loading: %d%%", Procents);

    txSetTextAlign ();
    txSetColor (TX_BLACK);
    txSelectFont ("Comic Sans MS", 80);
    txTextOut (750, 400, str);
    };

void Level1 (int* LevelNumber, ManType* Man, AllImageType AllImage)
    {
    double AllTemperature = 10;

    BlockType ManyBlocks [] = {// Ground
                               {{ -75,  675, 6}, 1, AllImage.Dirt},
                               {{ -25,  675, 6}, 1, AllImage.Dirt},
                               {{ 25,   675, 6}, 1, AllImage.Dirt},
                               {{ 75,   675, 6}, 1, AllImage.Dirt},
                               {{ 125,  675, 6}, 1, AllImage.Dirt},
                               {{ 175,  675, 6}, 1, AllImage.Dirt},
                               {{ 225,  675, 6}, 1, AllImage.Dirt},
                               {{ 275,  675, 6}, 5, AllImage.Water},
                               {{ 325,  675, 6}, 5, AllImage.Water},
                               {{ 375,  675, 6}, 5, AllImage.Water},
                               {{ 425,  675, 6}, 1, AllImage.Dirt},
                               {{ 475,  675, 6}, 1, AllImage.IronOre},
                               {{ 525,  675, 6}, 1, AllImage.Dirt},
                               {{ 575,  675, 6}, 1, AllImage.Dirt},
                               {{ 625,  675, 6}, 1, AllImage.Dirt},
                               {{ 675,  675, 6}, 1, AllImage.Dirt},
                               {{ 725,  675, 6}, 1, AllImage.Dirt},
                               {{ 775,  675, 6}, 1, AllImage.Dirt},
                               {{ 825,  675, 6}, 1, AllImage.Dirt},
                               {{ 875,  675, 6}, 1, AllImage.Dirt},
                               {{ 925,  675, 6}, 1, AllImage.Dirt},
                               {{ 975,  675, 6}, 1, AllImage.Dirt},
                               {{1025,  675, 6}, 1, AllImage.Dirt},
                               {{1075,  675, 6}, 1, AllImage.Dirt},
                               {{1125,  675, 6}, 1, AllImage.Dirt},
                               {{1175,  675, 6}, 1, AllImage.Dirt},
                               {{1225,  675, 6}, 1, AllImage.Dirt},
                               {{1275,  675, 6}, 1, AllImage.Dirt},
                               {{1325,  675, 6}, 1, AllImage.Dirt},
                               {{1375,  675, 6}, 1, AllImage.Dirt},
                               {{1425,  675, 6}, 1, AllImage.Dirt},
                               {{1475,  675, 6}, 1, AllImage.Dirt},
                               {{1525,  675, 6}, 1, AllImage.Dirt},

                               {{ -75,  725, 6}, 1, AllImage.Dirt},
                               {{ -25,  725, 6}, 1, AllImage.Dirt},
                               {{  25,  725, 6}, 1, AllImage.Dirt},
                               {{  75,  725, 6}, 1, AllImage.Dirt},
                               {{ 125,  725, 6}, 1, AllImage.Dirt},
                               {{ 175,  725, 6}, 1, AllImage.Dirt},
                               {{ 225,  725, 6}, 1, AllImage.Dirt},
                               {{ 275,  725, 6}, 1, AllImage.Dirt},
                               {{ 325,  725, 6}, 1, AllImage.Dirt},
                               {{ 375,  725, 6}, 1, AllImage.Dirt},
                               {{ 425,  725, 6}, 1, AllImage.Dirt},
                               {{ 475,  725, 6}, 1, AllImage.IronOre},
                               {{ 525,  725, 6}, 1, AllImage.IronOre},
                               {{ 575,  725, 6}, 1, AllImage.Dirt},
                               {{ 625,  725, 6}, 1, AllImage.Dirt},
                               {{ 725,  725, 6}, 1, AllImage.Dirt},
                               {{ 725,  725, 6}, 1, AllImage.Dirt},
                               {{ 775,  725, 6}, 1, AllImage.Dirt},
                               {{ 825,  725, 6}, 1, AllImage.Dirt},
                               {{ 875,  725, 6}, 1, AllImage.Dirt},
                               {{ 925,  725, 6}, 1, AllImage.Dirt},
                               {{ 975,  725, 6}, 1, AllImage.Dirt},
                               {{1025,  725, 6}, 1, AllImage.Dirt},
                               {{1075,  725, 6}, 1, AllImage.Dirt},
                               {{1125,  725, 6}, 1, AllImage.Dirt},
                               {{1175,  725, 6}, 1, AllImage.Dirt},
                               {{1225,  725, 6}, 1, AllImage.Dirt},
                               {{1275,  725, 6}, 1, AllImage.Dirt},
                               {{1325,  725, 6}, 1, AllImage.Dirt},
                               {{1375,  725, 6}, 1, AllImage.Dirt},
                               {{1425,  725, 6}, 1, AllImage.Dirt},
                               {{1475,  725, 6}, 1, AllImage.Dirt},
                               {{1525,  725, 6}, 1, AllImage.Dirt},
                               // Platforms
                               {{ 100,  200, 6}, 1, AllImage.Dirt},
                               {{ 150,  200, 6}, 1, AllImage.Dirt},
                               {{ 200,  200, 6}, 1, AllImage.Dirt},
                               {{ 250,  200, 6}, 1, AllImage.Dirt},
                               {{ 300,  200, 6}, 1, AllImage.Dirt},
                               {{ 350,  200, 6}, 1, AllImage.Dirt},
                               {{ 200,  500, 6}, 1, AllImage.Dirt},
                               {{ 250,  500, 6}, 1, AllImage.Dirt},
                               {{ 300,  500, 6}, 1, AllImage.Dirt},
                               {{ 350,  500, 6}, 1, AllImage.Dirt},
                               {{ 450,  400, 6}, 1, AllImage.Dirt},
                               {{ 500,  400, 6}, 1, AllImage.Dirt},
                               {{ 550,  400, 6}, 1, AllImage.Dirt},
                               {{ 550,  100, 6}, 1, AllImage.Dirt},
                               {{ 600,  100, 6}, 1, AllImage.Dirt},
                               {{ 650,  100, 6}, 1, AllImage.Dirt},
                               {{ 700,  100, 6}, 1, AllImage.Dirt},
                               {{ 850,  300, 6}, 1, AllImage.Dirt},
                               {{ 900,  300, 6}, 1, AllImage.Dirt},
                               {{ 950,  300, 6}, 1, AllImage.Dirt},
                               {{1050,  150, 6}, 1, AllImage.Dirt},
                               {{1100,  150, 6}, 1, AllImage.Dirt},
                               {{1150,  150, 6}, 1, AllImage.Dirt},
                               {{1300,  250, 6}, 1, AllImage.Dirt},
                               {{1350,  250, 6}, 1, AllImage.Dirt},
                               {{1400,  250, 6}, 1, AllImage.Dirt},
                               {{1450,  250, 6}, 1, AllImage.Dirt},
                               {{1500,  250, 6}, 1, AllImage.Dirt},
                               {{1550,  250, 6}, 1, AllImage.Dirt},
                               // Boxes
                               {{ 100,  625, 2},  2, AllImage.Box},
                               {{  50,  625, 2},  2, AllImage.Box},
                               {{ 100,  575, 2},  2, AllImage.Box},
                               // Fire
                               {{ 900,  615, 4},  4, AllImage.Fire},
                               {{ 800,  615, 4},  4, AllImage.Fire},
                               // Stalactites
                               {{ 100,  250, 7},  7, AllImage.Stalactite},
                               {{ 150,  250, 7},  7, AllImage.Stalactite},
                               {{ 200,  250, 7},  7, AllImage.Stalactite},
                               {{ 250,  250, 7},  7, AllImage.Stalactite},
                               {{ 300,  250, 7},  7, AllImage.Stalactite},
                               {{ 350,  250, 7},  7, AllImage.Stalactite},
                               {{ 200,  550, 7},  7, AllImage.Stalactite},
                               {{ 250,  550, 7},  7, AllImage.Stalactite},
                               {{ 300,  550, 7},  7, AllImage.Stalactite},
                               {{ 350,  550, 7},  7, AllImage.Stalactite},
                               {{ 450,  450, 7},  7, AllImage.Stalactite},
                               {{ 500,  450, 7},  7, AllImage.Stalactite},
                               {{ 550,  450, 7},  7, AllImage.Stalactite},
                               {{ 550,  150, 7},  7, AllImage.Stalactite},
                               {{ 600,  150, 7},  7, AllImage.Stalactite},
                               {{ 650,  150, 7},  7, AllImage.Stalactite},
                               {{ 700,  150, 7},  7, AllImage.Stalactite},
                               {{ 850,  350, 7},  7, AllImage.Stalactite},
                               {{ 900,  350, 7},  7, AllImage.Stalactite},
                               {{ 950,  350, 7},  7, AllImage.Stalactite},
                               {{1050,  200, 7},  7, AllImage.Stalactite},
                               {{1100,  200, 7},  7, AllImage.Stalactite},
                               {{1150,  200, 7},  7, AllImage.Stalactite},
                               {{1300,  300, 7},  7, AllImage.Stalactite},
                               {{1350,  300, 7},  7, AllImage.Stalactite},
                               {{1400,  300, 7},  7, AllImage.Stalactite},
                               {{1450,  300, 7},  7, AllImage.Stalactite},
                               {{1500,  300, 7},  7, AllImage.Stalactite},
                               {{1550,  300, 7},  7, AllImage.Stalactite},
                               // Stairs
                               {{ 700,  592, 3},  3, AllImage.Stairs},
                               {{ 700,  509, 3},  3, AllImage.Stairs},
                               {{ 700,  426, 3},  3, AllImage.Stairs},
                               {{ 700,  343, 3},  3, AllImage.Stairs},
                               {{ 700,  260, 3},  3, AllImage.Stairs},
                               {{ 700,  177, 3},  3, AllImage.Stairs},
                               {{ 700,   94, 3},  3, AllImage.Stairs},
                               // Berries
                               {{1100,  625, 1000}, 21, AllImage.Berries},
                               // Chests
                               {{1300,  625, 6},  8, AllImage.Chest},
                               // Things
                               {{1175,  625, 16}, 11, AllImage.Pickaxe},
                               {{ 250,  450, 16}, 11, AllImage.Pickaxe},
                               // End
                               {{  -1,   -6}}};

    CoinType Coins [] = {{{160,  165, 1}},
                         {{310,  165, 1}},
                         {{260,  465, 1}},
                         {{310,  465, 1}},
                         {{510,  365, 1}},
                         {{560,  65,  1}},
                         {{710,  65,  1}},
                         {{910,  265, 1}},
                         {{1110, 115, 1}},
                         {{1360, 215, 1}},
                         {{-1,   -1}}};

    BlockType Start  = {-100, 580, 0, 50, AllImage.Start};

    BlockType Finish = {1450, 580, 0, 50, AllImage.Finish};

    MoveGame (ManyBlocks, Coins, &Start, &Finish, AllImage, LevelNumber, Man, &AllTemperature);
    };

void Level2 (int* LevelNumber, ManType* Man, AllImageType AllImage)
    {
    double AllTemperature = 10;

    /*BlockType ManyBlocks [] = {// Ground
                               {-75,  675, 1, 6, AllImage.Dirt},
                               {-25,  675, 1, 6, AllImage.Dirt},
                               {25,   675, 1, 6, AllImage.Dirt},
                               {75,   675, 1, 6, AllImage.Dirt},
                               {125,  675, 1, 6, AllImage.Dirt},
                               {175,  675, 1, 6, AllImage.Dirt},
                               {225,  675, 1, 6, AllImage.Dirt},
                               {275,  675, 1, 6, AllImage.Dirt},
                               {325,  675, 1, 6, AllImage.Dirt},
                               {375,  675, 1, 6, AllImage.Dirt},
                               {425,  675, 1, 6, AllImage.Dirt},
                               {475,  675, 1, 6, AllImage.Dirt},
                               {525,  675, 1, 6, AllImage.Dirt},
                               {575,  675, 1, 6, AllImage.Dirt},
                               {625,  675, 1, 6, AllImage.Dirt},
                               {675,  675, 1, 6, AllImage.Dirt},
                               {725,  675, 1, 6, AllImage.Dirt},
                               {775,  675, 1, 6, AllImage.Dirt},
                               {825,  675, 1, 6, AllImage.Dirt},
                               {875,  675, 1, 6, AllImage.Dirt},
                               {925,  675, 1, 6, AllImage.Dirt},
                               {975,  675, 1, 6, AllImage.Dirt},
                               {1025,  675, 1, 6, AllImage.Dirt},
                               {1075,  675, 1, 6, AllImage.Dirt},
                               {1125,  675, 1, 6, AllImage.Dirt},
                               {1175,  675, 1, 6, AllImage.Dirt},
                               {1225,  675, 1, 6, AllImage.Dirt},
                               {1275,  675, 1, 6, AllImage.Dirt},
                               {1325,  675, 1, 6, AllImage.Dirt},
                               {1375,  675, 1, 6, AllImage.Dirt},
                               {1425,  675, 1, 6, AllImage.Dirt},
                               {1475,  675, 1, 6, AllImage.Dirt},
                               {1525,  675, 1, 6, AllImage.Dirt},
                               // Platforms
                               /* {100,  200, 1, 6, AllImage.Dirt},
                               {150,  200, 1, 6, AllImage.Dirt},
                               {200,  200, 1, 6, AllImage.Dirt},
                               {250,  200, 1, 6, AllImage.Dirt},
                               {300,  200, 1, 6, AllImage.Dirt},
                               {350,  200, 1, 6, AllImage.Dirt},
                               {200,  500, 1, 6, AllImage.Dirt},
                               {250,  500, 1, 6, AllImage.Dirt},
                               {300,  500, 1, 6, AllImage.Dirt},
                               {350,  500, 1, 6, AllImage.Dirt},
                               {450,  400, 1, 6, AllImage.Dirt},
                               {500,  400, 1, 6, AllImage.Dirt},
                               {550,  400, 1, 6, AllImage.Dirt},
                               {550,  100, 1, 6, AllImage.Dirt},
                               {600,  100, 1, 6, AllImage.Dirt},
                               {650,  100, 1, 6, AllImage.Dirt},
                               {700,  100, 1, 6, AllImage.Dirt},
                               {850,  300, 1, 6, AllImage.Dirt},
                               {900,  300, 1, 6, AllImage.Dirt},
                               {950,  300, 1, 6, AllImage.Dirt},
                               {1050, 150, 1, 6, AllImage.Dirt},
                               {1100, 150, 1, 6, AllImage.Dirt},
                               {1150, 150, 1, 6, AllImage.Dirt},
                               {1300, 250, 1, 6, AllImage.Dirt},
                               {1350, 250, 1, 6, AllImage.Dirt},
                               {1400, 250, 1, 6, AllImage.Dirt},
                               {1450, 250, 1, 6, AllImage.Dirt},
                               {1500, 250, 1, 6, AllImage.Dirt},
                               {1550, 250, 1, 6, AllImage.Dirt}, */
                               // Boxes
                               /*{500,  625, 2, 6, AllImage.Box},
                               // Stairs
                               {700,  592, 3, 6, AllImage.Stairs},
                               {700,  509, 3, 6, AllImage.Stairs},
                               {700,  426, 3, 6, AllImage.Stairs},
                               {700,  343, 3, 6, AllImage.Stairs},
                               {700,  260, 3, 6, AllImage.Stairs},
                               {700,  177, 3, 6, AllImage.Stairs},
                               // Fire
                               {900, 615, 4, 6, AllImage.Fire},
                               {800, 615, 4, 6, AllImage.Fire},
                               // End
                               {-1,   -1}};*/

    BlockType ManyBlocks [] = {// Ground
                               {{ -75,  675, 6}, 1, AllImage.Dirt},
                               {{ -25,  675, 6}, 1, AllImage.Dirt},
                               {{ 25,   675, 6}, 1, AllImage.Dirt},
                               {{ 75,   675, 6}, 1, AllImage.Dirt},
                               {{ 125,  675, 6}, 1, AllImage.Dirt},
                               {{ 175,  675, 6}, 1, AllImage.Dirt},
                               {{ 225,  675, 6}, 1, AllImage.Dirt},
                               {{ 275,  675, 6}, 5, AllImage.Water},
                               {{ 325,  675, 6}, 5, AllImage.Water},
                               {{ 375,  675, 6}, 5, AllImage.Water},
                               {{ 425,  675, 1}, 1, AllImage.Dirt},
                               {{ 475,  675, 1}, 1, AllImage.Dirt},
                               {{ 525,  675, 1}, 1, AllImage.Dirt},
                               {{ 575,  675, 1}, 1, AllImage.Dirt},
                               {{ 625,  675, 1}, 1, AllImage.Dirt},
                               {{ 675,  675, 1}, 1, AllImage.Dirt},
                               {{ 725,  675, 1}, 1, AllImage.Dirt},
                               {{ 775,  675, 1}, 1, AllImage.Dirt},
                               {{ 825,  675, 1}, 1, AllImage.Dirt},
                               {{ 875,  675, 1}, 1, AllImage.Dirt},
                               {{ 925,  675, 1}, 1, AllImage.Dirt},
                               {{ 975,  675, 1}, 1, AllImage.Dirt},
                               {{1025,  675, 1}, 1, AllImage.Dirt},
                               {{1075,  675, 1}, 1, AllImage.Dirt},
                               {{1125,  675, 1}, 1, AllImage.Dirt},
                               {{1175,  675, 1}, 1, AllImage.Dirt},
                               {{1225,  675, 1}, 1, AllImage.Dirt},
                               {{1275,  675, 1}, 1, AllImage.Dirt},
                               {{1325,  675, 1}, 1, AllImage.Dirt},
                               {{1375,  675, 1}, 1, AllImage.Dirt},
                               {{1425,  675, 1}, 1, AllImage.Dirt},
                               {{1475,  675, 1}, 1, AllImage.Dirt},
                               {{1525,  675, 1}, 1, AllImage.Dirt},

                               {{ -75,  725, 1}, 1, AllImage.Dirt},
                               {{ -25,  725, 1}, 1, AllImage.Dirt},
                               {{  25,  725, 1}, 1, AllImage.Dirt},
                               {{  75,  725, 1}, 1, AllImage.Dirt},
                               {{ 125,  725, 1}, 1, AllImage.Dirt},
                               {{ 175,  725, 1}, 1, AllImage.Dirt},
                               {{ 225,  725, 1}, 1, AllImage.Dirt},
                               {{ 275,  725, 1}, 1, AllImage.Dirt},
                               {{ 325,  725, 1}, 1, AllImage.Dirt},
                               {{ 375,  725, 1}, 1, AllImage.Dirt},
                               {{ 425,  725, 1}, 1, AllImage.Dirt},
                               {{ 475,  725, 1}, 1, AllImage.Dirt},
                               {{ 525,  725, 1}, 1, AllImage.Dirt},
                               {{ 575,  725, 1}, 1, AllImage.Dirt},
                               {{ 625,  725, 1}, 1, AllImage.Dirt},
                               {{ 725,  725, 1}, 1, AllImage.Dirt},
                               {{ 725,  725, 1}, 1, AllImage.Dirt},
                               {{ 775,  725, 1}, 1, AllImage.Dirt},
                               {{ 825,  725, 1}, 1, AllImage.Dirt},
                               {{ 875,  725, 1}, 1, AllImage.Dirt},
                               {{ 925,  725, 1}, 1, AllImage.Dirt},
                               {{ 975,  725, 1}, 1, AllImage.Dirt},
                               {{1025,  725, 1}, 1, AllImage.Dirt},
                               {{1075,  725, 1}, 1, AllImage.Dirt},
                               {{1125,  725, 1}, 1, AllImage.Dirt},
                               {{1175,  725, 1}, 1, AllImage.Dirt},
                               {{1225,  725, 1}, 1, AllImage.Dirt},
                               {{1275,  725, 1}, 1, AllImage.Dirt},
                               {{1325,  725, 1}, 1, AllImage.Dirt},
                               {{1375,  725, 1}, 1, AllImage.Dirt},
                               {{1425,  725, 1}, 1, AllImage.Dirt},
                               {{1475,  725, 1}, 1, AllImage.Dirt},
                               {{1525,  725, 1}, 1, AllImage.Dirt},
                               // Platforms
                               {{ 100,  200, 1}, 1, AllImage.Dirt},
                               {{ 150,  200, 1}, 1, AllImage.Dirt},
                               {{ 200,  200, 1}, 1, AllImage.Dirt},
                               {{ 250,  200, 1}, 1, AllImage.Dirt},
                               {{ 300,  200, 1}, 1, AllImage.Dirt},
                               {{ 350,  200, 1}, 1, AllImage.Dirt},
                               {{ 200,  500, 1}, 1, AllImage.Dirt},
                               {{ 250,  500, 1}, 1, AllImage.Dirt},
                               {{ 300,  500, 1}, 1, AllImage.Dirt},
                               {{ 350,  500, 1}, 1, AllImage.Dirt},
                               {{ 450,  400, 1}, 1, AllImage.Dirt},
                               {{ 500,  400, 1}, 1, AllImage.Dirt},
                               {{ 550,  400, 1}, 1, AllImage.Dirt},
                               {{ 550,  100, 1}, 1, AllImage.Dirt},
                               {{ 600,  100, 1}, 1, AllImage.Dirt},
                               {{ 650,  100, 1}, 1, AllImage.Dirt},
                               {{ 700,  100, 1}, 1, AllImage.Dirt},
                               {{ 850,  300, 1}, 1, AllImage.Dirt},
                               {{ 900,  300, 1}, 1, AllImage.Dirt},
                               {{ 950,  300, 1}, 1, AllImage.Dirt},
                               {{1050,  150, 1}, 1, AllImage.Dirt},
                               {{1100,  150, 1}, 1, AllImage.Dirt},
                               {{1150,  150, 1}, 1, AllImage.Dirt},
                               {{1300,  250, 1}, 1, AllImage.Dirt},
                               {{1350,  250, 1}, 1, AllImage.Dirt},
                               {{1400,  250, 1}, 1, AllImage.Dirt},
                               {{1450,  250, 1}, 1, AllImage.Dirt},
                               {{1500,  250, 1}, 1, AllImage.Dirt},
                               {{1550,  250, 1}, 1, AllImage.Dirt},
                               // Boxes
                               {{ 100,  625, 2},  2, AllImage.Box},
                               {{  50,  625, 2},  2, AllImage.Box},
                               {{ 100,  575, 2},  2, AllImage.Box},
                               // Fire
                               {{ 900,  615, 4},  4, AllImage.Fire},
                               {{ 800,  615, 4},  4, AllImage.Fire},
                               // Stalactites
                               {{ 100,  250, 7},  7, AllImage.Stalactite},
                               {{ 150,  250, 7},  7, AllImage.Stalactite},
                               {{ 200,  250, 7},  7, AllImage.Stalactite},
                               {{ 250,  250, 7},  7, AllImage.Stalactite},
                               {{ 300,  250, 7},  7, AllImage.Stalactite},
                               {{ 350,  250, 7},  7, AllImage.Stalactite},
                               {{ 200,  550, 7},  7, AllImage.Stalactite},
                               {{ 250,  550, 7},  7, AllImage.Stalactite},
                               {{ 300,  550, 7},  7, AllImage.Stalactite},
                               {{ 350,  550, 7},  7, AllImage.Stalactite},
                               {{ 450,  450, 7},  7, AllImage.Stalactite},
                               {{ 500,  450, 7},  7, AllImage.Stalactite},
                               {{ 550,  450, 7},  7, AllImage.Stalactite},
                               {{ 550,  150, 7},  7, AllImage.Stalactite},
                               {{ 600,  150, 7},  7, AllImage.Stalactite},
                               {{ 650,  150, 7},  7, AllImage.Stalactite},
                               {{ 700,  150, 7},  7, AllImage.Stalactite},
                               {{ 850,  350, 7},  7, AllImage.Stalactite},
                               {{ 900,  350, 7},  7, AllImage.Stalactite},
                               {{ 950,  350, 7},  7, AllImage.Stalactite},
                               {{1050,  200, 7},  7, AllImage.Stalactite},
                               {{1100,  200, 7},  7, AllImage.Stalactite},
                               {{1150,  200, 7},  7, AllImage.Stalactite},
                               {{1300,  300, 7},  7, AllImage.Stalactite},
                               {{1350,  300, 7},  7, AllImage.Stalactite},
                               {{1400,  300, 7},  7, AllImage.Stalactite},
                               {{1450,  300, 7},  7, AllImage.Stalactite},
                               {{1500,  300, 7},  7, AllImage.Stalactite},
                               {{1550,  300, 7},  7, AllImage.Stalactite},
                               // Stairs
                               {{ 700,  592, 3},  3, AllImage.Stairs},
                               {{ 700,  509, 3},  3, AllImage.Stairs},
                               {{ 700,  426, 3},  3, AllImage.Stairs},
                               {{ 700,  343, 3},  3, AllImage.Stairs},
                               {{ 700,  260, 3},  3, AllImage.Stairs},
                               {{ 700,  177, 3},  3, AllImage.Stairs},
                               {{ 700,   94, 3},  3, AllImage.Stairs},
                               // Things
                               {{1175,  625, 11}, 11, AllImage.Pickaxe},
                               {{ 250,  450, 11}, 11, AllImage.Pickaxe},
                               // End
                               {{  -1,   -1}}};

    CoinType Coins [] = {{{160,  165, 1}},
                         {{310,  165, 1}},
                         {{260,  465, 1}},
                         {{310,  465, 1}},
                         {{510,  365, 1}},
                         {{560,  65,  1}},
                         {{710,  65,  1}},
                         {{910,  265, 1}},
                         {{1110, 115, 1}},
                         {{1360, 215, 1}},
                         {{-1,   -1}}};

    BlockType Start  = {50, 580, 0, 50, AllImage.Start};

    BlockType Finish = {1650, 580, 0, 50, AllImage.Finish};

    MoveGame (ManyBlocks, Coins, &Start, &Finish, AllImage, LevelNumber, Man, &AllTemperature);
    };

void DrawManyBlocks (BlockType ManyBlocks [], CoinType Coins [], int AnimationNumber, AllImageType AllImage,
                     BlockType* Start, BlockType* Finish)
    {
    DrawLevelBlocks (ManyBlocks, AllImage, AnimationNumber);

    DrawFinish (Finish);
    DrawFinish (Start);

    DrawLevelCoins (Coins, AllImage, AnimationNumber);
    };

void InteractManWithBlocks (BlockType ManyBlocks [], CoinType Coins [], ManType* Man, int* NumberCoin,
                            int* LevelNumber, BlockType* Start, BlockType* Finish)
    {
    CallCoinPhysic (Coins, Man, NumberCoin);

    CallLevelPhysic (ManyBlocks, Man);

    FinishCollision (Man, Finish, LevelNumber, 1);
    FinishCollision (Man, Start,  LevelNumber, -1);
    };

void FinishCollision (ManType* Man, BlockType* Block, int* Level, int Number)
    {
    if ((Block->Base.x - Man->Base.x) <= 50 &&
        (Block->Base.x - Man->Base.x) > 0 &&
        (Block->Base.y - Man->Base.y) <= 50 &&
        (Block->Base.y - Man->Base.y) > 0)
        {
        //Man->Base.x = Number*(-1)*1550;
        *Level += Number;
        };
    };

void CoinCollision (ManType* Man, CoinType* Coin, int* NumberCoin)
    {
    if (Coin->Base.Health > 0)
    {
    if ((Coin->Base.x - (Man->Base.x+35)) < 10 &&
        (Coin->Base.x - (Man->Base.x+35)) > -10)
        if ((Coin->Base.y - (Man->Base.y+60)) < 70 &&
           (Coin->Base.y - (Man->Base.y+60)) > 0)
                    {
                    *NumberCoin += 1;
                    Coin->Base.Health -= 1;
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

    txSleep (10);
    };

void DrawTransparentImage (ImageType Image, int x, int y, int* xAnimationNumber, int* yAnimationNumber)
    {
    // printf ("DrawTransparentImage(): FileName = \"%s\", HDC = \"%p\" \n", Image.FileName, Image.Picture);

    int xSize = txGetExtentX (Image.Picture)/Image.xNumber;
    int ySize = txGetExtentY (Image.Picture)/Image.yNumber;

    txTransparentBlt (txDC (), x, y, xSize, ySize, Image.Picture, *xAnimationNumber*xSize, *yAnimationNumber*ySize, Image.color);

    if (*xAnimationNumber >= Image.xMaxAnimationNumber)
        {
        *xAnimationNumber = 1;
        };

    if (*yAnimationNumber >= Image.yMaxAnimationNumber)
        {
        *yAnimationNumber = 1;
        };
    };

void PrintfBlocks (BlockType Blocks [], int NumberBlock)
    {
    int i = 0;

    while (i < NumberBlock)
        {
        i = i+1;
        };
    };

void DrawLevelBlocks (BlockType ManyBlocks[], AllImageType AllImage,  int AnimationNumber)
    {
    int i = 0;

    while (ManyBlocks[i].Base.x != -1 && ManyBlocks[i].Base.y != -1)
        {
        DrawBlock (ManyBlocks [i], AnimationNumber, AllImage);

        i = i + 1;
        };
    };

void DrawLevelCoins (CoinType Coins[], AllImageType AllImage, int AnimationNumber)
    {
    int i = 0;

    while (Coins[i].Base.x != -1 && Coins[i].Base.y != -1)
        {
        DrawCoin (Coins [i], AnimationNumber, AllImage);

        i = i + 1;
        };
    };

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man)
    {
    int i = 0;

    while (ManyBlocks[i].Base.x != -1 && ManyBlocks[i].Base.y != -1)
        {
        BlockCollision (Man, &ManyBlocks [i]);

        i = i + 1;
        };
    };

void CallCoinPhysic (CoinType Coins[], ManType* Man, int* NumberCoin)
    {
    int i = 0;

    while (Coins[i].Base.x != -1 && Coins[i].Base.y != -1)
        {

        CoinCollision (Man, &Coins [i], NumberCoin);

        i = i + 1;
        };
    };

void EnemyMind (ManType* Man, EnemyType* Enemy)
    {
    Enemy->x = Enemy->x + Enemy->vX;
    Enemy->y = Enemy->y + Enemy->vY;

    if ((Man->Base.x - Enemy->x) <= 1000 &&
        (Man->Base.x - Enemy->x) >= 10)
        {
        if ((Man->Base.x - Enemy->x) > 100)
            {
            Enemy->vX = 5;
            };
        };

    if ((Man->Base.x - Enemy->x) < 10 &&
        (Man->Base.x - Enemy->x) > 0)
        {
        Enemy->vX = 0;
        };

    if ((Enemy->x - Man->Base.x) < 10 &&
        (Enemy->x - Man->Base.x) > 0)
        {
        Enemy->vX = 0;
        };

    if ((Enemy->x - Man->Base.x) <= 1000 &&
        (Enemy->x - Man->Base.x) >= 10)
        {
        if ((Enemy->x - Man->Base.x) > 100)
            {
            Enemy->vX = -5;
            };
        };

   //vY
   if ((Man->Base.y - Enemy->y) <= 1000 &&
        (Man->Base.y - Enemy->y) >= 10)
        {
        if ((Man->Base.y - Enemy->y) > 100)
            {
            Enemy->vY = 5;
            };
        };

    if ((Man->Base.y - Enemy->y) < 10 &&
        (Man->Base.y - Enemy->y) > 0)
        {
        Enemy->vY = 0;
        };

    if ((Enemy->y - Man->Base.y) < 10 &&
        (Enemy->y - Man->Base.y) > 0)
        {
        Enemy->vY = 0;
        };

    if ((Enemy->y - Man->Base.y) <= 1000 &&
        (Enemy->y - Man->Base.y) >= 10)
        {
        if ((Enemy->y - Man->Base.y) > 100)
            {
            Enemy->vY = -5;
            };
        };

   //Destroying

   if (fabs (Man->Base.x - Enemy->x) <= 100)
        {
        if (fabs (Man->Base.y - Enemy->y) <= 100)
            if (Enemy->Health > 0)
                {
                txSetColor (TX_RED, 5);
                if (Enemy->Side == 1)
                    {
                    // txLine (Enemy->x + 48, Enemy->y + 45, Man->Base.x + 10, Man->Base.y + 60);
                    // txLine (Enemy->x + 66, Enemy->y + 45, Man->Base.x + 28, Man->Base.y + 60);
                    };

                if (Enemy->Side == 2)
                    {
                    // txLine (Enemy->x + 94, Enemy->y + 45, Man->Base.x + 28, Man->Base.y + 60);
                    // txLine (Enemy->x + 76, Enemy->y + 45, Man->Base.x + 10, Man->Base.y + 60);
                    };

                // Man->Position = 2;

                Man->Base.Health -= 0.1;
                };
        };

   if (Enemy->Health <= 0)
        {
        Enemy->vY = 25;
        Enemy->vX = 0;
        if (Man->Position == 2)
            {
            Man->Position = 0;
            };
        };

   if (Enemy->y >= 592)
        {
        Enemy->y = 592;
        Enemy->vY = 0;
        };

   if (fabs ((Enemy->x+80) - txMouseX ()) <= 80)
        {
        if (fabs ((Enemy->y+120) - txMouseY ()) <= 120)
            if (GetAsyncKeyState (VK_LBUTTON))
                if (Enemy->Health > 0)
                    {
                    Enemy->Health = Enemy->Health - 0.5;
                    txSetColor (TX_RED);
                    txSetFillColor (TX_RED);
                    txRectangle (Enemy->x - 2, Enemy->y - 50, Enemy->x + 26*Enemy->Health, Enemy->y - 30);
                    txSetColor (TX_BLACK, 5);
                    txSetFillColor (TX_TRANSPARENT);
                    txRectangle (Enemy->x, Enemy->y - 50, Enemy->x + 158, Enemy->y - 30);
                    };
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
        Man->vX = 5;
        Man->Side = 2;
        };

    if (GetAsyncKeyState (VK_LEFT))
        {
        Man->vX = -5;
        Man->Side = 1;
        };

    // if ((GetTickCount () - *t) <= 5000)
    //     Man->aY = 0;
    };

void Run (ManType* Man, HDC LeftLeg, HDC RightLeg)
    {
    };

void ControlBlock (BlockType* Block)
    {
    };

void Physic (ManType* Man)
    {
    Man->Base.x = Man->Base.x + Man->vX;
    Man->Base.y = Man->Base.y + Man->vY;

    Man->vX = Man->vX + Man->aX;
    Man->vY = Man->vY + Man->aY;

    Man->vX = Man->vX*0.5;

    Man->aY = 5;

    if (Man->Base.x >= 1500)
        Man->Base.x = 1500;

    if (Man->Base.x <= 0)
        Man->Base.x = 0;
    };

void BlockPhysic (BlockType* Block)
    {
    int vY = 30;

    Block->Base.y = Block->Base.y + vY;
    };

void BlockCollision (ManType* Man, BlockType* Block)
    {
    // Physic
    if (Block->Base.Health  >= 1 &&
        Block->Number != 4 &&
        Block->Number != 5 &&
        Block->Number != 6 &&
        Block->Number <= 10)
    {
    if ((Block->Base.x - Man->Base.x) <= 74 &&
        (Block->Base.x - Man->Base.x) > 0)
    {
    if ((Block->Base.y - Man->Base.y) <= 120 &&
        (Block->Base.y - Man->Base.y) > 0)
            {
            if (GetAsyncKeyState (VK_UP))
                {
                Man->vY = -30;
                };
            if (Man->vY > 0)
                {
                Man->vY = 0;
                Man->Base.y = Block->Base.y - 120;
                };
            };
    };

    if ((Man->Base.x - Block->Base.x) <= 25 &&
        (Man->Base.x - Block->Base.x) > 0)

    {
    if ((Block->Base.y - Man->Base.y) <= 120 &&
        (Block->Base.y - Man->Base.y) > 0)
            {
            if (GetAsyncKeyState (VK_UP))
                {
                Man->vY = -30;
                };
            if (Man->vY > 0)
                {
                Man->vY = 0;
                Man->Base.y = Block->Base.y - 120;
                };
            };
    };

    if ((Block->Base.y - Man->Base.y) <= 110 &&
        (Block->Base.y - Man->Base.y) > 0    &&
        (Block->Number < 3))
        {
        if ((Block->Base.x - Man->Base.x) <= 74 &&
            (Block->Base.x - Man->Base.x)  > 0)
            {
            /* if (Man->vX < 0)
                Man->vX = 0; */
            };

        if ((Man->Base.x - Block->Base.x) <= 25 &&
            (Man->Base.x - Block->Base.x)  > 0)
            {
            /* if (Man->vX > 0)
                Man->vX = 0; */
            };
       };

    /* if ((Block->Base.y - Man->Base.y) > 120)
        {
        Man->vY = 30;
        }; */
    };

    // Destroying
    if (Block->Base.Health > 0 &&
        Block->Base.Health < 50 &&
        Block->Number != 4 &&
        Block->Number != 21 &&
        Block->Number != 8)
    {
    if (ModuleDistance (Block->Base.x+25, Block->Base.y+25, txMouseX(), txMouseY(), 50) == 1)
        if (GetAsyncKeyState (VK_LBUTTON) &&
            Man->LeftArm == 11 &&
            Block->Base.Health > 1)
               Block->Base.Health -= 1;

    if (ModuleDistance (Block->Base.x+25, Block->Base.y+25, txMouseX(), txMouseY(), 50) == 1)
        if (GetAsyncKeyState (VK_LBUTTON) &&
            Man->RightArm == 11 &&
            Block->Base.Health > 1)
               Block->Base.Health -= 1;

    if (Block->Base.Health == 1)
        {
        if (Man->LeftArm == 0)
            {
            Man->LeftArm = Block->Number;
            Man->LeftArmPicture = Block->Picture;
            Block->Base.Health = 0;
            }
        else
        if (Man->RightArm == 0)
            {
            Man->RightArm = Block->Number;
            Man->RightArmPicture = Block->Picture;
            Block->Base.Health = 0;
            }
        else
        {
        Block->Base.Health == 1;
        };
        };
    };

    // Building
    if (Man->LeftArm == 1 &&
        GetAsyncKeyState (VK_RBUTTON) &&
        GetAsyncKeyState (VK_NUMPAD1) &&
        Block->Base.Health == 0)
            {
            Block->Base.Health = Man->LeftArm;
            Block->Picture = Man->LeftArmPicture;
            Man->LeftArm = 0;
            };

    if (Man->RightArm == 1 &&
        GetAsyncKeyState (VK_RBUTTON) &&
        GetAsyncKeyState (VK_NUMPAD2) &&
        Block->Base.Health == 0)
            {
            Block->Base.Health = Man->RightArm;
            Block->Picture = Man->RightArmPicture;
            Man->RightArm = 0;
            };

    // Boxes
    if (Block->Number == 2)
        {
        if (// Man->High == 1 &&
            (Block->Base.x - Man->Base.x) <= 74 &&
            (Block->Base.x - Man->Base.x) > -50 &&
            (Block->Base.y - Man->Base.y) <= 140 &&
            (Block->Base.y - Man->Base.y) > 0 &&
            Man->vY > 0)
            {
            Block->Base.Health = Block->Base.Health - Man->vY*0.0005;
            };
        };

    // Fire
    if (Block->Number == 4)
        {
        if ((Block->Base.x - Man->Base.x) <= 25 &&
            (Block->Base.x - Man->Base.x) > -50 &&
            (Block->Base.y - Man->Base.y) <= 140 &&
            (Block->Base.y - Man->Base.y) > 0)
            {
            Man->Position = 1;
            };

        if ((Block->Base.x - Man->Base.x) <= 50 &&
            (Block->Base.x - Man->Base.x) > -100 &&
            (Block->Base.y - Man->Base.y) <= 140 &&
            (Block->Base.y - Man->Base.y) > 0)
            {
            Man->Temperature += 0.5;
            };
        };

    // Water
    if (Block->Number == 5)
        {
        if ((Block->Base.x - Man->Base.x) <= 25 &&
            (Block->Base.x - Man->Base.x) > -50 &&
            (Block->Base.y - Man->Base.y) <= 140 &&
            (Block->Base.y - Man->Base.y) > 0)
            {
            Man->Position = 0;
            };
        };

    if (Block->Base.x - Man->Base.x >= -50 &&
        Block->Base.x - Man->Base.x <= 0   &&
        Block->Base.y - Man->Base.y <= 150 &&
        Block->Base.y - Man->Base.y > 0    &&
        Man->vY >= 60)
            {
            Man->Base.Health -= 3;
            };

    // Things
    if (Block->Number > 10 &&
        Block->Number <= 20 &&
        Block->Base.Health > 0)
            {
            if (ModuleDistance (Block->Base.x+25, Block->Base.y+25, txMouseX(), txMouseY(), 50) == 1 &&
                GetAsyncKeyState (VK_MBUTTON))
                    {
                    if (Man->LeftArm == 0)
                        {
                        Man->LeftArm = Block->Number;
                        Man->LeftArmPicture = Block->Picture;
                        Block->Base.Health = 0;
                        }
                else
                if (Man->RightArm == 0)
                    {
                    Man->RightArm = Block->Number;
                    Man->RightArmPicture = Block->Picture;
                    Block->Base.Health = 0;
                    };
            };
            };

    // Food
    if (Man->LeftArm > 20 &&
        Man->LeftArm < 30 &&
        GetAsyncKeyState (VK_NUMPAD1))
            {
            Man->LeftArm = 0;
            Man->Base.Health += 4;
            };

    if (Man->RightArm > 20 &&
        Man->RightArm < 30 &&
        GetAsyncKeyState (VK_NUMPAD2))
            {
            Man->RightArm = 0;
            Man->Base.Health += 4;
            };

    if (ModuleDistance (Block->Base.x+25, Block->Base.y+25, txMouseX(), txMouseY(), 50) == 1 &&
        Block->Number > 20 &&
        Block->Number < 30 &&
        Block->Base.Health == 1000 &&
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

    if (Block->Number > 20 &&
        Block->Number < 30 &&
        Block->Base.Health < 1000)
            {
            Block->Base.Health += 1;
            };

    // Chest
    if (ModuleDistance (Block->Base.x+25, Block->Base.y+25, txMouseX(), txMouseY(), 50) == 1 &&
        Block->Number == 8)
        if (GetAsyncKeyState (VK_RETURN))
            {
            txSetColor (TX_DARKGREY, 5);
            txSetFillColor (TX_TRANSPARENT);

            txRectangle  (Block->Base.x, Block->Base.y-100, Block->Base.x+50, Block->Base.y-50);
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

int Distance (int a, int b, int Distance)
    {
    if ((fabs(a - b)) <= Distance)
    if ((fabs(a - b)) > 0)
        {
        return 1;
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

void Menu (MouseType Mouse)
    {
    int Menu = 1;

    txSetColor (TX_BLACK);
    txSetFillColor (TX_DARKGRAY);
        if (Menu == 2)
            {
            txSetColor (TX_BLACK, 5);
            txRectangle (20, 20, 980, 780);
            if (fabs (Mouse.x - 245) <= 245)
                {
                if (fabs (Mouse.y - 135) <= 35)
                    {
                    if (GetAsyncKeyState (VK_LBUTTON))
                        {
                        Menu = 1;
                        };
                    };
                };
            };

        if (Menu == 1)
            {
            if (sqrt((Mouse.x - 500)*(Mouse.x - 500) + (Mouse.y - 60)*(Mouse.y - 60)) <= 50)
                {
                if (GetAsyncKeyState (VK_LBUTTON))
                    {
                    Menu = 2;
                    };
                };
            };
    };

void DrawHealth (int Health, AllImageType AllImage)
    {
    int null = 0;

    DrawTransparentImage (AllImage.Health, 10, 113, &null, &null);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (60, 120, 160, 140);
    txSetFillColor (TX_RED);
    txRectangle (60, 120, 60+(Health*5), 140);
    };



