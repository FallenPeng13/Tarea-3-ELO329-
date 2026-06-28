#include "eloteltag.h"

EloTelTag::EloTelTag(const std::string& owner, const std::string& name,
                     double x, double y, double r, double theta, double dtheta)
    : Equipo(owner, x, y, r, theta, dtheta), name(name)
{}

void EloTelTag::update(double dt, const std::vector<Equipo*>& all) {
    // Avanzar animación si está bippeando
    if (bipping) {
        bipProgress += dt / BIP_DURATION;  //normalizado
        if (bipProgress >= 1.0) {
            bipProgress = 0.0;
            bipping = false;
        }
    }

    // Acumular tiempo para el próximo bip
    timeSinceBip += dt;
    if (timeSinceBip >= BIP_INTERVAL) {
        timeSinceBip = 0.0;
        bipping = true;
        bipProgress = 0.0;
    }

    // Guardar posición si traza activa
    if (tracingActive) {
        tracePoints.push_back(QPointF(x, y));
    }
}