#ifndef BASICOBJECTS
#define BASICOBJECTS

#include <QString>

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
    Color(double _r = 0, double _g = 0, double _b = 0);
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

struct Material
{
    Material(Color a, Color d, Color s, double r, QString str);
    Color ambient;
    Color diffuse;
    Color specular;
    double refractive_index;
    QString name;
};

struct TexCoord
{
    double u;
    double v;
};

struct Vertex
{
    QString name;
    QString material;
    Position position;
    Position normal;
    TexCoord texCoord;
    void setVertexPara(double* para, QString n, QString m);
};

struct Body
{
    int id;
    Position velocity;
    double mass;
};

struct Sphere
{
    QString material;
    Position position;
    double radius;
    Body body;
    void setSpherePara(double* para, QString m, int i);
};

struct Triangle
{
    QString material;
    Position position;
    QString vertexes[3];
    Body body;
    void setTriPara(double*para, QString p1, QString p2, QString p3, QString m, int i);
};

struct Plane
{
    int id;
    Position position;
    Position normal;
    void setPlanePara(double* para, int i);
};

struct Spring
{
    double constant;
    double equilibrium;
    Body body1;
    Body body2;
    Position offset2;
    double damping;
    void setSpringPara(double* para);
};

#endif // BASICOBJECTS

