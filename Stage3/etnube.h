#ifndef ETNUBE_H
#define ETNUBE_H

#include <string>
#include <vector>
#include <map>

struct DeviceReport {
    std::string deviceName;
    std::string ownerName;
    double x, y;
};

class ETNube {
public:

    static ETNube& getInstance();

    void report(const std::string& deviceName, const std::string& ownerName, double x, double y);

    std::vector<DeviceReport> getReportsForOwner(const std::string& ownerName) const;

    const DeviceReport* getLatestReport(const std::string& deviceName) const;

private:
    ETNube() = default;


    std::map<std::string, DeviceReport> latestReports;
};



#endif // ETNUBE_H
