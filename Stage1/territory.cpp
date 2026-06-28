#include "territory.h"

using namespace std;

void Territory::addEquipment(Equipo* eq)
{
    equipment.push_back(eq);
}

std::vector<Equipo*>& Territory::getEquipment() {
    return equipment;
}