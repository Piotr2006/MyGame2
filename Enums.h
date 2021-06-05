#ifndef ENUMS_H
#define ENUMS_H

const int NameSize = 50;
const int World_Size = 5;   // !!! Не делать больше 10-ти !!!

const int Exit = 1;
const int Continue = 0;

const int Blocks_Number = 402*World_Size + 12*World_Size; // (11400*World_Size)/1024
const int Rooms_Number = 67*World_Size;
const int Men_Number = 1;

enum SelectedInvTypes
    {
    ST_Weapon    = 0,
    ST_Resourses = 1,
    ST_Food      = 2
    };

enum InventoryNumbers
    {
    IT_Axe        = 0,
    IT_Wood       = 1,
    IT_Knife      = 2,
    IT_Apple      = 3,
    IT_Stone      = 4,
    IT_Bow        = 5,
    IT_Arrow      = 6,
    // IT_Coin       = 7,
    IT_Fishing    = 7,
    IT_Fish       = 8,
    IT_CookedFish = 9,
    IT_Rope       = 10,
    IT_Gun        = 11
    };

enum
    {
    Block_MaxHealth = 1000,
    Block_BaseWide = 95,
    Block_BaseHigh = 95,
    };

enum BlockNumbers
    {
    BT_Start      = -1,
    BT_Finish     = -2,
    BT_BlackSpace = 0,
    BT_Dirt       = 1,
    BT_Box        = 2,
    BT_Stairs     = 3,
    BT_Fire       = 4,
    BT_Tree       = 5,
    BT_Stalactite = 7,
    BT_Chest      = 8,
    BT_BonFire    = 9,
    BT_Rock       = 10,
    BT_Pickaxe    = 11,
    BT_Water      = 12,
    BT_FallingTree = 13,
    BT_SmallStone = 14,
    BT_Floor      = 15,
    BT_Dynamite   = 16,
    BT_Close_Case = 17,
    BT_Opened_Case= 18,
    BT_Berries    = 21,
    BT_Wall       = 22,
    BT_Air        = 50,
    BT_House      = 51,
    BT_Snow       = 52,
    BT_BackGround = 52,
    BT_Coin       = 101
    };

enum ManKinds
    {
    MT_Main   = 0,
    MT_Seller = 1,
    MT_Bandit = 2,
    MT_Bear   = 3,
    MT_Fish   = 5,
    MT_Spider = 6,
    MT_Wolf   = 7,
    MT_Ghost  = 8,
    MT_Boat   = 10
    };

enum
    {
    Number_of_Images = 100
    };

enum
    {
    Inventory_TextSize = 40,
    Coin_TextSize      = 40,
    Level_TextSize     = 70,
    Loading_TextSize   = 80
    };

enum Inv
    {
    // LeftArm
    Inv_LeftArm_TextX       = 1402,
    Inv_LeftArm_TextY       = 45,
    Inv_LeftArm_RectLeftX   = 1375,
    Inv_LeftArm_RectLeftY   = 50,
    Inv_LeftArm_RectRightX  = 1425,
    Inv_LeftArm_RectRightY  = 100,

    // RightArm
    Inv_RightArm_TextX      = 1477,
    Inv_RightArm_TextY      = 45,
    Inv_RightArm_RectLeftX  = 1450,
    Inv_RightArm_RectLeftY  = 50,
    Inv_RightArm_RectRightX = 1500,
    Inv_RightArm_RectRightY = 100
    };

enum Man
    {
    Man_x = 4000,
    Man_y = 500,
    Man_Health = 100,
    Man_Temperature = 36,
    Man_Energy = 100,
    Man_FastSpeed = 20,
    Man_SlowSpeed = 7,
    Man_DrawingX = 0,
    Man_DrawingY = -48,
    Man_MaxHealth = 100,
    Man_MaxTemperature = 90,
    Man_LeftSide = 1,
    Man_RightSide = 2,
    Man_aX = 0,
    Man_aY = 5,
    Man_JumpSpeed = 30,
    Man_FallingSpeed = 60,
    Man_Wide = 47,
    Man_High = 168,

    // Fire

    Man_Fire1X = 0,
    Man_Fire1Y = 10,
    Man_Fire2X = 50,
    Man_Fire2Y = 4,
    Man_Fire3X = 25,
    Man_Fire3Y = 60,

    Normal_Position = 0,
    Fire_Position = 1,
    Water_Position = 2,
    House_Position = 3,
    OutSide_Position = 4,
    Boat_Position = 5,
    Ghost_Position = 6,
    Climbing_Position = 7,
    ClimbDown_Position = 8,

    // Damage

    Man_FireDamage = 5,
    Man_ColdTempDamage = 1,
    Man_HotTempDamage  = 2,

    Man_TempDamage1 = 1,
    Man_TempDamage2 = 2,
    Man_TempDamage3 = 4
    };

enum
    {
    Man_ColdTemp1 = 20,
    Man_ColdTemp2 = 10,
    Man_ColdTemp3 = 5,

    Man_HotTemp1 = 50,
    Man_HotTemp2 = 70,
    Man_HotTemp3 = 80
    };

enum
    {
    Sign_PauseX = 45,
    Sign_PauseY = 35,
    Sign_Pause_Radius = 25,
    Pause_Active = 0,
    Pause_Stopped = 1,

    Sign_CoinX = 20,
    Sign_CoinY = 70,
    Sign_CoinTextX = 70,
    Sign_CoinTextY = 95,

    Sign_LevelTextX = 220,
    Sign_LevelTextY = 53,

    Sign_TermometerX = 10,
    Sign_TermometerY = 160,
    Sign_Term_RectLeftX = 19,
    Sign_Term_RectRightX = 22,
    Sign_Term_RectDownY = 105,

    Sign_HealthX = 19,
    Sign_HealthY = 113,

    Main_Sleep = 20
    };

enum
    {
    Text1_X = 800,
    Text1_Y = 100,
    Text1_Size = 40,

    Text2_X = 800,
    Text2_Y = 200,
    Text2_Size = 80,
    };

enum
    {
    Load_BigRect_X1 = 200,
    Load_BigRect_Y1 = 500,
    Load_BigRect_X2 = 1350,
    Load_BigRect_Y2 = 550,

    Load_SmallRect_X1 = 200,
    Load_SmallRect_Y1 = 500,
    Load_SmallRect_Y2 = 550,

    Loading_TextX = 750,
    Loading_TextY = 400,

    Loading_Sleep = 10
    };

enum Screen
    {
    Screen_xCenter = 725,
    Screen_yCenter = 425
    };

#endif
