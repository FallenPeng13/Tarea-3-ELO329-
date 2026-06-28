#include "eloteltag.h"

EloTelTag::EloTelTag(const std::string& owner, double x, double y, double r, double theta, double dtheta)
    : Equipo(owner, x, y, r, theta, dtheta)
{
}