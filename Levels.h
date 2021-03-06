#ifndef LEVELS_H
#define LEVELS_H

#include "AllImageType.h"
#include "Enums.h"
#include "ImageType.h"
#include "AnimationType.h"
#include "BaseType.h"
#include "InvType.h"
#include "CamType.h"
#include "ManType.h"
#include "ButtonType.h"
#include "BlockType.h"

void Reading (ManType* Man, BlockType* Blocks[]);

void Saving (ManType* Man, BlockType* Blocks[]);

int MoveGame (BlockType* ManyBlocks [], int* LevelNumber, ManType* Man, double* AllTemperature, CamType* Camera, ManType Villagers []);

int Level1 (int* LevelNumber, ManType* Man, CamType* Camera, BlockType* Blocks[]);

void TestLevel (int* LevelNumber, ManType* Man, CamType* Camera, BlockType* Blocks[]);

//-----------------------------------------------------------------------------

#endif
