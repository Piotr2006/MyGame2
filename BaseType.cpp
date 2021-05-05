#include "BaseType.h"
#include "SmallHelpFunctions.h"

BaseType :: BaseType (PointType _Point, double _Health, AnimationType _Animation) :
    Point (_Point),
    SizeX (_Animation.GetFrameSizeX ()),
    SizeY (_Animation.GetFrameSizeY ()),
    Health (_Health),
    Animation (_Animation)
    {};

BaseType :: BaseType () :
    Point (),
    SizeX (0),
    SizeY (0),
    Health (0),
    Animation (0, 0, &GlobalAllImage.Dirt)
    {};
