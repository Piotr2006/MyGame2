#ifndef BLOCKTYPE_H
#define BLOCKTYPE_H

#include "AllImageType.h"
#include "Enums.h"
#include "BaseType.h"
#include "CamType.h"
#include "ImageFunctions.h"
#include "SmallHelpFunctions.h"

struct ManType;

struct BlockType : BaseType
    {
    BlockType (PointType Point, double Health, AnimationType Animation,
               int Number);

    void DrawBlock (CamType* Camera, AllImageType AllImage);

    int Number;
    };



//-----------------------------------------------------------------------------

void DrawLevelBlocks (BlockType ManyBlocks[], CamType* Camera, AllImageType AllImage);

void CoinCollision (ManType* Man, BlockType* Coin, int* NumberCoin);

void CreateBlocks (BlockType Blocks [], AllImageType AllImage);

void DrawManyBlocks (BlockType ManyBlocks [], CamType* Camera, AllImageType AllImage);

void InteractManWithBlocks (BlockType ManyBlocks [], ManType* Man, CamType* Camera, int* NumberCoin, int* LevelNumber, AllImageType AllImage);

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man, CamType* Camera, int* NumberCoin, AllImageType AllImage);

void BlockCalling (BlockType* Block, ManType* Man, CamType* Camera);

//-----------------------------------------------------------------------------
#endif
