#include "ManType.h"

ManType :: ManType (double _x, double _y, double _Health, AnimationType _Animation,
                    double _vX, double _vY, double _aX, double _aY,
                    int _Side, int _Position, double _Temperature,
                    int _NumberCoin, int _xWeapon, int _ArmSpeed, char _Name [50], int _Kind, InvType _Inventory,
                    int _Time, int _Days, double _ArrowX, double _ArrowY, int _ArrowVX, int _ArrowVY, HelpType _HelpSystem) :
    BaseType (_x, _y, _Health, _Animation),
    vX (_vX),
    vY (_vY),
    aX (_aX),                                                  // & - Амперсанд(берет адрес переменной)
    aY (_aY),
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

    while (Villagers[i].x != -1 && Villagers[i].y != -1)
        {
        if (i < BearNumber)
            {
            Villagers[i].Health = 20;
            Villagers[i].Kind = MT_Bear;
            Villagers[i].Inventory.Rope = 10;
            Villagers[i].x = rand() % 11400*World_Size;
            Villagers[i].y = -500;
            Villagers[i].Animation.Picture = &AllImage.Bear;
            };

        if (i >= BearNumber &&
            i < 7)
            {
            Villagers[i].Health = 15;
            Villagers[i].Kind = MT_Bear;
            Villagers[i].Inventory.Rope = 13;
            Villagers[i].x = rand() % 11400*World_Size;
            Villagers[i].y = -500;
            Villagers[i].Animation.Picture = &AllImage.Wolf;
            };

        if (i >= 7 &&
            i < 10)
            {
            Villagers[i].Health = 10;
            Villagers[i].Kind = MT_Bear;
            Villagers[i].Inventory.Rope = 12;
            Villagers[i].x = rand() % 11400*World_Size;
            Villagers[i].y = -500;
            Villagers[i].Animation.Picture = &AllImage.Spider;
            };

        if (i >= 10 &&
            i < 13)
            {
            Villagers[i].Health = 20;
            Villagers[i].Kind = MT_Seller;
            Villagers[i].Inventory.Rope = 10;
            Villagers[i].x = rand() % 11400*World_Size;
            Villagers[i].y = -500;
            Villagers[i].Animation.Picture = &AllImage.Villager;
            };

        if (i >= 13 &&
            i < 20)
            {
            Villagers[i].Health = 20;
            Villagers[i].Kind = MT_Fish;
            // Villagers[i].Inventory.Rope = 10;
            Villagers[i].x = -rand() % 700 - 100;
            Villagers[i].y = 750 + rand() % 100;
            Villagers[i].Animation.Picture = &AllImage.Fish;
            };

        if (i == 20)
            {
            Villagers[i].Health = 999;
            Villagers[i].Kind = MT_Boat;
            Villagers[i].x = -rand() % 700 - 100;
            Villagers[i].y = 521;
            Villagers[i].Animation.Picture = &AllImage.Boat;
            };

        if (i > 20)
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

    if (Block > 0)
        {
        DrawTransparentImage (&Picture, x, y + 70, &null, &one, &FixedCamera);

        Text (TextX + 38, TextY + 114, 20, Block, "");
        };
    };

