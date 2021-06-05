#include "ManType.h"

ManType :: ManType (PointType _Point, double _Health, AnimationType _Animation,
                    PointType _Speed, PointType _Acceleration, double _Energy,
                    int _Side, int _Position, double _Temperature,
                    int _NumberCoin, int _xWeapon, int _ArmSpeed, const char _Name [50], int _Kind, InvType _Inventory,
                    int _Time, int _Days, double _ArrowX, double _ArrowY, int _ArrowVX, int _ArroeVY, HelpType _HelpSystem) :
    BaseType (_Point, _Health, _Animation),
    Speed (_Speed),
    Acceleration (_Acceleration),
    Energy (_Energy),                                                  // & - РђРјРїРµСЂСЃР°РЅРґ (Р±РµСЂРµС‚ Р°РґСЂРµСЃ РїРµСЂРµРјРµРЅРЅРѕР№)
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
    ArroeVY (_ArroeVY),
    HelpSystem (_HelpSystem)
    {
    /* for (int i = 0; i < NameSize; i += 1)
        {
        Name [i] = _Name [i];
        }; */

    // strcpy (Name, _Name);

    StrCpy (Name, _Name);
    };

void CreateVillagers (ManType Villagers [])
    {
    // int i = 0;

    int BearNumber = rand() % 4;

    for (int i = 0; i < Men_Number; i ++)
        {
        if (i < BearNumber)
            {
            Villagers[i].Health = 20;
            Villagers[i].Kind = MT_Bear;
            Villagers[i].Inventory.Stone = MT_Bear;
            Villagers[i].Inventory.Rope = 10;
            Villagers[i].Point.x = rand() % 11400*World_Size;
            Villagers[i].Point.y = -500;
            Villagers[i].Animation.Picture = &GlobalAllImage.Bear;
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
            Villagers[i].Animation.Picture = &GlobalAllImage.Wolf;
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
            Villagers[i].Animation.Picture = &GlobalAllImage.Spider;
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
            Villagers[i].Animation.Picture = &GlobalAllImage.Villager;
            };

        if (i >= 13 &&
            i < 20)
            {
            Villagers[i].Health = 20;
            Villagers[i].Kind = MT_Fish;
            // Villagers[i].Inventory.Rope = 10;
            Villagers[i].Point.x = -rand() % 700 - 500;
            Villagers[i].Point.y = 750 + rand() % 100;
            Villagers[i].Animation.Picture = &GlobalAllImage.Fish;
            };

        if (i >= 20 &&
            i < 22)
            {
            Villagers[i].Health = 2000;
            Villagers[i].Kind = MT_Bear;
            Villagers[i].Inventory.Rope = 10;
            Villagers[i].Inventory.Stone = MT_Ghost;
            Villagers[i].Inventory.Arrow = 0;
            Villagers[i].Point.x = rand() % 100;
            Villagers[i].Inventory.Arrow = -200;
            Villagers[i].Point.y = 400;
            Villagers[i].Animation.Picture = &GlobalAllImage.Ghost;
            };

        if (i >= 22)
            {
            Villagers[i].Health = 0;
            };

        // x += 1;

        // i += 1;
        };
    };

void DrawSlot (int Block, int x, int y, const ImageType& Picture, int TextX, int TextY)
    {
    int null = 0;
    int one = 1;

    PointType TextPoint = {TextX + 38, TextY + 44};

    if (Block > 0)
        {
        DrawTransparentImage (Picture, x, y, &null, &one);

        Text (TextPoint, 20, Block, "");
        };
    };

