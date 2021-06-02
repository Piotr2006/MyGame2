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
               int Number);



    void DrawBlock (CamType* Camera);

    int Number;

    virtual bool Detection (ManType* Man, CamType* Camera);

    virtual void Interaction (ManType* Man, CamType* Camera) = 0;
    };

//-----------------------------------------------------------------------------

struct DirtType : BlockType
    {
    using BlockType :: BlockType;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

struct TreeType : BlockType
    {
    using BlockType :: BlockType;

    virtual bool Detection (ManType* Man, CamType* Camera) override;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

struct FallingTreeType : BlockType
    {
    using BlockType :: BlockType;

    virtual bool Detection  (ManType* Man, CamType* Camera) override;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

struct SmallStoneType : BlockType
    {
    using BlockType :: BlockType;

    // virtual bool Detection  (ManType* Man, CamType* Camera) override;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

struct RockType : BlockType
    {
    using BlockType :: BlockType;

    virtual bool Detection  (ManType* Man, CamType* Camera) override;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

struct BonfireType : BlockType
    {
    using BlockType :: BlockType;

    virtual bool Detection  (ManType* Man, CamType* Camera) override;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

struct DynamiteType : BlockType
    {
    using BlockType :: BlockType;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

struct CaseType : BlockType
    {
    using BlockType :: BlockType;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

struct AirType : BlockType
    {
    using BlockType :: BlockType;

    virtual bool Detection  (ManType* Man, CamType* Camera) override;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

struct StairsType : BlockType
    {
    using BlockType :: BlockType;

    virtual bool Detection  (ManType* Man, CamType* Camera) override;

    virtual void Interaction (ManType* Man, CamType* Camera) override;
    };

//-----------------------------------------------------------------------------

// void BlocksSaving (BlockType* Blocks []);

void DrawLevelBlocks (BlockType* ManyBlocks[], CamType* Camera);

void CoinCollision (BlockType* Coin);

void CreateBlocks (BlockType* Blocks []);

void BlockFunction (BlockType* Blocks [], int Time);

void DrawManyBlocks (BlockType* ManyBlocks [], CamType* Camera);

void InteractManWithBlocks (BlockType* ManyBlocks [], ManType* Man, CamType* Camera, int* NumberCoin);

void CallLevelPhysic (BlockType* ManyBlocks[], ManType* Man, CamType* Camera);

//-----------------------------------------------------------------------------

#endif
