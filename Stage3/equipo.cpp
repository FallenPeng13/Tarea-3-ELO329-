#include "equipo.h"

#include <cmath>
#include <cstdlib>

using namespace std;


Equipo::Equipo(const string& owner, double x, double y, double r, double theta, double dtheta)
{
    ownerName = owner;
    this->x = x;
    this->y = y;
    this->r = r;
    this->theta = theta;
    this->dtheta = dtheta;

}

void Equipo::move(double dt, double width, double height)
{
    theta += (((double)rand() / RAND_MAX)-0.5)*dtheta;

    x = x + cos(theta)*r*dt;


    y = y + sin(theta)*r*dt;

    if (x<0 || x>width )
        theta = M_PI - theta;
    if (y<0 || y>height )
        theta = theta*-1;

}

Equipo::~Equipo() {}

double Equipo::getX() const
{
    return x;
}

double Equipo::getY() const
{
    return y;
}

string Equipo::getOwnerName() const
{
    return ownerName;
}