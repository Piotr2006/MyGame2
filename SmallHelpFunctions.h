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

int GetNumberOfSymbols (const char str[], const char Symbol);

int NewGetNumberOfStr (const char Allstr[], const char Smallstr []);

int GetNumberOfStr (const char Allstr[], const char Smallstr [2]);

int Myfscanf (FILE* file, const char str [], ...);

int ModuleDistance (PointType Point1, PointType Point2, int Distance);

int Distance (int a, int b, int Distance);

void DrawHealth (int Health);

void Text (PointType Point, int Size, int Number, char Name []);

void TextWithEnd (PointType Point, int Size, int Number, char Text1 [], char Text2 []);

void HelpSystem ();

void StrCpy (char ToName [], const char FromName []);

int BlockCheckClick (BlockType* Block, CamType* Camera);

int InBorders (double smaller, double x, double bigger);

bool HaveInventory (int Selected, int Type, int HaveNumber, int MinNumber);

int RectAiming (double x1, double y1, double x2, double y2, CamType* Camera);

int RectCheckClick (double x1, double y1, double x2, double y2, CamType* Camera);

void DrawHealth (PointType Point, int Health);

//-----------------------------------------------------------------------------

#endif
