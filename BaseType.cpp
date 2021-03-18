#include "BaseType.h"
#include "SmallHelpFunctions.h"

BaseType :: BaseType (double _x, double _y, double _Health, AnimationType _Animation) :
    x (_x),
    y (_y),
    SizeX (_Animation.GetFrameSizeX ()),
    SizeY (_Animation.GetFrameSizeY ()),
    Health (_Health),
    Animation (_Animation)
    {};
