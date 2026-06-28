#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

class Equipo {
public:
    Equipo(const std::string& owner, double x, double y, double r, double theta, double dtheta);
    virtual ~Equipo();

    void move(double dt, double width, double height);

    double getX() const;
    double getY() const;
    std::string getOwnerName() const;

    virtual std::string getType() const = 0;  // ← ESTO ES LO NUEVO

protected:
    std::string ownerName;
    double x, y;
    double r, theta, dtheta;
};

#endif
