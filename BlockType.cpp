#include "BlockType.h"

BlockType :: BlockType (PointType _Point, double _Health, AnimationType _Animation,
                        int _Number) :
    BaseType (_Point, _Health, _Animation),
    Number (_Number)
    {
    };

BlockType :: BlockType () :
    BaseType (),
    Number (BT_BlackSpace)
    {
    };

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

void BlockType :: DrawBlock (CamType* Camera)
    {
    IncreaseAnimationNumber (&Animation);

    if (Health > 0)
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

    int Rooms [Rooms_Number] = {};

    int X = 0;

    for (int i = 0; i < Rooms_Number; i ++)
        {
        int RoomKind = rand() % 2 + 1;

        if (Rooms [i-1] != RoomKind)
            Rooms [i]    = RoomKind;
        else
            Rooms [i] = rand() % 2 + 1;
        };

    // int X = 0;

    for (int i = 0; i < 12*World_Size; i ++)
        {
        Blocks [i] = new AirType ();
        Blocks[i]->Health = 10;
        Blocks[i]->Point.x = X*1024;
        Blocks[i]->Point.y = 20;
        Blocks[i]->Animation.Picture = &GlobalAllImage.BackGround;

        X += 1;

        Blocks[i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
        Blocks[i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();

        // printf ("%d : SizeX = %lf, SizeY = %lf \n", i, Blocks[i]->SizeX,   Blocks[i]->SizeY);
        };

    X = 0;

    int nRooms = 0;

    for (int i = 12*World_Size; i < (67+12)*World_Size; i += 2)
        {
        // OutSide Blocks :
        int OutSideKind = rand () % 2 + 1;

        if (OutSideKind == 1)
            {
            // Tree :
            Blocks [i] = new TreeType ();
            Blocks [i]->Health = 100;
            Blocks [i]->Point.x = X + 112;
            Blocks [i]->Point.y = 460;
            Blocks [i]->Animation.Picture = &GlobalAllImage.Tree;
            // Bonfire :
            Blocks [i+1] = new BonfireType ();
            Blocks [i+1]->Health = 10;
            Blocks [i+1]->Point.x = X + 484;
            Blocks [i+1]->Point.y = 452;
            Blocks [i+1]->Animation.Picture = &GlobalAllImage.BonFire;
            };

        if (OutSideKind == 2)
            {
            // Tree :
            Blocks [i] = new TreeType ();
            Blocks [i]->Health = 100;
            Blocks [i]->Point.x = X + 112;
            Blocks [i]->Point.y = 460;
            Blocks [i]->Animation.Picture = &GlobalAllImage.Tree;
            // Bonfire :
            Blocks [i+1] = new TreeType ();
            Blocks [i+1]->Health = 100;
            Blocks [i+1]->Point.x = X + 484;
            Blocks [i+1]->Point.y = 460;
            Blocks [i+1]->Animation.Picture = &GlobalAllImage.Tree;
            };

        Blocks[i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
        Blocks[i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();

        Blocks[i+1]->SizeX = Blocks[i+1]->Animation.GetFrameSizeX();
        Blocks[i+1]->SizeY = Blocks[i+1]->Animation.GetFrameSizeY();
        };

    for (int i = (67+12)*World_Size; i < Blocks_Number; i += 0)
        {
        // int nI = 0;

        int nRooms = 1;

        if (nRooms == 1)
            {
            int RoomKind = rand () % 2 + 1;
            int RoomSize = rand () % 2 + 1;

            if (RoomKind == 1)
                {
                // RoomPicture :
                Blocks [i] = new RoomType ();
                Blocks [i]->Point.x = X - 24;
                Blocks [i]->Point.y = 816;
                Blocks [i]->Health = 1;
                Blocks [i]->Animation.Picture = &GlobalAllImage.Kitchen;
                Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                i += 1;
                // Dirt :
                Blocks [i] = new DirtType ();
                Blocks [i]->Point.x = X - 24;
                Blocks [i]->Point.y = 700;
                Blocks [i]->Health = 10;
                Blocks [i]->Animation.Picture = &GlobalAllImage.MineEntrance;
                Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                i += 1;
                // Stairs :
                Blocks [i] = new StairsType ();
                Blocks [i]->Point.x = X + 584;
                Blocks [i]->Point.y = 816;
                Blocks [i]->Health = 10;
                Blocks [i]->Animation.Picture = &GlobalAllImage.Stairs;
                Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                i += 1;
                // InvisibleDirt:
                Blocks [i] = new DirtType ();
                Blocks [i]->Health = 10;
                Blocks [i]->Number = BT_Close_Case;
                Blocks [i]->Point.x = X;
                Blocks [i]->Point.y = 1176;
                Blocks [i]->Animation.Picture = &GlobalAllImage.InvisibleDirt;
                Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                i += 1;

                if (RoomSize == 2)
                    {
                    // SmallRoom :
                    Blocks [i] = new RoomType ();
                    Blocks [i]->Point.x = X + 316;
                    Blocks [i]->Point.y = 816 + 360;
                    Blocks [i]->Health = 1;
                    Blocks [i]->Animation.Picture = &GlobalAllImage.SmallKitchen;
                    Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                    Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                    i += 1;

                    // Block1 :
                    Blocks [i] = new CaseType ();
                    Blocks [i]->Health = 11 + rand()%2;
                    Blocks [i]->Number = BT_Close_Case;
                    Blocks [i]->Point.x = X - 16 + 180;
                    Blocks [i]->Point.y = 1420;
                    Blocks [i]->Animation.Picture = &GlobalAllImage.Fridge;
                    Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                    Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                    i += 1;

                    // Stairs :
                    Blocks [i] = new StairsType ();
                    Blocks [i]->Point.x = X + 584;
                    Blocks [i]->Point.y = 1176;
                    Blocks [i]->Health = 10;
                    Blocks [i]->Animation.Picture = &GlobalAllImage.Stairs;
                    Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                    Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                    i += 1;
                    };
                };

            if (RoomKind == 2)
                {
                // RoomPicture :
                Blocks [i] = new RoomType ();
                Blocks [i]->Point.x = X - 24;
                Blocks [i]->Point.y = 816;
                Blocks [i]->Health = 1;
                Blocks [i]->Animation.Picture = &GlobalAllImage.Bedroom;
                Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                i += 1;
                // Dirt :
                Blocks [i] = new DirtType ();
                Blocks [i]->Point.x = X - 24;
                Blocks [i]->Point.y = 700;
                Blocks [i]->Health = 10;
                Blocks [i]->Animation.Picture = &GlobalAllImage.BigDirt;
                Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                i += 1;
                // Block1 :
                Blocks [i] = new CaseType ();
                Blocks [i]->Health = 11 + rand()%2;
                Blocks [i]->Number = BT_Close_Case;
                Blocks [i]->Point.x = X + 300;
                Blocks [i]->Point.y = 1060;
                Blocks [i]->Animation.Picture = &GlobalAllImage.Fridge;
                Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                i += 1;
                // InvisibleDirt:
                Blocks [i] = new DirtType ();
                Blocks [i]->Health = 10;
                Blocks [i]->Number = BT_Close_Case;
                Blocks [i]->Point.x = X;
                Blocks [i]->Point.y = 1176;
                Blocks [i]->Animation.Picture = &GlobalAllImage.InvisibleDirt;
                Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                i += 1;

                if (RoomSize == 2)
                    {
                    // SmallRoom :
                    Blocks [i] = new RoomType ();
                    Blocks [i]->Point.x = X + 316;
                    Blocks [i]->Point.y = 816 + 360;
                    Blocks [i]->Health = 1;
                    Blocks [i]->Animation.Picture = &GlobalAllImage.SmallBedroom;
                    Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                    Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                    i += 1;

                    // Stairs :
                    Blocks [i] = new StairsType ();
                    Blocks [i]->Point.x = X + 584;
                    Blocks [i]->Point.y = 1176;
                    Blocks [i]->Health = 10;
                    Blocks [i]->Animation.Picture = &GlobalAllImage.Stairs;
                    Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
                    Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
                   i += 1;
                    };
                };
            };

        // i += nI;
        // nI = 0;

        int nDirt = 5 + rand () % 2;

        for (int d = 0; d < nDirt; d ++)
            {
            X += 704;
            Blocks [i] = new DirtType ();
            Blocks [i]->Point.x = X - 24;
            Blocks [i]->Point.y = 700;
            Blocks [i]->Health = 10;
            Blocks [i]->Animation.Picture = &GlobalAllImage.BigDirt;
            Blocks [i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
            Blocks [i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();
            i += 1;
            };

        // i += nI;

        // printf ("Rooms [i/6] = %d, i = %d, Blocks [i] = %d \n", Rooms [i/6], i, Blocks [i]);

        /* printf ("%d : SizeX = %lf, SizeY = %lf \n", i, Blocks[i]->SizeX,   Blocks[i]->SizeY);
        printf ("%d : SizeX = %lf, SizeY = %lf \n", i, Blocks[i+1]->SizeX, Blocks[i+1]->SizeY);
        printf ("%d : SizeX = %lf, SizeY = %lf \n", i, Blocks[i+2]->SizeX, Blocks[i+2]->SizeY);
        printf ("%d : SizeX = %lf, SizeY = %lf \n", i, Blocks[i+3]->SizeX, Blocks[i+3]->SizeY);
        printf ("%d : SizeX = %lf, SizeY = %lf \n", i, Blocks[i+4]->SizeX, Blocks[i+4]->SizeY); */
        };

    // X = 0;

    /* Blocks [Blocks_Number] = new DirtType ();
    Blocks [Blocks_Number]->Point.x = 0;
    Blocks [Blocks_Number]->Point.y = 1176;
    Blocks [Blocks_Number]->Animation.Picture = &GlobalAllImage.BackGround;
    Blocks [Blocks_Number]->SizeX = 11400*World_Size;
    Blocks [Blocks_Number]->SizeY = 400; */

    /* int X = 0;

    int Kind = 0;

    for (int i = 0; i < Blocks_Number; i ++)
        {
        // BlockFunction (Blocks, i);

        Kind = rand() % 100;

        // printf ("CreateBlocks() : i = %d, Blocks[i] = %p \n", i, Blocks[i]);

        // int Type = 0;

        if (i < 11*World_Size)
            {
            Blocks [i] = new AirType ();
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
            Blocks [i] = new DirtType ();
            Blocks[i]->Number = BT_Dirt;
            Blocks[i]->Animation.Picture = &GlobalAllImage.Grass;
            Blocks[i]->Health = 10;
            Blocks[i]->Point.x = X*184;
            Blocks[i]->Point.y = 700;
            };

        if (i == 73*World_Size)
            X = 0;

        if (i >= 73*World_Size &&
            i < 135*World_Size)
            {
            if (Kind < 6 &&
                Blocks[i - 1]->Animation.Picture != &GlobalAllImage.Stairs &&
                Blocks[i - 2]->Animation.Picture != &GlobalAllImage.Stairs)
                {
                Blocks [i] = new StairsType ();
                Blocks[i]->Number = BT_Air;
                Blocks[i]->Animation.Picture = &GlobalAllImage.Stairs;
                }
            else
                {
                Blocks [i] = new AirType ();
                Blocks[i]->Number = BT_Air;
                Blocks[i]->Animation.Picture = &GlobalAllImage.StoneWall;
                };
            Blocks[i]->Health = 10;
            Blocks[i]->Point.x = X*184;
            Blocks[i]->Point.y = 816;
            };

        if (i == 135*World_Size)
            X = 0;

        if (i >= 135*World_Size &&
            i < 197*World_Size)
            {
            Blocks [i] = new DirtType ();
            Blocks[i]->Health = 10;
            Blocks[i]->Point.x = X*184;
            Blocks[i]->Point.y = 1008;
            Blocks[i]->Number = BT_Dirt;
            Blocks[i]->Animation.Picture = &GlobalAllImage.StoneFloor;
            };

        // if (i ==  197*World_Size)
        //     X = 0;

        if (i >= 197*World_Size &&
            i < 211*World_Size)
            {
            Blocks [i] = new TreeType ();
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
            Blocks [i] = new BonfireType ();
            Blocks[i]->Health = 10;
            Blocks[i]->Number = BT_BonFire;
            Blocks[i]->Point.x = rand() % 11400*World_Size;
            Blocks[i]->Point.y = 452;
            Blocks[i]->Animation.Picture = &GlobalAllImage.BonFire;
            // Blocks[i]->Function = BonfireInteraction;
            };

        if (i >= 214*World_Size &&
            i < 218*World_Size)
            {
            Blocks [i] = new DynamiteType ();
            Blocks[i]->Health = 100;
            Blocks[i]->Number = BT_Dynamite;
            Blocks[i]->Point.x = rand() % 11400*World_Size;
            Blocks[i]->Point.y = 938;
            Blocks[i]->Animation.Picture = &GlobalAllImage.Dynamite;
            // Blocks[i]->Function = DynamiteInteraction;
            };

        if (i >= 218*World_Size &&
            i < 223*World_Size)
            {
            Blocks [i] = new CaseType ();
            Blocks[i]->Health = 11 + rand()%2;
            Blocks[i]->Number = BT_Close_Case;
            Blocks[i]->Point.x = rand() % 11400*World_Size;
            Blocks[i]->Point.y = 892;
            Blocks[i]->Animation.Picture = &GlobalAllImage.HighCase;
            // Blocks[i]->Function = CaseInteraction;
            };

        if (i >= 223*World_Size &&
            i < 228*World_Size)
            {
            Blocks [i] = new SmallStoneType ();
            Blocks[i]->Health = 11;
            // Blocks[i]->Number = BT_Stone;
            Blocks[i]->Point.x = rand() % 11400*World_Size;
            Blocks[i]->Point.y = 660;
            Blocks[i]->Animation.Picture = &GlobalAllImage.Stone;
            // Blocks[i]->Function = CaseInteraction;
            };

        if (i >= 228*World_Size)
            {
            Blocks [i] = new TreeType ();
            Blocks[i]->Health = 0;
            };

        Blocks[i]->SizeX = Blocks[i]->Animation.GetFrameSizeX();
        Blocks[i]->SizeY = Blocks[i]->Animation.GetFrameSizeY();

        X += 1;

        // i += 1;
        }; */
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

        // printf ("DrawLevelBlocks() : i = %d\n", i);

        ManyBlocks [i]->DrawBlock (Camera);

        // i = i + 1;
        };
    };

void CallLevelPhysic (BlockType* ManyBlocks[], ManType* Man, CamType* Camera)
    {
    // int i = 0;

    for (int i = 0; i < Blocks_Number; i ++)
        {
        Man->BlockInteraction (ManyBlocks [i], Camera);
        };
    };

//=============================================================================
//=============================================================================

