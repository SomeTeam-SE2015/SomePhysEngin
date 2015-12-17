#ifndef BASICOBJECTS
#define BASICOBJECTS

struct Position
{
    double x;
    double y;
    double z;
};

struct Orientation
{
    double a;
    double x;
    double y;
    double z;
};

struct Color
{
    double r;
    double g;
    double b;
};

struct Camera
{
    double fov;
    double near_clip;
    double far_clip;
    Position position;
    Orientation orientation;
};

struct PointLight
{
    Position position;
    Color color;
};

#endif // BASICOBJECTS

