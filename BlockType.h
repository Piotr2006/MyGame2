#ifndef BLOCKTYPE_H
#define BLOCKTYPE_H

// #include "ManType.h"
#include "AllImageType.h"
#include "Enums.h"
#include "BaseType.h"
#include "CamType.h"
#include "ImageFunctions.h"
#include "SmallHelpFunctions.h"

struct ManType;

struct BlockType : BaseType
    {
    BlockType ();

    BlockType (PointType Point, double Health, AnimationType Animation,
               int Number, void (*_Function) (ManType* Man, BlockType* Block, CamType* Camera));



    void DrawBlock (CamType* Camera);

    int Number;

    void (*Function) (ManType* Man, BlockType* Block, CamType* Camera);

    virtual void Interaction (ManType* Man, BlockType* Block, CamType* Camera)
        {
        Function (Man, Block, Camera);
        };
    };

void FallingTreeInteraction (ManType* Man, BlockType* Block, CamType* Camera);

void SmallStoneInteraction (ManType* Man, BlockType* Block, CamType* Camera);

void RockInteraction (ManType* Man, BlockType* Block, CamType* Camera);

void BonfireInteraction (ManType* Man, BlockType* Block, CamType* Camera);

void TreeInteraction (ManType* Man, BlockType* Block, CamType* Camera);

void DynamiteInteraction (ManType* Man, BlockType* Block, CamType* Camera);

void CaseInteraction (ManType* Man, BlockType* Block, CamType* Camera);

void AirInteraction (ManType* Man, BlockType* Block, CamType* Camera);

struct TreeType : BlockType
    {
    TreeType (PointType Point, double Health, AnimationType Animation,
               int Number, void (*_Function) (ManType* Man, BlockType* Block, CamType* Camera));

    virtual void Interaction (ManType* Man, BlockType* Block, CamType* Camera)
        {
        TreeInteraction (Man, Block, Camera);
        };

    };

//-----------------------------------------------------------------------------

void DrawLevelBlocks (BlockType* ManyBlocks[], CamType* Camera);

void CoinCollision (BlockType* Coin);

void CreateBlocks (BlockType* Blocks []);

void BlockFunction (BlockType* Blocks [], int Time);

void DrawManyBlocks (BlockType* ManyBlocks [], CamType* Camera);

void InteractManWithBlocks (BlockType* ManyBlocks [], ManType* Man, CamType* Camera, int* NumberCoin);

void CallLevelPhysic (BlockType* ManyBlocks[], ManType* Man, CamType* Camera);

//-----------------------------------------------------------------------------

#endif
