#include "BlockType.h"


BlockType :: BlockType (double _x, double _y, double _Health, AnimationType _Animation,
               int _Number) :
    BaseType (_x, _y, _Health, _Animation),
    Number (_Number)
    {
    };

void BlockType :: DrawBlock (CamType* Camera, AllImageType AllImage)
    {
    IncreaseAnimationNumber (&Animation);

    if (Health > 0)
        DrawTransparentImage (Animation.Picture, x + 50, y, &Animation.xFrame, &Animation.yFrame, Camera);
    };

void CreateBlocks (BlockType Blocks [], AllImageType AllImage)
    {
    int i = 0;

    int x = 0;

    while (Blocks[i].x != -1 && Blocks[i].y != -1)
        {
        // printf ("i = %d \n", i);

        // int Type = 0;

        if (i < 19*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Air;
            Blocks[i].x = x*604;
            Blocks[i].y = 500;
            Blocks[i].Animation.Picture = &AllImage.BackGround;
            };

        if (i == 19*World_Size)
            x = 0;

        if (i <= 79*World_Size &&
            i >= 19*World_Size)
            {
            Blocks[i].Health = 10;
            Blocks[i].Number = BT_Dirt;
            Blocks[i].x = x*190;
            Blocks[i].y = 700;
            Blocks[i].Animation.Picture = &AllImage.Grass;
            };

        if (i > 79*World_Size &&
            i <= 95*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Tree;
            Blocks[i].x = (rand() % 60*World_Size)*200;
            Blocks[i].y = 415;
            Blocks[i].Animation.Picture = &AllImage.Tree;
            };

        if (i > 95*World_Size &&
            i <= 99*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_FallingTree;
            Blocks[i].x = (rand() % 60*World_Size)*200;
            Blocks[i].y = 627;
            Blocks[i].Animation.Picture = &AllImage.FallingTree;
            };

        if (i > 99*World_Size &&
            i <= 105*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_Rock;
            Blocks[i].x = (rand() % 6*World_Size)*2000;
            Blocks[i].y = 577;
            Blocks[i].Animation.Picture = &AllImage.Rock;
            };

        if (i > 105*World_Size &&
            i <= 109*World_Size)
            {
            Blocks[i].Health = 100;
            Blocks[i].Number = BT_SmallStone;
            Blocks[i].x = (rand() % 6*World_Size)*2000;
            Blocks[i].y = 658;
            Blocks[i].Animation.Picture = &AllImage.Stone;
            };

        if (i > 109*World_Size &&
            i <= 110*World_Size)
            {
            Blocks[i].Health = 6;
            Blocks[i].Number = BT_BonFire;
            Blocks[i].x = rand() % 11000*World_Size;
            Blocks[i].y = 633;
            Blocks[i].Animation.Picture = &AllImage.BonFire;
            };

        if (i == 110*World_Size + 1)
            {
            Blocks[i].Health = 6;
            Blocks[i].Number = BT_Dirt;
            Blocks[i].x = -140;
            Blocks[i].y = 700;
            Blocks[i].Animation.Picture = &AllImage.Bridge;
            };

        if (i == 110*World_Size + 2)
            {
            Blocks[i].Health = 6;
            Blocks[i].Number = BT_Dirt;
            Blocks[i].x = 11400*World_Size;
            Blocks[i].y = 700;
            Blocks[i].Animation.Picture = &AllImage.Bridge;
            };

        if (i > 110*World_Size + 2)
            {
            Blocks[i].Health = 0;
            };

        x += 1;

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

    while (ManyBlocks[i].x != -1 && ManyBlocks[i].y != -1)
        {
        ManyBlocks [i].DrawBlock (Camera, AllImage);

        i = i + 1;
        };
    };

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man, CamType* Camera, int* NumberCoin, AllImageType AllImage)
    {
    int i = 0;

    while (ManyBlocks[i].x != -1 && ManyBlocks[i].y != -1)
        {
        Man->BlockCollision (&ManyBlocks [i], Camera, AllImage);

        CoinCollision (Man, &ManyBlocks [i], NumberCoin);

        i = i + 1;
        };
    };

void BlockCalling (BlockType* Block, ManType* Man, CamType* Camera)
    {
    // BlockCollision (Man, Block, Camera);
    };



