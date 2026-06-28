#ifndef TABLET_H
#define TABLET_H

#include "equipo.h"

class Tablet : public Equipo {
public:
    Tablet(const std::string& owner, double x, double y, double r, double theta, double dtheta);
    std::string getType() const override { return "tablet"; }
};

#endif // TABLET_H
