#include "essentialpara.h"

EssentialPara::EssentialPara()
{

}

void EssentialPara::setEssentialPara(double *parameters)
{
    this->camera.fov = parameters[0];
    this->camera.near_clip = parameters[1];
    this->camera.far_clip = parameters[2];
    this->camera.position.x = parameters[3];
    this->camera.position.y = parameters[4];
    this->camera.position.z = parameters[5];
    this->camera.orientation.a = parameters[6];
    this->camera.orientation.x = parameters[7];
    this->camera.orientation.y = parameters[8];
    this->camera.orientation.z = parameters[9];
    this->backgroundColor.r = parameters[10];
    this->backgroundColor.g = parameters[11];
    this->backgroundColor.b = parameters[12];
    this->refractiveIndex = parameters[13];
    this->ambientLight.r = parameters[14];
    this->ambientLight.g = parameters[15];
    this->ambientLight.b = parameters[16];
    this->pointLight.position.x = parameters[17];
    this->pointLight.position.y = parameters[18];
    this->pointLight.position.z = parameters[19];
    this->pointLight.color.r = parameters[20];
    this->pointLight.color.g = parameters[21];
    this->pointLight.color.b = parameters[22];
    this->gravity.x = parameters[23];
    this->gravity.x = parameters[24];
    this->gravity.x = parameters[25];
    this->collisionDamping = parameters[26];
}


