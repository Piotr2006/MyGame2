#include "TXLib.h"

// 123

const int NameSize = 50;

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
    BT_Water      = 5,
    BT_Stalactite = 7,
    BT_Chest      = 8,
    BT_BonFire    = 9,
    BT_Rock       = 10,
    BT_Pickaxe    = 11,
    BT_Berries    = 21,
    BT_Air        = 50,
    BT_House      = 51,
    BT_Snow       = 52,
    BT_Coin       = 101
    };

enum ManKinds
    {
    MT_Main = 0,
    MT_Seller = 1,
    MT_Bandit = 2,
    MT_Bear = 3
    };

enum
    {
    Number_of_Images = 24
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
    Man_x = 400,
    Man_y = -100,
    Man_Health = 20,
    Man_Temperature = 36,
    Man_FastSpeed = 15,
    Man_SlowSpeed = 5,
    Man_DrawingX = 0,
    Man_DrawingY = -48,
    Man_MaxHealth = 20,
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

    // Damage

    Man_FireDamage = 5,
    Man_ColdTempDamage = 5,
    Man_HotTempDamage  = 10,

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
    Pause_Active = 2,
    Pause_Stopped = 1,

    Sign_CoinX = 20,
    Sign_CoinY = 70,
    Sign_CoinTextX = 70,
    Sign_CoinTextY = 95,

    Sign_LevelTextX = 180,
    Sign_LevelTextY = 38,

    Sign_TermometerX = 10,
    Sign_TermometerY = 160,
    Sign_Term_RectLeftX = 19,
    Sign_Term_RectRightX = 22,
    Sign_Term_RectDownY = 105,

    Sign_HealthX = 19,
    Sign_HealthY = 113,

    Main_Sleep = 30
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

    Loading_Sleep = 20
    };

enum Screen
    {
    Screen_xCenter = 725,
    Screen_yCenter = 425
    };

struct ImageType
    {
    ImageType (const char* FileName, int xMaxAnimationNumber, int yMaxAnimationNumber, HDC Picture, COLOREF color);

    const char* FileName;

    // int xFrame;
    // int yFrame;

    int xMaxAnimationNumber;
    int yMaxAnimationNumber;

    HDC Picture;

    COLORREF color;
    };

struct AnimationType
    {
    AnimationType (int xFrame, int yFrame, ImageType* Picture);

    int xFrame;
    int yFrame;

    ImageType* Picture;
    };

struct BaseType
    {
    BaseType (double x, double y, double Health, AnimationType Animation);

    double x;
    double y;

    double Health;

    AnimationType Animation;
    };

struct AllImageType
    {
    ImageType BackGround;
    ImageType Cursor;
    ImageType Dirt;
    ImageType Health;
    ImageType Finish;
    ImageType Start;
    ImageType Pause;
    ImageType Coin;
    ImageType CoinAnimation;
    ImageType Box;
    ImageType Man;
    ImageType Stairs;
    ImageType Fire;
    ImageType GreenFire;
    ImageType BlackSpace;
    ImageType Bat;
    ImageType Stalactite;
    ImageType GameOver;
    ImageType Pickaxe;
    ImageType Termometer;
    ImageType Apple;
    ImageType Chest;
    ImageType IronOre;
    ImageType Water;
    ImageType Villager;
    ImageType SaySign;
    ImageType Thief;
    ImageType Covboy;
    ImageType Inventory;
    ImageType Lock;
    ImageType Gun;
    ImageType Grass;
    ImageType Knife;
    ImageType Tree;
    ImageType Wood;
    ImageType House;
    ImageType Slot;
    ImageType Axe;
    ImageType Snow;
    ImageType Menu;
    ImageType BonFire;
    ImageType Bear;
    ImageType Plus;
    ImageType CommonSlot;
    ImageType Rock;
    ImageType Stone;
    ImageType Bow;
    ImageType Arrow;
    ImageType SmallItems;
    ImageType Bandit;
    ImageType Bullet;
    };

struct InvType
    {
    int CraftNumber;
    int MainSlot;
    int MainNumber;
    int Axe;
    int Wood;
    int Apple;
    int Knife;
    int Stone;
    int Bow;
    int Arrow;
    int Coin;
    };

struct ManType;

struct CamType
    {
    CamType (double x, double y, double vX, double vY, int Timer);

    void MoveCamera (ManType* Man);

    double x;
    double y;

    double vX;
    double vY;

    int Timer;
    };

struct MouseType
    {
    int x;
    int y;

    ImageType Picture;
    };

struct ManType : BaseType
    {
    ManType (double x, double y, double _Health, AnimationType Animation,
             double _vX, double _vY, double _aX, double _aY,
             int _Side, int _Position, double _Temperature,
             int _NumberCoin, int _xWeapon, int _ArmSpeed, char _Name [50], int _Kind, InvType _Inventory,
             int _Time, int _Days, double _ArrowX, double _ArrowY, int _ArrowVX, int _ArrowVY);

    void DrawMan (CamType* Camera, AllImageType AllImage);

    void DrawInventory (CamType* Camera, CamType* FixedCamera, AllImageType AllImage);

    void Crafting (AllImageType AllImage, CamType* FixedCamera);

    void ManTemperature ();

    void ManFire (CamType* Camera, AllImageType AllImage);

    void ManHealth (CamType* Camera, AllImageType AllImage);

    void ControlMan (MouseType Mouse, int* t);

    void Physic ();

    double vX;
    double vY;

    double aX;
    double aY;

    int Side;
    int Position;

    double Temperature;

    int NumberCoin;

    int xWeapon;

    int ArmSpeed;

    char Name [50];

    int Kind;

    InvType Inventory;

    int Time;

    int Days;

    double ArrowX;
    double ArrowY;

    int ArrowVX;
    int ArrowVY;
    };

struct ButtonType
    {
    ButtonType (int x, int y, int Number);

    void DrawButton (CamType* Camera, AllImageType AllImage);

    int ButtonCheckClick (int x2, int y2, int DstX, int DstY);

    int x;
    int y;

    int Number;
    };

struct BlockType : BaseType
    {
    BlockType (double x, double y, double Health, AnimationType Animation,
               int Number);

    void DrawBlock (CamType* Camera, AllImageType AllImage);

    int Number;
    };

void Cycle ();

void MoveGame (BlockType ManyBlocks [], AllImageType AllImage, int* LevelNumber, ManType* Man, double* AllTemperature, CamType* Camera, CamType* FixedCamera, ManType* Villager);

void DeleteImage (AllImageType AllImage);

void DrawLevelBlocks (BlockType ManyBlocks[], CamType* Camera, AllImageType AllImage);

void DrawLevelPeople (ManType Villagers[], CamType* Camera, AllImageType AllImage);

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man, CamType* Camera, int* NumberCoin, AllImageType AllImage);

void Level1 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera);

void Level2 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera);

void DrawManyBlocks (BlockType ManyBlocks [], CamType* Camera, AllImageType AllImage);

void InteractManWithBlocks (BlockType ManyBlocks [], ManType* Man, CamType* Camera, int* NumberCoin, int* LevelNumber, AllImageType AllImage);

void LoadGameImage (ImageType* Image, const char* Picture, int xMaxFrame, int yMaxFrame, COLORREF color,
                    int* Procent, double Number);

int Collision (BlockType* Block, ManType* Man);

void ChangeAnimationNumber (BlockType* Block, ManType* Man, AllImageType AllImage);

void DrawCursor (MouseType* Mouse, CamType* Camera);

void BlockCollision (ManType* Man, BlockType* Block, CamType* Camera, AllImageType AllImage);

void CoinCollision (ManType* Man, BlockType* Coin, int* NumberCoin);

int ModuleDistance (int x1, int y1, int x2, int y2, int Distance);

int Distance (int a, int b, int Distance);

void DrawHealth (int Health, CamType* Camera, AllImageType AllImage);

void BlockCalling (BlockType* Block, ManType* Man, CamType* Camera);

void DrawLoading (int Procents);

void LoadImage (AllImageType* AllImage);

void Text (int x, int y, int Size, int Number, char Name []);

void DrawTransparentImage (ImageType* Image, int x, int y, int* xAnimationNumber, int* yAnimationNumber, CamType* Camera);

void LoadImages (AllImageType* AllImages);

void HelpSystem ();

void VillagerMind (ManType* Villager, ManType* Man, CamType* Camera, AllImageType AllImage);

void DrawSlot (int Block, int x, int y, ImageType Picture, int TextX, int TextY);

void Shooting (int x, int y, int vX, ImageType Picture, ManType* Man, CamType* Camera);

void IncreaseAnimationNumber (AnimationType* Animation);

void Menu (int* LevelNumber, AllImageType AllImage, CamType* FixedCamera);

int Timer (int Time);

void CreateBlocks (BlockType Blocks [], AllImageType AllImage);

void StrCpy (char Name [], char _Name []);

int main ()
    {
    txCreateWindow (1550, 850);

    Cycle ();

    return 0;
    };

ButtonType :: ButtonType (int _x, int _y, int _Number) :
    x (_x),
    y (_y),
    Number (_Number)
    {};

ImageType :: ImageType (const char* _FileName, int _xMaxAnimationNumber, int _yMaxAnimationNumber,
                        HDC _Picture, COLOREF _color) :
    xMaxAnimationNumber (_xMaxAnimationNumber),
    yMaxAnimationNumber (_xMaxAnimationNumber),

AnimationType :: AnimationType (int _xFrame, int _yFrame, ImageType* _Picture) :
    xFrame (_xFrame),
    yFrame (_yFrame),
    Picture (_Picture)
    {};

