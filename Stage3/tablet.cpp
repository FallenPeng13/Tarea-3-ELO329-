#include "tablet.h"

Tablet::Tablet(const std::string& owner, double x, double y, double r, double theta, double dtheta)
    : Equipo(owner, x, y, r, theta, dtheta)
{}

void Tablet::update(double dt, const std::vector<Equipo*>& all) {
    if (bipping) {
        bipProgress += dt / BIP_DURATION;
        if (bipProgress >= 1.0) {
            bipProgress = 0.0;
            bipping = false;
        }
    }

    timeSinceBip += dt;
    if (timeSinceBip >= BIP_INTERVAL) {
        timeSinceBip = 0.0;
        bipping = true;
        bipProgress = 0.0;
    }
}