#ifndef IMAGEFUNCTIONS_H
#define IMAGEFUNCTIONS_H

#include "AllImageType.h"
#include "Enums.h"
#include "ImageType.h"
#include "CamType.h"

extern CamType FixedCamera;

void DeleteAllImage ();

void LoadGameImage (ImageType* Image, const char* Picture, int xMaxFrame, int yMaxFrame, COLORREF color,
                    int* Procent, double Number);

void DrawLoading (int Procents);

void DrawTransparentImage (const ImageType& Image, double x, double y, int* xAnimationNumber, int* yAnimationNumber,
                           CamType* Camera = &FixedCamera);

void LoadAllImages ();

//-----------------------------------------------------------------------------

#endif
