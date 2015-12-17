#include "basicobjects.h"



Material::Material(Color a, Color d, Color s, double r, QString str):
    ambient(a), diffuse(d), specular(s), refractive_index(r), name(str)
{

}
