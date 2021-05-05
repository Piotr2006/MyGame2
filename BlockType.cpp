#include "BlockType.h"

BlockType :: BlockType (PointType _Point, double _Health, AnimationType _Animation,
                        int _Number, void (*_Function) (ManType* Man, BlockType* Block, CamType* Camera)) :
    BaseType (_Point, _Health, _Animation),
    Number (_Number),
    Function (_Function)
    {
    };

BlockType :: BlockType () :
    BaseType (),
    Number (BT_BlackSpace),
    Function (AirInteraction)
    {
    };

TreeType :: TreeType (PointType _Point, double _Health, AnimationType _Animation,
                      int _Number, void (*_Function) (ManType* Man, BlockType* Block, CamType* Camera)) :
    BlockType (_Point, _Health, _Animation, _Number, _Function)
    {};

void BlockType :: DrawBlock (CamType* Camera)
    {
    IncreaseAnimationNumber (&Animation);

    if (Health > 0 &&
        Number != BT_BlackSpace)
        DrawTransparentImage (*Animation.Picture, Point.x + 50, Point.y, &Animation.xFrame, &Animation.yFrame, Camera);
    };

void BlockFunction (BlockType* Blocks [], int Time)
    {
    for (int i = 0; i < Blocks_Number; i ++)
        {
        printf ("BlockFunction() : Time = %d, i = %d, Blocks[i] = %p \n", Time, i, Blocks[i]);

        // Blocks[i]->Point.x = Blocks[i]->Point.x;
        };
    };

