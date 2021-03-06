#include "basicobjects.h"



Material::Material(Color a, Color d, Color s, double r, QString str):
    ambient(a), diffuse(d), specular(s), refractive_index(r), name(str)
{

}

void Vertex::setVertexPara(double *para, QString n, QString m)
{
    position.x = para[0];
    position.y = para[1];
    position.z = para[2];
    normal.x = para[3];
    normal.y = para[4];
    normal.z = para[5];
    texCoord.u = para[6];
    texCoord.v = para[7];
    name = n;
    material = m;
}

void Sphere::setSpherePara(double *para, QString m, int i)
{
    position.x = para[0];
    position.y = para[1];
    position.z = para[2];
    radius = para[3];
    body.id = i;
    body.velocity.x = para[4];
    body.velocity.y = para[5];
    body.velocity.z = para[6];
    body.mass = para[7];
    material = m;
}

void Triangle::setTriPara(double *para, QString p1, QString p2, QString p3, QString m, int i)
{
    position.x = para[0];
    position.y = para[1];
    position.z = para[2];
    vertexes[0] =  p1;
    vertexes[1] =  p2;
    vertexes[2] =  p3;
    material = m;
    body.id = i;
}

void Plane::setPlanePara(double *para, int i)
{
    position.x = para[0];
    position.y = para[1];
    position.z = para[2];
    normal.x = para[3];
    normal.y = para[4];
    normal.z = para[5];
    id = i;
}

void Spring::setSpringPara(double *para)
{
    constant = para[0];
    equilibrium = para[1];
    offset2.x = para[2];
    offset2.y = para[3];
    offset2.z = para[4];
    damping = para[5];
    body1.id = para[6];
    body2.id = para[7];
}

Color::Color(double _r, double _g, double _b): r(_r), g(_g), b(_b)
{

}
