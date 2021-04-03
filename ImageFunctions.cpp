#include "ImageFunctions.h"

CamType FixedCamera = {{0, 0}, {0, 0}, 0};

void LoadAllImages (AllImageType* AllImages)
    {
    int Procent = 1;

    LoadGameImage (&AllImages->BackGround,    "Images/NewForestBackGround.bmp",    1, 1, TX_WHITE, &Procent, Number_of_Images);

    // printf ("1:LoadAllImages(): File = %s , HDC = %d \n", AllImages->BackGround.FileName, AllImages->BackGround.Picture);

    LoadGameImage (&AllImages->Cursor,        "Images/GameCursor.bmp",             1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Dirt,          "Images/DirtAnimation.bmp",          4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Health,        "Images/GameHeart.bmp",              1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Finish,        "Images/Finish.bmp",                 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Start,         "Images/Start.bmp",                  1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Pause,         "Images/GamePause.bmp",              1, 7, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Coin,          "Images/GameCoin.bmp",               2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->CoinAnimation, "Images/CoinAnimation.bmp",          4, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Box,           "Images/WoodBoxAnimation.bmp",       4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Man,           "Images/NewManWithAxe.bmp",          6, 8, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Stairs,        "Images/WallStairs.bmp",             1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Fire,          "Images/FireAnimation.bmp",          5, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->GreenFire,     "Images/GreenFire.bmp",              4, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->BlackSpace,    "Images/Black.bmp",                  4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bat,           "Images/Bat.bmp",                    4, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Stalactite,    "Images/Stalactite.bmp",             4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->GameOver,      "Images/GameOver.bmp",               1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Pickaxe,       "Images/Pickaxe.bmp",                4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Termometer,    "Images/termometer.bmp",             1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Apple,         "Images/Apple.bmp",                  1, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Chest,         "Images/Chest.bmp",                  4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->IronOre,       "Images/IronOre.bmp",                4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Water,         "Images/Water2.bmp",                 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Villager,      "Images/Forester.bmp",               3, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->SaySign,       "Images/SaySign.bmp",                1, 6, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Thief,         "Images/Thief.bmp",                  2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Covboy,        "Images/Covboy.bmp",                 2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Inventory,     "Images/Inventory.bmp",              1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Lock,          "Images/Lock.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Gun,           "Images/Gun.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Grass,         "Images/NewDirtBlock.bmp",           1, 4, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Knife,         "Images/Knife.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Tree,          "Images/NewSmallTree.bmp",           1, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Wood,          "Images/Wood.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->House,         "Images/House.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Slot,          "Images/Slot.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Axe,           "Images/Axe.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Snow,          "Images/Snow.bmp",                   6, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Menu,          "Images/MainMenu.bmp",               1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->BonFire,       "Images/NewFire.bmp",                8, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bear,          "Images/Bear.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Ghost,         "Images/Ghost.bmp",                  2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Plus,          "Images/Plus.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->CommonSlot,    "Images/CommonSlot.bmp",             1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Rock,          "Images/Rock.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Stone,         "Images/Stone.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bow,           "Images/Bow.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Arrow,         "Images/Arrow.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->SmallItems,    "Images/SmallItems.bmp",             1, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bandit,        "Images/Bandit.bmp",                 1, 4, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bullet,        "Images/Bullet.bmp",                 1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bridge,        "Images/Bridge.bmp",                 1, 4, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Boat,          "Images/Boat.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Wolf,          "Images/Wolf.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Fish,          "Images/Fish.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->FishingSmall,  "Images/FishingRod.bmp",             1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->FishingBig,    "Images/FishingBig.bmp",             1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->CookedFish,    "Images/CookedFish.bmp",             1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->FallingTree,   "Images/FallingTree.bmp",            1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Spider,        "Images/Spider.bmp",                 1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Rope,          "Images/Rope.bmp",                   1, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->CraftImage,    "Images/CraftImage.bmp",             1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Fence,         "Images/BigFence.bmp",               1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->StoneWall,     "Images/NewStoneWall.bmp",           1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->StoneFloor,    "Images/DarkFloor.bmp",              1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->MineEntrance,  "Images/DownEntrance.bmp",           1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Dynamite,      "Images/TNT.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Explosion,     "Images/Explosion.bmp",              6, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&AllImages->BlackFrontGround,"Images/BlackBackGround.bmp",      1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->HighCase,      "Images/HighCase.bmp",               1, 2, TX_WHITE, &Procent, Number_of_Images);
    };


void DeleteAllImage (AllImageType* AllImages)
    {
    GRDeleteDC (&AllImages->BackGround.Picture);
    GRDeleteDC (&AllImages->Cursor.Picture);
    GRDeleteDC (&AllImages->Dirt.Picture);
    GRDeleteDC (&AllImages->Health.Picture);
    GRDeleteDC (&AllImages->Finish.Picture);
    GRDeleteDC (&AllImages->Start.Picture);
    GRDeleteDC (&AllImages->Pause.Picture);
    GRDeleteDC (&AllImages->Coin.Picture);
    GRDeleteDC (&AllImages->CoinAnimation.Picture);
    GRDeleteDC (&AllImages->Box.Picture);
    GRDeleteDC (&AllImages->Man.Picture);
    GRDeleteDC (&AllImages->Stairs.Picture);
    GRDeleteDC (&AllImages->Fire.Picture);
    GRDeleteDC (&AllImages->GreenFire.Picture);
    GRDeleteDC (&AllImages->Water.Picture);
    GRDeleteDC (&AllImages->Bat.Picture);
    GRDeleteDC (&AllImages->Stalactite.Picture);
    GRDeleteDC (&AllImages->GameOver.Picture);
    GRDeleteDC (&AllImages->Pickaxe.Picture);
    GRDeleteDC (&AllImages->Villager.Picture);
    GRDeleteDC (&AllImages->SaySign.Picture);
    GRDeleteDC (&AllImages->Thief.Picture);
    GRDeleteDC (&AllImages->Covboy.Picture);
    GRDeleteDC (&AllImages->Gun.Picture);
    GRDeleteDC (&AllImages->Grass.Picture);
    GRDeleteDC (&AllImages->Knife.Picture);
    GRDeleteDC (&AllImages->Wood.Picture);
    GRDeleteDC (&AllImages->House.Picture);
    GRDeleteDC (&AllImages->Snow.Picture);
    GRDeleteDC (&AllImages->Menu.Picture);
    };

void DrawLoading (int Procents)
    {
    GRSetColor (RGB (72, 72, 72), 1);
    GRSetFillColor (RGB (72, 72, 72));
    GRRectangle (0, 0, 2000, 2000);
    GRSetColor (TX_BLACK, 3);
    GRRectangle (Load_BigRect_X1, Load_BigRect_Y1, Load_BigRect_X2, Load_BigRect_Y2);
    GRSetFillColor (TX_GREEN);
    GRRectangle (Load_SmallRect_X1, Load_SmallRect_Y1, 200+(11.50*Procents), Load_SmallRect_Y2);

    char str [50] = "";

    sprintf (str, "Loading: %d%%", Procents);

    PointType LoadingPoint = {Loading_TextX, Loading_TextY};

    GRSetAlign ();
    GRSetColor (TX_BLACK, 1);
    GRSelectFont ("Comic Sans MS", Loading_TextSize);
    GRTextOut (LoadingPoint, str);
    };

void LoadGameImage (ImageType* Image, const char* Picture, int xMaxFrame, int yMaxFrame, COLORREF color,
                        int* Procent, double Number)
    {
    *Procent += 100.0/Number;

    DrawLoading (*Procent);

    // printf ("LoadGameImage(): Picture = \"%s\" \n", Picture);

    // *Image = {Picture, xFrame, yFrame, xMaxFrame, yMaxFrame, txLoadImage (Picture), color};

    Image->FileName = Picture;

    Image->xMaxAnimationNumber = xMaxFrame;

    Image->yMaxAnimationNumber = yMaxFrame;

    Image->Picture = GRLoadImage (Picture);

    Image->color = color;

    if (Image->Picture == 0)
        {
        // printf ("FileName = \"%s\" \n", Image->FileName);
        };

    // printf ("LoadGameImage(): FileName = \"%s\", HDC = \"%p\" \n", Image->FileName, Image->Picture);

    GRSleep (Loading_Sleep);
    };

void DrawTransparentImage (const ImageType& Image, int x, int y, int* xAnimationNumber, int* yAnimationNumber, CamType* Camera)
    {
    // printf ("DrawTransparentImage(): FileName = \"%s\", HDC = \"%p\" \n", Image.FileName, Image.Picture);

    int xSize = GRGetExtentX (Image.Picture)/Image.xMaxAnimationNumber;
    int ySize = GRGetExtentY (Image.Picture)/Image.yMaxAnimationNumber;

    GRTransparentBlt (x - Camera->Point.x, y - Camera->Point.y, xSize, ySize, Image.Picture, *xAnimationNumber*xSize, *yAnimationNumber*ySize, Image.color);
    };

