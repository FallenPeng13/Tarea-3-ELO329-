#ifndef ELOTELTAG_H
#define ELOTELTAG_H

#include "equipo.h"
#include <QPointF>
#include <vector>

class EloTelTag : public Equipo {
public:
    EloTelTag(const std::string& owner, const std::string& name,
              double x, double y, double r, double theta, double dtheta);

    std::string getType() const override { return "tag"; }
    std::string getName() const { return name; }

    void update(double dt, const std::vector<Equipo*>& all) override;

    bool isBipping() const { return bipping; }
    double getBipProgress() const { return bipProgress; }

    // Traza
    void toggleTrace() { tracingActive = !tracingActive; if (!tracingActive) tracePoints.clear(); }
    bool isTracing() const { return tracingActive; }
    const std::vector<QPointF>& getTracePoints() const { return tracePoints; }

private:
    std::string name;

    bool bipping = false;
    double bipProgress = 0.0;
    double timeSinceBip = 0.0;
    static constexpr double BIP_INTERVAL = 4.0;
    static constexpr double BIP_DURATION = 1.0;

    // Traza
    bool tracingActive = false;
    std::vector<QPointF> tracePoints;
};

#endif