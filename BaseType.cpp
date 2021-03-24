#include "BaseType.h"
#include "SmallHelpFunctions.h"

BaseType :: BaseType (PointType _Point, double _Health, AnimationType _Animation) :
    Point (_Point),
    SizeX (_Animation.GetFrameSizeX ()),
    SizeY (_Animation.GetFrameSizeY ()),
    Health (_Health),
    Animation (_Animation)
    {};
