#ifndef BUTTONTYPE_H
#define BUTTONTYPE_H

#include "AllImageType.h"
#include "Enums.h"
#include "ImageType.h"
#include "AnimationType.h"
#include "BaseType.h"
#include "InvType.h"
#include "CamType.h"
#include "MouseType.h"
#include "ManType.h"
#include "Levels.h"
#include "SmallHelpFunctions.h"


struct CamType;
struct AllImageType;

struct ButtonType
    {
    ButtonType (int x, int y, int Number);

    void DrawButton ();

    int ButtonCheckClick (int x2, int y2, int DstX, int DstY);

    int x;
    int y;

    int Number;
    };


#endif