void CreateBlocks (BlockType* Blocks [])
    {
    // int i = 0;

    int X = 0;

    int Kind = 0;

    for (int i = 0; i < Blocks_Number; i ++)
        {
        // BlockFunction (Blocks, i);

        Kind = rand() % 100;

        // printf ("CreateBlocks() : i = %d, Blocks[i] = %p \n", i, Blocks[i]);

        // int Type = 0;

        /* if (i < 19*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_Air;
            Blocks[i]->Point.x = X*984;
            Blocks[i]->Point.y = 572;
            Blocks[i]->Animation.Picture = &AllImage.BackGround;
            };

        if (i == 19*World_Size)
            X = 0;

        if (i <= 79*World_Size &&
            i >= 19*World_Size)
            {
            Blocks[i]->Health = 10;
            Blocks[i]->Point.x = X*328;
            Blocks[i]->Point.y = 700;
            if (Kind > 2)
                {
                Blocks[i]->Number = BT_Dirt;
                Blocks[i]->Animation.Picture = &AllImage.Grass;
                }
            else
                {
                Blocks[i]->Number = BT_Wall;
                Blocks[i]->Animation.Picture = &AllImage.MineEntrance;
                };
            };

        if (i == 80*World_Size)
            X = 0;

        if (i <= 90*World_Size &&
            i > 79*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_Wall;
            Blocks[i]->Point.x = X*1150;
            Blocks[i]->Point.y = 1108;
            Blocks[i]->Animation.Picture = &AllImage.StoneWall;
            };

        if (i == 91*World_Size)
            X = 0;

        if (i <= 101*World_Size &&
            i >= 91*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_Floor;
            Blocks[i]->Point.x = X*1150;
            Blocks[i]->Point.y = 2308;
            Blocks[i]->Animation.Picture = &AllImage.StoneFloor;
            };

        if (i > 101*World_Size &&
            i <= 116*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_Tree;
            Blocks[i]->Point.x = (rand() % 600*World_Size)*20;
            Blocks[i]->Point.y = 272;
            Blocks[i]->Animation.Picture = &AllImage.Tree;
            };

        if (i > 116*World_Size &&
            i <= 120*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_FallingTree;
            Blocks[i]->Point.x = (rand() % 12000*World_Size);
            Blocks[i]->Point.y = 627;
            Blocks[i]->Animation.Picture = &AllImage.FallingTree;
            };

        if (i > 120*World_Size &&
            i <= 126*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_Rock;
            Blocks[i]->Point.x = (rand() % 6000*World_Size)*2;
            Blocks[i]->Point.y = 577;
            Blocks[i]->Animation.Picture = &AllImage.Rock;
            };

        if (i > 126*World_Size &&
            i <= 130*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_SmallStone;
            Blocks[i]->Point.x = (rand() % 12000*World_Size);
            Blocks[i]->Point.y = 662;
            Blocks[i]->Animation.Picture = &AllImage.Stone;
            };

        if (i > 130*World_Size &&
            i <= 131*World_Size)
            {
            Blocks[i]->Health = 6;
            Blocks[i]->Number = BT_BonFire;
            Blocks[i]->Point.x = rand() % 11000*World_Size;
            Blocks[i]->Point.y = 633;
            Blocks[i]->Animation.Picture = &AllImage.BonFire;
            };

        if (i == 131*World_Size + 1)
            {
            Blocks[i]->Health = 6;
            Blocks[i]->Number = BT_Dirt;
            Blocks[i]->Point.x = 700;
            Blocks[i]->Point.y = 310;
            Blocks[i]->Animation.Picture = &AllImage.Fence;
            };

        if (i == 131*World_Size + 2)
            {
            Blocks[i]->Health = 6;
            Blocks[i]->Number = BT_Dirt;
            Blocks[i]->Point.x = 11400*World_Size - 700;
            Blocks[i]->Point.y = 310;
            Blocks[i]->Animation.Picture = &AllImage.Fence;
            };

        if (i >= 131*World_Size + 3 &&
            i <= 133*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_Dynamite;
            Blocks[i]->Point.x = 1000 + rand() % 11400*World_Size;
            Blocks[i]->Point.y = 2238;
            Blocks[i]->Animation.Picture = &AllImage.Dynamite;
            };
              */

        if (i < 11*World_Size)
            {
            Blocks[i]->Health = 10;
            Blocks[i]->Point.x = X*1024;
            Blocks[i]->Point.y = 20;
            Blocks[i]->Number = BT_Wall;
            Blocks[i]->Animation.Picture = &GlobalAllImage.BackGround;
            };

        if (i == 11*World_Size)
            X = 0;

        if (i >= 11*World_Size &&
            i < 73*World_Size)
            {
            Blocks[i]->Health = 10;
            Blocks[i]->Point.x = X*184;
            Blocks[i]->Point.y = 700;
            if (Kind < 6 &&
                Blocks[i - 1]->Number != BT_Wall &&
                Blocks[i - 2]->Number != BT_Wall)
                {
                Blocks[i]->Number = BT_Wall;
                Blocks[i]->Animation.Picture = &GlobalAllImage.MineEntrance;
                }
            else
                {
                Blocks[i]->Number = BT_Dirt;
                Blocks[i]->Animation.Picture = &GlobalAllImage.Grass;
                };
            };

        if (i == 73*World_Size)
            X = 0;

        if (i >= 73*World_Size &&
            i < 135*World_Size)
            {
            Blocks[i]->Health = 10;
            Blocks[i]->Point.x = X*184;
            Blocks[i]->Point.y = 816;
            if (Blocks[i - 62*World_Size]->Number == BT_Wall)
                {
                Blocks[i]->Number = BT_Wall;
                Blocks[i]->Animation.Picture = &GlobalAllImage.Stairs;
                }
            else
                {
                Blocks[i]->Number = BT_Wall;
                Blocks[i]->Animation.Picture = &GlobalAllImage.StoneWall;
                };
            };

        if (i == 135*World_Size)
            X = 0;

        if (i >= 135*World_Size &&
            i < 197*World_Size)
            {
            Blocks[i]->Health = 10;
            Blocks[i]->Point.x = X*184;
            Blocks[i]->Point.y = 1008;
            Blocks[i]->Number = BT_Dirt;
            Blocks[i]->Animation.Picture = &GlobalAllImage.StoneFloor;
            };

        if (i >= 197*World_Size &&
            i < 211*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_Tree;
            Blocks[i]->Point.x = rand() % 11400*World_Size;
            Blocks[i]->Point.y = 460;
            Blocks[i]->Animation.Picture = &GlobalAllImage.Tree;
            // Blocks[i]->Function = TreeInteraction;
            };

        if (i >= 211*World_Size &&
            i < 214*World_Size)
            {
            Blocks[i]->Health = 10;
            Blocks[i]->Number = BT_BonFire;
            Blocks[i]->Point.x = rand() % 11400*World_Size;
            Blocks[i]->Point.y = 452;
            Blocks[i]->Animation.Picture = &GlobalAllImage.BonFire;
            Blocks[i]->Function = BonfireInteraction;
            };

        if (i >= 214*World_Size &&
            i < 218*World_Size)
            {
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_Dynamite;
            Blocks[i]->Point.x = rand() % 11400*World_Size;
            Blocks[i]->Point.y = 938;
            Blocks[i]->Animation.Picture = &GlobalAllImage.Dynamite;
            Blocks[i]->Function = DynamiteInteraction;
            };

        if (i >= 218*World_Size &&
            i < 223*World_Size)
            {
            Blocks[i]->Health = IT_Apple;
            Blocks[i]->Number = BT_Case;
            Blocks[i]->Point.x = rand() % 11400*World_Size;
            Blocks[i]->Point.y = 892;
            Blocks[i]->Animation.Picture = &GlobalAllImage.HighCase;
            Blocks[i]->Function = CaseInteraction;
            };

        if (i >= 223*World_Size)
            Blocks[i]->Health = 0;

        Blocks[i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
        Blocks[i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();

        X += 1;

        // i += 1;
        };
    };


void DrawManyBlocks (BlockType* ManyBlocks [], CamType* Camera)
    {
    DrawLevelBlocks (ManyBlocks, Camera);

    // DrawLevelPeople (Villagers, Camera, AllImage);
    };

void InteractManWithBlocks (BlockType* ManyBlocks [], ManType* Man, CamType* Camera, int* NumberCoin)
    {
    CallLevelPhysic (ManyBlocks, Man, Camera);
    };

void CoinCollision (BlockType* Coin)
    {
    if (Coin->Health > 0 &&
        Coin->Number == BT_Coin)
    {
    /* if (Collision (Coin, Man) == true)
        {
        *NumberCoin += 1;
        Coin->Health = 0;
        }; */
    };
    };

void DrawLevelBlocks (BlockType* ManyBlocks[], CamType* Camera)
    {
    // int i = 0;

    // BlockFunction (ManyBlocks, 2);

    for (int i = 0; i < Blocks_Number; i ++)
        {
        // printf ("DrawLevelBlocks() : i = %d, block = %p\n", i, ManyBlocks[i]);

        // printf ("DrawLevelBlocks() : i = %d , Number = %d \n", i, ManyBlocks[i]->Number);

        ManyBlocks [i]->DrawBlock (Camera);

        // i = i + 1;
        };
    };

void CallLevelPhysic (BlockType* ManyBlocks[], ManType* Man, CamType* Camera)
    {
    // int i = 0;

    for (int i = 0; i < Blocks_Number; i ++)
        {
        if (ManyBlocks[i]->Health > 0)
            Man->BlockCollision (ManyBlocks [i], Camera);

        Man->BlockInteraction (ManyBlocks [i], Camera);

        // Man->BlockInteraction (&ManyBlocks [i], Camera, AllImage);

        // CoinCollision (Man, &ManyBlocks [i], NumberCoin);

        // i = i + 1;
        };
    };

//=============================================================================

void  FallingTreeInteraction (ManType* Man, BlockType* Block, CamType* Camera)
    {
    if (fabs (Block->Point.x + Block->SizeX - Man->Point.x) <= Block->SizeX + Man->SizeX + 200 &&
        BlockCheckClick (Block, Camera) == true &&
        Block->Health > 0)
            {
            Man->Inventory.Wood += 2;
            Block->Health = 0;
            if (Man->HelpSystem.Number == HelpFallingTree)
                Man->HelpSystem.Number = HelpFindStone;
            };
    };

void  SmallStoneInteraction (ManType* Man, BlockType* Block, CamType* Camera)
    {
    if (fabs (Block->Point.x + Block->SizeX - Man->Point.x) <= Block->SizeX + Man->SizeX + 200 &&
        BlockCheckClick (Block, Camera) == true &&
        Block->Health > 0)
            {
            Man->Inventory.Stone += 1;
            Block->Health = 0;
            if (Man->HelpSystem.Number == HelpFindStone)
                Man->HelpSystem.Number = HelpCrafting;
            };
    };

void  RockInteraction (ManType* Man, BlockType* Block, CamType* Camera)
    {
    if (Man->Inventory.MainNumber == IT_Axe &&
        Man->Inventory.Axe > 0 &&
        fabs (Block->Point.x + Block->SizeX - Man->Point.x) <= Block->SizeX + Man->SizeX + 200 &&
        BlockCheckClick (Block, Camera) == true &&
        Man->ArmSpeed >= 10)
            {
            Block->Health -= 10;
            Block->Animation.yFrame = 1;
            Man->ArmSpeed = 0;
            }
        else
            Block->Animation.yFrame = 0;

        if (Block->Health <= 20 &&
            Block->Health > 0)
            {
            Man->Inventory.Stone += 3;
            Block->Health = 0;
            };
    };

void  BonfireInteraction (ManType* Man, BlockType* Block, CamType* Camera)
    {
    if (Block->Health <= 3)
        {
        Block->Animation.yFrame = 1;
        if (Man->Temperature < 10 &&
            fabs (Block->Point.x - Man->Point.x) <= 200)
        Man->Temperature += 0.025;
        };

        if (Block->Health > 3 &&
            Block->Health <= 6)
            {
        Block->Animation.yFrame = 1;
        if (Man->Temperature < 32 &&
            fabs (Block->Point.x - Man->Point.x) <= 200)
        Man->Temperature += 0.05;
        };

        if (Block->Health > 6 &&
            fabs (Block->Point.x - Man->Point.x) <= 200)
        {
        Block->Animation.yFrame = 0;
        if (Man->Temperature < 36.6)
        Man->Temperature += 0.1;
        };

        if (Block->Health >= 1)
            {
            if (Man->Days >= 0 &&
                Man->Days < 10)
                Block->Health -= 0.0025;

            if (Man->Days >= 10 &&
                Man->Days < 20)
                Block->Health -= 0.025;

            if (Man->Days >= 20 &&
                Man->Days < 30)
                Block->Health -= 0.0025;

            if (Man->Days >= 30 &&
                Man->Days < 40)
                Block->Health -= 0.0012;
            };

        if (Man->Inventory.MainNumber == IT_Wood &&
            Man->Inventory.Wood > 0 &&
            // ModuleDistance (Block->x + 30 - Camera->Point.x, Block->y + 30 - Camera->Point.y, txMouseX(), txMouseY(), 100) == true &&
            BlockCheckClick (Block, Camera) == true &&
            Block->Health <= 6 &&
            Block->Health > 0)
            {
            Man->Inventory.Wood -= 1;
            Block->Health += 3;
            if (Man->HelpSystem.Number == HelpAddWood)
                Man->HelpSystem.Number = HelpWarmBonfire;
            };

        if (Man->Inventory.MainNumber == IT_Fish &&
            Man->Inventory.Fish > 0 &&
            BlockCheckClick (Block, Camera) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Block->Health >= 3)
            {
            Man->Inventory.Fish -= 1;
            Man->Inventory.CookedFish += 1;
            Block->Health -= 3;
            };

        if (fabs (Man->Point.x - Block->Point.x) <= 200)
            {
            if (Man->HelpSystem.Number == HelpFindBonfire)
                Man->HelpSystem.Number = HelpAddWood;
            };
    };

void  AirInteraction (ManType* Man, BlockType* Block, CamType* Camera)
    {
    };

void  TreeInteraction (ManType* Man, BlockType* Block, CamType* Camera)
    {
        if (Man->Inventory.MainNumber == IT_Axe &&
            Man->Inventory.Axe > 0 && fabs (Block->Point.x + Block->SizeX - Man->Point.x) <= Block->SizeX + Man->SizeX + 100 &&
            BlockCheckClick (Block, Camera) == true &&
            Man->ArmSpeed >= 10 &&
            Block->Health > 2)
            {
            Man->ArmSpeed = 0;
            Block->Health -= 10;
            // Block->Animation.yFrame += 4;
            };

        if (Block->Health <= 12 &&
            Block->Health > 0)
            {
            Man->Inventory.Wood += 2;
            if (Man->Days >= 30 &&
                Man->Days < 40)
                Man->Inventory.Apple += 1;
            if (Man->HelpSystem.Number == HelpDestroyTree)
                Man->HelpSystem.Number = HelpFindBonfire;
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

void  DynamiteInteraction (ManType* Man, BlockType* Block, CamType* Camera)
    {
    // AnimationType Explosion = {};

    int null = 0;

        if (Block->Health > 0 &&
            fabs (Man->Point.x + Man->SizeX/2 - Block->Point.x - Block->SizeX/2) <= 500 &&
            BlockCheckClick (Block, Camera) == true)
            Block->Health = 80;

        if (Block->Health <= 80 &&
            Block->Health > 0)
            {
            Block->Health -= 5;
            Block->Animation.yFrame = 1;
            };

        int ExplosionFrame = -Block->Health;

        if (Block->Health <= 0 &&
            Block->Health > -6)
            {
            DrawTransparentImage (GlobalAllImage.Explosion, Block->Point.x - 315, Block->Point.y - 315, &ExplosionFrame, &null, Camera);

            Block->Health -= 1;
            }
    };

void  CaseInteraction (ManType* Man, BlockType* Block, CamType* Camera)
    {
    int null = 0;

    int MouseSpeed = 0;

        if (GetAsyncKeyState (VK_LBUTTON))
            MouseSpeed = 1;
        else
            MouseSpeed = 0;

        if (BlockCheckClick (Block, Camera) == true &&
            MouseSpeed == 0 &&
            Block->Animation.yFrame == 0)
            {
            Block->Animation.yFrame = 1;
            };

        if (Block->Animation.yFrame == 1 &&
            BlockCheckClick (Block, Camera) == true &&
            MouseSpeed == 0)
            {
            if (Block->Health == IT_Apple)
                {
                DrawTransparentImage (GlobalAllImage.Apple, Block->Point.x + 65, Block->Point.y + 86, &null, &null, Camera);

                if (BlockCheckClick (Block, Camera) == true)
                    {
                    Man->Inventory.Apple += 1;
                    Block->Health = 1;
                    };
                };
            };
    };


