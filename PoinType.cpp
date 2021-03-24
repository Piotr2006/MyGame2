struct PointType
    {
    double x;
    double y;
    };

typedef PointType SizeType;

PointType operator + (PointType Point, SizeType Size)
    {
    double RightX = Point.x + Size.x;
    double RightY = Point.y + Size.y;

    PointType Result = {RightX, RightY};

    return Result;
    };

SizeType operator / (SizeType Size, double Number)
    {
    double X = Size.x/Number;
    double Y = Size.y/Number;

    SizeType Result = {X, Y};

    return Result;
    };

int main ()
    {
    PointType Point = {10, 20};

    SizeType Size = {5, 5};

    PointType Result = Point + Size/2;

    return 0;
    };