void ManType :: Crafting ()
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
        DrawTransparentImage (GlobalAllImage.CommonSlot, 15, 300, &null, &null);

        DrawTransparentImage (GlobalAllImage.CraftImage, 10, 295, &null, &null);

        if (ModuleDistance (CraftPoint, Mouse, 50) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            {
            Inventory.CraftNumber = 1;
            Inventory.CraftControlSpeed = 1;
            };
        };

    if (Inventory.CraftNumber > 0)
    {
    DrawTransparentImage (GlobalAllImage.CommonSlot, 15, 300, &null, &null);

    DrawTransparentImage (GlobalAllImage.Plus, 75, 304, &null, &null);

    DrawTransparentImage (GlobalAllImage.CommonSlot, 127, 300, &null, &null);

    DrawTransparentImage (GlobalAllImage.Plus, 187, 304, &null, &one);

    DrawTransparentImage (GlobalAllImage.Slot, 239, 300, &null, &null);

    DrawTransparentImage (GlobalAllImage.Pause, 309, 300, &null, &four);

    DrawTransparentImage (GlobalAllImage.Pause, 309, 370, &null, &five);

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
        DrawSlot (2, 15, 230, GlobalAllImage.Wood, 15, 230);

        DrawTransparentImage (GlobalAllImage.Stone, 127, 300, &null, &one);

        DrawTransparentImage (GlobalAllImage.Axe, 240, 292, &null, &one);

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
        DrawTransparentImage (GlobalAllImage.Wood, 127, 300, &null, &one);

        DrawTransparentImage (GlobalAllImage.Stone, 15, 300, &null, &one);

        DrawTransparentImage (GlobalAllImage.Knife, 240, 312, &null, &one);

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
        DrawSlot (2, 15, 230, GlobalAllImage.Wood, 15, 230);

        DrawTransparentImage (GlobalAllImage.Rope, 127, 300, &null, &one);

        DrawTransparentImage (GlobalAllImage.FishingSmall, 240, 292, &null, &one);

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
        DrawSlot (2, 127, 230, GlobalAllImage.Wood, 127, 230);

        DrawSlot (2, 15, 230, GlobalAllImage.Rope, 15, 230);

        DrawTransparentImage (GlobalAllImage.Bow, 240, 292, &null, &one);

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
        DrawTransparentImage (GlobalAllImage.Wood, 127, 300, &null, &one);

        DrawTransparentImage (GlobalAllImage.Stone, 15, 300, &null, &one);

        DrawSlot (3, 233, 254, GlobalAllImage.Arrow, 240, 230);

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

void ManType :: DrawInventory (CamType* Camera)
    {
    // Inventory.MainNumber += 1;

    int null = 0;

    int one = 1;
    int two = 2;

    PointType Mouse = {txMouseX(), txMouseY()};

    /* PointType Axe   = {350, 515};
    PointType Bow   = {350, 585};
    PointType Arrow = {350, 655};

    PointType Wood  = {400, 515};
    PointType Stone = {400, 585};
    PointType Coin  = {400, 655};

    PointType Apple       = {450, 515};
    PointType Fish        = {450, 585};
    PointType CookedFish  = {450, 655}; */

    /* DrawTransparentImage (GlobalAllImage.CommonSlot, 325 + Inventory.MainSlot*50, 700, &null, &null);
    DrawTransparentImage (GlobalAllImage.CommonSlot, 375, 700, &null, &null);
    DrawTransparentImage (GlobalAllImage.CommonSlot, 425, 700, &null, &null);

    if (Inventory.SelectedType == ST_Weapon)
        {
        DrawTransparentImage (GlobalAllImage.CommonSlot, 325, 490, &null, &null);
        DrawTransparentImage (GlobalAllImage.CommonSlot, 325, 560, &null, &null);
        DrawTransparentImage (GlobalAllImage.CommonSlot, 325, 630, &null, &null);

        if (Inventory.MainNumber == IT_Axe)
            DrawTransparentImage (GlobalAllImage.Slot, 324, 489, &null, &null);

        if (Inventory.MainNumber == IT_Bow)
            DrawTransparentImage (GlobalAllImage.Slot, 324, 559, &null, &null);

        if (Inventory.MainNumber == IT_Arrow)
            DrawTransparentImage (GlobalAllImage.Slot, 324, 629, &null, &null);

        DrawSlot (Inventory.Axe, 325, 410, GlobalAllImage.Axe, 325, 420);

        DrawSlot (Inventory.Bow, 325, 480, GlobalAllImage.Bow, 325, 490);

        DrawSlot (Inventory.Arrow, 312, 579, GlobalAllImage.Arrow, 325, 560);

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
        DrawTransparentImage (GlobalAllImage.CommonSlot, 375, 490, &null, &null);
        DrawTransparentImage (GlobalAllImage.CommonSlot, 375, 560, &null, &null);
        DrawTransparentImage (GlobalAllImage.CommonSlot, 375, 630, &null, &null);

        if (Inventory.MainNumber == IT_Wood)
            DrawTransparentImage (GlobalAllImage.Slot, 374, 489, &null, &null);

        if (Inventory.MainNumber == IT_Stone)
            DrawTransparentImage (GlobalAllImage.Slot, 374, 559, &null, &null);

        if (Inventory.MainNumber == IT_Coin)
            DrawTransparentImage (GlobalAllImage.Slot, 374, 629, &null, &null);

        DrawSlot (Inventory.Wood,  375, 420, GlobalAllImage.Wood, 375, 420);

        DrawSlot (Inventory.Stone, 375, 490, GlobalAllImage.Stone, 375, 490);

        DrawSlot (Inventory.Coin,  385, 567, GlobalAllImage.Coin, 375, 560);

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
        DrawTransparentImage (GlobalAllImage.CommonSlot, 425, 490, &null, &null);
        DrawTransparentImage (GlobalAllImage.CommonSlot, 425, 560, &null, &null);
        DrawTransparentImage (GlobalAllImage.CommonSlot, 425, 630, &null, &null);

        if (Inventory.MainNumber == IT_Apple)
            DrawTransparentImage (GlobalAllImage.Slot, 424, 489, &null, &null);

        if (Inventory.MainNumber == IT_Fish)
            DrawTransparentImage (GlobalAllImage.Slot, 424, 559, &null, &null);

        if (Inventory.MainNumber == IT_CookedFish)
            DrawTransparentImage (GlobalAllImage.Slot, 424, 629, &null, &null);

        DrawSlot (Inventory.Apple,  425, 420, GlobalAllImage.Apple, 375, 420);

        DrawSlot (Inventory.Fish, 430, 497, GlobalAllImage.Fish, 375, 490);

        DrawSlot (Inventory.CookedFish,  430, 567, GlobalAllImage.CookedFish, 375, 560);

        if (ModuleDistance (Apple, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Apple;

        if (ModuleDistance (Fish, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_Fish;

        if (ModuleDistance (CookedFish, Mouse, 35) == true &&
            GetAsyncKeyState (VK_RBUTTON))
            Inventory.MainNumber = IT_CookedFish;
        };  */

    DrawTransparentImage (GlobalAllImage.Inventory, 375, 700, &null, &null);
    DrawTransparentImage (GlobalAllImage.Inventory, 825, 700, &null, &null);

    DrawTransparentImage (GlobalAllImage.Slot, 375 + Inventory.MainNumber*50, 700, &null, &null);

    DrawSlot (Inventory.Axe, 375, 690, GlobalAllImage.Axe, 375, 700);

    DrawSlot (Inventory.Wood, 425, 700, GlobalAllImage.Wood, 425, 700);

    DrawSlot (Inventory.Apple, 475, 700, GlobalAllImage.Apple, 475, 700);

    DrawSlot (Inventory.Knife, 520, 720, GlobalAllImage.Knife, 525, 700);

    DrawSlot (Inventory.Stone, 575, 700, GlobalAllImage.Stone, 575, 700);

    DrawSlot (Inventory.Bow, 630, 691, GlobalAllImage.Bow, 625, 700);

    DrawSlot (Inventory.Arrow, 662, 719, GlobalAllImage.Arrow, 675, 700);

    DrawSlot (Inventory.Fishing, 725, 700, GlobalAllImage.FishingSmall, 725, 700);

    DrawSlot (Inventory.Fish, 780, 713, GlobalAllImage.Fish, 775, 700);

    DrawSlot (Inventory.CookedFish, 825, 712, GlobalAllImage.CookedFish, 825, 700);

    DrawSlot (Inventory.Rope, 875, 700, GlobalAllImage.Rope, 875, 700);

    DrawSlot (Inventory.Gun, 925, 700, GlobalAllImage.Gun, 925, 700);

    int X = 1;

    if (Animation.yFrame == 0)
        X = -1;
    if (Animation.yFrame == 1)
        X = 1;

    // Controlling

    if (RectCheckClick (375, 700, 425, 750, &FixedCamera) == true)
        Inventory.MainNumber = 0;

    if (RectCheckClick (425, 700, 475, 750, &FixedCamera) == true)
        Inventory.MainNumber = 1;

    if (RectCheckClick (475, 700, 525, 750, &FixedCamera) == true)
        Inventory.MainNumber = 2;

    if (RectCheckClick (525, 700, 575, 750, &FixedCamera) == true)
        Inventory.MainNumber = 3;

    if (RectCheckClick (575, 700, 625, 750, &FixedCamera) == true)
        Inventory.MainNumber = 4;

    if (RectCheckClick (625, 700, 675, 750, &FixedCamera) == true)
        Inventory.MainNumber = 5;

    if (RectCheckClick (675, 700, 725, 750, &FixedCamera) == true)
        Inventory.MainNumber = 6;

    if (RectCheckClick (725, 700, 775, 750, &FixedCamera) == true)
        Inventory.MainNumber = 7;

    if (RectCheckClick (775, 700, 825, 750, &FixedCamera) == true)
        Inventory.MainNumber = 8;

    if (RectCheckClick (825, 700, 875, 750, &FixedCamera) == true)
        Inventory.MainNumber = 9;

    if (RectCheckClick (875, 700, 925, 750, &FixedCamera) == true)
        Inventory.MainNumber = 10;

    if (RectCheckClick (925, 700, 975, 750, &FixedCamera) == true)
        Inventory.MainNumber = 11;

    if (RectCheckClick (975, 700, 1025, 750, &FixedCamera) == true)
        Inventory.MainNumber = 12;

    if (RectCheckClick (1025, 700, 1075, 750, &FixedCamera) == true)
        Inventory.MainNumber = 13;

    if (RectCheckClick (1075, 700, 1125, 750, &FixedCamera) == true)
        Inventory.MainNumber = 14;

    if (RectCheckClick (1125, 700, 1175, 750, &FixedCamera) == true)
        Inventory.MainNumber = 15;

    if (RectCheckClick (1175, 700, 1225, 750, &FixedCamera) == true)
        Inventory.MainNumber = 16;

    if (RectCheckClick (1225, 700, 1275, 750, &FixedCamera) == true)
        Inventory.MainNumber = 17;

    /* if (!GetAsyncKeyState (VK_LCONTROL) &&
        !GetAsyncKeyState (VK_RCONTROL))
            Inventory.InvControlSpeed = -1;


    if (GetAsyncKeyState (VK_LCONTROL) &&
        Inventory.InvControlSpeed == 0)
        {
        Inventory.MainNumber -= 1;
        Inventory.InvControlSpeed = -1;
        };

    if (GetAsyncKeyState (VK_RCONTROL) &&
        Inventory.InvControlSpeed == 0)
        {
        Inventory.MainNumber += 1;
        Inventory.InvControlSpeed = 1;
        };    */

    if (Inventory.MainNumber < 0)
        Inventory.MainNumber = 17;

    if (Inventory.MainNumber >= 17)
        Inventory.MainNumber = 0;

    // Numbers

  /*  if (Inventory.MainNumber == IT_Axe)
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
        }; */

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


    if (Inventory.MainNumber == IT_Gun &&
        HaveInventory (Inventory.MainNumber, IT_Gun, Inventory.Gun, 1) == true)
        Animation.Picture = &GlobalAllImage.ManWithGuns;
    else if (Inventory.MainNumber == IT_Axe &&
             HaveInventory (Inventory.MainNumber, IT_Axe, Inventory.Axe, 1) == true)
        Animation.Picture = &GlobalAllImage.ManWithAxe;
    else
        Animation.Picture = &GlobalAllImage.Man;

    // ManArm
    /* if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Knife &&
        Inventory.Knife > 0)
        DrawTransparentImage (GlobalAllImage.Knife, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 112, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Apple &&
        Inventory.Apple > 0)
        DrawTransparentImage (GlobalAllImage.Apple, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 112, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Arrow &&
        Inventory.Arrow > 0)
        DrawTransparentImage (GlobalAllImage.Arrow, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 112, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Stone &&
        Inventory.Stone > 0)
        DrawTransparentImage (GlobalAllImage.Stone, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 112, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Wood &&
        Inventory.Wood > 0)
        DrawTransparentImage (GlobalAllImage.Wood, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 70, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Coin &&
        Inventory.Coin > 0)
        DrawTransparentImage (GlobalAllImage.Coin, Point.x + 33 - yFrame*20 + xWeapon*X,
                              Point.y + 70, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Axe &&
        Inventory.Axe > 0)
        DrawTransparentImage (GlobalAllImage.Axe, Point.x - 26 + yFrame*98,
                              Point.y + 60, &xWeapon, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Fishing &&
        Inventory.Fishing > 0)
        DrawTransparentImage (GlobalAllImage.FishingBig, Point.x - 23 + yFrame*101,
                              Point.y + 60, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Fish &&
        Inventory.Fish > 0)
        DrawTransparentImage (GlobalAllImage.Fish, Point.x - 23 + yFrame*101,
                              Point.y + 110, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_CookedFish &&
        Inventory.CookedFish > 0)
        DrawTransparentImage (GlobalAllImage.CookedFish, Point.x - 23 + yFrame*101,
                              Point.y + 110, &null, &yFrame, Camera);

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Rope &&
        Inventory.Rope > 0)
        DrawTransparentImage (GlobalAllImage.Rope, Point.x - 23 + yFrame*101,
                              Point.y + 110, &null, &yFrame, Camera);

    // Bow

    if (yFrame <= 1 &&
        Inventory.MainNumber == IT_Bow &&
        Inventory.Bow > 0)
        {
        DrawTransparentImage (GlobalAllImage.Bow, Point.x + yFrame*72,
                              Point.y + 70, &xWeapon, &yFrame, Camera);

        if (Inventory.Arrow > 0)
            DrawTransparentImage (GlobalAllImage.Arrow, -11 + 61*yFrame + ArrowX,
                                  ArrowY + 100, &null, &yFrame, Camera);
        };

    // printf ("y = %d \n", ArrowY); */
    };

void ManType :: DrawMan (CamType* Camera)
    {
    int null = 0;

    printf ("Position = %d, \r", Position);

    /* int HaveWeapon = true;

    if (Inventory.MainNumber != IT_Axe &&
        HaveInventory (Inventory.MainNumber, IT_Axe, Inventory.Axe, 1) == true &&
        Inventory.MainNumber != IT_Gun &&
        HaveInventory (Inventory.MainNumber, IT_Gun, Inventory.Gun, 1) == true)
        HaveWeapon = false;   */

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
    if (Animation.yFrame <= 3)
        {
        if (Speed.x > 0)
            Animation.yFrame = 6;

        if (Speed.y < 0)
            Animation.yFrame = 3;

        if (GetAsyncKeyState (VK_LBUTTON) &&
            Animation.Picture != &GlobalAllImage.Man &&
            Speed.y >= 0)
            Animation.yFrame = 1;

        if (Speed.y >= 0 &&
            !GetAsyncKeyState (VK_LBUTTON) &&
            Animation.Picture != &GlobalAllImage.Man &&
            Speed.x < 0)
            Animation.yFrame = 2;

        if (Speed.x == 0 &&
            Speed.y >= 0 &&
            !GetAsyncKeyState (VK_LBUTTON))
            Animation.yFrame = 0;
        };

    if (Animation.yFrame >= 4)
        {
        if (Speed.x < 0)
            Animation.yFrame = 2;

        if (Speed.y < 0)
            Animation.yFrame = 7;

        if (GetAsyncKeyState (VK_LBUTTON) &&
            Animation.Picture != &GlobalAllImage.Man &&
            Speed.y >= 0)
            Animation.yFrame = 5;

        if (Speed.y >= 0 &&
            !GetAsyncKeyState (VK_LBUTTON) &&
            Animation.Picture != &GlobalAllImage.Man &&
            Speed.x > 0)
            Animation.yFrame = 6;

       if (Speed.x == 0 &&
           Speed.y >= 0 &&
           !GetAsyncKeyState (VK_LBUTTON))
           Animation.yFrame = 4;
        };
    };

    // printf ("x = %d, y = %d, twonumber = %d\n", Animation.xFrame, Animation.yFrame, twonumber);

    if (Kind != 0 &&
        Kind != MT_Boat)
        {
        if (Speed.x < 0)
            {
            Animation.yFrame = 0;
            };

        if (Speed.x > 0)
            {
            Animation.yFrame = 1;
            };
        };

    // if (Health <= 0)
    //        Animation.yFrame = 2;

    if (Position == Climbing_Position)
        {
        Animation.Picture = &GlobalAllImage.ClimbingMan;
        Animation.yFrame = 0;
        Speed.y = -5;
        };

    if (Position == ClimbDown_Position)
        {
        Animation.Picture = &GlobalAllImage.ClimbingMan;
        Animation.yFrame = 0;
        Speed.y = 5;
        };

    /* if (Position == Climbing_Position &&
        !GetAsyncKeyState (VK_UP))
            Position = Normal_Position; */

    if (Kind == 0)
        DrawTransparentImage (*Animation.Picture, Point.x, Point.y, &Animation.xFrame, &Animation.yFrame, Camera);

    if (Kind != 0 &&
        Health > 0)
        DrawTransparentImage (*Animation.Picture, Point.x, Point.y, &Animation.xFrame, &Animation.yFrame, Camera);

    if (RectAiming (Point.x, Point.y, Point.x + SizeX,
            Point.y + SizeY, Camera) == true)
                {
                /* int TermX = Point.x - 17 - Camera->Point.x;
                int TermY = Point.y - Camera->Point.y;

                DrawHealth ({Point.x + SizeX/2 - Camera->Point.x,
                             Point.y - 25 - Camera->Point.y}, Health);

                GRSetColor (RGB (237, 28, 36), 1);
                GRSetFillColor (RGB (237, 28, 36));

                DrawTransparentImage (GlobalAllImage.Termometer, TermX, TermY, &null, &null);

                GRRectangle (TermX + Sign_Term_RectLeftX, TermY + Sign_Term_RectDownY - Temperature,
                             TermX + Sign_Term_RectRightX, TermY + Sign_Term_RectDownY); */

                DrawManParameters (Camera);
                };


    // int null = 0;

    // PointType TextPoint = {Point.x - Camera->Point.x + 50, Point.y - Camera->Point.y};

    if (Health > 0)
        {
        GRSetColor (TX_WHITE, 5);
        GRSelectFont ("Comic Sans MS", 30);
        GRTextOut (Point - Camera->Point + PointType {50, 0}, Name);
        };

    /* if (Position == Ghost_Position)
        {
        if (Animation.yFrame <= 4)
            Animation.yFrame = 4;

        if (Animation.yFrame >= 5)
            Animation.yFrame = 9;
        }; */
    };

