#include "BlockType.h"

bool BlockType :: Detection (ManType* Man, CamType* Camera)
    {
    if (fabs (Point.x + SizeX - Man->Point.x) <= SizeX + Man->SizeX + 200 &&
        BlockCheckClick (this, Camera) == true)
            return true;
        else
            return false;
    };

//-----------------------------------------------------------------------------

void FallingTreeType :: Interaction (ManType* Man, CamType* Camera)
    {
    if (Detection(Man, Camera) == true &&
        this->Health > 0)
        {
        Man->Inventory.Wood += 2;
        this->Health = 0;
        if (Man->HelpSystem.Number == HelpFallingTree)
            Man->HelpSystem.Number =  HelpFindStone;
        };

    Man->BlockCollision (this, Camera);
    };

//-----------------------------------------------------------------------------

void SmallStoneType :: Interaction (ManType* Man, CamType* Camera)
    {
    if (Detection(Man, Camera) == true &&
        Health > 0)
            {
            Man->Inventory.Stone += 1;
            Health = 0;
            if (Man->HelpSystem.Number == HelpFindStone)
                Man->HelpSystem.Number = HelpCrafting;
            };

    Man->BlockCollision (this, Camera);
    };

//-----------------------------------------------------------------------------

void RockType :: Interaction (ManType* Man, CamType* Camera)
    {
    if (HaveInventory (Man->Inventory.MainNumber, IT_Axe, Man->Inventory.Axe, 1) == true &&
        Man->ArmSpeed >= 10 &&
        Detection(Man, Camera) == true)
            {
            this->Health -= 10;
            this->Animation.yFrame = 1;
            Man->ArmSpeed = 0;
            }
        else
            this->Animation.yFrame = 0;

        if (this->Health <= 20 &&
            this->Health > 0)
            {
            Man->Inventory.Stone += 3;
            this->Health = 0;
            };

    Man->BlockCollision (this, Camera);
    };

//-----------------------------------------------------------------------------

bool BonfireType :: Detection   (ManType* Man, CamType* Camera)
    {
    return true;
    };

void BonfireType :: Interaction (ManType* Man, CamType* Camera)
    {
    if (Health <= 3)
        {
        this->Animation.yFrame = 1;
        if (Man->Temperature < 10 &&
            fabs (this->Point.x - Man->Point.x) <= 200)
        Man->Temperature += 0.025;
        };

    if (this->Health > 3 &&
        this->Health <= 6)
        {
        this->Animation.yFrame = 1;
        if (Man->Temperature < 32 &&
            fabs (this->Point.x - Man->Point.x) <= 200)
        Man->Temperature += 0.05;
        };

    if (this->Health > 6 &&
        fabs (this->Point.x - Man->Point.x) <= 200)
        {
        this->Animation.yFrame = 0;
        if (Man->Temperature < 36.6)
            Man->Temperature += 0.1;
        };

    if (this->Health >= 1)
        {
        if (Man->Days >= 0 &&
            Man->Days < 10)
            this->Health -= 0.0025;

        if (Man->Days >= 10 &&
            Man->Days < 20)
            this->Health -= 0.025;

        if (Man->Days >= 20 &&
            Man->Days < 30)
            this->Health -= 0.0025;

        if (Man->Days >= 30 &&
            Man->Days < 40)
            this->Health -= 0.0012;
        };

    if (HaveInventory (Man->Inventory.MainNumber, IT_Wood, Man->Inventory.Wood, 1) == true &&
        // ModuleDistance (this->x + 30 - Camera->Point.x, this->y + 30 - Camera->Point.y, txMouseX(), txMouseY(), 100) == true &&
        BlockCheckClick (this, Camera) == true &&
        this->Health <= 6 &&
        this->Health > 0)
        {
        Man->Inventory.Wood -= 1;
        this->Health += 3;
        if (Man->HelpSystem.Number == HelpAddWood)
            Man->HelpSystem.Number = HelpWarmBonfire;
        };

    if (HaveInventory (Man->Inventory.MainNumber, IT_Fish, Man->Inventory.Fish, 1) == true &&
        BlockCheckClick (this, Camera) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
        this->Health >= 3)
        {
        Man->Inventory.Fish -= 1;
        Man->Inventory.CookedFish += 1;
        this->Health -= 3;
        };

    if (fabs (Man->Point.x - this->Point.x) <= 200)
        {
        if (Man->HelpSystem.Number == HelpFindBonfire)
            Man->HelpSystem.Number = HelpAddWood;
        };
    };

