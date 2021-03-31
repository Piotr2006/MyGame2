#ifndef IMAGEFUNCTIONS_H
#define IMAGEFUNCTIONS_H

#include "AllImageType.h"
#include "Enums.h"
#include "ImageType.h"
#include "CamType.h"

extern CamType FixedCamera;

void DeleteAllImage (AllImageType AllImages);

void LoadGameImage (ImageType* Image, const char* Picture, int xMaxFrame, int yMaxFrame, COLORREF color,
                    int* Procent, double Number);

void DrawLoading (int Procents);

void DrawTransparentImage (const ImageType& Image, int x, int y, int* xAnimationNumber, int* yAnimationNumber,
                           CamType* Camera = &FixedCamera);

void LoadAllImages (AllImageType* AllImages);

//-----------------------------------------------------------------------------

#endif
