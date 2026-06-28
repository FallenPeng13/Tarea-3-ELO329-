#include "etnube.h"

ETNube& ETNube::getInstance() {
    static ETNube instance;  // se crea solo la primera vez
    return instance;
}

void ETNube::report(const std::string& deviceName,
                    const std::string& ownerName,
                    double x, double y)
{
    std::string key = ownerName + ":" + deviceName;
    latestReports[key] = {deviceName, ownerName, x, y};
}

std::vector<DeviceReport> ETNube::getReportsForOwner(const std::string& ownerName) const {
    std::vector<DeviceReport> result;
    for (const auto& pair : latestReports) {
        if (pair.second.ownerName == ownerName) {
            result.push_back(pair.second);
        }
    }
    return result;
}

const DeviceReport* ETNube::getLatestReport(const std::string& deviceName) const {
    auto it = latestReports.find(deviceName);
    if (it != latestReports.end()) {
        return &it->second;
    }
    return nullptr;
}