//-----------------------------------------------------------------------------

bool AirType :: Detection   (ManType* Man, CamType* Camera)
    {
    return true;
    };

void AirType :: Interaction (ManType* Man, CamType* Camera)
    {
    };

//-----------------------------------------------------------------------------

bool TreeType :: Detection   (ManType* Man, CamType* Camera)
    {
    if (BlockCheckClick (this, Camera) == true)
        return true;

    return false;
    };

void TreeType :: Interaction (ManType* Man, CamType* Camera)
    {
    // Text ({Point.x + 10 - Camera->Point.x, Point.y - 10 - Camera->Point.y}, 40, Health, "Health = ");

    if (HaveInventory (Man->Inventory.MainNumber, IT_Axe, Man->Inventory.Axe, 1) == true &&
        Detection(Man, Camera) == true &&
        Man->ArmSpeed >= 10 &&
        this->Health > 2)
        {
        Man->ArmSpeed = 0;
        this->Health -= 10;
        // Man->Inventory.Wood += 2;
        // this->Animation.yFrame += 4;
        };

    if (this->Health <= 12 &&
        this->Health > 0)
        {
        Man->Inventory.Wood += 2;
        if (Man->Days >= 30 &&
            Man->Days < 40)
            Man->Inventory.Apple += 1;
        if (Man->HelpSystem.Number == HelpDestroyTree)
            Man->HelpSystem.Number = HelpFindBonfire;
        this->Health = -88;
        };

    if (this->Health < 0 &&
        this->Health >= -88)
        {
        this->Health += 0.5;
        // this->Animation.yFrame = 8;
        };

    if (this->Health == 0)
        this->Health = 100;
    };

//-----------------------------------------------------------------------------

void DynamiteType :: Interaction (ManType* Man, CamType* Camera)
    {
    // AnimationType Explosion = {};

    int null = 0;

        if (this->Health > 0 &&
            Detection(Man, Camera) == true)
            this->Health = 80;

        if (this->Health <= 80 &&
            this->Health > 0)
            {
            this->Health -= 5;
            this->Animation.yFrame = 1;
            };

        int ExplosionFrame = -this->Health;

        if (this->Health <= 0 &&
            this->Health > -6)
            {
            DrawTransparentImage (GlobalAllImage.Explosion, this->Point.x - 315, this->Point.y - 315, &ExplosionFrame, &null, Camera);

            this->Health -= 1;
            }

    // Man->BlockCollision (this, Camera);
    };

//-----------------------------------------------------------------------------

