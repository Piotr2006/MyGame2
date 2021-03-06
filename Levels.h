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

void MoveGame (BlockType ManyBlocks [], AllImageType AllImage, int* LevelNumber, ManType* Man, double* AllTemperature, CamType* Camera, CamType* FixedCamera, ManType Villagers []);

void Level1 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera);

void Level2 (int* LevelNumber, ManType* Man, AllImageType AllImage, CamType* Camera, CamType* FixedCamera);

//-----------------------------------------------------------------------------

#endif