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
        DrawTransparentImage (Animation.Picture, Point.x + 50, Point.y, &Animation.xFrame, &Animation.yFrame, Camera);
    };

void CreateBlocks (BlockType Blocks [], AllImageType AllImage)
    {
    int i = 0;

    int X = 0;

    while (Blocks[i].Point.x != -1 && Blocks[i].Point.y != -1)
        {
        // printf ("i = %d \n", i);

        // int Type = 0;

        if (i < 19*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Air;
            Blocks[i].Point.x = X*604;
            Blocks[i].Point.y = 500;
            Blocks[i].Animation.Picture = &AllImage.BackGround;
            };

        if (i == 19*World_Size)
            X = 0;

        if (i <= 79*World_Size &&
            i >= 19*World_Size)
            {
            Blocks[i].Health = 10;
            Blocks[i].Number = BT_Dirt;
            Blocks[i].Point.x = X*190;
            Blocks[i].Point.y = 700;
            Blocks[i].Animation.Picture = &AllImage.Grass;
            };

        if (i > 79*World_Size &&
            i <= 95*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Tree;
            Blocks[i].Point.x = (rand() % 600*World_Size)*20;
            Blocks[i].Point.y = 415;
            Blocks[i].Animation.Picture = &AllImage.Tree;
            };

        if (i > 95*World_Size &&
            i <= 99*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_FallingTree;
            Blocks[i].Point.x = (rand() % 12000*World_Size);
            Blocks[i].Point.y = 627;
            Blocks[i].Animation.Picture = &AllImage.FallingTree;
            };

        if (i > 99*World_Size &&
            i <= 105*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Rock;
            Blocks[i].Point.x = (rand() % 6000*World_Size)*2;
            Blocks[i].Point.y = 577;
            Blocks[i].Animation.Picture = &AllImage.Rock;
            };

        if (i > 105*World_Size &&
            i <= 109*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_SmallStone;
            Blocks[i].Point.x = (rand() % 12000*World_Size);
            Blocks[i].Point.y = 662;
            Blocks[i].Animation.Picture = &AllImage.Stone;
            };

        if (i > 109*World_Size &&
            i <= 110*World_Size)
            {
            Blocks[i].Health = 6;
            Blocks[i].Number = BT_BonFire;
            Blocks[i].Point.x = rand() % 11000*World_Size;
            Blocks[i].Point.y = 633;
            Blocks[i].Animation.Picture = &AllImage.BonFire;
            };

        if (i == 110*World_Size + 1)
            {
            Blocks[i].Health = 6;
            Blocks[i].Number = BT_Dirt;
            Blocks[i].Point.x = 700;
            Blocks[i].Point.y = 310;
            Blocks[i].Animation.Picture = &AllImage.Fence;
            };

        if (i == 110*World_Size + 2)
            {
            Blocks[i].Health = 6;
            Blocks[i].Number = BT_Dirt;
            Blocks[i].Point.x = 11400*World_Size - 700;
            Blocks[i].Point.y = 310;
            Blocks[i].Animation.Picture = &AllImage.Fence;
            };

        if (i > 110*World_Size + 2)
            {
            Blocks[i].Health = 0;
            };

        X += 1;

        i += 1;
        };
    };


void DrawManyBlocks (BlockType ManyBlocks [], CamType* Camera, AllImageType AllImage)
    {
    DrawLevelBlocks (ManyBlocks, Camera, AllImage);

    // DrawLevelPeople (Villagers, Camera, AllImage);
    };

void InteractManWithBlocks (BlockType ManyBlocks [], ManType* Man, CamType* Camera, int* NumberCoin,
                            int* LevelNumber, AllImageType AllImage)
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

void DrawLevelBlocks (BlockType ManyBlocks[], CamType* Camera, AllImageType AllImage)
    {
    int i = 0;

    while (ManyBlocks[i].Point.x != -1 && ManyBlocks[i].Point.y != -1)
        {
        ManyBlocks [i].DrawBlock (Camera, AllImage);

        i = i + 1;
        };
    };

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man, CamType* Camera, int* NumberCoin, AllImageType AllImage)
    {
    int i = 0;

    while (ManyBlocks[i].Point.x != -1 && ManyBlocks[i].Point.y != -1)
        {
        if (ManyBlocks[i].Health > 0)
            Man->BlockCollision (&ManyBlocks [i], Camera, AllImage);

        Man->BlockInteraction (&ManyBlocks [i], Camera, AllImage);

        // CoinCollision (Man, &ManyBlocks [i], NumberCoin);

        i = i + 1;
        };
    };

void BlockCalling (BlockType* Block, ManType* Man, CamType* Camera)
    {
    // BlockCollision (Man, Block, Camera);
    };



