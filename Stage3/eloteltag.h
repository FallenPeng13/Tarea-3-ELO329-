#ifndef ELOTELTAG_H
#define ELOTELTAG_H

#include "equipo.h"

class EloTelTag : public Equipo {
public:
    EloTelTag(const std::string& owner, const std::string& name,
              double x, double y, double r, double theta, double dtheta);

    std::string getType() const override { return "tag"; }
    std::string getName() const { return name; }

    void update(double dt, const std::vector<Equipo*>& all) override;

    bool isBipping() const { return bipping; }
    double getBipProgress() const { return bipProgress; }

private:
    std::string name;

    bool bipping = false;
    double bipProgress = 0.0;       // avance de la animación
    double timeSinceBip = 0.0;      // tiempo desde bip
    static constexpr double BIP_INTERVAL = 4.0;   // segundos bips
    static constexpr double BIP_DURATION = 1.0;   // duración
};

#endif