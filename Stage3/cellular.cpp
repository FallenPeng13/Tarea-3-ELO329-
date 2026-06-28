#include "cellular.h"
#include "eloteltag.h"
#include "tablet.h"
#include "etnube.h"
#include <cmath>

using namespace std;

Cellular::Cellular(const string& owner, double x, double y,
                   double r, double theta, double dtheta)
    : Equipo(owner, x, y, r, theta, dtheta)
{}

void Cellular::update(double dt, const vector<Equipo*>& all) {
    timeSinceReport += dt;
    if (timeSinceReport < REPORT_INTERVAL) return;
    timeSinceReport = 0.0;

    for (Equipo* eq : all) {
        if (eq == this) continue;

        double dx = eq->getX() - x;
        double dy = eq->getY() - y;
        if (sqrt(dx*dx + dy*dy) > DETECTION_RADIUS) continue;

        if (eq->getType() == "tag") {
            EloTelTag* tag = static_cast<EloTelTag*>(eq);
            ETNube::getInstance().report(tag->getName(), tag->getOwnerName(), x, y);
        } else if (eq->getType() == "tablet") {
            // tablet usa ownerName como identificador
            ETNube::getInstance().report(eq->getOwnerName(), eq->getOwnerName(), x, y);
        }
    }
}