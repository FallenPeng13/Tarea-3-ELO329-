#ifndef CELLULAR_H
#define CELLULAR_H

#include "equipo.h"

class Cellular : public Equipo {
public:
    Cellular(const std::string& owner, double x, double y, double r, double theta, double dtheta);
    std::string getType() const override { return "cellular"; }
};

#endif // CELLULAR_H