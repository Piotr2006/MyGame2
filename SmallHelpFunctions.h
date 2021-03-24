#ifndef SMALLHELPFUNCTIONS_H
#define SMALLHELPFUNCTIONS_H

#include "AllImageType.h"
#include "Enums.h"
#include "ImageType.h"
#include "CamType.h"
#include "ManType.h"
#include "Graphycs.h"

struct BlockType;

// int Collision (BlockType* Block, ManType* Man);

int ModuleDistance (PointType Point1, PointType Point2, int Distance);

int Distance (int a, int b, int Distance);

void DrawHealth (int Health, CamType* Camera, AllImageType AllImage);

void Text (PointType Point, int Size, int Number, char Name []);

void HelpSystem ();

void StrCpy (char Name [], char _Name []);

int BlockCheckClick (BlockType* Block, CamType* Camera);

int InBorders (double smaller, double x, double bigger);

//-----------------------------------------------------------------------------

#endif
