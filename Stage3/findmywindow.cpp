#include "findmywindow.h"
#include "etnube.h"
#include <QLabel>

FindMyWindow::FindMyWindow(const std::string& owner, QWidget* parent)
    : QWidget(parent), ownerName(owner)
{
    setWindowTitle("Find My");
    resize(200, 150);

    layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel(QString("Bienes de ") +
                                 QString::fromStdString(ownerName)));

    refresh();
}

void FindMyWindow::refresh() {
    // Eliminar labels anteriores excepto el título
    QLayoutItem* item;
    while (layout->count() > 1) {
        item = layout->takeAt(1);
        delete item->widget();
        delete item;
    }

    // Agregar un label por cada reporte en la nube
    auto reports = ETNube::getInstance().getReportsForOwner(ownerName);

    if (reports.empty()) {
        layout->addWidget(new QLabel("Sin datos aún"));
        return;
    }

    for (const DeviceReport& report : reports) {
        QString text = QString::fromStdString(report.deviceName) +
                       ": " +
                       QString::number((int)report.x) + ", " +
                       QString::number((int)report.y);
        layout->addWidget(new QLabel(text));
    }
}