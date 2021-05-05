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

void MoveGame (BlockType* ManyBlocks [], int* LevelNumber, ManType* Man, double* AllTemperature, CamType* Camera, ManType Villagers []);

void Level1 (int* LevelNumber, ManType* Man, CamType* Camera);

void TestLevel (int* LevelNumber, ManType* Man, CamType* Camera);

//-----------------------------------------------------------------------------

#endif
