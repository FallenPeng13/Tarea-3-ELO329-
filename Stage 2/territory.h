#ifndef TERRITORY_H
#define TERRITORY_H

#include "equipo.h"
#include <vector>


class Territory{
public:
    void addEquipment(Equipo* eq);
    std::vector<Equipo*>& getEquipment();


private:
    std::vector<Equipo*> equipment;
};


#endif // TERRITORY_H