void CaseType :: Interaction (ManType* Man, CamType* Camera)
    {
    int null = 0;
    int one  = 1;
    int two  = 2;

    int MouseSpeed = 0;

    /* if (GetAsyncKeyState (VK_LBUTTON))
        MouseSpeed = 1;
    else
        MouseSpeed = 0;

    if (Detection(Man, Camera) == true &&
        MouseSpeed == 0 &&
        this->Animation.yFrame == 0)
        {
        this->Animation.yFrame = 1;
        };

    if (this->Animation.yFrame == 1 &&
        Detection(Man, Camera) == true &&
        MouseSpeed == 0)
        {
        if (this->Health == IT_Apple)
            {
            DrawTransparentImage (GlobalAllImage.Apple, this->Point.x + 65, this->Point.y + 86, &null, &null, Camera);

            if (BlockCheckClick (this, Camera) == true)
                {
                Man->Inventory.Apple += 1;
                this->Health = 1;
                };
            };
        }; */

    if (BlockCheckClick (this, Camera) == true)
        {
        Number = BT_Opened_Case;
        };

    if (Number == BT_Opened_Case)
        {
        if (Health == 11)
            {
            // take
            DrawTransparentImage (GlobalAllImage.Take_close, this->Point.x + SizeX - 90, this->Point.y - 50, &null, &null, Camera);

            DrawTransparentImage (GlobalAllImage.Apple, this->Point.x + 107, this->Point.y + 70, &null, &null, Camera);

            if (RectCheckClick (this->Point.x + SizeX - 90, this->Point.y - 50, this->Point.x + SizeX - 90 + 84, this->Point.y - 50 + 40, Camera) == true)
                {
                Man->Inventory.Apple += 1;
                Number = BT_Close_Case;
                Health = 10;
                };
            };

        if (Health == 12)
            {
            // take
            DrawTransparentImage (GlobalAllImage.Take_close, this->Point.x + SizeX - 90, this->Point.y - 50, &null, &null, Camera);

            DrawTransparentImage (GlobalAllImage.Gun, this->Point.x + 107, this->Point.y + 62, &null, &null, Camera);

            if (RectCheckClick (this->Point.x + SizeX - 90, this->Point.y - 50, this->Point.x + SizeX - 90 + 84, this->Point.y - 50 + 40, Camera) == true)
                {
                Man->Inventory.Gun += 1;
                Number = BT_Close_Case;
                Health = 10;
                };
            };

        if (Health == 10)
            {
            // grey
            DrawTransparentImage (GlobalAllImage.Take_close, this->Point.x + SizeX - 90, this->Point.y - 50, &null, &two, Camera);
            };

        // close
        DrawTransparentImage (GlobalAllImage.Take_close, this->Point.x + SizeX + 27, this->Point.y - 50, &null, &one, Camera);

        if (RectCheckClick (this->Point.x + SizeX + 27, this->Point.y - 50, this->Point.x + SizeX + 27 + 84, this->Point.y - 50 + 40, Camera) == true)
            {
            Number = BT_Close_Case;
            };

        Animation.yFrame = 1;
        }
    else
        Animation.yFrame = 0;

    // Man->BlockCollision (this, Camera);
    };

//-----------------------------------------------------------------------------

void DirtType :: Interaction (ManType* Man, CamType* Camera)
    {
    Man->BlockCollision (this, Camera);
    };

//-----------------------------------------------------------------------------

bool StairsType :: Detection (ManType* Man, CamType* Camera)
    {
    if (fabs (Man->Point.x + Man->SizeX/2 - Point.x - SizeX/2) < Man->SizeX + SizeX)
        return true;

    return false;
    };

void StairsType :: Interaction (ManType* Man, CamType* Camera)
    {
    // Man->BlockCollision (this, Camera);

    int null = 0;
    int one  = 1;

    if (Detection (Man, Camera) == true &&
        Man->Point.y < Point.y &&
        Man->Position != Climbing_Position &&
        Man->Position != ClimbDown_Position)
        {
        /* DrawTransparentImage (GlobalAllImage.Up_down, this->Point.x + 35, this->Point.y - 100, &null, &one, Camera);

        if (RectCheckClick (this->Point.x + 35, this->Point.y - 100, this->Point.x + 135, this->Point.y + 32, Camera) == true)
            Man->Point.y = Point.y + 60; */

        if (GetAsyncKeyState (VK_DOWN))
            {
            Man->Point.y = Point.y - 70;
            Man->Position = ClimbDown_Position;
            };
        };

    if (Detection (Man, Camera) == true &&
        Man->Point.y > Point.y &&
        Man->Position != Climbing_Position &&
        Man->Position != ClimbDown_Position)
        {
        // DrawTransparentImage (GlobalAllImage.Up_down, this->Point.x + 35, this->Point.y + 200, &null, &null, Camera);

        /* if (RectCheckClick (this->Point.x + 35, this->Point.y + 200, this->Point.x + 135, this->Point.y + 332, Camera) == true)
            {
            Man->Position = Climbing_Position;
            };
            //Man->Point.y = Point.y - 240; */

        if (GetAsyncKeyState (VK_UP))
            Man->Position = Climbing_Position;
        };

    if (Detection (Man, Camera) == true &&
        Man->Position == Climbing_Position)
            {
            Man->Speed.x = 0;
            Man->Point.x = Point.x + 30;

            if (Man->Point.y < Point.y - 200)
                Man->Position = Normal_Position;
            };

    if (Detection (Man, Camera) == true &&
        Man->Position == ClimbDown_Position)
            {
            Man->Speed.x = 0;
            Man->Point.x = Point.x + 30;

            if (Man->Point.y > Point.y + 200)
                Man->Position = Normal_Position;
            };

    /* if (Detection (Man, Camera) == true &&
        Man->Point.y < Point.y)
        {
        DrawTransparentImage (GlobalAllImage.Up_down, this->Point.x + 35, this->Point.y - 100, &null, &one, Camera);

        if (RectCheckClick (this->Point.x + 35, this->Point.y - 100, this->Point.x + 135, this->Point.y + 32, Camera) == true)
            Man->Point.y = Point.y + 60;
        };

    int xCollision = 0;
    int yCollision = 0;

    if (Detection (Man, Camera) == true)
        xCollision = true;
    else
        xCollision = false;

    if (Man->Point.y + Man->SizeY > Point.y &&
        Man->Point.y > Point.y)
        yCollision = true;
    else
        yCollision = false;

    if (xCollision == true &&
        yCollision == true)
        {
        DrawTransparentImage (GlobalAllImage.Up_down, this->Point.x + 35, this->Point.y + 200, &null, &null, Camera);

        // if (RectCheckClick (this->Point.x + 35, this->Point.y + 200, this->Point.x + 135, this->Point.y + 332, Camera) == true)
        //     Man->Position = Climbing_Position;
            //Man->Point.y = Point.y - 240;

        if (GetAsyncKeyState (VK_UP))
            Man->Position = Climbing_Position;
        };

    if (xCollision != yCollision &&
        Man->Position == Climbing_Position)
        Man->Position = Normal_Position;

    // else if (Man->Position == Climbing_Position)
    //          Man->Position = Normal_Position; */


    /* if (Man->Point.y < Point.y &&
        Detection(Man, Camera) == true &&
        GetAsyncKeyState (VK_DOWN))
        Man->Point.y = Point.y + 60;

    if (Man->Point.y > Point.y &&
        Detection(Man, Camera) == true &&
        GetAsyncKeyState (VK_UP))
        Man->Point.y = Point.y - 240; */
    };