CamType :: CamType (double _x, double _y, double _vX, double _vY, int _Timer) :
    x (_x),
    y (_y),
    vX (_vX),
    vY (_vY),
    Timer (_Timer)
    {};

BaseType :: BaseType (double _x, double _y, double _Health, AnimationType _Animation) :
    x (_x),
    y (_y),
    Health (_Health),
    Animation (_Animation)
    {};

BlockType :: BlockType (double _x, double _y, double _Health, AnimationType _Animation,
               int _Number) :
    BaseType (_x, _y, _Health, _Animation),
    Number (_Number)
    {
    };

ManType :: ManType (double _x, double _y, double _Health, AnimationType _Animation,
                    double _vX, double _vY, double _aX, double _aY,
                    int _Side, int _Position, double _Temperature,
                    int _NumberCoin, int _xWeapon, int _ArmSpeed, char _Name [50], int _Kind, InvType _Inventory,
                    int _Time, int _Days, double _ArrowX, double _ArrowY, int _ArrowVX, int _ArrowVY) :
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
    ArrowVY (_ArrowVY)
    {
    /* for (int i = 0; i < NameSize; i += 1)
        {
        Name [i] = _Name [i];
        }; */

    // strcpy (Name, _Name);

    StrCpy (Name, _Name);
    };

void StrCpy (char Name [], char _Name [])
    {
    for (int i = 0; i < NameSize; i += 1)
        {
        Name [i] = _Name [i];
        };
    };

void LoadAllImages (AllImageType* AllImages)
    {
    int Procent = 1;

    LoadGameImage (&AllImages->BackGround,    "Images/ForestBackGround.bmp",       1, 2, TX_WHITE, &Procent, Number_of_Images);

    // printf ("1:LoadAllImages(): File = %s , HDC = %d \n", AllImages->BackGround.FileName, AllImages->BackGround.Picture);

    LoadGameImage (&AllImages->Cursor,        "Images/GameCursor.bmp",             1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Dirt,          "Images/DirtAnimation.bmp",          4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Health,        "Images/GameHeart.bmp",              1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Finish,        "Images/Finish.bmp",                 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Start,         "Images/Start.bmp",                  1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Pause,         "Images/GamePause.bmp",              1, 6, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Coin,          "Images/GameCoin.bmp",               2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->CoinAnimation, "Images/CoinAnimation.bmp",          4, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Box,           "Images/WoodBoxAnimation.bmp",       4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Man,           "Images/RedManAnimation.bmp",        1, 6, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Stairs,        "Images/Stairs.bmp",                 4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Fire,          "Images/FireAnimation.bmp",          5, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->GreenFire,     "Images/GreenFire.bmp",              4, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->BlackSpace,    "Images/Black.bmp",                  4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bat,           "Images/Bat.bmp",                    4, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Stalactite,    "Images/Stalactite.bmp",             4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->GameOver,      "Images/GameOver.bmp",               1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Pickaxe,       "Images/Pickaxe.bmp",                4, 3, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Termometer,    "Images/termometer.bmp",             1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Apple,         "Images/Apple.bmp",                  1, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Chest,         "Images/Chest.bmp",                  4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->IronOre,       "Images/IronOre.bmp",                4, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Water,         "Images/Water2.bmp",                 1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Villager,      "Images/Villager.bmp",               3, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->SaySign,       "Images/SaySign.bmp",                1, 6, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Thief,         "Images/Thief.bmp",                  2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Covboy,        "Images/Covboy.bmp",                 2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Inventory,     "Images/Inventory.bmp",              1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Lock,          "Images/Lock.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Gun,           "Images/Gun.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Grass,         "Images/Grass.bmp",                  1, 4, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Knife,         "Images/Knife.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Tree,          "Images/Tree.bmp",                   1, 4, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Wood,          "Images/Wood.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->House,         "Images/House.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Slot,          "Images/Slot.bmp",                   1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Axe,           "Images/Axe.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Snow,          "Images/Snow.bmp",                   6, 2, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Menu,          "Images/MainMenu.bmp",               1, 1, TX_BLACK, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->BonFire,       "Images/BonFire.bmp",                1, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bear,          "Images/Bear.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Plus,          "Images/Plus.bmp",                   2, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->CommonSlot,    "Images/CommonSlot.bmp",             1, 1, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Rock,          "Images/Rock.bmp",                   1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Stone,         "Images/Stone.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bow,           "Images/Bow.bmp",                    2, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Arrow,         "Images/Arrow.bmp",                  1, 2, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->SmallItems,    "Images/SmallItems.bmp",             1, 3, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bandit,        "Images/Bandit.bmp",                 1, 4, TX_WHITE, &Procent, Number_of_Images);

    LoadGameImage (&AllImages->Bullet,        "Images/Bullet.bmp",                 1, 2, TX_WHITE, &Procent, Number_of_Images);
    };

void Cycle ()
    {
    AllImageType AllImage = {};

    LoadAllImages (&AllImage);

    int LevelNumber = 1;

    // double AllTemperature = 10;

    CamType Camera {Man_x - Screen_xCenter, Man_y - Screen_yCenter, 0.3, 0.3, 0};

    CamType FixedCamera {0, 0, 0, 0, 0};

    ManType Man {Man_x, Man_y, Man_Health, {0, 0, &AllImage.Man},
                 0, 0, Man_aX, 2,
                 0, 0, Man_Temperature,
                 0, 0, 0, "Я", 0, {0, 0, 0, 0, 1, 1, 1, 1, 1, 111, 2},
                 0, rand() % 40, Man_x, Man_y, 0, 0};

    while (true)
        {
        txSetFillColor (RGB (72, 72, 72));
        txClear ();

        if (LevelNumber == 0)
            Menu (&LevelNumber, AllImage, &FixedCamera);

        if (LevelNumber == 1)
            {
            Level1 (&LevelNumber, &Man, AllImage, &Camera, &FixedCamera);
            };

        if (LevelNumber == 2)
            {
            Level2 (&LevelNumber, &Man, AllImage, &Camera, &FixedCamera);
            };

        if (GetAsyncKeyState (VK_ESCAPE))
            break;
        };
    };

void Menu (int* LevelNumber, AllImageType AllImage, CamType* FixedCamera)
    {
    int null = 0;

    while (true)
    {
    DrawTransparentImage (&AllImage.Menu, 0, 0, &null, &null, FixedCamera);

    if (ModuleDistance (900, 100 , txMouseX(), txMouseY(), 50) == true &&
        GetAsyncKeyState (VK_LBUTTON))
        {
        LevelNumber += 1;
        break;
        };
    };
    };

