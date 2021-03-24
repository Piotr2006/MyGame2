#include "ManType.h"

ManType :: ManType (PointType _Point, double _Health, AnimationType _Animation,
                    double _vX, double _vY, double _aX, double _aY,
                    int _Side, int _Position, double _Temperature,
                    int _NumberCoin, int _xWeapon, int _ArmSpeed, char _Name [50], int _Kind, InvType _Inventory,
                    int _Time, int _Days, double _ArrowX, double _ArrowY, int _ArrowVX, int _ArrowVY, HelpType _HelpSystem) :
    BaseType (_Point, _Health, _Animation),
    vX (_vX),
    vY (_vY),
    aX (_aX),                                                  // & - Àìïåðñàíä(áåðåò àäðåñ ïåðåìåííîé)
    aY (_aY),                                                  // & - Амперсанд (берет адрес переменной)
    Side (_Side),
    Position (_Position),
    Temperature (_Temperature),
    NumberCoin (_NumberCoin),
    xWeapon (_xWeapon),
    ArmSpeed (_ArmSpeed),
    Kind (_Kind),
    Inventory (_Inventory),
    Time (_Time),
    Days (_Days),
    ArrowX (_ArrowX),
    ArrowY (_ArrowY),
    ArrowVX (_ArrowVX),
    ArrowVY (_ArrowVY),
    HelpSystem (_HelpSystem)
    {
    /* for (int i = 0; i < NameSize; i += 1)
        {
        Name [i] = _Name [i];
        }; */

    // strcpy (Name, _Name);

    StrCpy (Name, _Name);
    };

void CreateVillagers (ManType Villagers [], AllImageType AllImage)
    {
    int i = 0;

    int BearNumber = rand() % 4;

    while (Villagers[i].Point.x != -1 && Villagers[i].Point.y != -1)
        {
        if (i < BearNumber)
            {
            Villagers[i].Health = 20;
            Villagers[i].Kind = MT_Bear;
            Villagers[i].Inventory.Stone = MT_Bear;
            Villagers[i].Inventory.Rope = 10;
            Villagers[i].Point.x = rand() % 11400*World_Size;
            Villagers[i].Point.y = -500;
            Villagers[i].Animation.Picture = &AllImage.Bear;
            };

        if (i >= BearNumber &&
            i < 7)
            {
            Villagers[i].Health = 15;
            Villagers[i].Kind = MT_Bear;
            Villagers[i].Inventory.Stone = MT_Wolf;
            Villagers[i].Inventory.Rope = 13;
            Villagers[i].Point.x = rand() % 11400*World_Size;
            Villagers[i].Point.y = -500;
            Villagers[i].Animation.Picture = &AllImage.Wolf;
            };

        if (i >= 7 &&
            i < 10)
            {
            Villagers[i].Health = 10;
            Villagers[i].Kind = MT_Bear;
            Villagers[i].Inventory.Stone = MT_Spider;
            Villagers[i].Inventory.Rope = 12;
            Villagers[i].Inventory.Arrow = 34;
            Villagers[i].Point.x = rand() % 11400*World_Size;
            Villagers[i].Point.y = -500;
            Villagers[i].Animation.Picture = &AllImage.Spider;
            };

        if (i >= 10 &&
            i < 13)
            {
            Villagers[i].Health = 20;
            Villagers[i].Kind = MT_Seller;
            Villagers[i].Inventory.Rope = 10;
            Villagers[i].Inventory.Axe = rand() % 3;
            Villagers[i].Inventory.Knife = rand() % 3;
            Villagers[i].Inventory.Bow = rand() % 3;
            Villagers[i].Point.x = rand() % 11400*World_Size;
            Villagers[i].Point.y = -500;
            Villagers[i].Animation.Picture = &AllImage.Villager;
            };

        if (i >= 13 &&
            i < 20)
            {
            Villagers[i].Health = 20;
            Villagers[i].Kind = MT_Fish;
            // Villagers[i].Inventory.Rope = 10;
            Villagers[i].Point.x = -rand() % 700 - 500;
            Villagers[i].Point.y = 750 + rand() % 100;
            Villagers[i].Animation.Picture = &AllImage.Fish;
            };

        if (i >= 20 &&
            i < 22)
            {
            Villagers[i].Health = 20;
            Villagers[i].Kind = MT_Bear;
            Villagers[i].Inventory.Rope = 10;
            Villagers[i].Inventory.Stone = MT_Ghost;
            Villagers[i].Inventory.Arrow = 0;
            Villagers[i].Point.x = rand() % 100;
            Villagers[i].Inventory.Arrow = -300;
            Villagers[i].Point.y = 400;
            Villagers[i].Animation.Picture = &AllImage.Ghost;
            };

        if (i >= 22)
            {
            Villagers[i].Health = 0;
            };

        // x += 1;

        i += 1;
        };
    };


void DrawSlot (int Block, int x, int y, ImageType Picture, int TextX, int TextY)
    {
    int null = 0;
    int one = 1;

    CamType FixedCamera = {0, 0, 0, 0, 0};

    PointType TextPoint = {TextX + 38, TextY + 114};

    if (Block > 0)
        {
        DrawTransparentImage (&Picture, x, y + 70, &null, &one, &FixedCamera);

        Text (TextPoint, 20, Block, "");
        };
    };

