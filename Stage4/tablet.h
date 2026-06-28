#ifndef TABLET_H
#define TABLET_H

#include <QPointF>
#include "equipo.h"

class Tablet : public Equipo {
public:
    Tablet(const std::string& owner, double x, double y,
           double r, double theta, double dtheta);

    std::string getType() const override { return "tablet"; }

    void update(double dt, const std::vector<Equipo*>& all) override;

    bool isBipping() const { return bipping; }
    double getBipProgress() const { return bipProgress; }

    void toggleTrace() { tracingActive = !tracingActive; if (!tracingActive) tracePoints.clear(); }
    bool isTracing() const { return tracingActive; }
    const std::vector<QPointF>& getTracePoints() const { return tracePoints; }

private:
    bool bipping = false;
    double bipProgress = 0.0;
    double timeSinceBip = 0.0;
    static constexpr double BIP_INTERVAL = 5.0;  // tablets van cada 5s
    static constexpr double BIP_DURATION = 1.0;
    bool tracingActive = false;
    std::vector<QPointF> tracePoints;
};

#endif // TABLET_H
