#ifndef ESSENSIALPARA_H
#define ESSENSIALPARA_H

#include "basicobjects.h"

class EssentialPara
{
public:
    EssentialPara();
    Camera camera;
    Color backgroundColor;
    double refractiveIndex;
    Color ambientLight;
    PointLight pointLight;
    Position gravity;
    double collisionDamping;
    void setEssentialPara(double* parameters);
};

#endif // ESSENSIALPARA_H