void ManType :: Crafting (AllImageType AllImage, CamType* FixedCamera)
    {
    PointType Mouse = {txMouseX(), txMouseY()};

    PointType CraftPoint = {40, 325};

    PointType CraftRight = {324, 325};
    PointType CraftLeft = {324, 395};

    PointType CraftResult = {265, 325};

    int null = 0;
    int one  = 1;
    int four = 4;
    int five = 5;

    if (GetAsyncKeyState (VK_LBUTTON))
        {}
    else
        Inventory.CraftControlSpeed = 0;

    if (Inventory.CraftNumber == 0)
        {
        DrawTransparentImage (&AllImage.CommonSlot, 15, 300, &null, &null, FixedCamera);

        DrawTransparentImage (&AllImage.CraftImage, 10, 295, &null, &null, FixedCamera);

        if (ModuleDistance (CraftPoint, Mouse, 50) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            {
            Inventory.CraftNumber = 1;
            Inventory.CraftControlSpeed = 1;
            };
        };

    if (Inventory.CraftNumber > 0)
    {
    DrawTransparentImage (&AllImage.CommonSlot, 15, 300, &null, &null, FixedCamera);

    DrawTransparentImage (&AllImage.Plus, 75, 304, &null, &null, FixedCamera);

    DrawTransparentImage (&AllImage.CommonSlot, 127, 300, &null, &null, FixedCamera);

    DrawTransparentImage (&AllImage.Plus, 187, 304, &null, &one, FixedCamera);

    DrawTransparentImage (&AllImage.Slot, 239, 300, &null, &null, FixedCamera);

    DrawTransparentImage (&AllImage.Pause, 309, 300, &null, &four, FixedCamera);

    DrawTransparentImage (&AllImage.Pause, 309, 370, &null, &five, FixedCamera);

    if (ModuleDistance (CraftRight, Mouse, 50) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
        Inventory.CraftControlSpeed == 0 &&
        Inventory.CraftNumber < 5)
        {
        Inventory.CraftNumber += 1;
        Inventory.CraftControlSpeed = 1;
        };

    if (ModuleDistance (CraftLeft, Mouse, 50) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
        Inventory.CraftControlSpeed == 0)
        {
        Inventory.CraftNumber -= 1;
        Inventory.CraftControlSpeed = 1;
        };

    if (Inventory.CraftNumber < 0)
        Inventory.CraftNumber = 0;

    if (Inventory.CraftNumber == 1)
        {
        DrawSlot (2, 15, 230, AllImage.Wood, 15, 230);

        DrawTransparentImage (&AllImage.Stone, 127, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Axe, 240, 292, &null, &one, FixedCamera);

        if (Inventory.Wood >= 2 &&
            Inventory.Stone >= 1 &&
            ModuleDistance (CraftResult, Mouse, 50) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Inventory.CraftControlSpeed == 0)
            {
            Inventory.Wood -= 2;
            Inventory.Stone -= 1;
            Inventory.Axe += 1;
            Inventory.CraftNumber = 0;
            Inventory.CraftControlSpeed = 1;
            if (HelpSystem.Number == HelpCrafting)
                HelpSystem.Number = HelpDestroyTree;
            };
        };

    if (Inventory.CraftNumber == 2)
        {
        DrawTransparentImage (&AllImage.Wood, 127, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Stone, 15, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Knife, 240, 312, &null, &one, FixedCamera);

        if (Inventory.Wood >= 1 &&
            Inventory.Stone >= 1 &&
            ModuleDistance (CraftResult, Mouse, 50) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Inventory.CraftControlSpeed == 0)
            {
            Inventory.Wood -= 1;
            Inventory.Stone -= 1;
            Inventory.Knife += 1;
            Inventory.CraftNumber = 0;
            Inventory.CraftControlSpeed = 1;
            };
        };

    if (Inventory.CraftNumber == 3)
        {
        DrawSlot (2, 15, 230, AllImage.Wood, 15, 230);

        DrawTransparentImage (&AllImage.Rope, 127, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.FishingSmall, 240, 292, &null, &one, FixedCamera);

        if (Inventory.Wood >= 2 &&
            Inventory.Rope >= 1 &&
            ModuleDistance (CraftResult, Mouse, 50) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Inventory.CraftControlSpeed == 0)
            {
            Inventory.Wood -= 2;
            Inventory.Rope -= 1;
            Inventory.Fishing += 1;
            Inventory.CraftNumber = 0;
            Inventory.CraftControlSpeed = 1;
            };
        };

    if (Inventory.CraftNumber == 4)
        {
        DrawSlot (2, 127, 230, AllImage.Wood, 127, 230);

        DrawSlot (2, 15, 230, AllImage.Rope, 15, 230);

        DrawTransparentImage (&AllImage.Bow, 240, 292, &null, &one, FixedCamera);

        if (Inventory.Wood >= 2 &&
            Inventory.Rope >= 2 &&
            ModuleDistance (CraftResult, Mouse, 50) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Inventory.CraftControlSpeed == 0)
            {
            Inventory.Wood -= 2;
            Inventory.Rope -= 2;
            Inventory.Bow += 1;
            Inventory.CraftNumber = 0;
            Inventory.CraftControlSpeed = 1;
            };
        };

    if (Inventory.CraftNumber == 5)
        {
        DrawTransparentImage (&AllImage.Wood, 127, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Stone, 15, 300, &null, &one, FixedCamera);

        DrawSlot (3, 233, 254, AllImage.Arrow, 240, 230);

        if (Inventory.Wood >= 1 &&
            Inventory.Stone >= 1 &&
            ModuleDistance (CraftResult, Mouse, 50) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Inventory.CraftControlSpeed == 0)
            {
            Inventory.Wood -= 1;
            Inventory.Stone -= 1;
            Inventory.Arrow += 3;
            Inventory.CraftNumber = 0;
            Inventory.CraftControlSpeed = 1;
            };
        };
    };

    };

void ManType :: DrawInventory (CamType* Camera, CamType* FixedCamera, AllImageType AllImage)
    {
    int null = 0;

    int one = 1;
    int two = 2;

    PointType Mouse = {txMouseX(), txMouseY()};

    PointType Axe   = {350, 515};
    PointType Bow   = {350, 585};
    PointType Arrow = {350, 655};

    PointType Wood  = {400, 515};
    PointType Stone = {400, 585};
    PointType Coin  = {400, 655};

    PointType Apple       = {450, 515};
    PointType Fish        = {450, 585};
    PointType CookedFish  = {450, 655};

    DrawTransparentImage (&AllImage.CommonSlot, 325, 700, &null, &null, FixedCamera);
    DrawTransparentImage (&AllImage.CommonSlot, 375, 700, &null, &null, FixedCamera);
    DrawTransparentImage (&AllImage.CommonSlot, 425, 700, &null, &null, FixedCamera);

    if (Inventory.SelectedType == ST_Weapon)
        {
        DrawTransparentImage (&AllImage.CommonSlot, 325, 490, &null, &null, FixedCamera);
        DrawTransparentImage (&AllImage.CommonSlot, 325, 560, &null, &null, FixedCamera);
        DrawTransparentImage (&AllImage.CommonSlot, 325, 630, &null, &null, FixedCamera);

        if (Inventory.MainNumber == IT_Axe)
            DrawTransparentImage (&AllImage.Slot, 324, 489, &null, &null, FixedCamera);

        if (Inventory.MainNumber == IT_Bow)
            DrawTransparentImage (&AllImage.Slot, 324, 559, &null, &null, FixedCamera);

        if (Inventory.MainNumber == IT_Arrow)
            DrawTransparentImage (&AllImage.Slot, 324, 629, &null, &null, FixedCamera);

        DrawSlot (Inventory.Axe, 325, 410, AllImage.Axe, 325, 420);

        DrawSlot (Inventory.Bow, 325, 480, AllImage.Bow, 325, 490);

        DrawSlot (Inventory.Arrow, 312, 579, AllImage.Arrow, 325, 560);

        if (ModuleDistance (Axe, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Axe;

        if (ModuleDistance (Bow, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Bow;

        if (ModuleDistance (Arrow, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Arrow;
        };

    if (Inventory.SelectedType == ST_Resourses)
        {
        DrawTransparentImage (&AllImage.CommonSlot, 375, 490, &null, &null, FixedCamera);
        DrawTransparentImage (&AllImage.CommonSlot, 375, 560, &null, &null, FixedCamera);
        DrawTransparentImage (&AllImage.CommonSlot, 375, 630, &null, &null, FixedCamera);

        if (Inventory.MainNumber == IT_Wood)
            DrawTransparentImage (&AllImage.Slot, 374, 489, &null, &null, FixedCamera);

        if (Inventory.MainNumber == IT_Stone)
            DrawTransparentImage (&AllImage.Slot, 374, 559, &null, &null, FixedCamera);

        if (Inventory.MainNumber == IT_Coin)
            DrawTransparentImage (&AllImage.Slot, 374, 629, &null, &null, FixedCamera);

        DrawSlot (Inventory.Wood,  375, 420, AllImage.Wood, 375, 420);

        DrawSlot (Inventory.Stone, 375, 490, AllImage.Stone, 375, 490);

        DrawSlot (Inventory.Coin,  385, 567, AllImage.Coin, 375, 560);

        if (ModuleDistance (Wood, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Wood;

        if (ModuleDistance (Stone, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Stone;

        if (ModuleDistance (Coin, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Coin;
        };

    if (Inventory.SelectedType == ST_Food)
        {
        DrawTransparentImage (&AllImage.CommonSlot, 425, 490, &null, &null, FixedCamera);
        DrawTransparentImage (&AllImage.CommonSlot, 425, 560, &null, &null, FixedCamera);
        DrawTransparentImage (&AllImage.CommonSlot, 425, 630, &null, &null, FixedCamera);

        if (Inventory.MainNumber == IT_Apple)
            DrawTransparentImage (&AllImage.Slot, 424, 489, &null, &null, FixedCamera);

        if (Inventory.MainNumber == IT_Fish)
            DrawTransparentImage (&AllImage.Slot, 424, 559, &null, &null, FixedCamera);

        if (Inventory.MainNumber == IT_CookedFish)
            DrawTransparentImage (&AllImage.Slot, 424, 629, &null, &null, FixedCamera);

        DrawSlot (Inventory.Apple,  425, 420, AllImage.Apple, 375, 420);

        DrawSlot (Inventory.Fish, 430, 497, AllImage.Fish, 375, 490);

        DrawSlot (Inventory.CookedFish,  430, 567, AllImage.CookedFish, 375, 560);

        if (ModuleDistance (Apple, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Apple;

        if (ModuleDistance (Fish, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Fish;

        if (ModuleDistance (CookedFish, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_CookedFish;
        };

    // DrawSlot (Inventory.Apple, 475, 700, AllImage.Apple, 475, 700);

    // DrawSlot (Inventory.Knife, 425, 720, AllImage.Knife, 425, 700);

    // DrawSlot (Inventory.Fishing, 725, 700, AllImage.FishingSmall, 725, 700);

    // DrawSlot (Inventory.Fish, 780, 713, AllImage.Fish, 775, 700);

    // DrawSlot (Inventory.CookedFish, 825, 712, AllImage.CookedFish, 825, 700);

    // DrawSlot (Inventory.Rope, 875, 700, AllImage.Rope, 875, 700);

    int X = 1;

    if (Animation.yFrame == 0)
        X = -1;
    if (Animation.yFrame == 1)
        X = 1;

    // Controlling

    if (GetAsyncKeyState (VK_LCONTROL))
        {
        // InvControlSpeed = -1;
        }
    else
        {
        if (GetAsyncKeyState (VK_RCONTROL))
        {
        // InvControlSpeed = 1;
        }
        else
            Inventory.InvControlSpeed = 0;
        };

    if (GetAsyncKeyState (VK_LCONTROL) &&
        Inventory.InvControlSpeed == 0)
        {
        Inventory.SelectedType -= 1;
        Inventory.InvControlSpeed = -1;
        };

    if (GetAsyncKeyState (VK_RCONTROL) &&
        Inventory.InvControlSpeed == 0)
        {
        Inventory.SelectedType += 1;
        Inventory.InvControlSpeed = 1;
        };

    if (Inventory.SelectedType < ST_Weapon)
        Inventory.SelectedType = 8;

    if (Inventory.SelectedType > 8)
        Inventory.SelectedType = ST_Weapon;

    // Numbers

    if (Inventory.MainNumber == IT_Axe)
        {
        Inventory.MainSlot = Inventory.Axe;
        };

    if (Inventory.MainNumber == IT_Wood)
        {
        Inventory.MainSlot = Inventory.Wood;
        };

    if (Inventory.MainNumber == IT_Knife)
        {
        Inventory.MainSlot = Inventory.Knife;
        };

    if (Inventory.MainNumber == IT_Apple)
        {
        Inventory.MainSlot = Inventory.Apple;
        };

    if (Inventory.MainNumber == IT_Stone)
        {
        Inventory.MainSlot = Inventory.Stone;
        };

    if (Inventory.MainNumber == IT_Bow)
        {
        Inventory.MainSlot = Inventory.Bow;
        };

    if (Inventory.MainNumber == IT_Arrow)
        {
        Inventory.MainSlot = Inventory.Arrow;
        };

    if (Inventory.MainNumber == IT_Coin)
        {
        Inventory.MainSlot = Inventory.Coin;
        };

    if (Inventory.MainNumber == IT_Fishing)
        {
        Inventory.MainSlot = Inventory.Fishing;
        };

    if (Inventory.MainNumber == IT_Fish)
        {
        Inventory.MainSlot = Inventory.Fish;
        };

    if (Inventory.MainNumber == IT_CookedFish)
        {
        Inventory.MainSlot = Inventory.CookedFish;
        };

    if (Inventory.MainNumber == IT_Rope)
        {
        Inventory.MainSlot = Inventory.Rope;
        };

    int yFrame = 0;

    if (Animation.yFrame == 0 ||
        Animation.yFrame == 1)
        yFrame= 0;

    if (Animation.yFrame == 5 ||
        Animation.yFrame == 6)
        yFrame= 1;

    if (Animation.yFrame != 0 &&
        Animation.yFrame != 1 &&
        Animation.yFrame != 5 &&
        Animation.yFrame != 6)
        yFrame= 2;

    // ManArm
    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Knife &&
        Inventory.Knife > 0)
        DrawTransparentImage (&AllImage.Knife, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 112, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Apple &&
        Inventory.Apple > 0)
        DrawTransparentImage (&AllImage.Apple, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 112, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Arrow &&
        Inventory.Arrow > 0)
        DrawTransparentImage (&AllImage.Arrow, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 112, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Stone &&
        Inventory.Stone > 0)
        DrawTransparentImage (&AllImage.Stone, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 112, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Wood &&
        Inventory.Wood > 0)
        DrawTransparentImage (&AllImage.Wood, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 70, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Coin &&
        Inventory.Coin > 0)
        DrawTransparentImage (&AllImage.Coin, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 70, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Axe &&
        Inventory.Axe > 0)
        DrawTransparentImage (&AllImage.Axe, Point.x - 26 + yFrame*98,
                              Point.y + 60, &xWeapon, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Fishing &&
        Inventory.Fishing > 0)
        DrawTransparentImage (&AllImage.FishingBig, Point.x - 23 + yFrame*101,
                              Point.y + 60, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Fish &&
        Inventory.Fish > 0)
        DrawTransparentImage (&AllImage.Fish, Point.x - 23 + yFrame*101,
                              Point.y + 110, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_CookedFish &&
        Inventory.CookedFish > 0)
        DrawTransparentImage (&AllImage.CookedFish, Point.x - 23 + yFrame*101,
                              Point.y + 110, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Rope &&
        Inventory.Rope > 0)
        DrawTransparentImage (&AllImage.Rope, Point.x - 23 + yFrame*101,
                              Point.y + 110, &null, &yFrame, Camera);

    // Bow

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Bow &&
        Inventory.Bow > 0)
        {
        DrawTransparentImage (&AllImage.Bow, Point.x + yFrame*72,
                              Point.y + 70, &xWeapon, &yFrame, Camera);

        if (Inventory.Arrow > 0)
            DrawTransparentImage (&AllImage.Arrow, -11 + 61*yFrame + ArrowX,
                                  ArrowY + 100, &null, &yFrame, Camera);
        };

    // printf ("y = %d \n", ArrowY);
    };

void ManType :: DrawMan (CamType* Camera, AllImageType AllImage)
    {
    /* if (GetAsyncKeyState (VK_LBUTTON) &&
        ArmSpeed > 0)
        {
        if (Animation.yFrame <= 4)
            Animation.yFrame = 4;
        if (Animation.yFrame > 4)
            Animation.yFrame = 9;

        ArmSpeed -= 1;
        }
    else
        ArmSpeed = 2; */


    IncreaseAnimationNumber (&Animation);

    int nine = 9;
    // int twonumber = Animation.yFrame + 2;

    if (Kind == 0)
    {
    if (vX > 0)
        {
        if (vY <= 0)
            Animation.yFrame = 7;
        else
            {
            if (vX < Man_SlowSpeed)
                Animation.yFrame = 5;
            else
                Animation.yFrame = 6;
            };

        if (Health <= 0)
            Animation.yFrame = 8;
        };

    if (vX < 0)
        {
        if (vY <= 0)
            Animation.yFrame = 2;
        else
            {
            if (vX > -Man_SlowSpeed)
                Animation.yFrame = 0;
            else
                Animation.yFrame = 1;
            };

        if (Health <= 0)
            Animation.yFrame = 3;
        };
    };

    // printf ("x = %d, y = %d, twonumber = %d\n", Animation.xFrame, Animation.yFrame, twonumber);

    if (Kind != 0 &&
        Kind != MT_Boat)
        {
        if (vX < 0)
            {
            Animation.yFrame = 0;
            };

        if (vX > 0)
            {
            Animation.yFrame = 1;
            };
        };

    // if (Health <= 0)
    //        Animation.yFrame = 2;

    if (Kind == 0)
        DrawTransparentImage (Animation.Picture, Point.x, Point.y, &Animation.xFrame, &Animation.yFrame, Camera);

    if (Kind != 0 &&
        Health > 0)
        DrawTransparentImage (Animation.Picture, Point.x, Point.y, &Animation.xFrame, &Animation.yFrame, Camera);

    int null = 0;

    PointType TextPoint = {Point.x - Camera->x + 50, Point.y - Camera->y};

    if (Health > 0)
        {
        GRSetColor (TX_WHITE, 5);
        GRSelectFont ("Comic Sans MS", 30);
        GRTextOut (TextPoint, Name);
        };
    };

void ManType :: ManFire (CamType* Camera, AllImageType AllImage)
    {
    /* BlockType Fire1 {0 - GRGetExtentX (Animation.Picture->Picture)/2 + Man_Fire1X, 0 - GRGetExtentY (Animation.Picture->Picture)/2 + Man_Fire1Y, 4, {rand() % 4, 0, &AllImage.Fire}, 0};
    BlockType Fire2 {0 - GRGetExtentX (Animation.Picture->Picture)/2 + Man_Fire2X, 0 - GRGetExtentY (Animation.Picture->Picture)/2 + Man_Fire2Y, 4, {rand() % 4, 0, &AllImage.Fire}, 0};
    BlockType Fire3 {0 - GRGetExtentX (Animation.Picture->Picture)/2 + Man_Fire3X, 0 - GRGetExtentY (Animation.Picture->Picture)/2 + Man_Fire3Y, 4, {rand() % 4, 0, &AllImage.Fire}, 0};

    if (Position == Fire_Position)
        {
        Health -= Man_FireDamage/100;
        Temperature += 1;
        Fire1.DrawBlock (Camera, AllImage);
        Fire2.DrawBlock (Camera, AllImage);
        Fire3.DrawBlock (Camera, AllImage);
        }; */
    };

void ManType :: ManHealth (CamType* Camera, AllImageType AllImage)
    {
    int null = 0;

    if (Health < 0)
        {
        Health = 0;
        };

    if (Health == 0)
        {
        DrawTransparentImage (&AllImage.GameOver, Point.x, Point.y, &null, &null, Camera);
        vX = 0;
        vY = 0;
        Position = 0;
        // Inventory.Wood = 0;
        // ArmPicture = &AllImage.BlackSpace;
        // RightArm = 0;
        };

    if (Health > Man_MaxHealth)
        Health = Man_MaxHealth;

    //if (Position = Fixed_Position)
    //    vX *= 0.1;
    };

void ManType :: VillagerMind (ManType* Man, CamType* Camera, AllImageType AllImage)
    {
    PointType Mouse = {txMouseX(), txMouseY()};

    if (Health > 0)
    {
    int null = 0;
    int a = 0;
    int three = 3;
    int four = 4;
    int one = 1;
    int two = 2;

    if (Kind == MT_Seller)
    {
    /* Inventory.Axe = rand() % 3;
       Inventory.Knife = rand() % 3;
       Inventory.Bow = rand() % 3;  */

    int Side = 1;
    if (Point.x > Man->Point.x)
        Side = 0;
    if (Point.x < Man->Point.x)
        Side = 1;

    if (Man->Point.x - Point.x > 100 &&
            Man->Point.x - Point.x < 200)
            vX = Inventory.Rope;

    if (Man->Point.x - Point.x < 100 &&
            Man->Point.x - Point.x > 0)
            {
            vX = 0;
            };

    if (Point.x - Man->Point.x > 100 &&
            Point.x - Man->Point.x < 200)
            vX = -Inventory.Rope;

    if (Point.x - Man->Point.x < 100 &&
            Point.x - Man->Point.x > 0)
            {
            vX = 0;
            };

    if (fabs (Man->Point.x - Point.x) <= 200)
        {

        PointType TradePoint = {Point.x + 50 - Camera->x, Point.y + 84 - Camera->y};

        if (Inventory.Wood == 0)
            {
            if (ModuleDistance (TradePoint, Mouse, 50) == true &&
                GetAsyncKeyState (VK_LBUTTON))
            Inventory.Wood = 1;
            };

        if (Inventory.Wood == 1)
            {
            DrawTransparentImage (&AllImage.CommonSlot, Point.x - 20, Point.y - 60, &null, &null, Camera);

            DrawTransparentImage (&AllImage.CommonSlot, Point.x + 50, Point.y - 60, &null, &null, Camera);

            DrawTransparentImage (&AllImage.CommonSlot, Point.x + 120, Point.y - 60, &null, &null, Camera);

            PointType Slot1 = {Point.x + 5 - Camera->x, Point.y - 35 - Camera->y};
            PointType Slot2 = {Point.x + 75 - Camera->x, Point.y - 35 - Camera->y};
            PointType Slot3 = {Point.x + 145 - Camera->x, Point.y - 35 - Camera->y};

            // slot1
            if (Inventory.Axe == 0)
                {
                DrawTransparentImage (&AllImage.Coin, Point.x - 10, Point.y - 53, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Point.x + 10, Point.y - 33, &null, &null, Camera);
                // Text (x + 8, y - 16, 20, one, "");

                if (ModuleDistance (Slot1, Mouse, 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Wood >= 1)
                    {
                    Man->Inventory.Wood -= 1;
                    Man->Inventory.Coin += 1;
                    Inventory.Wood = 0;
                    };
                };

            if (Inventory.Axe == 1)
                {
                DrawTransparentImage (&AllImage.Axe, Point.x - 20, Point.y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Point.x + 10, Point.y - 33, &null, &two, Camera);
                // Text (x + 8, y - 16, 20, one, "");
                if (ModuleDistance (Slot1, Mouse, 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Stone >= 1)
                    {
                    Man->Inventory.Stone -= 1;
                    Man->Inventory.Axe += 1;
                    Inventory.Wood = 0;
                    };
                };

            if (Inventory.Axe == 2)
                {
                DrawTransparentImage (&AllImage.Apple, Point.x - 20, Point.y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Point.x + 10, Point.y - 33, &null, &one, Camera);
                // Text (x + 8, y - 16, 20, one, "");
                if (ModuleDistance (Slot1, Mouse, 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Coin >= 1)
                    {
                    Man->Inventory.Coin -= 1;
                    Man->Inventory.Apple += 1;
                    Inventory.Wood = 0;
                    };
                };

            // slot2
            if (Inventory.Knife == 0)
                {
                DrawTransparentImage (&AllImage.Knife, Point.x + 50, Point.y - 40, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Point.x + 80, Point.y - 33, &null, &null, Camera);

                if (ModuleDistance (Slot2, Mouse, 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Wood >= 1)
                    {
                    Man->Inventory.Wood -= 1;
                    Man->Inventory.Knife += 1;
                    Inventory.Wood = 0;
                    };
                };

            if (Inventory.Knife == 1)
                {
                DrawTransparentImage (&AllImage.Stone, Point.x + 50, Point.y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Point.x + 80, Point.y - 33, &null, &one, Camera);

                if (ModuleDistance (Slot2, Mouse, 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Coin >= 1)
                    {
                    Man->Inventory.Coin -= 1;
                    Man->Inventory.Stone += 1;
                    Inventory.Wood = 0;
                    };
                };

            if (Inventory.Knife == 2)
                {
                DrawTransparentImage (&AllImage.Arrow, Point.x + 50, Point.y - 46, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Point.x + 80, Point.y - 33, &null, &two, Camera);

                if (ModuleDistance (Slot2, Mouse, 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Stone >= 1)
                    {
                    Man->Inventory.Stone -= 1;
                    Man->Inventory.Arrow += 1;
                    Inventory.Wood = 0;
                    };
                };

            // slot3
            if (Inventory.Bow == 0)
                {
                DrawTransparentImage (&AllImage.Bow, Point.x + 120, Point.y - 70, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Point.x + 150, Point.y - 33, &null, &one, Camera);

                if (ModuleDistance (Slot3, Mouse, 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Coin >= 1)
                    {
                    Man->Inventory.Coin -= 1;
                    Man->Inventory.Bow += 1;
                    Inventory.Wood = 0;
                    };
                };

            if (Inventory.Bow == 1)
                {
                DrawTransparentImage (&AllImage.Apple, Point.x + 120, Point.y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Point.x + 150, Point.y - 33, &null, &two, Camera);

                if (ModuleDistance (Slot3, Mouse, 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Stone >= 1)
                    {
                    Man->Inventory.Stone -= 1;
                    Man->Inventory.Apple += 1;
                    Inventory.Wood = 0;
                    };
                };

            if (Inventory.Bow == 2)
                {
                DrawTransparentImage (&AllImage.Coin, Point.x + 130, Point.y - 53, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Point.x + 150, Point.y - 33, &null, &null, Camera);

                if (ModuleDistance (Slot3, Mouse, 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Wood >= 1)
                    {
                    Man->Inventory.Wood -= 1;
                    Man->Inventory.Coin += 1;
                    Inventory.Wood = 0;
                    };
                };
            };

        // $i printf ("number = %d \n", Inventory.Wood); $d
        }
        else
            Inventory.Wood = 0;
    };

    /* if (Inventory.Knife == 2)
        {
        if (Side == 1)
        DrawTransparentImage (&AllImage.Gun, x + 74, y + 93, &null, &null, Camera);
        if (Side == 0)
        DrawTransparentImage (&AllImage.Gun, x + 44, y + 93, &one, &null, Camera);
        Position += 1;
        if (Position >= 10)
            {
            int x = x + 74;
            int vX = 0;
            if (x > Man->Point.x)
                vX = -10;
            if (x < Man->Point.x)
                vX = 10;
            x += vX;
            int null = 0;
            int one = 1;
            if (vX > 0)
                DrawTransparentImage (&AllImage.Gun, x, y + 88, &null, &one, Camera);
            if (vX < 0)
                DrawTransparentImage (&AllImage.Gun, x, y + 88, &one, &one, Camera);
            if (ModuleDistance (Man->Point.x + 47, Man->Point.y + 84, x,  y + 88, 30) == true)
                {
                Position = 0;
                };
            };
        }; */

    // Fighting:

    PointType FightPoint = {Point.x + 50 - Camera->x, Point.y + 84 - Camera->y};
    // PointType Mouse = {txMouseX(), txMouseY()};

    if (ModuleDistance (FightPoint, Mouse, 50) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
        Man->Inventory.MainNumber == IT_Axe &&
        Man->Inventory.Axe >= 0 &&
        Man->ArmSpeed >= 10)
        {
        Health -= 2;
        vY = -15;
        if (Point.x > Man->Point.x)
            vX = 50;
        if (Point.x < Man->Point.x)
            vX = -50;
        // Animation.xFrame += 1;
        // txCircle (Man->Point.x - Camera->x, Man->Point.y - Camera->y, 50);
        Man->ArmSpeed = 0;
        Time = 1;
        };
    // else
    //     Animation.xFrame = 0;

    if (Man->xWeapon > 0)
        Man->xWeapon -= 1;

    if (Man->xWeapon < 0)
        Man->xWeapon = 0;
    };

    // Bow

    if (fabs (Man->ArrowX - Point.x) <= 200 &&
        fabs (Man->ArrowY - Point.y) <= 80 &&
        Health > 0 &&
        Man->ArrowVX != 0 &&
        Man->Inventory.Arrow > 0)
        {
        vY = -15;
        if (Point.x > Man->Point.x)
            vX = 50;
        if (Point.x < Man->Point.x)
            vX = -50;
        Health -= 5;
        Man->Inventory.Arrow -= 1;
        Man->ArrowVX = 0;
        Man->ArrowVY = 0;
        Man->ArrowX  = Man->Point.x;
        Man->ArrowY  = Man->Point.y;
        };

    // House
    if (Man->Position == House_Position)
        Position = OutSide_Position;

    if (Man->Position != House_Position &&
        Position == OutSide_Position)
        Position = Normal_Position;

    // Bear
    if (Kind == MT_Bear &&
        Health > 0)
        {
        if (Man->Point.x - Point.x > 50 &&
            Man->Point.x - Point.x < 500)
            vX = Inventory.Rope;

        if (Man->Point.x - Point.x < 50 &&
            Man->Point.x - Point.x > 0)
            {
            vX = 0;
            };

        if (Point.x - Man->Point.x > 50 &&
            Point.x - Man->Point.x < 500)
            vX = -Inventory.Rope;

        if (Point.x - Man->Point.x < 50 &&
            Point.x - Man->Point.x > 0)
            {
            vX = 0;
            };

        // Fighting
        ArmSpeed += 1;

        if (ArmSpeed >= 10 &&
            vX == 0 &&
            fabs (Man->Point.x + Man->SizeX/2 - Point.x - SizeX/2) <= SizeX/2 + Man->SizeX/2&&
            fabs (Man->Point.y + Man->SizeY/2 - Point.y - SizeY/2) <= SizeY/2 + Man->SizeY/2)
            {
            Man->Health -= 1;
            Man->vY = -15;
            if (Man->Point.x > Point.x)
                Man->vX = 50;
            if (Man->Point.x < Point.x)
                Man->vX = -50;
            // Man->Animation.xFrame += 1;
            // txCircle (Man->Point.x - Camera->x, Man->Point.y - Camera->y, 50);
            ArmSpeed = 0;
            };

        };

    // Bandit
    if (Kind == MT_Bandit &&
        Health > 0)
        {
        if (Man->Point.x > Point.x)
            vX = 10;

        if (Man->Point.x < Point.x)
            vX = -10;

        /* if (Animation.yFrame == 0 &&
            vX == 0)
            Animation.yFrame = 2;
        if (Animation.yFrame == 1 &&
            vX == 0)
            Animation.yFrame = 3; */

        if (fabs (Man->Point.x - Point.x) <= 200)
            vX = 0;

        ArmSpeed += 1;

        ArrowX += ArrowVX;
        ArrowY += ArrowVY;

        int null = 0;

        DrawTransparentImage (&AllImage.Bullet, -11 + 61*Animation.yFrame + ArrowX,
                              ArrowY + 60, &null, &Animation.yFrame, Camera);

        if (ArmSpeed >= 80)
            {
            // ArrowVY = 5;
            ArrowX = Point.x;
            ArrowY = Point.y;

            if (Man->Point.x > Point.x)
            ArrowVX =  100;
            if (Man->Point.x < Point.x)
            ArrowVX = -100;

            // xWeapon = 1;
            ArmSpeed = 0;
            };

        if (fabs (ArrowX - Man->Point.x) <= 200 &&
            fabs (ArrowY - Man->Point.y) <= 80)
            {
            Man->Health -= 1;
            Man->vY = -15;
            if (Point.x > Man->Point.x)
                Man->vX = -50;
            if (Point.x < Man->Point.x)
                Man->vX = 50;
            };
        };

    // Boat
    if (Kind == MT_Boat &&
        Position != Water_Position)
        {
        };

    if (Health > 0 &&
        Kind == MT_Boat &&
        Man->Health > 0)
        {
        Point.y = 687;

        PointType BoatPoint = {Point.x + 130 - Camera->x, Point.y + 15 - Camera->y};

        if (ModuleDistance (BoatPoint, Mouse, 100) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            {
            Man->Position = Boat_Position;
            };
        };

    if (Man->Position == Boat_Position &&
        Kind == MT_Boat)
        {
        Man->Point.x = Point.x + 80;
        Man->Point.y = Point.y - 135;
        Man->vX = 0;
        Man->vY = 0;

        if (GetAsyncKeyState (VK_LEFT))
            vX = -20;

        if (GetAsyncKeyState (VK_RIGHT) &&
            Point.x <= -300)
            vX = 20;

        if (GetAsyncKeyState (VK_UP))
            Man->Position = Normal_Position;
        };

    // Fish
    if (Kind == MT_Fish &&
        Health > 0)
        {
        if (Point.y < 720)
            Point.y = 720;

        if (Man->Inventory.MainNumber == 8 &&
            Man->Inventory.MainSlot > 0)
            {
            if (Man->Point.x + 55 > Point.x)
                vX = 4;
            if (Man->Point.x + 55 < Point.x)
                vX = -4;

            if (Point.y >= 720)
                vY = -2;
            else
                vY = 0;

            PointType Fish = {Point.x+25, Point.y+10};
            PointType FishingMan = {Man->Point.x + 55, Man->Point.y + 85};

            if (ModuleDistance (FishingMan, Fish, 100) == true)
                {
                Health = 0;
                Man->Inventory.Fish += 1;
                };
            }
        else
            vX = 4*(rand()%3 - 1);

        aY = 0;

        if (Man->Days >= 20 &&
            Man->Days < 30)
            vX = 4*(rand()%3 - 1);
        };

    if (Health <= 5 &&
        Health > 0)
        {
        Health = 0;
        if (Inventory.Stone == MT_Bear)
            Man->Inventory.Fish += 1;

        if (Inventory.Stone == MT_Wolf)
            Man->Inventory.Coin += 1;

        if (Inventory.Stone == MT_Spider)
            Man->Inventory.Rope += 1;
        };

    if (Man->Days % 3 == 0 &&
        Man->Time == 0 &&
        Kind == MT_Bear)
        {
        Health = 20;
        Point.x = rand() % 11400 * World_Size;
        Point.y = -500;
        };

    if (Man->Days % 3 == 0 &&
        Man->Time == 0 &&
        Kind == MT_Seller)
        {
        Health = 20;
        Point.x = rand() % 11400 * World_Size;
        Point.y = -500;
        };

    if (Man->Days % 3 == 0 &&
        Man->Time == 0 &&
        Kind == MT_Fish)
        {
        Health = 20;
        Point.x = -rand() % 700 - 100;
        Point.y = 750 + rand() % 100;
        };

    // Ghost
    if (Inventory.Stone == MT_Ghost)
        {
        ArmSpeed += 1;

        ArrowX += ArrowVX;
        ArrowY += ArrowVY;

        if (fabs (Point.x + SizeX/2 - (Man->Point.x + Man->SizeX/2)) <= SizeX/2)
        {

        int null = 0;

        if (ArmSpeed >= 10)
            {
            DrawTransparentImage (&AllImage.Bullet, ArrowX,
                              ArrowY, &null, &null, Camera);

            ArrowVX = 0;
            ArrowVY = 10;

            // xWeapon = 1;
            ArmSpeed = 0;
            };

        if (fabs (ArrowX - Man->Point.x + Man->SizeX/2) <= 50 &&
            fabs (ArrowY - Man->Point.y + Man->SizeY/2) <= 20)
            {
            Man->Health -= 2;
            // Man->vY = -15;
            if (Point.x > Man->Point.x)
                Man->vX = -50;
            if (Point.x < Man->Point.x)
                Man->vX = 50;

            ArrowVX = 0;
            ArrowVY = 0;

            ArrowX = Point.x + SizeX/2;
            ArrowY = Point.y + SizeY/2;
            };
        };
        };
    };

void ManType :: ManTemperature ()
    {
    if (Temperature < 0)
        {
        Temperature = 0;
        };

    if (Temperature > Man_MaxTemperature)
        {
        Temperature = Man_MaxTemperature;
        };

    if (Temperature <= Man_ColdTemp1)
        Health -= 0.01;

    if (Temperature <= Man_ColdTemp2)
        Health -= 0.02;

    if (Temperature <= Man_ColdTemp3)
        Health -= 0.04;

    if (Temperature >= Man_HotTemp1)
        Health -= 0.01;

    if (Temperature >= Man_HotTemp2)
        Health -= 0.02;

    if (Temperature >= Man_HotTemp3)
        Health -= 0.04;
    };

void ManType :: ControlMan (MouseType Mouse, int* t)
    {
    if (GetAsyncKeyState (VK_HOME))
        {
        Point.y = -1000;
        Point.x = 1000;
        };

    if (GetAsyncKeyState (VK_END))
        {
        Point.y = -1000;
        Point.x = 11400*World_Size - 1000;
        };

    if (GetAsyncKeyState (VK_RIGHT))
        {
        vX = Man_FastSpeed;
        Side = Man_RightSide;
        };

    if (GetAsyncKeyState (VK_LEFT))
        {
        vX = -Man_FastSpeed;
        Side = Man_LeftSide;
        };

    if (vX > 0)
        {
        if (GetAsyncKeyState (VK_SHIFT))
            {
            vX = Man_SlowSpeed;
            };
        };

    if (vX < 0)
        {
        if (GetAsyncKeyState (VK_SHIFT))
            {
            vX = -Man_SlowSpeed;
            };
        };

    if (GetAsyncKeyState (VK_LBUTTON) &&
        Inventory.MainNumber == 2 &&
        Inventory.MainSlot > 0 &&
        xWeapon <= 40)
        xWeapon += 20;
    else
        if (Inventory.MainNumber == 2 &&
            Inventory.MainSlot > 0)
        {
        xWeapon -= 20;
        // ArmSpeed = 100;
        };

    if (GetAsyncKeyState (VK_LBUTTON) &&
        Inventory.MainNumber == 0 &&
        Inventory.MainSlot > 0 &&
        xWeapon <= 3)
        {
        xWeapon += 1;
        ArmSpeed = 0;
        }
    else
        if (Inventory.MainNumber == 0 &&
            Inventory.MainSlot > 0)
        {
        xWeapon -= 1;
        ArmSpeed = 10;
        };


    if (xWeapon < 0)
        xWeapon = 0;

    ArmSpeed += 1;

    // Food

    if (GetAsyncKeyState (VK_LBUTTON) &&
        Inventory.MainNumber == 3 &&
        Inventory.MainSlot > 0 &&
        Health < 20)
        {
        Health += 1;
        Inventory.Apple -= 1;
        };

    if (GetAsyncKeyState (VK_LBUTTON) &&
        Inventory.MainNumber == 9 &&
        Inventory.MainSlot > 0 &&
        Health < 20)
        {
        Health += 1;
        Inventory.Fish -= 1;
        };

    if (GetAsyncKeyState (VK_LBUTTON) &&
        Inventory.MainNumber == 10 &&
        Inventory.MainSlot > 0 &&
        Health < 20)
        {
        Health += 5;
        Temperature += 5;
        Inventory.CookedFish -= 1;
        };

    // Bow
    ArrowX += ArrowVX;
    ArrowY += ArrowVY;

    if (Inventory.MainNumber == 5 &&
        Inventory.MainSlot > 0)
            {
            if (ArrowY >= 700)
                {
                Inventory.Arrow -= 1;
                ArrowVX = 0;
                ArrowVY = 0;
                ArrowX  = Point.x;
                ArrowY  = Point.y;
                };

            if (Animation.yFrame == 1 &&
                GetAsyncKeyState (VK_LBUTTON) &&
                Inventory.Arrow > 0)
                {
                ArrowVX = 100;
                ArrowVY = 2;
                };

            if (Animation.yFrame == 0 &&
                GetAsyncKeyState (VK_LBUTTON) &&
                Inventory.Arrow > 0)
                {
                ArrowVX = -100;
                ArrowVY = 8;
                };

            if (ArrowVX == 0)
                {
                xWeapon = 0;
                ArrowX  = Point.x;
                ArrowY  = Point.y;
                }
            else
                xWeapon = 1;
            };

    // printf ("x = %lf, y = %lf \n", x, y);
    };

void ManType :: Physic ()
    {
    if (Point.x < 1000 &&
        vX < 0)
        vX = 0;

    if (Point.x > 11400*World_Size - 730 &&
        vX > 0)
        vX = 0;

    Point.x += vX;
    Point.y += vY;

    vX += aX;
    vY += aY;

    vX = vX*0.5;

    aY = Man_aY;

    if (vY > 50)
        vY = 50;

    if (vY < -50)
        vY = -50;

    if (vX > 50)
        vX = 50;

    if (vX < -50)
        vX = -50;

    // Time;
    Time += 1;

    if (Time >= 1000)
        Time = 0;

    if (Time == 900)
        Days += 1;

    if (Days >= 40)
        Days = 0;

    // Water
    if (Point.y >= 620)
        Position = Water_Position;
    else
        if (Position == Water_Position)
            Position = Normal_Position;

    if (Position == Water_Position &&
        Kind != MT_Boat &&
        Kind != MT_Fish)
        {
        vY = -3;
        Health -= 0.01;
        };

    if (Kind == MT_Boat)
        {
        Point.y = 687;
        };
    // printf ("Days = %d \n", Days);

    if (Kind != MT_Boat &&
        Kind != 0 &&
        Point.x >= -160 &&
        Point.x <= 190*11400*World_Size)
        {
        if (Point.y >= 700 - GRGetExtentY(Animation.Picture->Picture)/Animation.Picture->yMaxAnimationNumber + Inventory.Arrow &&
            vY > 0)
            {
            // y = 500;
            vY = 0;
            };

        if (Point.y >= 700 - GRGetExtentY(Animation.Picture->Picture)/Animation.Picture->yMaxAnimationNumber + Inventory.Arrow)
            {
            Point.y = 700 - GRGetExtentY(Animation.Picture->Picture)/Animation.Picture->yMaxAnimationNumber + Inventory.Arrow;
            // vY = 0;
            };
        };

    if (Days >= 20 &&
        Days <  30)
        {
        if (Position == Water_Position)
            Temperature -= 1;
        };
    };



void ManType :: BlockInteraction (BlockType* Block, CamType* Camera, AllImageType AllImage)
    {
    int null = 0;
    int two = 2;
    int three = 3;
    int four = 4;

    // FallingTree
    if (Block->Number == BT_FallingTree)
        {
        if (fabs (Block->Point.x + Block->SizeX - Point.x) <= Block->SizeX + SizeX + 200 &&
            BlockCheckClick (Block, Camera) == true &&
            Block->Health > 0)
            {
            Inventory.Wood += 2;
            Block->Health = 0;
            if (HelpSystem.Number == HelpFallingTree)
                HelpSystem.Number = HelpFindStone;
            };
        };

    if (Block->Number == BT_SmallStone)
        {
        if (fabs (Block->Point.x + Block->SizeX - Point.x) <= Block->SizeX + SizeX + 200 &&
            BlockCheckClick (Block, Camera) == true &&
            Block->Health > 0)
            {
            Inventory.Stone += 1;
            Block->Health = 0;
            if (HelpSystem.Number == HelpFindStone)
                HelpSystem.Number = HelpCrafting;
            };
        };

    // Rock
    if (Block->Number == BT_Rock)
    {
    if (Inventory.MainNumber == IT_Axe &&
        Inventory.Axe > 0 &&
        fabs (Block->Point.x + Block->SizeX - Point.x) <= Block->SizeX + SizeX + 200 &&
        BlockCheckClick (Block, Camera) == true &&
        ArmSpeed >= 10)
            {
            Block->Health -= 10;
            Block->Animation.yFrame = 1;
            ArmSpeed = 0;
            }
        else
            Block->Animation.yFrame = 0;

        if (Block->Health <= 20 &&
            Block->Health > 0)
            {
            Inventory.Stone += 3;
            Block->Health = 0;
            };
    };

    // BonFire
    if (Block->Number == BT_BonFire)
        {
        if (Block->Health <= 3)
        {
        Block->Animation.yFrame = 0;
        if (Temperature < 10 &&
            fabs (Block->Point.x - Point.x) <= 200)
        Temperature += 0.025;
        };

        if (Block->Health > 3 &&
            Block->Health <= 6)
            {
        Block->Animation.yFrame = 1;
        if (Temperature < 32 &&
            fabs (Block->Point.x - Point.x) <= 200)
        Temperature += 0.05;
        };

        if (Block->Health > 6 &&
            fabs (Block->Point.x - Point.x) <= 200)
        {
        Block->Animation.yFrame = 2;
        if (Temperature < 36.6)
        Temperature += 0.1;
        };

        if (Block->Health >= 1)
            {
            if (Days >= 0 &&
                Days < 10)
                Block->Health -= 0.0025;

            if (Days >= 10 &&
                Days < 20)
                Block->Health -= 0.025;

            if (Days >= 20 &&
                Days < 30)
                Block->Health -= 0.0025;

            if (Days >= 30 &&
                Days < 40)
                Block->Health -= 0.0012;
            };

        if (Inventory.MainNumber == IT_Wood &&
            Inventory.Wood > 0 &&
            // ModuleDistance (Block->x + 30 - Camera->x, Block->y + 30 - Camera->y, txMouseX(), txMouseY(), 100) == true &&
            BlockCheckClick (Block, Camera) == true &&
            Block->Health <= 6 &&
            Block->Health > 0)
            {
            Inventory.Wood -= 1;
            Block->Health += 3;
            if (HelpSystem.Number == HelpAddWood)
                HelpSystem.Number = HelpWarmBonfire;
            };

        if (Inventory.MainNumber == IT_Fish &&
            Inventory.Fish > 0 &&
            BlockCheckClick (Block, Camera) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Block->Health >= 3)
            {
            Inventory.Fish -= 1;
            Inventory.CookedFish += 1;
            Block->Health -= 3;
            };

        if (fabs (Point.x - Block->Point.x) <= 200)
            {
            if (HelpSystem.Number == HelpFindBonfire)
                HelpSystem.Number = HelpAddWood;
            };
        };

    // Year
    if (Block->Number == BT_Dirt)
    {
    if (Days >= 0 &&
        Days < 10)
            Block->Animation.yFrame = 0;

    if (Days >= 10 &&
        Days < 20)
            Block->Animation.yFrame = 1;

    if (Days >= 20 &&
        Days < 30)
            Block->Animation.yFrame = 2;

    if (Days >= 30 &&
        Days < 40)
            Block->Animation.yFrame = 3;
    };

    if (Block->Number == BT_Tree)
    {
    if (Days >= 0 &&
        Days < 10)
            Block->Animation.yFrame = 0;

    if (Days >= 10 &&
        Days < 20)
            Block->Animation.yFrame = 1;

    if (Days >= 20 &&
        Days < 30)
            Block->Animation.yFrame = 2;

    if (Days >= 30 &&
        Days < 40)
            Block->Animation.yFrame = 3;
    };

    if (Block->Number == BT_Snow)
        {
        if (Days >= 10 &&
            Days < 20)
            Block->Animation.yFrame = 0;
        else
            Block->Animation.yFrame = 1;
        };

    // House
    /* if (fabs (Block->Point.x + 150 - Point.x) <= Man->SizeX + 40 &&
        Block->Number == BT_House &&
        Position != House_Position &&
        Kind == 0)
        {
        DrawTransparentImage (&AllImage.Pause, Block->Point.x + 180, Block->Point.y + 100, &null, &two, Camera);
        if (ModuleDistance (Block->Point.x + 180 - Camera->x, Block->Point.y + 100 - Camera->y ,
                            txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            Position = House_Position;
        };

    if (Block->Number == BT_House &&
        Position == House_Position)
        {
        Block->Animation.yFrame = 1;

        DrawTransparentImage (&AllImage.Pause, Block->x + 420, Block->y + 120, &null, &three, Camera);
        if (ModuleDistance (Block->x + 420 - Camera->x, Block->y + 120 - Camera->y ,
                            txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            Position = Normal_Position;

        if (x >= Block->x + 460 &&
            vX > 0)
            vX = 0;

        if (x <= Block->x + 80 &&
            vX < 0)
            vX = 0;
        };

    if (Block->Number == BT_House &&
        Position == OutSide_Position)
        {
        if (x >= Block->x &&
            x <= Block->x + 500)
        x = Block->x - 200;
        };

    if (Block->Number == BT_House &&
        Position != House_Position)
        Block->Animation.yFrame = 0; */

    if (Block->Number == BT_Fire)
        {
        if (Time >= 500)
            Block->Animation.yFrame = 1;
        else
            Block->Animation.yFrame = 0;
            };
    if (Block->Number == BT_Air)
        {
        if (Time >= 500)
            Block->Animation.yFrame = 1;
        else
            Block->Animation.yFrame = 0;
            };

    if (Point.y >= 10000)
        Health -= 1;

    /* if (Block->Number == BT_Fire)
        {
        if (Collision (Block, Man) == true)
            {
            Camera->Timer = GetTickCount () + 30000;
            };
        }; */

    // Tree
    if (Block->Number == BT_Tree)
        {
        /*if (Time >= 500)
            Block->Animation.yFrame = 1;
        else
            Block->Animation.yFrame = 0; */

        if (Inventory.MainNumber == IT_Axe &&
            Inventory.Axe > 0 &&            fabs (Block->Point.x + Block->SizeX - Point.x) <= Block->SizeX + SizeX + 100 &&
            BlockCheckClick (Block, Camera) == true &&
            ArmSpeed >= 10 &&
            Block->Health > 2)
            {
            ArmSpeed = 0;
            Block->Health -= 10;
            Block->Animation.yFrame += 4;
            };

        if (Block->Health <= 12 &&
            Block->Health > 0)
            {
            Inventory.Wood += 2;
            if (Days >= 30 &&
                Days < 40)
                Inventory.Apple += 1;
            if (HelpSystem.Number == HelpDestroyTree)
                HelpSystem.Number = HelpFindBonfire;
            Block->Health = -88;
            };

        if (Block->Health < 0 &&
            Block->Health >= -88)
            {
            Block->Health += 0.5;
            // Block->Animation.yFrame = 8;
            };

        if (Block->Health == 0)
            Block->Health = 100;
        };

    };

void ManType :: BlockCollision (BlockType* Block, CamType* Camera, AllImageType AllImage)
    {
    if (Block->Number == BT_Coin)
        return;

    if (Block->Health < 1)
        return;

    if (Block->Number != BT_Rock &&
        Block->Number != BT_FallingTree &&
        Block->Number != BT_Dirt)
        return;

    // Physic

    // CollisionDetection

    if (fabs (Block->Point.x + Block->SizeX/2 - Point.x - SizeX/2) <= Block->SizeX/2 &&
        InBorders (0, Block->Point.y + Block->SizeY - Point.y, Block->SizeY + this->SizeY) == true)
            {
            // CollisionResponse

            if (GetAsyncKeyState (VK_UP) &&
                Kind == MT_Main)
                {
                vY = -Man_JumpSpeed;
                };

            if (vY > 0)
                {
                vY = 0;
                Point.y = Block->Point.y - SizeY;
                };
            };

    // Walls
    if (Block->Health  >= 1)
            {
            /* if (fabs (Block->Point.x + Block->SizeX - Point.x) <= Block->SizeX + this->SizeY &&
                Block->Point.y + Block->SizeY > Point.y &&
                Block->Point.y < Point.y + SizeY)
                {
                if (Block->Point.x <= Point.x + SizeX &&
                    vX > 0)
                        vX = 0;

                if (Block->Point.x + Block->SizeX >= Point.x &&
                    vX < 0)
                        vX = 0;
                }; */
            };
    };

//-----------------------------------------------------------------------------

void DrawLevelPeople (ManType Villagers[], CamType* Camera, AllImageType AllImage)
    {
    int i = 0;

    while (Villagers[i].Point.x != -1 && Villagers[i].Point.y != -1)
        {
        Villagers [i].DrawMan (Camera, AllImage);

        i += 1;
        };
    };

void CallPeoplePhysic (ManType Villagers[], CamType* Camera, AllImageType AllImage, BlockType ManyBlocks [], ManType* Man)
    {
    /* int i = 0;
    int b = 0;
    AllImageType AllImage1 = AllImage;
    while (ManyBlocks[i].x != -1 && ManyBlocks[i].y != -1)
        {
        Villagers[i].BlockCollision (&ManyBlocks[b], Camera, AllImage);
        Villagers[i].VillagerMind (Man, Camera, AllImage);
        Villagers[i].Physic ();
        i += 1;
        if (Villagers[i].x == -1)
            {
            b += 1;
            i = 0;
            };
        }; */

    int i = 0;

    while (Villagers[i].Point.x != -1 && Villagers[i].Point.y != -1)
        {
        Villagers[i].VillagerMind (Man, Camera, AllImage);
        Villagers[i].Physic ();

        i += 1;
        };
    };
