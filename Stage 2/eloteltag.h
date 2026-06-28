#ifndef ELOTELTAG_H
#define ELOTELTAG_H

#include "equipo.h"

class EloTelTag : public Equipo {
public:
    EloTelTag(const std::string& owner, double x, double y, double r, double theta, double dtheta);
    std::string getType() const override { return "tag"; }
};

#endif