#ifndef SMALLHELPFUNCTIONS_H
#define SMALLHELPFUNCTIONS_H

#include "AllImageType.h"
#include "Enums.h"
#include "ImageType.h"
#include "CamType.h"
#include "ManType.h"

// int Collision (BlockType* Block, ManType* Man);

int ModuleDistance (int x1, int y1, int x2, int y2, int Distance);

int Distance (int a, int b, int Distance);

void DrawHealth (int Health, CamType* Camera, AllImageType AllImage);

void Text (int x, int y, int Size, int Number, char Name []);

void HelpSystem ();

void StrCpy (char Name [], char _Name []);

//-----------------------------------------------------------------------------

#endif
