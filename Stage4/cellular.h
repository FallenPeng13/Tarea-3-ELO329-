#ifndef CELLULAR_H
#define CELLULAR_H



#include "equipo.h"

class Cellular : public Equipo {
public:
    Cellular(const std::string& owner,
             double x, double y, double r, double theta, double dtheta);

    std::string getType() const override { return "cellular"; }
    void update(double dt, const std::vector<Equipo*>& all) override;

private:
    double timeSinceReport = 0.0;
    static constexpr double REPORT_INTERVAL = 4.0;
    static constexpr double DETECTION_RADIUS = 50.0;
};


#endif // CELLULAR_H