void ManType :: Crafting (AllImageType AllImage, CamType* FixedCamera)
    {
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

        if (ModuleDistance (40, 325, txMouseX(), txMouseY(), 50) == true &&
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

    if (ModuleDistance (324, 325, txMouseX(), txMouseY(), 50) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
        Inventory.CraftControlSpeed == 0 &&
        Inventory.CraftNumber < 5)
        {
        Inventory.CraftNumber += 1;
        Inventory.CraftControlSpeed = 1;
        };

    if (ModuleDistance (324, 395, txMouseX(), txMouseY(), 50) == true &&
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
            ModuleDistance (265, 325, txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Inventory.CraftControlSpeed == 0)
            {
            Inventory.Wood -= 2;
            Inventory.Stone -= 1;
            Inventory.Axe += 1;
            Inventory.CraftNumber = 0;
            Inventory.CraftControlSpeed = 1;
            if (HelpSystem.Number == 2)
                HelpSystem.Number = 3;
            };
        };

    if (Inventory.CraftNumber == 2)
        {
        DrawTransparentImage (&AllImage.Wood, 127, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Stone, 15, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Knife, 240, 312, &null, &one, FixedCamera);

        if (Inventory.Wood >= 1 &&
            Inventory.Stone >= 1 &&
            ModuleDistance (265, 325, txMouseX(), txMouseY(), 50) == true &&
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
            ModuleDistance (265, 325, txMouseX(), txMouseY(), 50) == true &&
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
            ModuleDistance (265, 325, txMouseX(), txMouseY(), 50) == true &&
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
            ModuleDistance (265, 325, txMouseX(), txMouseY(), 50) == true &&
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

    DrawTransparentImage (&AllImage.Inventory, 325, 770, &null, &null, FixedCamera);
    DrawTransparentImage (&AllImage.Inventory, 775, 770, &null, &null, FixedCamera);

    DrawTransparentImage (&AllImage.Slot, 324 + Inventory.MainNumber*50, 769, &null, &null, FixedCamera);

    DrawSlot (Inventory.Axe, 325, 690, AllImage.Axe, 325, 700);

    DrawSlot (Inventory.Wood, 375, 700, AllImage.Wood, 375, 700);

    DrawSlot (Inventory.Apple, 475, 700, AllImage.Apple, 475, 700);

    DrawSlot (Inventory.Knife, 425, 720, AllImage.Knife, 425, 700);

    DrawSlot (Inventory.Stone, 525, 700, AllImage.Stone, 525, 700);

    DrawSlot (Inventory.Bow, 575, 690, AllImage.Bow, 575, 700);

    DrawSlot (Inventory.Arrow, 603, 719, AllImage.Arrow, 625, 700);

    DrawSlot (Inventory.Coin, 685, 707, AllImage.Coin, 675, 700);

    DrawSlot (Inventory.Fishing, 725, 700, AllImage.FishingSmall, 725, 700);

    DrawSlot (Inventory.Fish, 780, 713, AllImage.Fish, 775, 700);

    DrawSlot (Inventory.CookedFish, 825, 712, AllImage.CookedFish, 825, 700);

    DrawSlot (Inventory.Rope, 875, 700, AllImage.Rope, 875, 700);

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
        Inventory.MainNumber -= 1;
        Inventory.InvControlSpeed = -1;
        };

    if (GetAsyncKeyState (VK_RCONTROL) &&
        Inventory.InvControlSpeed == 0)
        {
        Inventory.MainNumber += 1;
        Inventory.InvControlSpeed = 1;
        };

    if (Inventory.MainNumber < 0)
        Inventory.MainNumber = 17;

    if (Inventory.MainNumber > 17)
        Inventory.MainNumber = 0;

    // Numbers

    if (Inventory.MainNumber == 0)
        {
        Inventory.MainSlot = Inventory.Axe;
        };

    if (Inventory.MainNumber == 1)
        {
        Inventory.MainSlot = Inventory.Wood;
        };

    if (Inventory.MainNumber == 2)
        {
        Inventory.MainSlot = Inventory.Knife;
        };

    if (Inventory.MainNumber == 3)
        {
        Inventory.MainSlot = Inventory.Apple;
        };

    if (Inventory.MainNumber == 4)
        {
        Inventory.MainSlot = Inventory.Stone;
        };

    if (Inventory.MainNumber == 5)
        {
        Inventory.MainSlot = Inventory.Bow;
        };

    if (Inventory.MainNumber == 6)
        {
        Inventory.MainSlot = Inventory.Arrow;
        };

    if (Inventory.MainNumber == 7)
        {
        Inventory.MainSlot = Inventory.Coin;
        };

    if (Inventory.MainNumber == 8)
        {
        Inventory.MainSlot = Inventory.Fishing;
        };

    if (Inventory.MainNumber == 9)
        {
        Inventory.MainSlot = Inventory.Fish;
        };

    if (Inventory.MainNumber == 10)
        {
        Inventory.MainSlot = Inventory.CookedFish;
        };

    if (Inventory.MainNumber == 11)
        {
        Inventory.MainSlot = Inventory.Rope;
        };

    // ManArm
    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 2 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Knife, x + 33 - Animation.yFrame*20 + xWeapon*X,
                              y + 112, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 3 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Apple, x + 33 - Animation.yFrame*20 + xWeapon*X,
                              y + 112, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 6 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Arrow, x + 33 - Animation.yFrame*20 + xWeapon*X,
                              y + 112, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 4 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Stone, x + 33 - Animation.yFrame*20 + xWeapon*X,
                              y + 112, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 1 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Wood, x + 33 - Animation.yFrame*20 + xWeapon*X,
                              y + 70, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 7 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Coin, x + 33 - Animation.yFrame*20 + xWeapon*X,
                              y + 70, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 0 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Axe, x - 26 + Animation.yFrame*98,
                              y + 60, &xWeapon, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 8 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.FishingBig, x - 23 + Animation.yFrame*101,
                              y + 60, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 9 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Fish, x - 23 + Animation.yFrame*101,
                              y + 110, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 10 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.CookedFish, x - 23 + Animation.yFrame*101,
                              y + 110, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 11 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Rope, x - 23 + Animation.yFrame*101,
                              y + 110, &null, &Animation.yFrame, Camera);

    // Bow

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 5 &&
        Inventory.MainSlot > 0)
        {
        DrawTransparentImage (&AllImage.Bow, x + Animation.yFrame*72,
                              y + 70, &xWeapon, &Animation.yFrame, Camera);

        if (Inventory.Arrow > 0)
            DrawTransparentImage (&AllImage.Arrow, -11 + 61*Animation.yFrame + ArrowX,
                                  ArrowY + 100, &null, &Animation.yFrame, Camera);
        };

    // printf ("y = %d \n", ArrowY);
    };

