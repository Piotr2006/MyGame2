#include "BlockType.h"


BlockType :: BlockType (PointType _Point, double _Health, AnimationType _Animation,
               int _Number) :
    BaseType (_Point, _Health, _Animation),
    Number (_Number)
    {
    };

void BlockType :: DrawBlock (CamType* Camera, AllImageType AllImage)
    {
    IncreaseAnimationNumber (&Animation);

    if (Health > 0)
        DrawTransparentImage (*Animation.Picture, Point.x + 50, Point.y, &Animation.xFrame, &Animation.yFrame, Camera);
    };

void CreateBlocks (BlockType Blocks [], const AllImageType& AllImage)
    {
    int i = 0;

    int X = 0;

    int Kind = 0;

    while (Blocks[i].Point.x != -1 && Blocks[i].Point.y != -1)
        {
        Kind = rand() % 100;

        // printf ("i = %d \n", i);

        // int Type = 0;

        /* if (i < 19*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Air;
            Blocks[i].Point.x = X*984;
            Blocks[i].Point.y = 572;
            Blocks[i].Animation.Picture = &AllImage.BackGround;
            };

        if (i == 19*World_Size)
            X = 0;

        if (i <= 79*World_Size &&
            i >= 19*World_Size)
            {
            Blocks[i].Health = 10;
            Blocks[i].Point.x = X*328;
            Blocks[i].Point.y = 700;
            if (Kind > 2)
                {
                Blocks[i].Number = BT_Dirt;
                Blocks[i].Animation.Picture = &AllImage.Grass;
                }
            else
                {
                Blocks[i].Number = BT_Wall;
                Blocks[i].Animation.Picture = &AllImage.MineEntrance;
                };
            };

        if (i == 80*World_Size)
            X = 0;

        if (i <= 90*World_Size &&
            i > 79*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Wall;
            Blocks[i].Point.x = X*1150;
            Blocks[i].Point.y = 1108;
            Blocks[i].Animation.Picture = &AllImage.StoneWall;
            };

        if (i == 91*World_Size)
            X = 0;

        if (i <= 101*World_Size &&
            i >= 91*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Floor;
            Blocks[i].Point.x = X*1150;
            Blocks[i].Point.y = 2308;
            Blocks[i].Animation.Picture = &AllImage.StoneFloor;
            };

        if (i > 101*World_Size &&
            i <= 116*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Tree;
            Blocks[i].Point.x = (rand() % 600*World_Size)*20;
            Blocks[i].Point.y = 272;
            Blocks[i].Animation.Picture = &AllImage.Tree;
            };

        if (i > 116*World_Size &&
            i <= 120*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_FallingTree;
            Blocks[i].Point.x = (rand() % 12000*World_Size);
            Blocks[i].Point.y = 627;
            Blocks[i].Animation.Picture = &AllImage.FallingTree;
            };

        if (i > 120*World_Size &&
            i <= 126*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Rock;
            Blocks[i].Point.x = (rand() % 6000*World_Size)*2;
            Blocks[i].Point.y = 577;
            Blocks[i].Animation.Picture = &AllImage.Rock;
            };

        if (i > 126*World_Size &&
            i <= 130*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_SmallStone;
            Blocks[i].Point.x = (rand() % 12000*World_Size);
            Blocks[i].Point.y = 662;
            Blocks[i].Animation.Picture = &AllImage.Stone;
            };

        if (i > 130*World_Size &&
            i <= 131*World_Size)
            {
            Blocks[i].Health = 6;
            Blocks[i].Number = BT_BonFire;
            Blocks[i].Point.x = rand() % 11000*World_Size;
            Blocks[i].Point.y = 633;
            Blocks[i].Animation.Picture = &AllImage.BonFire;
            };

        if (i == 131*World_Size + 1)
            {
            Blocks[i].Health = 6;
            Blocks[i].Number = BT_Dirt;
            Blocks[i].Point.x = 700;
            Blocks[i].Point.y = 310;
            Blocks[i].Animation.Picture = &AllImage.Fence;
            };

        if (i == 131*World_Size + 2)
            {
            Blocks[i].Health = 6;
            Blocks[i].Number = BT_Dirt;
            Blocks[i].Point.x = 11400*World_Size - 700;
            Blocks[i].Point.y = 310;
            Blocks[i].Animation.Picture = &AllImage.Fence;
            };

        if (i >= 131*World_Size + 3 &&
            i <= 133*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Dynamite;
            Blocks[i].Point.x = 1000 + rand() % 11400*World_Size;
            Blocks[i].Point.y = 2238;
            Blocks[i].Animation.Picture = &AllImage.Dynamite;
            };
              */

        if (i < 11*World_Size)
            {
            Blocks[i].Health = 10;
            Blocks[i].Point.x = X*1024;
            Blocks[i].Point.y = 20;
            Blocks[i].Number = BT_Wall;
            Blocks[i].Animation.Picture = &AllImage.BackGround;
            };

        if (i == 11*World_Size)
            X = 0;

        if (i >= 11*World_Size &&
            i < 73*World_Size)
            {
            Blocks[i].Health = 10;
            Blocks[i].Point.x = X*184;
            Blocks[i].Point.y = 700;
            if (Kind < 6 &&
                Blocks[i - 1].Number != BT_Wall &&
                Blocks[i - 2].Number != BT_Wall)
                {
                Blocks[i].Number = BT_Wall;
                Blocks[i].Animation.Picture = &AllImage.MineEntrance;
                }
            else
                {
                Blocks[i].Number = BT_Dirt;
                Blocks[i].Animation.Picture = &AllImage.Grass;
                };
            };

        if (i == 73*World_Size)
            X = 0;

        if (i >= 73*World_Size &&
            i < 135*World_Size)
            {
            Blocks[i].Health = 10;
            Blocks[i].Point.x = X*184;
            Blocks[i].Point.y = 816;
            if (Blocks[i - 62*World_Size].Number == BT_Wall)
                {
                Blocks[i].Number = BT_Wall;
                Blocks[i].Animation.Picture = &AllImage.Stairs;
                }
            else
                {
                Blocks[i].Number = BT_Wall;
                Blocks[i].Animation.Picture = &AllImage.StoneWall;
                };
            };

        if (i == 135*World_Size)
            X = 0;

        if (i >= 135*World_Size &&
            i < 197*World_Size)
            {
            Blocks[i].Health = 10;
            Blocks[i].Point.x = X*184;
            Blocks[i].Point.y = 1008;
            Blocks[i].Number = BT_Dirt;
            Blocks[i].Animation.Picture = &AllImage.StoneFloor;
            };

        if (i >= 197*World_Size &&
            i < 211*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Tree;
            Blocks[i].Point.x = rand() % 11400*World_Size;
            Blocks[i].Point.y = 460;
            Blocks[i].Animation.Picture = &AllImage.Tree;
            };

        if (i >= 211*World_Size &&
            i < 214*World_Size)
            {
            Blocks[i].Health = 10;
            Blocks[i].Number = BT_BonFire;
            Blocks[i].Point.x = rand() % 11400*World_Size;
            Blocks[i].Point.y = 452;
            Blocks[i].Animation.Picture = &AllImage.BonFire;
            };

        if (i >= 214*World_Size &&
            i < 218*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Dynamite;
            Blocks[i].Point.x = rand() % 11400*World_Size;
            Blocks[i].Point.y = 938;
            Blocks[i].Animation.Picture = &AllImage.Dynamite;
            };

        if (i >= 218*World_Size &&
            i < 223*World_Size)
            {
            Blocks[i].Health = IT_Apple;
            Blocks[i].Number = BT_Case;
            Blocks[i].Point.x = rand() % 11400*World_Size;
            Blocks[i].Point.y = 892;
            Blocks[i].Animation.Picture = &AllImage.HighCase;
            };

        if (i >= 223*World_Size)
            Blocks[i].Health = 0;

        Blocks[i].SizeX = Blocks[i].Animation.GetFrameSizeX();
        Blocks[i].SizeY = Blocks[i].Animation.GetFrameSizeY();

        X += 1;

        i += 1;
        };
    };


