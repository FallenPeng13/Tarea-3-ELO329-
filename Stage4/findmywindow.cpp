#include "findmywindow.h"
#include "etnube.h"
#include "eloteltag.h"
#include "tablet.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>

FindMyWindow::FindMyWindow(const std::string& owner, Territory* territory, QWidget* parent)
    : QWidget(parent), ownerName(owner), territory(territory)
{
    setWindowTitle("Find My");
    resize(250, 200);

    layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel(QString("Bienes de ") +
                                 QString::fromStdString(ownerName)));
    refresh();


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &FindMyWindow::refresh);
    timer->start(1000);
}

void FindMyWindow::refresh() {

    while (layout->count() > 1) {
        QLayoutItem* item = layout->takeAt(1);
        delete item->widget();
        delete item;
    }

    auto reports = ETNube::getInstance().getReportsForOwner(ownerName);

    if (reports.empty()) {
        layout->addWidget(new QLabel("Sin datos aún"));
        return;
    }

    for (const DeviceReport& report : reports) {

        QHBoxLayout* row = new QHBoxLayout();

        QString text = QString::fromStdString(report.deviceName) +
                       ": " +
                       QString::number((int)report.x) + ", " +
                       QString::number((int)report.y);

        row->addWidget(new QLabel(text));

        // Buscar el equipo correspondiente en el territorio
        Equipo* target = nullptr;
        for (Equipo* eq : territory->getEquipment()) {
            if (eq->getType() == "tag") {
                EloTelTag* tag = static_cast<EloTelTag*>(eq);
                if (tag->getName() == report.deviceName) {
                    target = eq;
                    break;
                }
            } else if (eq->getType() == "tablet" && eq->getOwnerName() == report.deviceName) {
                target = eq;
                break;
            }
        }

        QPushButton* traceBtn = new QPushButton("Traza");
        if (target) {
            Equipo* captured = target;
            connect(traceBtn, &QPushButton::clicked, [captured]() {
                if (captured->getType() == "tag")
                    static_cast<EloTelTag*>(captured)->toggleTrace();
                else if (captured->getType() == "tablet")
                    static_cast<Tablet*>(captured)->toggleTrace();
            });
        }
        row->addWidget(traceBtn);

        QWidget* rowWidget = new QWidget();
        rowWidget->setLayout(row);
        layout->addWidget(rowWidget);
    }
}