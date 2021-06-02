#include "ImageFunctions.h"

CamType FixedCamera = {{0, 0}, {0, 0}, 0};

void LoadAllImages ()
    {
    int Procent = 1;

    LoadGameImage (&GlobalAllImage.BackGround,    "Images/NewForestBackGround.bmp",    1, 1, TX_WHITE, &Procent, Number_of_Images);

    // printf ("1:LoadGlobalAllImage(): File = %s , HDC = %d \n", GlobalAllImage.BackGround.FileName, GlobalAllImage.BackGround.Picture);

    LoadGameImage (&GlobalAllImage.Cursor,        "Images/GameCursor.bmp",             1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Dirt,          "Images/DirtAnimation.bmp",          4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Health,        "Images/GameHeart.bmp",              1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Finish,        "Images/Finish.bmp",                 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Start,         "Images/Start.bmp",                  1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Pause,         "Images/GamePause.bmp",              1, 7, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Coin,          "Images/GameCoin.bmp",               2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.CoinAnimation, "Images/CoinAnimation.bmp",          4, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Box,           "Images/WoodBoxAnimation.bmp",       4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Man,           "Images/NewMan.bmp",                 6, 8, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Stairs,        "Images/WallStairs.bmp",             1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Fire,          "Images/FireAnimation.bmp",          5, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.GreenFire,     "Images/GreenFire.bmp",              4, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.BlackSpace,    "Images/Black.bmp",                  4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Bat,           "Images/Bat.bmp",                    4, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Stalactite,    "Images/Stalactite.bmp",             4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.GameOver,      "Images/GameOver.bmp",               1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Pickaxe,       "Images/Pickaxe.bmp",                4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Termometer,    "Images/termometer.bmp",             1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Apple,         "Images/Apple.bmp",                  1, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Chest,         "Images/Chest.bmp",                  4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.IronOre,       "Images/IronOre.bmp",                4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Water,         "Images/Water2.bmp",                 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Villager,      "Images/Forester.bmp",               3, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.SaySign,       "Images/SaySign.bmp",                1, 6, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Thief,         "Images/Thief.bmp",                  2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Covboy,        "Images/Covboy.bmp",                 2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Inventory,     "Images/Inventory.bmp",              1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Lock,          "Images/Lock.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Gun,           "Images/Gun.bmp",                    1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Grass,         "Images/NewDirtBlock.bmp",           1, 4, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Knife,         "Images/Knife.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Tree,          "Images/NewSmallTree.bmp",           1, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Wood,          "Images/Wood.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.House,         "Images/House.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Slot,          "Images/Slot.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Axe,           "Images/Axe.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Snow,          "Images/Snow.bmp",                   6, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Menu,          "Images/MainMenu.bmp",               1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.BonFire,       "Images/NewFire.bmp",                8, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Bear,          "Images/Bear.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Ghost,         "Images/Ghost.bmp",                  2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Plus,          "Images/Plus.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.CommonSlot,    "Images/CommonSlot.bmp",             1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Rock,          "Images/Rock.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Stone,         "Images/Stone.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Bow,           "Images/Bow.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Arrow,         "Images/Arrow.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.SmallItems,    "Images/SmallItems.bmp",             1, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Bandit,        "Images/Bandit.bmp",                 1, 4, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Bullet,        "Images/Bullet.bmp",                 1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Bridge,        "Images/Bridge.bmp",                 1, 4, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Boat,          "Images/Boat.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Wolf,          "Images/Wolf.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Fish,          "Images/Fish.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.FishingSmall,  "Images/FishingRod.bmp",             1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.FishingBig,    "Images/FishingBig.bmp",             1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.CookedFish,    "Images/CookedFish.bmp",             1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.FallingTree,   "Images/FallingTree.bmp",            1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Spider,        "Images/Spider.bmp",                 1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Rope,          "Images/Rope.bmp",                   1, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.CraftImage,    "Images/CraftImage.bmp",             1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Fence,         "Images/BigFence.bmp",               1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.StoneWall,     "Images/NewStoneWall.bmp",           1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.StoneFloor,    "Images/DarkFloor.bmp",              1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.MineEntrance,  "Images/DownEntrance.bmp",           1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Dynamite,      "Images/TNT.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Explosion,     "Images/Explosion.bmp",              6, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.BlackFrontGround,"Images/BlackBackGround.bmp",      1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.HighCase,      "Images/HighCase.bmp",               1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Take_close,    "Images/Take_Close.bmp",             1, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Up_down,       "Images/Up_Down.bmp",                1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.LoadQuestion,  "Images/LoadQuestion.bmp",           1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.ManWithAxe,    "Images/NewManWithAxe.bmp",          6, 8, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.ManWithGuns,   "Images/NewManWithGuns.bmp",         6, 8, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.BigDirt,       "Images/NewBigDirt.bmp",             1, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    // Rooms :
    LoadGameImage (&GlobalAllImage.Kitchen,       "Images/Kitchen.bmp",                1, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Room1,         "Images/Room1.bmp",                  1, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Room2,         "Images/Room2.bmp",                  1, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Room3,         "Images/Room3.bmp",                  1, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Room4,         "Images/Room4.bmp",                  1, 1, RGB (91, 110, 225), &Procent, Number_of_Images);

    LoadGameImage (&GlobalAllImage.Room5,         "Images/Room5.bmp",                  1, 1, RGB (91, 110, 225), &Procent, Number_of_Images);
    };

void DeleteAllImage ()
    {
    GRDeleteDC (&GlobalAllImage.BackGround.Picture);
    GRDeleteDC (&GlobalAllImage.Cursor.Picture);
    GRDeleteDC (&GlobalAllImage.Dirt.Picture);
    GRDeleteDC (&GlobalAllImage.Health.Picture);
    GRDeleteDC (&GlobalAllImage.Finish.Picture);
    GRDeleteDC (&GlobalAllImage.Start.Picture);
    GRDeleteDC (&GlobalAllImage.Pause.Picture);
    GRDeleteDC (&GlobalAllImage.Coin.Picture);
    GRDeleteDC (&GlobalAllImage.CoinAnimation.Picture);
    GRDeleteDC (&GlobalAllImage.Box.Picture);
    GRDeleteDC (&GlobalAllImage.Man.Picture);
    GRDeleteDC (&GlobalAllImage.Stairs.Picture);
    GRDeleteDC (&GlobalAllImage.Fire.Picture);
    GRDeleteDC (&GlobalAllImage.GreenFire.Picture);
    GRDeleteDC (&GlobalAllImage.Water.Picture);
    GRDeleteDC (&GlobalAllImage.Bat.Picture);
    GRDeleteDC (&GlobalAllImage.Stalactite.Picture);
    GRDeleteDC (&GlobalAllImage.GameOver.Picture);
    GRDeleteDC (&GlobalAllImage.Pickaxe.Picture);
    GRDeleteDC (&GlobalAllImage.Villager.Picture);
    GRDeleteDC (&GlobalAllImage.SaySign.Picture);
    GRDeleteDC (&GlobalAllImage.Thief.Picture);
    GRDeleteDC (&GlobalAllImage.Covboy.Picture);
    GRDeleteDC (&GlobalAllImage.Gun.Picture);
    GRDeleteDC (&GlobalAllImage.Grass.Picture);
    GRDeleteDC (&GlobalAllImage.Knife.Picture);
    GRDeleteDC (&GlobalAllImage.Wood.Picture);
    GRDeleteDC (&GlobalAllImage.House.Picture);
    GRDeleteDC (&GlobalAllImage.Snow.Picture);
    GRDeleteDC (&GlobalAllImage.Menu.Picture);
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

void DrawTransparentImage (const ImageType& Image, double x, double y, int* xAnimationNumber, int* yAnimationNumber, CamType* Camera)
    {
    // printf ("DrawTransparentImage(): FileName = \"%s\", HDC = \"%p\" \n", Image.FileName, Image.Picture);

    int xSize = GRGetExtentX (Image.Picture)/Image.xMaxAnimationNumber;
    int ySize = GRGetExtentY (Image.Picture)/Image.yMaxAnimationNumber;

    GRTransparentBlt (x - Camera->Point.x, y - Camera->Point.y, xSize, ySize, Image.Picture, *xAnimationNumber*xSize, *yAnimationNumber*ySize, Image.color);
    };

