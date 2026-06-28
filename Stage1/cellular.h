#ifndef CELLULAR_H
#define CELLULAR_H

#include "equipo.h"


class Cellular : public Equipo{
    public:
        Cellular(const std::string& owner, double x, double y, double r, double theta, double dtheta);
};


#endif // CELLULAR_H
