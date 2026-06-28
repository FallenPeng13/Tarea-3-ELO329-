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

    // Dibujar cada equipo
    for (Equipo* eq : territory->getEquipment()) {
        // Dibujar rectángulo azul para celular
        painter.setBrush(QColor(30, 144, 255));  // DodgerBlue
        painter.setPen(Qt::NoPen);
        painter.drawRoundedRect(eq->getX() - 6, eq->getY() - 12, 12, 24, 4, 4);

        // Dibujar nombre
        painter.setPen(Qt::black);
        painter.drawText(eq->getX() + 10, eq->getY() + 6, QString::fromStdString(eq->getOwnerName()));
    }
}