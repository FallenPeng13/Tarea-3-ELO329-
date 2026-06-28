#include "territoryview.h"
#include <QPainter>

TerritoryView::TerritoryView(Territory* territory, const std::string& imageName, QWidget* parent)
    : QWidget(parent), territory(territory)
{
    backgroundImage.load(QString::fromStdString(imageName));
    setFixedSize(backgroundImage.size());
}

int TerritoryView::getImageWidth() const {
    return backgroundImage.width();
}

int TerritoryView::getImageHeight() const {
    return backgroundImage.height();
}

void TerritoryView::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, backgroundImage);

    for (Equipo* eq : territory->getEquipment()) {
        QString type = QString::fromStdString(eq->getType());

        if (type == "cellular") {
            // Azul - rectángulo
            painter.setBrush(QColor(30, 144, 255));
            painter.setPen(Qt::NoPen);
            painter.drawRoundedRect(eq->getX() - 6, eq->getY() - 12, 12, 24, 4, 4);

        } else if (type == "tag") {
            // Verde - círculo pequeño
            painter.setBrush(QColor(50, 205, 50));
            painter.setPen(Qt::NoPen);
            painter.drawEllipse(eq->getX() - 8, eq->getY() - 8, 16, 16);

        } else if (type == "tablet") {
            // Naranja - rectángulo más grande
            painter.setBrush(QColor(255, 140, 0));
            painter.setPen(Qt::NoPen);
            painter.drawRoundedRect(eq->getX() - 10, eq->getY() - 7, 20, 14, 3, 3);
        }

        // Nombre del equipo
        painter.setPen(Qt::black);
        painter.drawText(eq->getX() + 10, eq->getY() + 6,
                         QString::fromStdString(eq->getOwnerName()));
    }
}