void ManType :: ManFire (CamType* Camera)
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

void ManType :: DrawManParameters (CamType* Camera)
    {
    GRSetColor (RGB (237, 28, 36), 1);
    TextWithEnd ({Point.x + SizeX + 25 - Camera->Point.x, Point.y + 30 - Camera->Point.y}, 20, Health, "Health = ", "%");

    GRSetColor (RGB (91, 110, 225), 1);
    TextWithEnd ({Point.x + SizeX + 25 - Camera->Point.x, Point.y + 45 - Camera->Point.y}, 20, Energy, "Energy = ", "%");

    GRSetColor (RGB (127, 127, 127), 1);
    TextWithEnd ({Point.x + SizeX + 25 - Camera->Point.x, Point.y + 60 - Camera->Point.y}, 20, Temperature, "Temper = ", "'C");
    };

void ManType :: ManHealth (CamType* Camera)
    {
    int null = 0;

    if (Health < 0)
        {
        Health = 0;
        };

    if (Health == 0)
        {
        DrawTransparentImage (GlobalAllImage.GameOver, Point.x, Point.y, &null, &null, Camera);
        Speed.x = 0;
        Speed.y = 0;
        Position = 0;
        // Inventory.Wood = 0;
        // ArmPicture = &AllImage.BlackSpace;
        // RightArm = 0;
        };

    if (Health > Man_MaxHealth)
        Health = Man_MaxHealth;

    //if (Position = Fixed_Position)
    //    Speed.x *= 0.1;
    };