//-----------------------------------------------------------------------------

bool DoorType :: Detection (ManType* Man, CamType* Camera)
    {
    if (BlockCheckClick (this, Camera) == true)
        return true;

    return false;
    };

void DoorType :: Interaction (ManType* Man, CamType* Camera)
    {
    // Man->BlockCollision (this, Camera);

    int null = 0;
    int one  = 1;

    /* if (Detection (Man, Camera) == true &&
        Health > 10)
        Health -= 10;
    else if (Health < 50)
             Health += 1;

    if (Health >= 10 &&
        Health < 20)
        Animation.yFrame = 3;

    if (Health >= 20 &&
        Health < 30)
        Animation.yFrame = 2;

    if (Health >= 30 &&
        Health < 40)
        Animation.yFrame = 1;

    if (Health >= 40 &&
        Health <= 50)
        Animation.yFrame = 0;  */

    if (Health >= 30 &&
        Man->Point.y > 700)
        {
        /* // Man more left than door :
        if (Man->Point.x + Man->SizeX >= Point.x - 50 &&
            Man->Point.x + Man->SizeX <= Point.x + 50 &&
            Man->Speed.x > 0)
            {
            Man->Speed.x = 0;
            Man->Point.x = Point.x - Man->SizeX;
            };

        // Man more right than door :
        if (Man->Point.x - 50 >= Point.x + SizeX &&
            Man->Point.x + 50 <= Point.x + SizeX &&
            Man->Speed.x < 0)
            {
            Man->Speed.x = 0;
            Man->Point.x = Point.x + SizeX;
            };   */

        /* if (InBorders (-50, Point.x - Man->Point.x - Man->SizeX, 0) == true &&
            Man->Speed.x > 0)
                {
                Man->Speed.x = 0;
                Man->Point.x = Point.x - Man->SizeX;
                }; */
        };
    };


//-----------------------------------------------------------------------------

bool RoomType :: Detection (ManType* Man, CamType* Camera)
    {
    if (BlockCheckClick (this, Camera) == true)
        return true;

    return false;
    };

void RoomType :: Interaction (ManType* Man, CamType* Camera)
    {
    // Man->BlockCollision (this, Camera);

    int null = 0;
    int one  = 1;

    if (Health == 1 &&
        RectAiming (Point.x, Point.y, Point.x + SizeX, Point.y + SizeY, Camera) == true)
        {
        // DrawTransparentImage (&GlobalAllImage.OrangeButton, Point.x + 265, Point.y + 45, &null, &null, Camera);
        };

    // if (Detection ()
    };

