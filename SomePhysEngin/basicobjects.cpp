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
