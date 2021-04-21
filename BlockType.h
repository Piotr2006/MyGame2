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
               int Number, void (*_Function) (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage));

    void DrawBlock (CamType* Camera, AllImageType AllImage);

    int Number;

    void (*Function) (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage);
    };

//-----------------------------------------------------------------------------

void DrawLevelBlocks (BlockType ManyBlocks[], CamType* Camera, const AllImageType& AllImage);

void CoinCollision (ManType* Man, BlockType* Coin, int* NumberCoin);

void CreateBlocks (BlockType Blocks [], const AllImageType& AllImage);

void DrawManyBlocks (BlockType ManyBlocks [], CamType* Camera, const AllImageType& AllImage);

void InteractManWithBlocks (BlockType ManyBlocks [], ManType* Man, CamType* Camera, int* NumberCoin, int* LevelNumber, const AllImageType& AllImage);

void CallLevelPhysic (BlockType ManyBlocks[], ManType* Man, CamType* Camera, int* NumberCoin, const AllImageType& AllImage);

void BlockCalling (BlockType* Block, ManType* Man, CamType* Camera);

//-----------------------------------------------------------------------------

void FallingTreeInteraction (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage);

void SmallStoneInteraction (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage);

void RockInteraction (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage);

void BonfireInteraction (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage);

void TreeInteraction (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage);

void DynamiteInteraction (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage);

void CaseInteraction (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage);

void AirInteraction (ManType* Man, BlockType* Block, CamType* Camera, const AllImageType& AllImage);

#endif