void ManType :: VillagerMind (ManType* Man, CamType* Camera)
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
            Speed.x = Inventory.Rope;

    if (Man->Point.x - Point.x < 100 &&
            Man->Point.x - Point.x > 0)
            {
            Speed.x = 0;
            };

    if (Point.x - Man->Point.x > 100 &&
            Point.x - Man->Point.x < 200)
            Speed.x = -Inventory.Rope;

    if (Point.x - Man->Point.x < 100 &&
            Point.x - Man->Point.x > 0)
            {
            Speed.x = 0;
            };

    if (fabs (Man->Point.x - Point.x) <= 200)
        {

        PointType TradePoint = {Point.x + 50 - Camera->Point.x, Point.y + 84 - Camera->Point.y};

        if (Inventory.Wood == 0)
            {
            if (ModuleDistance (TradePoint, Mouse, 50) == true &&
                GetAsyncKeyState (VK_LBUTTON))
            Inventory.Wood = 1;
            };

        if (Inventory.Wood == 1)
            {
            DrawTransparentImage (GlobalAllImage.CommonSlot, Point.x - 20, Point.y - 60, &null, &null, Camera);

            DrawTransparentImage (GlobalAllImage.CommonSlot, Point.x + 50, Point.y - 60, &null, &null, Camera);

            DrawTransparentImage (GlobalAllImage.CommonSlot, Point.x + 120, Point.y - 60, &null, &null, Camera);

            PointType Slot1 = {Point.x + 5 - Camera->Point.x, Point.y - 35 - Camera->Point.y};
            PointType Slot2 = {Point.x + 75 - Camera->Point.x, Point.y - 35 - Camera->Point.y};
            PointType Slot3 = {Point.x + 145 - Camera->Point.x, Point.y - 35 - Camera->Point.y};

            // slot1
            if (Inventory.Axe == 0)
                {
                DrawTransparentImage (GlobalAllImage.Coin, Point.x - 10, Point.y - 53, &null, &null, Camera);

                DrawTransparentImage (GlobalAllImage.SmallItems, Point.x + 10, Point.y - 33, &null, &null, Camera);
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
                DrawTransparentImage (GlobalAllImage.Axe, Point.x - 20, Point.y - 60, &null, &null, Camera);

                DrawTransparentImage (GlobalAllImage.SmallItems, Point.x + 10, Point.y - 33, &null, &two, Camera);
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
                DrawTransparentImage (GlobalAllImage.Apple, Point.x - 20, Point.y - 60, &null, &null, Camera);

                DrawTransparentImage (GlobalAllImage.SmallItems, Point.x + 10, Point.y - 33, &null, &one, Camera);
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
                DrawTransparentImage (GlobalAllImage.Knife, Point.x + 50, Point.y - 40, &null, &null, Camera);

                DrawTransparentImage (GlobalAllImage.SmallItems, Point.x + 80, Point.y - 33, &null, &null, Camera);

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
                DrawTransparentImage (GlobalAllImage.Stone, Point.x + 50, Point.y - 60, &null, &null, Camera);

                DrawTransparentImage (GlobalAllImage.SmallItems, Point.x + 80, Point.y - 33, &null, &one, Camera);

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
                DrawTransparentImage (GlobalAllImage.Arrow, Point.x + 50, Point.y - 46, &null, &null, Camera);

                DrawTransparentImage (GlobalAllImage.SmallItems, Point.x + 80, Point.y - 33, &null, &two, Camera);

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
                DrawTransparentImage (GlobalAllImage.Bow, Point.x + 120, Point.y - 70, &null, &null, Camera);

                DrawTransparentImage (GlobalAllImage.SmallItems, Point.x + 150, Point.y - 33, &null, &one, Camera);

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
                DrawTransparentImage (GlobalAllImage.Apple, Point.x + 120, Point.y - 60, &null, &null, Camera);

                DrawTransparentImage (GlobalAllImage.SmallItems, Point.x + 150, Point.y - 33, &null, &two, Camera);

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
                DrawTransparentImage (GlobalAllImage.Coin, Point.x + 130, Point.y - 53, &null, &null, Camera);

                DrawTransparentImage (GlobalAllImage.SmallItems, Point.x + 150, Point.y - 33, &null, &null, Camera);

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
        DrawTransparentImage (GlobalAllImage.Gun, x + 74, y + 93, &null, &null, Camera);
        if (Side == 0)
        DrawTransparentImage (GlobalAllImage.Gun, x + 44, y + 93, &one, &null, Camera);
        Position += 1;
        if (Position >= 10)
            {
            int x = x + 74;
            int Speed.x = 0;
            if (x > Man->Point.x)
                Speed.x = -10;
            if (x < Man->Point.x)
                Speed.x = 10;
            x += Speed.x;
            int null = 0;
            int one = 1;
            if (Speed.x > 0)
                DrawTransparentImage (GlobalAllImage.Gun, x, y + 88, &null, &one, Camera);
            if (Speed.x < 0)
                DrawTransparentImage (GlobalAllImage.Gun, x, y + 88, &one, &one, Camera);
            if (ModuleDistance (Man->Point.x + 47, Man->Point.y + 84, x,  y + 88, 30) == true)
                {
                Position = 0;
                };
            };
        }; */

    // Fighting:

    PointType FightPoint = {Point.x + 50 - Camera->Point.x, Point.y + 84 - Camera->Point.y};
    // PointType Mouse = {txMouseX(), txMouseY()};

    if (ModuleDistance (FightPoint, Mouse, 50) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
        Man->Inventory.MainNumber == IT_Axe &&
        Man->Inventory.Axe >= 0 &&
        Man->ArmSpeed >= 10)
        {
        Health -= 2;
        Speed.y = -15;
        if (Point.x > Man->Point.x)
            Speed.x = 50;
        if (Point.x < Man->Point.x)
            Speed.x = -50;
        // Animation.xFrame += 1;
        // txCircle (Man->Point.x - Camera->Point.x, Man->Point.y - Camera->Point.y, 50);
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
        Speed.y = -15;
        if (Point.x > Man->Point.x)
            Speed.x = 50;
        if (Point.x < Man->Point.x)
            Speed.x = -50;
        Health -= 5;
        Man->Inventory.Arrow -= 1;
        Man->ArrowVX = 0;
        Man->ArroeVY = 0;
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
            Speed.x = Inventory.Rope;

        if (Man->Point.x - Point.x < 50 &&
            Man->Point.x - Point.x > 0)
            {
            Speed.x = 0;
            };

        if (Point.x - Man->Point.x > 50 &&
            Point.x - Man->Point.x < 500)
            Speed.x = -Inventory.Rope;

        if (Point.x - Man->Point.x < 50 &&
            Point.x - Man->Point.x > 0)
            {
            Speed.x = 0;
            };

        // Fighting
        ArmSpeed += 1;

        if (ArmSpeed >= 10 &&
            Speed.x == 0 &&
            Inventory.Stone != MT_Ghost &&
            fabs (Man->Point.x + Man->SizeX/2 - Point.x - SizeX/2) <= SizeX/2 + Man->SizeX/2&&
            fabs (Man->Point.y + Man->SizeY/2 - Point.y - SizeY/2) <= SizeY/2 + Man->SizeY/2)
            {
            Man->Health -= 1;
            Man->Speed.y = -15;
            if (Man->Point.x > Point.x)
                Man->Speed.x = 50;
            if (Man->Point.x < Point.x)
                Man->Speed.x = -50;
            // Man->Animation.xFrame += 1;
            // txCircle (Man->Point.x - Camera->Point.x, Man->Point.y - Camera->Point.y, 50);
            ArmSpeed = 0;
            };

        };

    // Bandit
    if (Kind == MT_Bandit &&
        Health > 0)
        {
        if (Man->Point.x > Point.x)
            Speed.x = 10;

        if (Man->Point.x < Point.x)
            Speed.x = -10;

        /* if (Animation.yFrame == 0 &&
            Speed.x == 0)
            Animation.yFrame = 2;
        if (Animation.yFrame == 1 &&
            Speed.x == 0)
            Animation.yFrame = 3; */

        if (fabs (Man->Point.x - Point.x) <= 200)
            Speed.x = 0;

        ArmSpeed += 1;

        ArrowX += ArrowVX;
        ArrowY += ArroeVY;

        int null = 0;

        DrawTransparentImage (GlobalAllImage.Bullet, -11 + 61*Animation.yFrame + ArrowX,
                              ArrowY + 60, &null, &Animation.yFrame, Camera);

        if (ArmSpeed >= 80)
            {
            // ArroeVY = 5;
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
            Man->Speed.y = -15;
            if (Point.x > Man->Point.x)
                Man->Speed.x = -50;
            if (Point.x < Man->Point.x)
                Man->Speed.x = 50;
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

        PointType BoatPoint = {Point.x + 130 - Camera->Point.x, Point.y + 15 - Camera->Point.y};

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
        Man->Speed.x = 0;
        Man->Speed.y = 0;

        if (GetAsyncKeyState (VK_LEFT))
            Speed.x = -20;

        if (GetAsyncKeyState (VK_RIGHT) &&
            Point.x <= -300)
            Speed.x = 20;

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
                Speed.x = 4;
            if (Man->Point.x + 55 < Point.x)
                Speed.x = -4;

            if (Point.y >= 720)
                Speed.y = -2;
            else
                Speed.y = 0;

            PointType Fish = {Point.x+25, Point.y+10};
            PointType FishingMan = {Man->Point.x + 55, Man->Point.y + 85};

            if (ModuleDistance (FishingMan, Fish, 100) == true)
                {
                Health = 0;
                Man->Inventory.Fish += 1;
                };
            }
        else
            Speed.x = 4*(rand()%3 - 1);

        Acceleration.y = 0;

        if (Man->Days >= 20 &&
            Man->Days < 30)
            Speed.x = 4*(rand()%3 - 1);
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

        if (InBorders (70, ArmSpeed, 149) == true &&
            fabs (Point.x + SizeX/2 - Man->Point.x - Man->SizeX/2) <= SizeX)
            {
            // Health = 0;
            Man->Position = Ghost_Position;
            // Health += 1;
            // ArmSpeed += 1;
            };

        if (InBorders (70, ArmSpeed, 149) == false &&
            Man->Position == Ghost_Position)
            Man->Position = Normal_Position;

        if (ArmSpeed == 150)
            {
            ArmSpeed = 0;
            // Health = Man_Health;
            };

        if (Man->Position == Ghost_Position)
            {
            Health += 1;
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

void ManType :: ControlMan (const MouseType& Mouse, int* t)
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

    if (GetAsyncKeyState (VK_RIGHT) &&
        Position != Ghost_Position)
        {
        Speed.x = Man_FastSpeed;
        Side = Man_RightSide;
        };

    if (GetAsyncKeyState (VK_LEFT) &&
        Position != Ghost_Position)
        {
        Speed.x = -Man_FastSpeed;
        Side = Man_LeftSide;
        };

    if (Speed.x > 0)
        {
        if (GetAsyncKeyState (VK_SHIFT))
            {
            Speed.x = Man_SlowSpeed;
            };
        };

    if (Speed.x < 0)
        {
        if (GetAsyncKeyState (VK_SHIFT))
            {
            Speed.x = -Man_SlowSpeed;
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
        // ArmSpeed = 0;
        }
    else
        if (Inventory.MainNumber == 0 &&
            Inventory.MainSlot > 0)
        {
        xWeapon -= 1;
        // ArmSpeed = 10;
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
    ArrowY += ArroeVY;

    if (Inventory.MainNumber == 5 &&
        Inventory.MainSlot > 0)
            {
            if (ArrowY >= 700)
                {
                Inventory.Arrow -= 1;
                ArrowVX = 0;
                ArroeVY = 0;
                ArrowX  = Point.x;
                ArrowY  = Point.y;
                };

            if (Animation.yFrame == 1 &&
                GetAsyncKeyState (VK_LBUTTON) &&
                Inventory.Arrow > 0)
                {
                ArrowVX = 100;
                ArroeVY = 2;
                };

            if (Animation.yFrame == 0 &&
                GetAsyncKeyState (VK_LBUTTON) &&
                Inventory.Arrow > 0)
                {
                ArrowVX = -100;
                ArroeVY = 8;
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
    /* if (Point.y + SizeY >= 2308 &&
        Speed.y > 0)
        Speed.y = 0; */

    if (!GetAsyncKeyState (VK_LEFT) &&
        !GetAsyncKeyState (VK_RIGHT))
        Speed.x = 0;

    if (Point.x < 2000 &&
        Speed.x < 0)
        Speed.x = 0;

    if (Point.x > 11400*World_Size - 1730 &&
        Speed.x > 0)
        Speed.x = 0;

    if (Point.y >= 1052 &&
        Speed.y > 0)
        {
        Speed.y = 0;
        Point.y = 1052;
        };

    if (Point.y == 1052 &&
        GetAsyncKeyState (VK_UP))
        Speed.y = -Man_JumpSpeed;

    Point += Speed;

    Speed += Acceleration;

    Speed.x = Speed.x*0.5;

    Acceleration.y = Man_aY;

    if (Speed.y > 50)
        Speed.y = 50;

    if (Speed.y < -50)
        Speed.y = -50;

    if (Speed.x > 50)
        Speed.x = 50;

    if (Speed.x < -50)
        Speed.x = -50;

    // Time;
    Time += 1;

    if (Time >= 1000)
        Time = 0;

    if (Time == 900)
        Days += 1;

    if (Days >= 40)
        Days = 0;

    // Water
    /* if (Point.y >= 620)
        Position = Water_Position;
    else
        if (Position == Water_Position)
            Position = Normal_Position; */

    if (Position == Water_Position &&
        Kind != MT_Boat &&
        Kind != MT_Fish)
        {
        Speed.y = -3;
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
            Speed.y > 0)
            {
            // y = 500;
            Speed.y = 0;
            };

        if (Point.y >= 700 - GRGetExtentY(Animation.Picture->Picture)/Animation.Picture->yMaxAnimationNumber + Inventory.Arrow)
            {
            Point.y = 700 - GRGetExtentY(Animation.Picture->Picture)/Animation.Picture->yMaxAnimationNumber + Inventory.Arrow;
            // Speed.y = 0;
            };
        };

    if (Days >= 20 &&
        Days <  30)
        {
        if (Position == Water_Position)
            Temperature -= 1;
        };

    if (Position == Ghost_Position)
        {
        Health -= 0.5;
        Speed.x = 0;
        };
    };

void ManType :: BlockInteraction (BlockType* Block, CamType* Camera)
    {
    Block->Interaction (this, Camera);
    };

void ManType :: BlockCollision (BlockType* Block, CamType* Camera)
    {
    /* if (Block->Number == BT_Coin)
        return;

    if (Block->Health < 1)
        return;

    if (Block->Number != BT_Rock &&
        Block->Number != BT_FallingTree &&
        Block->Number != BT_Floor &&
        Block->Number != BT_Dirt &&
        Block->Number != BT_Dynamite)
        return; */

    // Physic

    // CollisionDetection

    if (fabs (Block->Point.x + Block->SizeX/2 - Point.x - SizeX/2) <= Block->SizeX/2 &&
        InBorders (Block->SizeY + this->SizeY - 100, Block->Point.y + Block->SizeY - Point.y, Block->SizeY + this->SizeY) == true)
            {
            // CollisionResponse

            if (GetAsyncKeyState (VK_UP) &&
                Kind == MT_Main)
                {
                Speed.y = -Man_JumpSpeed;
                };

            if (Speed.y > 0)
                {
                Speed.y = 0;
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
                    Speed.x > 0)
                        Speed.x = 0;

                if (Block->Point.x + Block->SizeX >= Point.x &&
                    Speed.x < 0)
                        Speed.x = 0;
                }; */
            };
    };

//-----------------------------------------------------------------------------

void DrawLevelPeople (ManType Villagers[], CamType* Camera)
    {
    // int i = 0;

    for (int i = 0; i < Men_Number; i ++)
        {
        Villagers [i].DrawMan (Camera);

        // i += 1;
        };
    };

void CallPeoplePhysic (ManType Villagers[], CamType* Camera, BlockType* ManyBlocks [], ManType* Man)
    {
    /* int i = 0;
    int b = 0;
    AllImageType AllImage1 = AllImage;
    while (ManyBlocks[i]->x != -1 && ManyBlocks[i]->y != -1)
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

    for (int i = 0; i < Men_Number; i ++)
        {
        Villagers[i].VillagerMind (Man, Camera);
        Villagers[i].Physic ();

        i += 1;
        };
    };


//=============================================================================

