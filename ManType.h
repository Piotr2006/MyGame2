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

// typedef void (*FunctionType) (BlockType* Block, CamType* Camera, const AllImageType& AllImage);

struct ManType : BaseType
    {
    ManType (PointType Point, double _Health, AnimationType Animation,
             PointType Speed, PointType _Acceleration,
             int _Side, int _Position, double _Temperature,
             int _NumberCoin, int _xWeapon, int _ArmSpeed, char _Name [50], int _Kind, InvType _Inventory,
             int _Time, int _Days, double _ArrowX, double _ArrowY, int _ArrowVX, int _ArroeVY, HelpType _HelpSystem);

    void DrawMan (CamType* Camera, const AllImageType& AllImage);

    void DrawInventory (CamType* Camera, const AllImageType& AllImage);

    void Crafting (const AllImageType& AllImage);

    void ManTemperature ();

    void ManFire (CamType* Camera, const AllImageType& AllImage);

    void ManHealth (CamType* Camera, const AllImageType& AllImage);

    void ControlMan (const MouseType& Mouse, int* t);

    void VillagerMind (ManType* Man, CamType* Camera, const AllImageType& AllImage);

    void BlockCollision (BlockType* Block, CamType* Camera, const AllImageType& AllImage);

    void BlockInteraction (BlockType* Block, CamType* Camera, const AllImageType& AllImage);

    void Physic ();

    PointType Speed;

    PointType Acceleration;

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
    int ArroeVY;

    HelpType HelpSystem;
    };

void DrawSlot (int Block, int x, int y, const ImageType& Picture, int TextX, int TextY);

void CreateVillagers (ManType Villagers [], const AllImageType& AllImage);

void DrawLevelPeople (ManType Villagers[], CamType* Camera, const AllImageType& AllImage);

void CallPeoplePhysic (ManType Villagers[], CamType* Camera, const AllImageType& AllImage, BlockType ManyBlocks [], ManType* Man);


//-----------------------------------------------------------------------------

#endif
