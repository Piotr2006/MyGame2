#ifndef MANTYPE_H
#define MANTYPE_H

#include "HelpSystem.h"
#include "BaseType.h"
#include "CamType.h"
#include "AllImageType.h"
#include "BlockType.h"
#include "InvType.h"
#include "MouseType.h"
#include "Enums.h"

struct BlockType;

struct ManType : BaseType
    {
    ManType (double x, double y, double _Health, AnimationType Animation,
             double _vX, double _vY, double _aX, double _aY,
             int _Side, int _Position, double _Temperature,
             int _NumberCoin, int _xWeapon, int _ArmSpeed, char _Name [50], int _Kind, InvType _Inventory,
             int _Time, int _Days, double _ArrowX, double _ArrowY, int _ArrowVX, int _ArrowVY, HelpType _HelpSystem);

    void DrawMan (CamType* Camera, AllImageType AllImage);

    void DrawInventory (CamType* Camera, CamType* FixedCamera, AllImageType AllImage);

    void Crafting (AllImageType AllImage, CamType* FixedCamera);

    void ManTemperature ();

    void ManFire (CamType* Camera, AllImageType AllImage);

    void ManHealth (CamType* Camera, AllImageType AllImage);

    void ControlMan (MouseType Mouse, int* t);

    void VillagerMind (ManType* Man, CamType* Camera, AllImageType AllImage);

    void BlockCollision (BlockType* Block, CamType* Camera, AllImageType AllImage);

    void BlockInteraction (BlockType* Block, CamType* Camera, AllImageType AllImage);

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

    HelpType HelpSystem;
    };

void DrawSlot (int Block, int x, int y, ImageType Picture, int TextX, int TextY);

void CreateVillagers (ManType Villagers [], AllImageType AllImage);

void DrawLevelPeople (ManType Villagers[], CamType* Camera, AllImageType AllImage);

void CallPeoplePhysic (ManType Villagers[], CamType* Camera, AllImageType AllImage, BlockType ManyBlocks [], ManType* Man);

#endif