void DrawManyBlocks (BlockType ManyBlocks [], CamType* Camera, const AllImageType& AllImage)
    {
    DrawLevelBlocks (ManyBlocks, Camera, AllImage);

    // DrawLevelPeople (Villagers, Camera, AllImage);
    };

void InteractManWithBlocks (BlockType ManyBlocks [], ManType* Man, CamType* Camera, int* NumberCoin,
                            int* LevelNumber, const AllImageType& AllImage)
    {
    CallLevelPhysic (ManyBlocks, Man, Camera, NumberCoin, AllImage);
    };

void CoinCollision (ManType* Man, BlockType* Coin, int* NumberCoin)
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

void DrawLevelBlocks (BlockType ManyBlocks[], CamType* Camera, const AllImageType& AllImage)
    {
    int i = 0;

    while (ManyBlocks[i].Point.x != -1 && ManyBlocks[i].Point.y != -1)
        {
        ManyBlocks [i].DrawBlock (Camera, AllImage);

        i = i + 1;
        };
    };

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man, CamType* Camera, int* NumberCoin, const AllImageType& AllImage)
    {
    int i = 0;

    while (ManyBlocks[i].Point.x != -1 && ManyBlocks[i].Point.y != -1)
        {
        if (ManyBlocks[i].Health > 0)
            Man->BlockCollision (&ManyBlocks [i], Camera, AllImage);

        // Man->BlockInteraction (&ManyBlocks [i], Camera, AllImage);

        if (ManyBlocks [i].Number == BT_FallingTree)
            Man->BlockInteraction (FallingTreeInteraction, &ManyBlocks [i], Camera, AllImage);

        if (ManyBlocks [i].Number == BT_SmallStone)
            Man->BlockInteraction (SmallStoneInteraction, &ManyBlocks [i], Camera, AllImage);

        if (ManyBlocks [i].Number == BT_Rock)
            Man->BlockInteraction (RockInteraction, &ManyBlocks [i], Camera, AllImage);

        if (ManyBlocks [i].Number == BT_BonFire)
            Man->BlockInteraction (BonFireInteraction, &ManyBlocks [i], Camera, AllImage);

        if (ManyBlocks [i].Number == BT_Tree)
            Man->BlockInteraction (TreeInteraction, &ManyBlocks [i], Camera, AllImage);

        if (ManyBlocks [i].Number == BT_Dynamite)
            Man->BlockInteraction (DynamiteInteraction, &ManyBlocks [i], Camera, AllImage);

        if (ManyBlocks [i].Number == BT_Case)
            Man->BlockInteraction (CaseInteraction, &ManyBlocks [i], Camera, AllImage);

        // CoinCollision (Man, &ManyBlocks [i], NumberCoin);

        i = i + 1;
        };
    };

void BlockCalling (BlockType* Block, ManType* Man, CamType* Camera)
    {
    // BlockCollision (Man, Block, Camera);
    };