void ManType :: Crafting (AllImageType AllImage, CamType* FixedCamera)
    {
    int null = 0;
    int one  = 1;
    int four = 4;
    int five = 5;

    if (Inventory.CraftNumber == 0)
        {
        DrawTransparentImage (&AllImage.CommonSlot, 15, 300, &null, &null, FixedCamera);

        if (ModuleDistance (40, 325, txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            Inventory.CraftNumber = 1;
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
        GetAsyncKeyState (VK_LBUTTON))
        Inventory.CraftNumber += 1;

    if (ModuleDistance (324, 395, txMouseX(), txMouseY(), 50) == true &&
        GetAsyncKeyState (VK_LBUTTON))
        Inventory.CraftNumber -= 1;

    if (Inventory.CraftNumber < 0)
        Inventory.CraftNumber = 0;

    if (Inventory.CraftNumber == 1)
        {
        DrawTransparentImage (&AllImage.Wood, 15, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Stone, 127, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Axe, 240, 292, &null, &one, FixedCamera);

        if (Inventory.Wood >= 1 &&
            Inventory.Stone >= 1 &&
            ModuleDistance (265, 325, txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            {
            Inventory.Wood -= 1;
            Inventory.Stone -= 1;
            Inventory.Axe += 1;
            Inventory.CraftNumber = 0;
            };
        };

    if (Inventory.CraftNumber == 2)
        {
        DrawTransparentImage (&AllImage.Wood, 15, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Wood, 127, 300, &null, &one, FixedCamera);

        DrawTransparentImage (&AllImage.Knife, 240, 312, &null, &one, FixedCamera);

        if (Inventory.Wood >= 2 &&
            ModuleDistance (265, 325, txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            {
            Inventory.Wood -= 2;
            Inventory.Knife += 1;
            Inventory.CraftNumber = 0;
            };
        };
    };

    };

void ManType :: DrawInventory (CamType* Camera, CamType* FixedCamera, AllImageType AllImage)
    {
    int null = 0;

    int one = 1;
    int two = 2;

    DrawTransparentImage (&AllImage.Inventory, 550, 700, &null, &null, FixedCamera);

    DrawTransparentImage (&AllImage.Slot, 549 + Inventory.MainNumber*50, 699, &null, &null, FixedCamera);

    DrawSlot (Inventory.Axe, 550, 690, AllImage.Axe, 550, 700);

    DrawSlot (Inventory.Wood, 600, 700, AllImage.Wood, 600, 700);

    DrawSlot (Inventory.Apple, 700, 700, AllImage.Apple, 700, 700);

    DrawSlot (Inventory.Knife, 650, 720, AllImage.Knife, 650, 700);

    DrawSlot (Inventory.Stone, 750, 700, AllImage.Stone, 750, 700);

    DrawSlot (Inventory.Bow, 800, 690, AllImage.Bow, 800, 700);

    DrawSlot (Inventory.Arrow, 828, 719, AllImage.Arrow, 850, 700);

    DrawSlot (Inventory.Coin, 910, 707, AllImage.Coin, 900, 700);

    int x = 1;

    if (Animation.yFrame == 0)
        x = -1;
    if (Animation.yFrame == 1)
        x = 1;

    // Controlling

    if (GetAsyncKeyState (VK_LCONTROL))
        {
        Inventory.MainNumber -= 1;
        };

    if (GetAsyncKeyState (VK_RCONTROL))
        {
        Inventory.MainNumber += 1;
        };

    if (Inventory.MainNumber < 0)
        Inventory.MainNumber = 8;

    if (Inventory.MainNumber > 8)
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

    // ManArm
    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 2 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Knife, x + 33 - Animation.yFrame*20 + xWeapon*x,
                              y + 112, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 3 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Apple, x + 33 - Animation.yFrame*20 + xWeapon*x,
                              y + 112, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 6 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Arrow, x + 33 - Animation.yFrame*20 + xWeapon*x,
                              y + 112, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 4 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Stone, x + 33 - Animation.yFrame*20 + xWeapon*x,
                              y + 112, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 1 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Wood, x + 33 - Animation.yFrame*20 + xWeapon*x,
                              y + 70, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 7 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Coin, x + 33 - Animation.yFrame*20 + xWeapon*x,
                              y + 70, &null, &Animation.yFrame, Camera);

    if (Animation.yFrame <= 1 &&
        Inventory.MainNumber == 0 &&
        Inventory.MainSlot > 0)
        DrawTransparentImage (&AllImage.Axe, x - 26 + Animation.yFrame*98,
                              y + 60, &xWeapon, &Animation.yFrame, Camera);

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

void DrawSlot (int Block, int x, int y, ImageType Picture, int TextX, int TextY)
    {
    int null = 0;
    int one = 1;

    CamType FixedCamera = {0, 0, 0, 0, 0};

    if (Block > 0)
        {
        DrawTransparentImage (&Picture, x, y, &null, &one, &FixedCamera);

        Text (TextX + 38, TextY + 44, 20, Block, "");
        };
    };

void CreateBlocks (BlockType Blocks [], AllImageType AllImage)
    {
    int i = 0;

    int x = -1;

    while (i < 1000)
        {
        Blocks [i] = BlockType {x*190, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt};

        if (x <= 100)
            x += 1;

        i += 1;
        };
    };

void BlockType :: DrawBlock (CamType* Camera, AllImageType AllImage)
    {
    IncreaseAnimationNumber (&Animation);

    if (Health > 0)
        DrawTransparentImage (Animation.Picture, x + 50, y, &Animation.xFrame, &Animation.yFrame, Camera);
    };

int Collision (BlockType* Block, ManType* Man)
    {
    if (fabs (Man->x - (Block->x + Block_BaseWide)) <= Block_BaseWide + Man_Wide &&
        fabs (Man->y - (Block->y + Block_BaseHigh)) <= Block_BaseHigh + Man_High)
    return 1;

    return 0;
    };

void IncreaseAnimationNumber (AnimationType* Animation)
    {
    Animation->xFrame += 1;

    if (Animation->xFrame >= Animation->Picture->xMaxAnimationNumber)
        Animation->xFrame = 0;
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

    if (Kind != 0)
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

    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", 30);
    txTextOut (x - Camera->x + 50, y - Camera->y, Name);
    };
    };

void ManType :: ManFire (CamType* Camera, AllImageType AllImage)
    {
    BlockType Fire1 {0 - txGetExtentX (Animation.Picture->Picture)/2 + Man_Fire1X, 0 - txGetExtentY (Animation.Picture->Picture)/2 + Man_Fire1Y, 4, {rand() % 4, 0, &AllImage.Fire}, 0};
    BlockType Fire2 {0 - txGetExtentX (Animation.Picture->Picture)/2 + Man_Fire2X, 0 - txGetExtentY (Animation.Picture->Picture)/2 + Man_Fire2Y, 4, {rand() % 4, 0, &AllImage.Fire}, 0};
    BlockType Fire3 {0 - txGetExtentX (Animation.Picture->Picture)/2 + Man_Fire3X, 0 - txGetExtentY (Animation.Picture->Picture)/2 + Man_Fire3Y, 4, {rand() % 4, 0, &AllImage.Fire}, 0};

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

void VillagerMind (ManType* Villager, ManType* Man, CamType* Camera, AllImageType AllImage)
    {
    if (Villager->Health > 0)
    {
    int null = 0;
    int a = 0;
    int three = 3;
    int four = 4;
    int one = 1;
    int two = 2;

    if (Villager->Kind == MT_Seller)
    {
    /* Villager->Inventory.Axe = rand() % 3;
       Villager->Inventory.Knife = rand() % 3;
       Villager->Inventory.Bow = rand() % 3;  */

    int Side = 1;
    if (Villager->x > Man->x)
        Side = 0;
    if (Villager->x < Man->x)
        Side = 1;

    if (Man->x - Villager->x > 100 &&
            Man->x - Villager->x < 500)
            Villager->vX = 10;

    if (Man->x - Villager->x < 100 &&
            Man->x - Villager->x > 0)
            {
            Villager->vX = 0;
            };

    if (Villager->x - Man->x > 100 &&
            Villager->x - Man->x < 500)
            Villager->vX = -10;

    if (Villager->x - Man->x < 100 &&
            Villager->x - Man->x > 0)
            {
            Villager->vX = 0;
            };

    if (fabs (Man->x - Villager->x) <= 200)
        {

        if (Villager->Inventory.Wood == 0)
            {
            if (ModuleDistance (Villager->x + 50 - Camera->x, Villager->y + 84 - Camera->y , txMouseX(), txMouseY(), 50) == true &&
                GetAsyncKeyState (VK_LBUTTON))
            Villager->Inventory.Wood = 1;
            };

        if (Villager->Inventory.Wood == 1)
            {
            DrawTransparentImage (&AllImage.CommonSlot, Villager->x - 20, Villager->y - 60, &null, &null, Camera);

            DrawTransparentImage (&AllImage.CommonSlot, Villager->x + 50, Villager->y - 60, &null, &null, Camera);

            DrawTransparentImage (&AllImage.CommonSlot, Villager->x + 120, Villager->y - 60, &null, &null, Camera);

            // slot1
            if (Villager->Inventory.Axe == 0)
                {
                DrawTransparentImage (&AllImage.Coin, Villager->x - 10, Villager->y - 53, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Villager->x + 10, Villager->y - 33, &null, &null, Camera);
                // Text (Villager->x + 8, Villager->y - 16, 20, one, "");

                if (ModuleDistance (Villager->x + 5 - Camera->x, Villager->y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Wood >= 1)
                    {
                    Man->Inventory.Wood -= 1;
                    Man->Inventory.Coin += 1;
                    Villager->Inventory.Wood = 0;
                    };
                };

            if (Villager->Inventory.Axe == 1)
                {
                DrawTransparentImage (&AllImage.Axe, Villager->x - 20, Villager->y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Villager->x + 10, Villager->y - 33, &null, &two, Camera);
                // Text (Villager->x + 8, Villager->y - 16, 20, one, "");
                if (ModuleDistance (Villager->x + 5 - Camera->x, Villager->y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Stone >= 1)
                    {
                    Man->Inventory.Stone -= 1;
                    Man->Inventory.Axe += 1;
                    Villager->Inventory.Wood = 0;
                    };
                };

            if (Villager->Inventory.Axe == 2)
                {
                DrawTransparentImage (&AllImage.Apple, Villager->x - 20, Villager->y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Villager->x + 10, Villager->y - 33, &null, &one, Camera);
                // Text (Villager->x + 8, Villager->y - 16, 20, one, "");
                if (ModuleDistance (Villager->x + 5 - Camera->x, Villager->y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Coin >= 1)
                    {
                    Man->Inventory.Coin -= 1;
                    Man->Inventory.Apple += 1;
                    Villager->Inventory.Wood = 0;
                    };
                };

            // slot2
            if (Villager->Inventory.Knife == 0)
                {
                DrawTransparentImage (&AllImage.Knife, Villager->x + 50, Villager->y - 40, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Villager->x + 80, Villager->y - 33, &null, &null, Camera);

                if (ModuleDistance (Villager->x + 75 - Camera->x, Villager->y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Wood >= 1)
                    {
                    Man->Inventory.Wood -= 1;
                    Man->Inventory.Knife += 1;
                    Villager->Inventory.Wood = 0;
                    };
                };

            if (Villager->Inventory.Knife == 1)
                {
                DrawTransparentImage (&AllImage.Stone, Villager->x + 50, Villager->y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Villager->x + 80, Villager->y - 33, &null, &one, Camera);

                if (ModuleDistance (Villager->x + 75 - Camera->x, Villager->y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Coin >= 1)
                    {
                    Man->Inventory.Coin -= 1;
                    Man->Inventory.Stone += 1;
                    Villager->Inventory.Wood = 0;
                    };
                };

            if (Villager->Inventory.Knife == 2)
                {
                DrawTransparentImage (&AllImage.Arrow, Villager->x + 50, Villager->y - 46, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Villager->x + 80, Villager->y - 33, &null, &two, Camera);

                if (ModuleDistance (Villager->x + 75 - Camera->x, Villager->y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Stone >= 1)
                    {
                    Man->Inventory.Stone -= 1;
                    Man->Inventory.Arrow += 1;
                    Villager->Inventory.Wood = 0;
                    };
                };

            // slot3
            if (Villager->Inventory.Bow == 0)
                {
                DrawTransparentImage (&AllImage.Bow, Villager->x + 120, Villager->y - 70, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Villager->x + 150, Villager->y - 33, &null, &one, Camera);

                if (ModuleDistance (Villager->x + 145 - Camera->x, Villager->y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Coin >= 1)
                    {
                    Man->Inventory.Coin -= 1;
                    Man->Inventory.Bow += 1;
                    Villager->Inventory.Wood = 0;
                    };
                };

            if (Villager->Inventory.Bow == 1)
                {
                DrawTransparentImage (&AllImage.Apple, Villager->x + 120, Villager->y - 60, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Villager->x + 150, Villager->y - 33, &null, &two, Camera);

                if (ModuleDistance (Villager->x + 145 - Camera->x, Villager->y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Stone >= 1)
                    {
                    Man->Inventory.Stone -= 1;
                    Man->Inventory.Apple += 1;
                    Villager->Inventory.Wood = 0;
                    };
                };

            if (Villager->Inventory.Bow == 2)
                {
                DrawTransparentImage (&AllImage.Coin, Villager->x + 130, Villager->y - 53, &null, &null, Camera);

                DrawTransparentImage (&AllImage.SmallItems, Villager->x + 150, Villager->y - 33, &null, &null, Camera);

                if (ModuleDistance (Villager->x + 145 - Camera->x, Villager->y - 35 - Camera->y, txMouseX(), txMouseY(), 50) == true &&
                    GetAsyncKeyState (VK_LBUTTON) &&
                    Man->Inventory.Wood >= 1)
                    {
                    Man->Inventory.Wood -= 1;
                    Man->Inventory.Coin += 1;
                    Villager->Inventory.Wood = 0;
                    };
                };
            };

        // $i printf ("number = %d \n", Villager->Inventory.Wood); $d
        }
        else
            Villager->Inventory.Wood = 0;
    };

    /* if (Villager->Inventory.Knife == 2)
        {
        if (Side == 1)
        DrawTransparentImage (&AllImage.Gun, Villager->x + 74, Villager->y + 93, &null, &null, Camera);
        if (Side == 0)
        DrawTransparentImage (&AllImage.Gun, Villager->x + 44, Villager->y + 93, &one, &null, Camera);
        Villager->Position += 1;

        if (Villager->Position >= 10)
            {
            int x = Villager->x + 74;
            int vX = 0;

            if (Villager->x > Man->x)
                vX = -10;

            if (Villager->x < Man->x)
                vX = 10;

            x += vX;

            int null = 0;
            int one = 1;

            if (vX > 0)
                DrawTransparentImage (&AllImage.Gun, x, Villager->y + 88, &null, &one, Camera);

            if (vX < 0)
                DrawTransparentImage (&AllImage.Gun, x, Villager->y + 88, &one, &one, Camera);

            if (ModuleDistance (Man->x + 47, Man->y + 84, x,  Villager->y + 88, 30) == true)
                {
                Villager->Position = 0;
                };
            };
        }; */

    // Fighting:

    if (ModuleDistance (Villager->x + 50 - Camera->x, Villager->y + 84 - Camera->y , txMouseX(), txMouseY(), 50) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
        Man->Inventory.MainNumber == 2 &&
        Man->Inventory.MainSlot > 0 &&
        Man->ArmSpeed >= 10)
        {
        Villager->Health -= 1;
        Villager->vY = -15;
        if (Villager->x > Man->x)
            Villager->vX = 50;
        if (Villager->x < Man->x)
            Villager->vX = -50;
        // Villager->Animation.xFrame += 1;
        // txCircle (Man->x - Camera->x, Man->y - Camera->y, 50);
        Man->ArmSpeed = 0;
        Villager->Time = 1;
        };
    // else
    //     Villager->Animation.xFrame = 0;

    if (Man->xWeapon > 0)
        Man->xWeapon -= 1;

    if (Man->xWeapon < 0)
        Man->xWeapon = 0;
    };

    // Bow

    if (fabs (Man->ArrowX - Villager->x) <= 200 &&
        fabs (Man->ArrowY - Villager->y) <= 80 &&
        Villager->Health > 0 &&
        Man->ArrowVX != 0 &&
        Man->Inventory.Arrow > 0)
        {
        Villager->vY = -15;
        if (Villager->x > Man->x)
            Villager->vX = 50;
        if (Villager->x < Man->x)
            Villager->vX = -50;
        Villager->Health -= 5;
        Man->Inventory.Arrow -= 1;
        Man->ArrowVX = 0;
        Man->ArrowVY = 0;
        Man->ArrowX  = Man->x;
        Man->ArrowY  = Man->y;
        };


    // House
    if (Man->Position == House_Position)
        Villager->Position = OutSide_Position;

    if (Man->Position != House_Position &&
        Villager->Position == OutSide_Position)
        Villager->Position = Normal_Position;

    // Bear
    if (Villager->Kind == MT_Bear &&
        Villager->Health > 0)
        {
        if (Villager->Time == 1)
            {
            if (Man->x > Villager->x)
                Villager->vX = 10;

            if (Man->x < Villager->x)
                Villager->vX = -10;

            if (Man->x - Villager->x < 100 &&
            Man->x - Villager->x > 0)
            {
            Villager->vX = 0;
            };

            if (Villager->x - Man->x < 100 &&
                Villager->x - Man->x > 0)
            {
            Villager->vX = 0;
            };

            // Fighting
            Villager->ArmSpeed += 1;

            if (Villager->ArmSpeed >= 10 &&
                Villager->vX == 0)
                {
                Man->Health -= 1;
                Man->vY = -15;
                if (Man->x > Villager->x)
                    Man->vX = 50;
                if (Man->x < Villager->x)
                    Man->vX = -50;
                // Man->Animation.xFrame += 1;
                // txCircle (Man->x - Camera->x, Man->y - Camera->y, 50);
                Villager->ArmSpeed = 0;
                };
            };

        if (Man->Time < 500)
            {
            // Villager->Animation.xFrame = 0;
            Villager->vX = 1;
            };
        if (Man->Time >= 500 &&
            Villager->y - Man->y <= 300 &&
            Villager->y - Man->y >= -300 &&
            Villager->Time != 1)
            {
            // Villager->Animation.xFrame = 2;
            if (Man->x > Villager->x)
                Villager->vX = 10;

            if (Man->x < Villager->x)
                Villager->vX = -10;

            if (Man->x - Villager->x < 100 &&
            Man->x - Villager->x > 0)
            {
            Villager->vX = 0;
            };

            if (Villager->x - Man->x < 100 &&
                Villager->x - Man->x > 0)
            {
            Villager->vX = 0;
            };

            // Fighting
            Villager->ArmSpeed += 1;

            if (Villager->ArmSpeed >= 10 &&
                Villager->vX == 0)
                {
                Man->Health -= 1;
                Man->vY = -15;
                if (Man->x > Villager->x)
                    Man->vX = 50;
                if (Man->x < Villager->x)
                    Man->vX = -50;
                // Man->Animation.xFrame += 1;
                // txCircle (Man->x - Camera->x, Man->y - Camera->y, 50);
                Villager->ArmSpeed = 0;
                };
            };
        };

    // Bandit
    if (Villager->Kind == MT_Bandit &&
        Villager->Health > 0)
        {
        if (Man->x > Villager->x)
            Villager->vX = 10;

        if (Man->x < Villager->x)
            Villager->vX = -10;

        /* if (Villager->Animation.yFrame == 0 &&
            Villager->vX == 0)
            Villager->Animation.yFrame = 2;

        if (Villager->Animation.yFrame == 1 &&
            Villager->vX == 0)
            Villager->Animation.yFrame = 3; */

        if (fabs (Man->x - Villager->x) <= 200)
            Villager->vX = 0;

        Villager->ArmSpeed += 1;

        Villager->ArrowX += Villager->ArrowVX;
        Villager->ArrowY += Villager->ArrowVY;

        int null = 0;

        DrawTransparentImage (&AllImage.Bullet, -11 + 61*Villager->Animation.yFrame + Villager->ArrowX,
                              Villager->ArrowY + 60, &null, &Villager->Animation.yFrame, Camera);

        if (Villager->ArmSpeed >= 80)
            {
            // Villager->ArrowVY = 5;
            Villager->ArrowX = Villager->x;
            Villager->ArrowY = Villager->y;

            if (Man->x > Villager->x)
            Villager->ArrowVX =  100;
            if (Man->x < Villager->x)
            Villager->ArrowVX = -100;

            // Villager->xWeapon = 1;
            Villager->ArmSpeed = 0;
            };

        if (fabs (Villager->ArrowX - Man->x) <= 200 &&
            fabs (Villager->ArrowY - Man->y) <= 80)
            {
            Man->Health -= 1;
            Man->vY = -15;
            if (Villager->x > Man->x)
                Man->vX = -50;
            if (Villager->x < Man->x)
                Man->vX = 50;
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
        Health -= Man_ColdTempDamage/1000*Man_TempDamage1;

    if (Temperature <= Man_ColdTemp2)
        Health -= Man_ColdTempDamage/1000*Man_TempDamage2;

    if (Temperature <= Man_ColdTemp3)
        Health -= Man_ColdTempDamage/1000*Man_TempDamage3;

    if (Temperature >= Man_HotTemp1)
        Health -= Man_HotTempDamage/1000*Man_TempDamage1;

    if (Temperature >= Man_HotTemp2)
        Health -= Man_HotTempDamage/1000*Man_TempDamage2;

    if (Temperature >= Man_HotTemp3)
        Health -= Man_HotTempDamage/1000*Man_TempDamage3;
    };

int Distance (int a, int b, int Dst)
    {
    if (fabs (a - b) <= Dst)
        return 1;

    return 0;
    };

void ButtonType :: DrawButton (CamType* Camera, AllImageType AllImage)
    {
    int null = 0;

    DrawTransparentImage (&AllImage.Pause, x, y, &null, &Number, Camera);
    };

void DrawCursor (MouseType* Mouse, CamType* Camera)
    {
    Mouse->x = txMouseX ();

    Mouse->y = txMouseY ();

    int null = 0;

    DrawTransparentImage (&Mouse->Picture, Mouse->x, Mouse->y, &null, &null, Camera);
    };

void Shooting (int x, int y, int vX, ImageType Picture, ManType* Man, CamType* Camera)
    {
    };

void DeleteAllImage (AllImageType AllImages)
    {
    txDeleteDC (AllImages.BackGround.Picture);
    txDeleteDC (AllImages.Cursor.Picture);
    txDeleteDC (AllImages.Dirt.Picture);
    txDeleteDC (AllImages.Health.Picture);
    txDeleteDC (AllImages.Finish.Picture);
    txDeleteDC (AllImages.Start.Picture);
    txDeleteDC (AllImages.Pause.Picture);
    txDeleteDC (AllImages.Coin.Picture);
    txDeleteDC (AllImages.CoinAnimation.Picture);
    txDeleteDC (AllImages.Box.Picture);
    txDeleteDC (AllImages.Man.Picture);
    txDeleteDC (AllImages.Stairs.Picture);
    txDeleteDC (AllImages.Fire.Picture);
    txDeleteDC (AllImages.GreenFire.Picture);
    txDeleteDC (AllImages.Water.Picture);
    txDeleteDC (AllImages.Bat.Picture);
    txDeleteDC (AllImages.Stalactite.Picture);
    txDeleteDC (AllImages.GameOver.Picture);
    txDeleteDC (AllImages.Pickaxe.Picture);
    txDeleteDC (AllImages.Villager.Picture);
    txDeleteDC (AllImages.SaySign.Picture);
    txDeleteDC (AllImages.Thief.Picture);
    txDeleteDC (AllImages.Covboy.Picture);
    txDeleteDC (AllImages.Gun.Picture);
    txDeleteDC (AllImages.Grass.Picture);
    txDeleteDC (AllImages.Knife.Picture);
    txDeleteDC (AllImages.Wood.Picture);
    txDeleteDC (AllImages.House.Picture);
    txDeleteDC (AllImages.Snow.Picture);
    txDeleteDC (AllImages.Menu.Picture);
    };

void MoveGame (BlockType ManyBlocks [], AllImageType AllImage, int* LevelNumber, ManType* Man, double* AllTemperature, CamType* Camera, CamType* FixedCamera, ManType* Villager)
    {
    int StartLevelNumber = *LevelNumber;

    int NumberPicture = 0;

    int Time = GetTickCount();

    ButtonType Pause = {Sign_PauseX - Sign_Pause_Radius, Sign_PauseY - Sign_Pause_Radius, 0};

    MouseType Mouse = {txMouseX(), txMouseY(), AllImage.Cursor};

    int t = 0;

    int NumberLevel = *LevelNumber;

    int PauseNumber = Pause_Active;

    COLORREF color = TX_BLACK;

    // CreateBlocks (ManyBlocks, AllImage);

    txBegin ();

    while (true)
        {
        txSetFillColor (color);
        txClear ();

        if (Man->Time <= 500)
            color = RGB (91, 110, 225);
        else
            color = RGB (18, 18, 33);

        NumberLevel = *LevelNumber;

        Time = Time + 1;

        int null = 0;

        Camera->MoveCamera (Man);

        // DrawTransparentImage (&AllImage.BackGround, 0, 0, &null, &null, FixedCamera);

        // txSetColor (RGB (143, 86, 59), 0);
        // txSetFillColor (RGB (143, 86, 59));
        // txRectangle (130, 700, 2410, 700);

        txSetColor (RGB (143, 86, 59), 1);
        txSetFillColor (RGB (143, 86, 59));
        txRectangle (-1390 - Camera->x, 700 - Camera->y, 3740 - Camera->x, 2000 - Camera->y);

        DrawManyBlocks (ManyBlocks, Camera, AllImage);

        txSetColor (TX_RED, 10);
        txLine (-1000000, 10000, 1000000, 10000);

        Man->DrawMan (Camera, AllImage);

        Man->Crafting (AllImage, FixedCamera);

        Man->DrawInventory (Camera, FixedCamera, AllImage);

        // Villager
        Villager->Physic ();
        InteractManWithBlocks (ManyBlocks, Villager, Camera, &Man->NumberCoin, LevelNumber, AllImage);
        Villager->DrawMan (Camera, AllImage);
        VillagerMind (Villager, Man, Camera, AllImage);

        DrawTransparentImage (&AllImage.Coin, Sign_CoinX, Sign_CoinY, &null, &null, FixedCamera);

        Man->ManFire (Camera, AllImage);
        Man->ManHealth (Camera, AllImage);
        Man->ManTemperature ();

        InteractManWithBlocks (ManyBlocks, Man, Camera, &Man->NumberCoin, LevelNumber, AllImage);

        Man->Physic ();

        Man->ControlMan (Mouse, &t);

        if (Pause.ButtonCheckClick (txMouseX(), txMouseY(), Sign_Pause_Radius, Sign_Pause_Radius) == true)
            {
            PauseNumber = Pause_Stopped;
            };

        Text (Sign_CoinTextX, Sign_CoinTextY, Coin_TextSize, Man->NumberCoin, "");

        Text (Sign_LevelTextX, Sign_LevelTextY, Level_TextSize, NumberLevel, "Level");

        Pause.DrawButton (FixedCamera, AllImage);

        DrawHealth (Man->Health, FixedCamera, AllImage);

        if (PauseNumber == Pause_Stopped)
            {
            Man->vX = 0;
            Man->vY = 0;

            Pause.Number = Pause_Stopped;

            if (Pause.ButtonCheckClick (txMouseX(), txMouseY(), Sign_Pause_Radius, Sign_Pause_Radius) == 1)
                PauseNumber = Pause_Active;
            }
        else
            Pause.Number = 0;

        if (Man->Temperature > *AllTemperature)
            {
            Man->Temperature -= (Man->Temperature - *AllTemperature)*0.001;
            };

        if (Man->Temperature < *AllTemperature)
            {
            Man->Temperature += (*AllTemperature - Man->Temperature)*0.001;
            };

        txSetColor (TX_RED);
        txSetFillColor (TX_RED);

        DrawTransparentImage (&AllImage.Termometer, Sign_TermometerX, Sign_TermometerY, &null, &null, FixedCamera);
        txRectangle (Sign_TermometerX + Sign_Term_RectLeftX, Sign_TermometerY + Sign_Term_RectDownY - Man->Temperature,
                     Sign_TermometerX + Sign_Term_RectRightX, Sign_TermometerY + Sign_Term_RectDownY);

        if (GetAsyncKeyState (VK_SPACE))
            {
            // HelpSystem ();
            };



        DrawCursor (&Mouse, FixedCamera);

        if (StartLevelNumber != *LevelNumber)
            {
            break;
            };

        if (GetAsyncKeyState (VK_ESCAPE))
            break;

        txSleep (Main_Sleep);
        };
    txEnd ();

    DeleteAllImage (AllImage);
    };

void CamType :: MoveCamera (ManType* Man)
    {
    /* if (GetAsyncKeyState (VK_RIGHT))
            {
            x += 5;
            };

    if (GetAsyncKeyState (VK_LEFT))
            {
            x -= 5;
            };

    if (GetAsyncKeyState (VK_CONTROL) &&
        GetAsyncKeyState (VK_UP))
            {
            y -= 10;
            };

    if (GetAsyncKeyState (VK_CONTROL) &&
        GetAsyncKeyState (VK_DOWN))
            {
            y += 10;
            }; */

    /* if (GetKeyState (VK_CAPITAL))
        printf ("x = %lf, y = %lf, Man->x = %lf, Man->y = %lf \n", x, y, Man->x, Man->y);
    else
        txClearConsole (); */

    int xDst = fabs (fabs (x - Man->x) - Screen_xCenter);
    int yDst = fabs (fabs (y - Man->y) - Screen_yCenter);

    /* if (xDst >= 500)
        vX = 0.02;
    else
        vX = 0;

    if (yDst >= 100)
        vY = 0.05;
    else
        vY = 0; */

    // $i printf ("Man->x = %lf, Man->y = %lf, Cam->x = %lf, Cam->y = %lf, xDst = %d, yDst = %d, vX = %lf, vY = %lf \n", Man->x, Man->y, x, y, xDst, yDst, vX, vY); $d

    x -= (x + Screen_xCenter - Man->x) * vX;
    y -= (y + Screen_yCenter - Man->y) * vY;
    };

void HelpSystem ()
    {
    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", Text1_Size);
    txTextOut (Text1_X, Text1_Y, "Для передвижения нажмите клавиши вправо и влево, для ускорения нажмите Shift");

    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", Text2_Size);
    txTextOut (Text2_X, Text2_Y, "Удачной игры!");
    };

void Text (int x, int y, int Size, int Number, char Name [])
    {
    char str [50] = "";

    sprintf (str, "%s %d", Name, Number);

    txSetTextAlign ();
    txSetColor (TX_WHITE);
    txSelectFont ("Comic Sans MS", Size);
    txTextOut (x, y, str);
    };

void DrawLoading (int Procents)
    {
    txSetColor (RGB (72, 72, 72));
    txSetFillColor (RGB (72, 72, 72));
    txRectangle (0, 0, 2000, 2000);
    txSetColor (TX_BLACK, 3);
    txRectangle (Load_BigRect_X1, Load_BigRect_Y1, Load_BigRect_X2, Load_BigRect_Y2);
    txSetFillColor (TX_GREEN);
    txRectangle (Load_SmallRect_X1, Load_SmallRect_Y1, 200+(11.50*Procents), Load_SmallRect_Y2);

    char str [50] = "";

    sprintf (str, "Loading: %d%%", Procents);

    txSetTextAlign ();
    txSetColor (TX_BLACK);
    txSelectFont ("Comic Sans MS", Loading_TextSize);
    txTextOut (Loading_TextX, Loading_TextY, str);
    };

int Timer (int Time)
    {
    int a = GetTickCount ();

    if ((GetTickCount() - a) >= Time*1000)
        return 1;

    return 0;
    };

void Level1 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera)
    {
    double AllTemperature = 10;

    if (Man->Days >= 0 &&
        Man->Days < 10)
            AllTemperature = 0;

    if (Man->Days >= 10 &&
        Man->Days < 20)
            AllTemperature = -20;

    if (Man->Days >= 20 &&
        Man->Days < 30)
            AllTemperature = 0;

    if (Man->Days >= 30 &&
        Man->Days < 40)
            AllTemperature = 40;

    BlockType ManyBlocks [] = {
                            {130, 500, 10, {0, 0, &AllImage.BackGround}, BT_Air},
                            {734, 500, 10, {0, 0, &AllImage.BackGround}, BT_Air},
                            {1338, 500, 10, {0, 0, &AllImage.BackGround}, BT_Air},
                            {1942, 500, 10, {0, 0, &AllImage.BackGround}, BT_Air},
                            {2546, 500, 10, {0, 0, &AllImage.BackGround}, BT_Air},
                            {3150, 500, 10, {0, 0, &AllImage.BackGround}, BT_Air},
                            {3754, 500, 10, {0, 0, &AllImage.BackGround}, BT_Air},
                            // Snow
                            {-1000, 100,    10, {0, 0, &AllImage.Snow}, BT_Snow},
                            {0,     100,    10, {0, 0, &AllImage.Snow}, BT_Snow},
                            {1000,  100,    10, {0, 0, &AllImage.Snow}, BT_Snow},
                            {2000,  100,    10, {0, 0, &AllImage.Snow}, BT_Snow},
                            // Grass
                            {0, 640, 10, {0, 0, &AllImage.Fire}, BT_Fire},
                            {130, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {320, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {510, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {700, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {890, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {1080, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {1270, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {1460, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {1650, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {1840, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {2030, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {2220, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {2410, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {2600, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {2790, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {2980, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {3170, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {3360, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {3550, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {-60, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {-250, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {-440, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {-630, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {-820, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {-1010, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {-1200, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            {-1390, 700, 10, {0, 0, &AllImage.Grass}, BT_Dirt},
                            // Rock
                            {-1010, 577, 100, {0, 0, &AllImage.Rock}, BT_Rock},
                            {-440, 577, 100, {0, 0, &AllImage.Rock}, BT_Rock},
                            // House
                            {590, 342, 10, {0, 0, &AllImage.House}, BT_House},
                            {590, 633, 10, {0, 0, &AllImage.BonFire}, BT_BonFire},
                            // Tree
                            {1270, 415, 100, {0, 0, &AllImage.Tree}, BT_Tree},
                            {1470, 415, 100, {0, 0, &AllImage.Tree}, BT_Tree},
                            {1870, 415, 100, {0, 0, &AllImage.Tree}, BT_Tree},
                            // End
                            {-1, -1, 1, {0, 0, &AllImage.Finish}, BT_Finish}};

    ManType Villager = {2125, 521, 20, {0, 0, &AllImage.Villager},
                        0, 0, Man_aX, 2,
                        0, 0, Man_Temperature,
                        0, 0, 0, "", MT_Seller, {0, 0, 0, rand() % 3, 0, 0, rand() % 3, 0, rand() % 3, 0}, 0, 0,
                        2125, 521, 0, 0};

    MoveGame (ManyBlocks, AllImage, LevelNumber, Man, &AllTemperature, Camera, FixedCamera, &Villager);
    };

void Level2 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera)
    {
    double AllTemperature = 10;


    if (Man->Days >= 0 &&
        Man->Days < 10)
            AllTemperature = 10;

    if (Man->Days >= 10 &&
        Man->Days < 20)
            AllTemperature = 0;

    if (Man->Days >= 20 &&
        Man->Days < 30)
            AllTemperature = 10;

    if (Man->Days >= 30 &&
        Man->Days < 40)
            AllTemperature = 40;

    BlockType ManyBlocks [] = {// Ground
                               { -75,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { -25,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 25,   675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 75,   675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 125,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 175,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 225,  675, 6, {rand() % 4, 0, &AllImage.Water}, BT_Water},
                               { 275,  675, 6, {rand() % 4, 0, &AllImage.Water}, BT_Water},
                               { 325,  675, 6, {rand() % 4, 0, &AllImage.Water}, BT_Water},
                               { 375,  675, 6, {rand() % 4, 0, &AllImage.Water}, BT_Water},
                               { 425,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 475,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 525,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 575,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 625,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 675,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 725,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 775,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 825,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 875,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 925,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 975,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1025,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1075,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1125,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1175,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1225,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1275,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1325,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1375,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1425,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1475,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1525,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1575,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1625,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1675,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1725,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1775,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1825,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1875,  675, 6, {rand() % 4, 0, &AllImage.Water}, BT_Water},
                               {1925,  675, 6, {rand() % 4, 0, &AllImage.Water}, BT_Water},
                               {1975,  675, 6, {rand() % 4, 0, &AllImage.Water}, BT_Water},
                               {2025,  675, 6, {rand() % 4, 0, &AllImage.Water}, BT_Water},
                               {2075,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2125,  675, 6, {0, 0, &AllImage.IronOre}, BT_Dirt},
                               {2175,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2225,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2275,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2325,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2375,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2425,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2475,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2525,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2575,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2625,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2675,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2725,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2775,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2825,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2875,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2925,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2975,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {3025,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {3075,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {3125,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {3175,  675, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},

                               { -75,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { -25,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {  25,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {  75,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 125,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 175,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 225,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 275,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 325,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 375,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 425,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 475,  725, 6, {0, 0, &AllImage.IronOre}, BT_Dirt},
                               { 525,  725, 6, {0, 0, &AllImage.IronOre}, BT_Dirt},
                               { 575,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 625,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 725,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 725,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 775,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 825,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 875,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 925,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 975,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1025,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1075,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1125,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1175,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1225,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1275,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1325,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1375,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1425,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1475,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1525,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1575,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1625,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1675,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1725,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1775,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1825,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1875,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1925,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1975,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2025,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2075,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2125,  725, 6, {0, 0, &AllImage.IronOre}, BT_Dirt},
                               {2175,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2225,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2275,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2325,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2375,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2425,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2475,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2525,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2575,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2625,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2675,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2725,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2775,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2825,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2875,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2925,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {2975,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {3025,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {3075,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {3125,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {3175,  725, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               // Platforms
                               { 100,  200, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 150,  200, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 200,  200, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 250,  200, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 300,  200, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 350,  200, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 200,  500, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 250,  500, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 300,  500, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 350,  500, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 450,  400, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 500,  400, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 550,  400, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 550,  100, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 600,  100, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 650,  100, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 700,  100, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 850,  300, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 900,  300, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               { 950,  300, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1050,  150, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1100,  150, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1150,  150, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1300,  250, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1350,  250, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1400,  250, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1450,  250, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1500,  250, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               {1550,  250, 6, {0, 0, &AllImage.Dirt}, BT_Dirt},
                               // Boxes
                               { 100,  625, 2, {0, 0, &AllImage.Box},  BT_Box},
                               {  50,  625, 2, {0, 0, &AllImage.Box},  BT_Box},
                               { 100,  575, 2, {0, 0, &AllImage.Box},  BT_Box},
                               // Fire
                               { 900,  615, 4, {1, 0, &AllImage.Fire},  BT_Fire},
                               { 800,  615, 4, {3, 0, &AllImage.Fire},  BT_Fire},
                               // Stalactites
                               { 100,  250, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 150,  250, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 200,  250, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 250,  250, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 300,  250, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 350,  250, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 200,  550, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 250,  550, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 300,  550, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 350,  550, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 450,  450, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 500,  450, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 550,  450, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 550,  150, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 600,  150, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 650,  150, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 700,  150, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 850,  350, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 900,  350, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               { 950,  350, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               {1050,  200, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               {1100,  200, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               {1150,  200, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               {1300,  300, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               {1350,  300, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               {1400,  300, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               {1450,  300, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               {1500,  300, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               {1550,  300, 7, {0, 0, &AllImage.Stalactite},  BT_Stalactite},
                               // Stairs
                               { 700,  592, 3, {0, 0, &AllImage.Stairs}, BT_Stairs},
                               { 700,  509, 3, {0, 0, &AllImage.Stairs}, BT_Stairs},
                               { 700,  426, 3, {0, 0, &AllImage.Stairs}, BT_Stairs},
                               { 700,  343, 3, {0, 0, &AllImage.Stairs}, BT_Stairs},
                               { 700,  260, 3, {0, 0, &AllImage.Stairs}, BT_Stairs},
                               { 700,  177, 3, {0, 0, &AllImage.Stairs}, BT_Stairs},
                               { 700,   94, 3, {0, 0, &AllImage.Stairs}, BT_Stairs},
                               // Chests
                               {1300,  625, 6, {0, 0, &AllImage.Chest}, BT_Chest},
                               // Things
                               {1175,  625, 16, {0, 0, &AllImage.Pickaxe}, BT_Pickaxe},
                               { 250,  450, 16, {0, 0, &AllImage.Pickaxe}, BT_Pickaxe},
                               // Coins
                               {160,  165, 1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               {310,  165, 1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               {260,  465, 1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               {310,  465, 1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               {510,  365, 1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               {560,  65,  1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               {710,  65,  1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               {910,  265, 1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               {1110, 115, 1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               {1360, 215, 1, {0, 0, &AllImage.CoinAnimation}, BT_Coin},
                               // Start
                               {-100, -1000000, 1, {0, 0, &AllImage.Start}, BT_Start},
                               // Finish
                               {1450, -1000000, 1, {0, 0, &AllImage.Finish}, BT_Finish},
                               // End
                               {-1, -1000000, 1, {0, 0, &AllImage.Finish}, BT_Finish}};

    ManType Villager = {2125, 0, 20, {0, 0, &AllImage.Villager},
                        0, 0, Man_aX, 2,
                        0, 0, Man_Temperature,
                        0, 0, 0, "", 1, {}, 0, 0,
                        0, 0, 0, 0};

    MoveGame (ManyBlocks, AllImage, LevelNumber, Man, &AllTemperature, Camera, FixedCamera, &Villager);
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
    if (Collision (Coin, Man) == true)
        {
        *NumberCoin += 1;
        Coin->Health = 0;
        };
    };
    };

void DrawLevelPeople (ManType Villagers[], CamType* Camera, AllImageType AllImage)
    {
    int i = 0;

    while (Villagers[i].x != -1 && Villagers[i].y != -1)
        {
        // DrawMan (&Villagers [i], Camera, AllImage);

        i = i + 1;
        };
    };

void LoadGameImage (ImageType* Image, const char* Picture, int xMaxFrame, int yMaxFrame, COLORREF color,
                        int* Procent, double Number)
    {
    *Procent += 100.0/Number;

    DrawLoading (*Procent);

    // printf ("LoadGameImage(): Picture = \"%s\" \n", Picture);

    // *Image = {Picture, xFrame, yFrame, xMaxFrame, yMaxFrame, txLoadImage (Picture), color};

    Image->FileName = Picture;

    Image->xMaxAnimationNumber = xMaxFrame;

    Image->yMaxAnimationNumber = yMaxFrame;

    Image->Picture = txLoadImage (Picture);

    Image->color = color;

    if (Image->Picture == 0)
        {
        // printf ("FileName = \"%s\" \n", Image->FileName);
        };

    // printf ("LoadGameImage(): FileName = \"%s\", HDC = \"%p\" \n", Image->FileName, Image->Picture);

    txSleep (Loading_Sleep);
    };

void DrawTransparentImage (ImageType* Image, int x, int y, int* xAnimationNumber, int* yAnimationNumber, CamType* Camera)
    {
    // printf ("DrawTransparentImage(): FileName = \"%s\", HDC = \"%p\" \n", Image.FileName, Image.Picture);

    int xSize = txGetExtentX (Image->Picture)/Image->xMaxAnimationNumber;
    int ySize = txGetExtentY (Image->Picture)/Image->yMaxAnimationNumber;

    txTransparentBlt (txDC (), x - Camera->x, y - Camera->y, xSize, ySize, Image->Picture, *xAnimationNumber*xSize, *yAnimationNumber*ySize, Image->color);
    };

void DrawLevelBlocks (BlockType ManyBlocks[], CamType* Camera, AllImageType AllImage)
    {
    int i = 0;

    while (ManyBlocks [i].x != -1 && ManyBlocks [i].y != -1)
        {
        ManyBlocks [i].DrawBlock (Camera, AllImage);

        i = i + 1;
        };
    };


void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man, CamType* Camera, int* NumberCoin, AllImageType AllImage)
    {
    int i = 0;

    while (ManyBlocks [i].x != -1 && ManyBlocks [i].y != -1)
        {
        BlockCollision (Man, &ManyBlocks [i], Camera, AllImage);

        CoinCollision (Man, &ManyBlocks [i], NumberCoin);

        i = i + 1;
        };
    };

void BlockCalling (BlockType* Block, ManType* Man, CamType* Camera)
    {
    // BlockCollision (Man, Block, Camera);
    };

void ManType :: ControlMan (MouseType Mouse, int* t)
    {
    if (GetAsyncKeyState (VK_HOME))
        {
        y = -1000;
        x = 100;
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
        xWeapon += 1;
    else
        if (Inventory.MainNumber == 0 &&
            Inventory.MainSlot > 0)
        {
        xWeapon -= 1;
        // ArmSpeed = 100;
        };


    if (xWeapon < 0)
        xWeapon = 0;

    ArmSpeed += 1;

    // Berries
    if (GetAsyncKeyState (VK_LBUTTON) &&
        Inventory.MainNumber == 3 &&
        Inventory.MainSlot > 0 &&
        Health < 20)
        {
        Health += 1;
        Inventory.Apple -= 1;
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
    };

void ManType :: Physic ()
    {
    x = x + vX;
    y = y + vY;

    vX = vX + aX;
    vY = vY + aY;

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
    Time += 100;

    if (Time >= 1000)
        Time = 0;

    if (Time == 900)
        Days += 1;

    if (Days >= 40)
        Days = 0;

    // printf ("Days = %d \n", Days);
    };

void BlockCollision (ManType* Man, BlockType* Block, CamType* Camera, AllImageType AllImage)
    {
    int null = 0;
    int two = 2;
    int three = 3;
    int four = 4;

    // Rock
    if (Block->Number == BT_Rock)
    {
    if (Man->Inventory.MainNumber == 0 &&
        Man->Inventory.MainSlot > 0 &&
        fabs (Block->x + Block_BaseWide - Man->x) <= Block_BaseWide + Man_Wide + 100 &&
        ModuleDistance (Block->x + 90 - Camera->x, Block->y + 50 - Camera->y , txMouseX(), txMouseY(), 50) == true &&
        GetAsyncKeyState (VK_LBUTTON) &&
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

    // BonFire
    if (Block->Number == BT_BonFire)
        {
        if (Block->Health <= 3)
        {
        Block->Animation.yFrame = 0;
        if (Man->Temperature < 10 &&
            fabs (Block->x - Man->x) <= 200)
        Man->Temperature += 0.025;
        };

        if (Block->Health > 3 &&
            Block->Health <= 6)
            {
        Block->Animation.yFrame = 1;
        if (Man->Temperature < 32 &&
            fabs (Block->x - Man->x) <= 200)
        Man->Temperature += 0.05;
        };

        if (Block->Health > 6 &&
            fabs (Block->x - Man->x) <= 200)
        {
        Block->Animation.yFrame = 2;
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

        if (Man->Inventory.MainNumber == 1 &&
            Man->Inventory.MainSlot > 0 &&
            ModuleDistance (Block->x + 30 - Camera->x, Block->y + 30 - Camera->y, txMouseX(), txMouseY(), 100) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Block->Health <= 6 &&
            Block->Health > 0)
            {
            Man->Inventory.Wood -= 1;
            Block->Health += 3;
            };
        };

    // Year
    if (Block->Number == BT_Dirt)
    {
    if (Man->Days >= 0 &&
        Man->Days < 10)
            Block->Animation.yFrame = 0;

    if (Man->Days >= 10 &&
        Man->Days < 20)
            Block->Animation.yFrame = 1;

    if (Man->Days >= 20 &&
        Man->Days < 30)
            Block->Animation.yFrame = 2;

    if (Man->Days >= 30 &&
        Man->Days < 40)
            Block->Animation.yFrame = 3;
    };

    if (Block->Number == BT_Tree)
    {
    if (Man->Days >= 0 &&
        Man->Days < 10)
            Block->Animation.yFrame = 0;

    if (Man->Days >= 10 &&
        Man->Days < 20)
            Block->Animation.yFrame = 1;

    if (Man->Days >= 20 &&
        Man->Days < 30)
            Block->Animation.yFrame = 2;

    if (Man->Days >= 30 &&
        Man->Days < 40)
            Block->Animation.yFrame = 3;
    };

    if (Block->Number == BT_Snow)
        {
        if (Man->Days >= 10 &&
            Man->Days < 20)
            Block->Animation.yFrame = 0;
        else
            Block->Animation.yFrame = 1;
        };

    // House
    if (fabs (Block->x + 150 - Man->x) <= Man_Wide + 40 &&
        Block->Number == BT_House &&
        Man->Position != House_Position &&
        Man->Kind == 0)
        {
        DrawTransparentImage (&AllImage.Pause, Block->x + 180, Block->y + 100, &null, &two, Camera);
        if (ModuleDistance (Block->x + 180 - Camera->x, Block->y + 100 - Camera->y ,
                            txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            Man->Position = House_Position;
        };

    if (Block->Number == BT_House &&
        Man->Position == House_Position)
        {
        Block->Animation.yFrame = 1;

        DrawTransparentImage (&AllImage.Pause, Block->x + 420, Block->y + 120, &null, &three, Camera);
        if (ModuleDistance (Block->x + 420 - Camera->x, Block->y + 120 - Camera->y ,
                            txMouseX(), txMouseY(), 50) == true &&
            GetAsyncKeyState (VK_LBUTTON))
            Man->Position = Normal_Position;

        if (Man->x >= Block->x + 460 &&
            Man->vX > 0)
            Man->vX = 0;

        if (Man->x <= Block->x + 80 &&
            Man->vX < 0)
            Man->vX = 0;
        };

    if (Block->Number == BT_House &&
        Man->Position == OutSide_Position)
        {
        if (Man->x >= Block->x &&
            Man->x <= Block->x + 500)
        Man->x = Block->x - 200;
        };

    if (Block->Number == BT_House &&
        Man->Position != House_Position)
        Block->Animation.yFrame = 0;

    if (Block->Number == BT_Fire)
        {
        if (Man->Time >= 500)
            Block->Animation.yFrame = 1;
        else
            Block->Animation.yFrame = 0;
            };
    if (Block->Number == BT_Air)
        {
        if (Man->Time >= 500)
            Block->Animation.yFrame = 1;
        else
            Block->Animation.yFrame = 0;
            };

    if (Man->y >= 10000)
        Man->Health -= 1;

    if (Block->Number == BT_Fire)
        {
        if (Collision (Block, Man) == true)
            {
            Camera->Timer = GetTickCount () + 30000;
            };
        };

    // Tree
    if (Block->Number == BT_Tree)
        {
        /*if (Man->Time >= 500)
            Block->Animation.yFrame = 1;
        else
            Block->Animation.yFrame = 0; */

        if (Man->Inventory.MainNumber == 0 &&
            Man->Inventory.MainSlot > 0 &&
            fabs (Block->x + Block_BaseWide - Man->x) <= Block_BaseWide + Man_Wide + 100 &&
            ModuleDistance (Block->x + 140 - Camera->x, Block->y + 215 - Camera->y , txMouseX(), txMouseY(), 140) == true &&
            GetAsyncKeyState (VK_LBUTTON) &&
            Man->ArmSpeed >= 10)
            {
            Block->Health -= 10;
            // Block->Animation.yFrame = 2;
            Man->ArmSpeed = 0;
            };

        if (Block->Health <= 20 &&
            Block->Health > 0)
            {
            Man->Inventory.Wood += 2;
            if (Man->Days >= 30 &&
                Man->Days < 40)
                Man->Inventory.Apple += 1;
            Block->Health = 0;
            };
        };

    if (Block->Number != BT_Coin)
    {

    // Physic
    if (Block->Health  >= 1 &&
        Block->Number != BT_Fire &&
        Block->Number != BT_Water &&
        Block->Number != BT_Stalactite &&
        Block->Number != BT_BonFire &&
        Block->Number < BT_Pickaxe)
    {
    if (fabs (Block->x + Block_BaseWide - Man->x) <= Block_BaseWide + Man_Wide &&
        Block->y + Block_BaseHigh - Man->y <= Block_BaseHigh + txGetExtentY (Man->Animation.Picture->Picture) / Man->Animation.Picture->yMaxAnimationNumber &&
        Block->y + Block_BaseHigh - Man->y  >=  0)
            {
            if (GetAsyncKeyState (VK_UP) &&
                Man->Kind == MT_Main)
                {
                Man->vY = -Man_JumpSpeed;
                };

            if (Man->vY > 0)
                {
                Man->vY = 0;
                Man->y = Block->y - Man_High;
                };
            };

    // Walls
    if (Block->Health  >= 1 &&
        Block->Number != BT_Fire &&
        Block->Number != BT_Water &&
        Block->Number != BT_Stalactite &&
        Block->Number < BT_Pickaxe)
            {
            if (fabs (Block->x + Block_BaseWide - Man->x) <= Block_BaseWide + Man_Wide &&
                Block->y + Block_BaseHigh > Man->y &&
                Block->y < Man->y + Man_High)
                {
                if (Block->x <= Man->x + Man_Wide &&
                    Man->vX > 0)
                        Man->vX = 0;

                if (Block->x + Block_BaseWide >= Man->x &&
                    Man->vX < 0)
                        Man->vX = 0;
                };
            };

    /* if ((Block->x - Man->x - Man_Wide) <= Man_Wide + 2 &&
        (Block->x - Man->x - Man_Wide) >= 0 &&
        Block->y + Block_BaseHigh - Man->y <= Block_BaseHigh + Man_High &&
        Block->y + Block_BaseHigh - Man->y  >=  0 &&
        Man->vX > 0)
            Man->vX = 0;

    if ((Man->x - Block->x - Block_BaseWide) <= Block_BaseWide + 2 &&
        (Man->x - Block->x - Block_BaseWide) >= 0 &&
        Block->y + Block_BaseHigh - Man->y <= Block_BaseHigh + Man_High &&
        Block->y + Block_BaseHigh - Man->y  >=  0 &&
        Man->vX < 0)
            Man->vX = 0; */

        };

    // Destroying
    if (Block->Health > 0 &&
        Block->Health < 50 &&
        Block->Number != BT_Fire &&
        Block->Number != BT_Berries &&
        Block->Number != BT_Chest)
    {
    /* if (ModuleDistance (Block->x + Block_BaseWide + Man->x, Block->y + Block_BaseHigh + Man->x, txMouseX(), txMouseY(), Block_BaseWide) == true)
        if (GetAsyncKeyState (VK_LBUTTON) &&
            Man->LeftArm == BT_Pickaxe &&
            Block->Health > 1)
               Block->Health -= 1;

    if (ModuleDistance (Block->x + Block_BaseWide + Man->x, Block->y + Block_BaseHigh + Man->x, txMouseX(), txMouseY(), Block_BaseWide) == true)
        if (GetAsyncKeyState (VK_RBUTTON) &&
            Man->RightArm == BT_Pickaxe &&
            Block->Health > 1)
               Block->Health -= 1; */

    };

    // Boxes
    if (Block->Number == BT_Box)
        {
        if (Collision (Block, Man) == true)
            {
            Block->Health = Block->Health - 0.005;
            };
        };

    // Fire
    if (Block->Number == BT_Fire)
        {
        if (Collision (Block, Man) == true)
            {
            Man->Position = Fire_Position;
            Man->Temperature += 0.5;
            };
        };

    // Water
    if (Block->Number == BT_Water)
        {
        if (Collision (Block, Man) == true)
            {
            Man->Position = Normal_Position;
            };
        };

    // High
    if (Block->x + Block_BaseWide - Man->x >= Block_BaseWide + Man_Wide &&
        Block->x + Block_BaseWide - Man->x <= 0   &&
        Block->y + Block_BaseHigh - Man->y <= Block_BaseHigh + Man_High &&
        Block->y + Block_BaseHigh - Man->y > 0    &&
        Man->vY >= Man_FallingSpeed)
            {
            Man->Health -= 3;
            };

    // Things
    if (Block->Number > BT_Pickaxe &&
        Block->Number <= BT_Berries &&
        Block->Health > 0)
            {
            /* if (ModuleDistance (Block->x+Block_BaseWide-Camera->x, Block->y+Block_BaseHigh-Camera->y, txMouseX(), txMouseY(), Block_BaseWide) == true &&
                GetAsyncKeyState (VK_MBUTTON))
                    {
                    if (Man->LeftArm == BT_BlackSpace)
                        {
                        Man->LeftArm = Block->Number;
                        Man->ArmPicture = Block->Animation.Picture;
                        Block->Health = 0;
                        }
                else
                if (Man->RightArm == BT_BlackSpace)
                    {
                    Man->RightArm = Block->Number;
                    Man->ArmPicture = Block->Animation.Picture;
                    Block->Health = 0;
                    };
            }; */
            };

    // Food
   /*  if (Man->LeftArm >= BT_Berries &&
        GetAsyncKeyState (VK_NUMPAD1))
            {
            Man->LeftArm = BT_BlackSpace;
            Man->Health += 4;
            };

    if (Man->RightArm >= BT_Berries &&
        GetAsyncKeyState (VK_NUMPAD2))
            {
            Man->RightArm = BT_BlackSpace;
            Man->Health += 4;
            };

    if (ModuleDistance (Block->x+Block_BaseWide-Camera->x, Block->y+Block_BaseHigh-Camera->x, txMouseX(), txMouseY(), Block_BaseWide) == true &&
        Block->Number > BT_Berries &&
        Block->Health == Block_MaxHealth &&
        GetAsyncKeyState (VK_RETURN))
        {
        if (Man->LeftArm == 0)
            {
            Man->LeftArm = Block->Number;
            Man->ArmPicture = Block->Animation.Picture;
            Block->Health = 1;
            }
        else
        if (Man->RightArm == 0)
            {
            Man->RightArm = Block->Number;
            Man->ArmPicture = Block->Animation.Picture;
            Block->Health = 1;
            };  */
        };

    // Berries

    // 111
    // int null = 0;

    /* if (Block->Health > 0 &&
        Block->Number == BT_Berries)
            {
            if (Block->Health < 50 &&
                Block->Health > 0)
                Block->Animation.xFrame = 2;
            if (Block->Health >= 50 &&
                Block->Health < 100)
                Block->Animation.xFrame = 1;
            if (Block->Health >= 100)
                Block->Animation.xFrame = 3;

            if (ModuleDistance (Block->x + 25 - Camera->x, Block->y + 25 - Camera->y , txMouseX(), txMouseY(), 50) == true &&
                GetAsyncKeyState (VK_LBUTTON) &&
                Block->Health >= 100)
                {
                Block->Health = 1;
                Man->Inventory.Berries += 1;
                };

            Block->Health += 1;
            }; */

    };

int ModuleDistance (int x1, int y1, int x2, int y2, int Distance)
    {
    if (fabs (x1 - x2) <= Distance)
        {
        if (fabs (y1 - y2) <= Distance)
            {
            return 1;
            };
        };

    return 0;
    };

int ButtonType :: ButtonCheckClick (int x2, int y2, int DstX, int DstY)
    {
    if (fabs (x - x2) <= DstX)
        if (fabs (y - y2) <= DstY)
            if (GetAsyncKeyState (VK_LBUTTON))
                {
                return 1;
                };
    return 0;
    };

void DrawHealth (int Health, CamType* Camera, AllImageType AllImage)
    {
    int null = 0;
    int one  = 1;

    DrawTransparentImage (&AllImage.Coin, Sign_HealthX, Sign_HealthY, &one, &null, Camera);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (60, 120, 160, 140);
    txSetFillColor (RGB (237, 28, 36));
    txRectangle (60, 120, 60+(Health*5), 140);
    };