void ManType :: DrawMan (CamType* Camera, AllImageType AllImage)
    {
    // if (Kind == 0)
    //    IncreaseAnimationNumber (&Animation);

    int nine = 9;
    // int twonumber = Animation.yFrame + 2;

    if (Kind == 0)
    {
    if (vX > 0)
        {
        if (vY <= 0)
            Animation.yFrame = 3;
        else
            Animation.yFrame = 1;

        if (Health <= 0)
            Animation.yFrame = 5;
        };

    if (vX < 0)
        {
        if (vY <= 0)
            Animation.yFrame = 2;
        else
            Animation.yFrame = 0;

        if (Health <= 0)
            Animation.yFrame = 4;
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
        DrawTransparentImage (Animation.Picture, x, y, &Animation.xFrame, &Animation.yFrame, Camera);

    if (Kind != 0 &&
        Health > 0)
        DrawTransparentImage (Animation.Picture, x, y, &Animation.xFrame, &Animation.yFrame, Camera);

    int null = 0;

    if (Health > 0)
        {
        GRSetColor (TX_WHITE, 5);
        GRSelectFont ("Comic Sans MS", 30);
        GRTextOut (x - Camera->x + 50, y - Camera->y, Name);
        };
    };

void ManType :: ManFire (CamType* Camera, AllImageType AllImage)
    {
    BlockType Fire1 {0 - GRGetExtentX (Animation.Picture->Picture)/2 + Man_Fire1X, 0 - GRGetExtentY (Animation.Picture->Picture)/2 + Man_Fire1Y, 4, {rand() % 4, 0, &AllImage.Fire}, 0};
    BlockType Fire2 {0 - GRGetExtentX (Animation.Picture->Picture)/2 + Man_Fire2X, 0 - GRGetExtentY (Animation.Picture->Picture)/2 + Man_Fire2Y, 4, {rand() % 4, 0, &AllImage.Fire}, 0};
    BlockType Fire3 {0 - GRGetExtentX (Animation.Picture->Picture)/2 + Man_Fire3X, 0 - GRGetExtentY (Animation.Picture->Picture)/2 + Man_Fire3Y, 4, {rand() % 4, 0, &AllImage.Fire}, 0};

    if (Position == Fire_Position)
        {
        Health -= Man_FireDamage/100;
        Temperature += 1;
        Fire1.DrawBlock (Camera, AllImage);
        Fire2.DrawBlock (Camera, AllImage);
        Fire3.DrawBlock (Camera, AllImage);
        };
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
        DrawTransparentImage (&AllImage.GameOver, x, y, &null, &null, Camera);
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
    if (x > Man->x)
        Side = 0;
    if (x < Man->x)
        Side = 1;

    if (Man->x - x > 100 &&
            Man->x - x < 200)
            vX = Inventory.Rope;

    if (Man->x - x < 100 &&
            Man->x - x > 0)
            {
            vX = 0;
            };

    if (x - Man->x > 100 &&
            x - Man->x < 200)
            vX = -Inventory.Rope;

    if (x - Man->x < 100 &&
            x - Man->x > 0)
            {
            vX = 0;
            };

    if (fabs (Man->x - x) <= 200)
        {

        if (Inventory.Wood == 0)
            {
            if (ModuleDistance (x + 50 - Camera->x, y + 84 - Camera->y , txMouseX(), txMouseY(), 50) == true &&
                GetAsyncKeyState (VK_LBUTTON))
            Inventory.Wood = 1;
            };

        if (Inventory.Wood == 1)
            {
            DrawTransparentImage (&AllImage.CommonSlot, x - 20, y - 60, &null, &null, Camera);

            DrawTransparentImage (&AllImage.CommonSlot, x + 50, y - 60, &null, &null, Camera);

            DrawTransparentImage (&AllImage.CommonSlot, x + 120, y - 60, &null, &null, Camera);

            // slot1
            if (Inventory.Axe == 0)
                {
                DrawTransparentImage (&AllImage.Coin, x - 10, y - 53, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, x + 10, y - 33, &null, &null, Camera);
                // Text (x + 8, y - 16, 20, one, "");

                if (ModuleDistance (x + 5 - Camera->x, y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
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
                DrawTransparentImage (&AllImage.Axe, x - 20, y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, x + 10, y - 33, &null, &two, Camera);
                // Text (x + 8, y - 16, 20, one, "");
                if (ModuleDistance (x + 5 - Camera->x, y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
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
                DrawTransparentImage (&AllImage.Apple, x - 20, y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, x + 10, y - 33, &null, &one, Camera);
                // Text (x + 8, y - 16, 20, one, "");
                if (ModuleDistance (x + 5 - Camera->x, y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
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
                DrawTransparentImage (&AllImage.Knife, x + 50, y - 40, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, x + 80, y - 33, &null, &null, Camera);

                if (ModuleDistance (x + 75 - Camera->x, y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
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
                DrawTransparentImage (&AllImage.Stone, x + 50, y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, x + 80, y - 33, &null, &one, Camera);

                if (ModuleDistance (x + 75 - Camera->x, y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
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
                DrawTransparentImage (&AllImage.Arrow, x + 50, y - 46, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, x + 80, y - 33, &null, &two, Camera);

                if (ModuleDistance (x + 75 - Camera->x, y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
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
                DrawTransparentImage (&AllImage.Bow, x + 120, y - 70, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, x + 150, y - 33, &null, &one, Camera);

                if (ModuleDistance (x + 145 - Camera->x, y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
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
                DrawTransparentImage (&AllImage.Apple, x + 120, y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, x + 150, y - 33, &null, &two, Camera);

                if (ModuleDistance (x + 145 - Camera->x, y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
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
                DrawTransparentImage (&AllImage.Coin, x + 130, y - 53, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, x + 150, y - 33, &null, &null, Camera);

                if (ModuleDistance (x + 145 - Camera->x, y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
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

            if (x > Man->x)
                vX = -10;

            if (x < Man->x)
                vX = 10;

            x += vX;

            int null = 0;
            int one = 1;

            if (vX > 0)
                DrawTransparentImage (&AllImage.Gun, x, y + 88, &null, &one, Camera);

            if (vX < 0)
                DrawTransparentImage (&AllImage.Gun, x, y + 88, &one, &one, Camera);

            if (ModuleDistance (Man->x + 47, Man->y + 84, x,  y + 88, 30) == true)
                {
                Position = 0;
                };
            };
        }; */

    // Fighting:

    if (ModuleDistance (x + 50 - Camera->x, y + 84 - Camera->y , txMouseX(), txMouseY(), 50) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
        Man->Inventory.MainNumber == 2 &&
        Man->Inventory.MainSlot > 0 &&
        Man->ArmSpeed >= 10)
        {
        Health -= 2;
        vY = -15;
        if (x > Man->x)
            vX = 50;
        if (x < Man->x)
            vX = -50;
        // Animation.xFrame += 1;
        // txCircle (Man->x - Camera->x, Man->y - Camera->y, 50);
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

    if (fabs (Man->ArrowX - x) <= 200 &&
        fabs (Man->ArrowY - y) <= 80 &&
        Health > 0 &&
        Man->ArrowVX != 0 &&
        Man->Inventory.Arrow > 0)
        {
        vY = -15;
        if (x > Man->x)
            vX = 50;
        if (x < Man->x)
            vX = -50;
        Health -= 5;
        Man->Inventory.Arrow -= 1;
        Man->ArrowVX = 0;
        Man->ArrowVY = 0;
        Man->ArrowX  = Man->x;
        Man->ArrowY  = Man->y;
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
        if (Man->x - x > 50 &&
            Man->x - x < 500)
            vX = Inventory.Rope;

        if (Man->x - x < 50 &&
            Man->x - x > 0)
            {
            vX = 0;
            };

        if (x - Man->x > 50 &&
            x - Man->x < 500)
            vX = -Inventory.Rope;

        if (x - Man->x < 50 &&
            x - Man->x > 0)
            {
            vX = 0;
            };

        // Fighting
        ArmSpeed += 1;

        if (ArmSpeed >= 10 &&
            vX == 0 &&
            fabs (Man->x - x) <= 100)
            {
            Man->Health -= 1;
            Man->vY = -15;
            if (Man->x > x)
                Man->vX = 50;
            if (Man->x < x)
                Man->vX = -50;
            // Man->Animation.xFrame += 1;
            // txCircle (Man->x - Camera->x, Man->y - Camera->y, 50);
            ArmSpeed = 0;
            };

        };

    // Bandit
    if (Kind == MT_Bandit &&
        Health > 0)
        {
        if (Man->x > x)
            vX = 10;

        if (Man->x < x)
            vX = -10;

        /* if (Animation.yFrame == 0 &&
            vX == 0)
            Animation.yFrame = 2;

        if (Animation.yFrame == 1 &&
            vX == 0)
            Animation.yFrame = 3; */

        if (fabs (Man->x - x) <= 200)
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
            ArrowX = x;
            ArrowY = y;

            if (Man->x > x)
            ArrowVX =  100;
            if (Man->x < x)
            ArrowVX = -100;

            // xWeapon = 1;
            ArmSpeed = 0;
            };

        if (fabs (ArrowX - Man->x) <= 200 &&
            fabs (ArrowY - Man->y) <= 80)
            {
            Man->Health -= 1;
            Man->vY = -15;
            if (x > Man->x)
                Man->vX = -50;
            if (x < Man->x)
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
        y = 687;

        if (ModuleDistance (x + 130 - Camera->x, y + 15 - Camera->y , txMouseX(), txMouseY(), 100) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            {
            Man->Position = Boat_Position;
            };
        };

    if (Man->Position == Boat_Position &&
        Kind == MT_Boat)
        {
        Man->x = x + 80;
        Man->y = y - 135;
        Man->vX = 0;
        Man->vY = 0;

        if (GetAsyncKeyState (VK_LEFT))
            vX = -20;

        if (GetAsyncKeyState (VK_RIGHT) &&
            x <= -300)
            vX = 20;

        if (GetAsyncKeyState (VK_UP))
            Man->Position = Normal_Position;
        };

    // Fish
    if (Kind == MT_Fish &&
        Health > 0)
        {
        if (y < 720)
            y = 720;

        if (Man->Inventory.MainNumber == 8 &&
            Man->Inventory.MainSlot > 0)
            {
            if (Man->x + 55 > x)
                vX = 4;
            if (Man->x + 55 < x)
                vX = -4;

            if (y >= 720)
                vY = -2;
            else
                vY = 0;

            if (ModuleDistance (Man->x + 55, Man->y + 85, x+25, y+10, 100) == true)
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
        x = rand() % 11400 * World_Size;
        y = -500;
        };

    if (Man->Days % 3 == 0 &&
        Man->Time == 0 &&
        Kind == MT_Seller)
        {
        Health = 20;
        x = rand() % 11400 * World_Size;
        y = -500;
        };

    if (Man->Days % 3 == 0 &&
        Man->Time == 0 &&
        Kind == MT_Fish)
        {
        Health = 20;
        x = -rand() % 700 - 100;
        y = 750 + rand() % 100;
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
        y = -1000;
        x = 100;
        };

    if (GetAsyncKeyState (VK_END))
        {
        y = -1000;
        x = 11400;
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
                ArrowX  = x;
                ArrowY  = y;
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
                ArrowX  = x;
                ArrowY  = y;
                }
            else
                xWeapon = 1;
            };

    // printf ("x = %lf, y = %lf \n", x, y);
    };

void ManType :: Physic ()
    {
    x += vX;
    y += vY;

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
    if (y >= 620)
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
        y = 687;
        };
    // printf ("Days = %d \n", Days);

    if (Kind != MT_Boat &&
        Kind != 0 &&
        x >= -160 &&
        x <= 190*11400*World_Size)
        {
        if (y >= 700 - GRGetExtentY(Animation.Picture->Picture)/Animation.Picture->yMaxAnimationNumber + Inventory.Arrow &&
            vY > 0)
            {
            // y = 500;
            vY = 0;
            };

        if (y >= 700 - GRGetExtentY(Animation.Picture->Picture)/Animation.Picture->yMaxAnimationNumber + Inventory.Arrow)
            {
            y = 700 - GRGetExtentY(Animation.Picture->Picture)/Animation.Picture->yMaxAnimationNumber + Inventory.Arrow;
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

void ManType :: BlockCollision (BlockType* Block, CamType* Camera, AllImageType AllImage)
    {
    int null = 0;
    int two = 2;
    int three = 3;
    int four = 4;

    // FallingTree
    if (Block->Number == BT_FallingTree)
        {
        if (fabs (Block->x + Block_BaseWide - x) <= Block_BaseWide + Man_Wide + 200 &&
            ModuleDistance (Block->x + 90 - Camera->x, Block->y + 50 - Camera->y , txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Block->Health > 0)
            {
            Inventory.Wood += 2;
            Block->Health = 0;
            if (HelpSystem.Number == 0)
                HelpSystem.Number = 1;
            };
        };

    if (Block->Number == BT_SmallStone)
        {
        if (fabs (Block->x + Block_BaseWide - x) <= Block_BaseWide + Man_Wide + 200 &&
            ModuleDistance (Block->x + 15 - Camera->x, Block->y + 50 - Camera->y , txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Block->Health > 0)
            {
            Inventory.Stone += 1;
            Block->Health = 0;
            if (HelpSystem.Number == 1)
                HelpSystem.Number = 2;
            };
        };

    // Rock
    if (Block->Number == BT_Rock)
    {
    if (Inventory.MainNumber == 0 &&
        Inventory.MainSlot > 0 &&
        fabs (Block->x + Block_BaseWide - x) <= Block_BaseWide + Man_Wide + 200 &&
        ModuleDistance (Block->x + 90 - Camera->x, Block->y + 50 - Camera->y , txMouseX(), txMouseY(), 50) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
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
            fabs (Block->x - x) <= 200)
        Temperature += 0.025;
        };

        if (Block->Health > 3 &&
            Block->Health <= 6)
            {
        Block->Animation.yFrame = 1;
        if (Temperature < 32 &&
            fabs (Block->x - x) <= 200)
        Temperature += 0.05;
        };

        if (Block->Health > 6 &&
            fabs (Block->x - x) <= 200)
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

        if (Inventory.MainNumber == 1 &&
            Inventory.MainSlot > 0 &&
            ModuleDistance (Block->x + 30 - Camera->x, Block->y + 30 - Camera->y, txMouseX(), txMouseY(), 100) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Block->Health <= 6 &&
            Block->Health > 0)
            {
            Inventory.Wood -= 1;
            Block->Health += 3;
            if (HelpSystem.Number == 5)
                HelpSystem.Number = 6;
            };

        if (Inventory.MainNumber == 9 &&
            Inventory.MainSlot > 0 &&
            ModuleDistance (Block->x + 30 - Camera->x, Block->y + 30 - Camera->y, txMouseX(), txMouseY(), 100) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Block->Health >= 3)
            {
            Inventory.Fish -= 1;
            Inventory.CookedFish += 1;
            Block->Health -= 3;
            };

        if (fabs (x - Block->x) <= 200)
            {
            if (HelpSystem.Number == 4)
                HelpSystem.Number = 5;
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
    if (fabs (Block->x + 150 - x) <= Man_Wide + 40 &&
        Block->Number == BT_House &&
        Position != House_Position &&
        Kind == 0)
        {
        DrawTransparentImage (&AllImage.Pause, Block->x + 180, Block->y + 100, &null, &two, Camera);
        if (ModuleDistance (Block->x + 180 - Camera->x, Block->y + 100 - Camera->y ,
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
        Block->Animation.yFrame = 0;

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

    if (y >= 10000)
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

        if (Inventory.MainNumber == 0 &&
            Inventory.MainSlot > 0 &&
            fabs (Block->x + Block_BaseWide - x) <= Block_BaseWide + Man_Wide + 100 &&
            ModuleDistance (Block->x + 140 - Camera->x, Block->y + 215 - Camera->y , txMouseX(), txMouseY(), 140) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
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
            if (HelpSystem.Number == 3)
                HelpSystem.Number = 4;
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

    //-----------------------------------------------------------------------------

    if (Block->Number != BT_Coin)
    {

    // Physic
    if (Block->Health  >= 1 &&
        Block->Number != BT_Fire &&
        Block->Number != BT_Water &&
        Block->Number != BT_Stalactite &&
        Block->Number != BT_BonFire &&
        Block->Number != BT_Air &&
        Block->Number != BT_Tree &&
        Block->Number < BT_Pickaxe)
    {
    if (fabs (Block->x + Block_BaseWide - x) <= Block_BaseWide + Man_Wide &&
        Block->y + Block_BaseHigh - y <= Block_BaseHigh + GRGetExtentY (Animation.Picture->Picture) / Animation.Picture->yMaxAnimationNumber &&
        Block->y + Block_BaseHigh - y  >=  0)
            {
            if (GetAsyncKeyState (VK_UP) &&
                Kind == MT_Main)
                {
                vY = -Man_JumpSpeed;
                };

            if (vY > 0)
                {
                vY = 0;
                y = Block->y - Man_High;
                };
            };

    // Walls
    if (Block->Health  >= 1 &&
        Block->Number != BT_Fire &&
        Block->Number != BT_Water &&
        Block->Number != BT_Stalactite &&
        Block->Number < BT_Pickaxe)
            {
            if (fabs (Block->x + Block_BaseWide - x) <= Block_BaseWide + Man_Wide &&
                Block->y + Block_BaseHigh > y &&
                Block->y < y + Man_High)
                {
                if (Block->x <= x + Man_Wide &&
                    vX > 0)
                        vX = 0;

                if (Block->x + Block_BaseWide >= x &&
                    vX < 0)
                        vX = 0;
                };
            };
        };
    };
    };



//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------

void DrawLevelPeople (ManType Villagers[], CamType* Camera, AllImageType AllImage)
    {
    int i = 0;

    while (Villagers[i].x != -1 && Villagers[i].y != -1)
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

    while (Villagers[i].x != -1 && Villagers[i].y != -1)
        {
        Villagers[i].VillagerMind (Man, Camera, AllImage);
        Villagers[i].Physic ();

        i += 1;
        };
    };


