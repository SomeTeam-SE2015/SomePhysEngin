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

enum MaterialType {red, sred, green ,sgreen, blue, sblue, mirror};

//typedef Material MaterialRed(Color(1,0,0), Color(1,0,0), Color(0,0,0), 0, QString("red"));
//typedef Material MaterialSred(Color(1,0,0), Color(1,0,0), Color(1,1,1), 0, QString("sred"));
//typedef Material MaterialGreen(Color(0,1,0), Color(0,1,0), Color(0,0,0), 0, QString("green"));
//typedef Material MaterialSGreen(Color(0,1,0), Color(0,1,0), Color(1,1,1), 0, QString("sgreen"));
//typedef Material MaterialBlue(Color(0,0,1), Color(0,0,1), Color(0,0,0), 0, QString("blue"));
//typedef Material MaterialSBlue(Color(0,0,1), Color(0,0,1), Color(0,1,1), 0, QString("sblue"));
//typedef Material MaterialMirror(Color(0,0,0), Color(0,0,0), Color(1,1,1), 0, QString("mirror"));

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

#endif // BASICOBJECTS

