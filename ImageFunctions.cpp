#include "ImageFunctions.h"

void LoadAllImages (AllImageType* AllImages)
    {
    int Procent = 1;

    LoadGameImage (&AllImages->BackGround,    "Images/ForestBackGround.bmp",       1, 2, TX_WHITE, &Procent, Number_of_Images);

    // printf ("1:LoadAllImages(): File = %s , HDC = %d \n", AllImages->BackGround.FileName, AllImages->BackGround.Picture);

    LoadGameImage (&AllImages->Cursor,        "Images/GameCursor.bmp",             1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Dirt,          "Images/DirtAnimation.bmp",          4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Health,        "Images/GameHeart.bmp",              1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Finish,        "Images/Finish.bmp",                 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Start,         "Images/Start.bmp",                  1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Pause,         "Images/GamePause.bmp",              1, 6, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Coin,          "Images/GameCoin.bmp",               2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->CoinAnimation, "Images/CoinAnimation.bmp",          4, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Box,           "Images/WoodBoxAnimation.bmp",       4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Man,           "Images/RedManAnimation.bmp",        1, 6, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Stairs,        "Images/Stairs.bmp",                 4, 3, TX_BLACK, &Procent, Number_of_Images);

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

    LoadGameImage (&AllImages->Villager,      "Images/Villager.bmp",               3, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->SaySign,       "Images/SaySign.bmp",                1, 6, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Thief,         "Images/Thief.bmp",                  2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Covboy,        "Images/Covboy.bmp",                 2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Inventory,     "Images/Inventory.bmp",              1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Lock,          "Images/Lock.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Gun,           "Images/Gun.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Grass,         "Images/Grass.bmp",                  1, 4, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Knife,         "Images/Knife.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Tree,          "Images/Tree.bmp",                   1, 8, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Wood,          "Images/Wood.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->House,         "Images/House.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Slot,          "Images/Slot.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Axe,           "Images/Axe.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Snow,          "Images/Snow.bmp",                   6, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Menu,          "Images/MainMenu.bmp",               1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->BonFire,       "Images/BonFire.bmp",                1, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bear,          "Images/Bear.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

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
    txDeleteDC (AllImages.Villager.Picture);
    txDeleteDC (AllImages.SaySign.Picture);
    txDeleteDC (AllImages.Thief.Picture);
    txDeleteDC (AllImages.Covboy.Picture);
    txDeleteDC (AllImages.Gun.Picture);
    txDeleteDC (AllImages.Grass.Picture);
    txDeleteDC (AllImages.Knife.Picture);
    txDeleteDC (AllImages.Wood.Picture);
    txDeleteDC (AllImages.House.Picture);
    txDeleteDC (AllImages.Snow.Picture);
    txDeleteDC (AllImages.Menu.Picture);
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

    Image->Picture = txLoadImage (Picture);

    Image->color = color;

    if (Image->Picture == 0)
        {
        // printf ("FileName = \"%s\" \n", Image->FileName);
        };

    // printf ("LoadGameImage(): FileName = \"%s\", HDC = \"%p\" \n", Image->FileName, Image->Picture);

    txSleep (Loading_Sleep);
    };

void DrawTransparentImage (ImageType* Image, int x, int y, int* xAnimationNumber, int* yAnimationNumber, CamType* Camera)
    {
    // printf ("DrawTransparentImage(): FileName = \"%s\", HDC = \"%p\" \n", Image.FileName, Image.Picture);

    int xSize = txGetExtentX (Image->Picture)/Image->xMaxAnimationNumber;
    int ySize = txGetExtentY (Image->Picture)/Image->yMaxAnimationNumber;

    DrawTransparentBlt (x - Camera->x, y - Camera->y, xSize, ySize, Image->Picture, *xAnimationNumber*xSize, *yAnimationNumber*ySize, Image->color);
    };

