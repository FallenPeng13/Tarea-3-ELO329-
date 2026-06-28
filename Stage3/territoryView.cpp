#include "territoryview.h"
#include "eloteltag.h"
#include "tablet.h"
#include "findmywindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMenu>
#include <cmath>

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
            //Nombre
            painter.setPen(Qt::black);
            painter.drawText(eq->getX() + 10, eq->getY() + 6,
                             QString::fromStdString(eq->getOwnerName()));





        // TAG
        } else if (type == "tag") {
            EloTelTag* tag = static_cast<EloTelTag*>(eq);

            // Radar si está bippeando
            if (tag->isBipping()) {
                double radius = tag->getBipProgress() * 50.0;
                int alpha = static_cast<int>(255 * (1.0 - tag->getBipProgress()));
                painter.setBrush(Qt::NoBrush);
                painter.setPen(QPen(QColor(0, 120, 255, alpha), 2));
                painter.drawEllipse(QPointF(eq->getX(), eq->getY()), radius, radius);
            }


            // Verde - círculo pequeño
            painter.setBrush(QColor(50, 205, 50));
            painter.setPen(Qt::NoPen);
            painter.drawEllipse(eq->getX() - 8, eq->getY() - 8, 16, 16);

            painter.setPen(Qt::black);
            painter.drawText(eq->getX() + 10, eq->getY() + 6,
                             QString::fromStdString(tag->getName()));



        // TABLET
        } else if (type == "tablet") {
            Tablet* tab = static_cast<Tablet*>(eq);

            // Radar si está bippeando
            if (tab->isBipping()) {
                double radius = tab->getBipProgress() * 50.0;
                int alpha = static_cast<int>(255 * (1.0 - tab->getBipProgress()));
                painter.setBrush(Qt::NoBrush);
                painter.setPen(QPen(QColor(0, 120, 255, alpha), 2));
                painter.drawEllipse(QPointF(eq->getX(), eq->getY()), radius, radius);
            }

            // Naranja - rectángulo más grande
            painter.setBrush(QColor(255, 140, 0));
            painter.setPen(Qt::NoPen);
            painter.drawRoundedRect(eq->getX() - 10, eq->getY() - 7, 20, 14, 3, 3);

            painter.setPen(Qt::black);
            painter.drawText(eq->getX() + 12, eq->getY() + 6,
                             QString::fromStdString(eq->getOwnerName()));
        }


    }
}



Equipo* TerritoryView::equipoAt(int mx, int my) {
    for (Equipo* eq : territory->getEquipment()) {
        // radio de detección de clic: 15px
        double dx = eq->getX() - mx;
        double dy = eq->getY() - my;
        if (sqrt(dx*dx + dy*dy) <= 15.0) {
            return eq;
        }
    }
    return nullptr;
}

void TerritoryView::mousePressEvent(QMouseEvent* event) {
    Equipo* eq = equipoAt(event->x(), event->y());
    if (!eq) return;

    // Solo celulares y tablets tienen menú emergente
    std::string type = eq->getType();
    if (type != "cellular" && type != "tablet") return;

    // Obtener nombre del dueño
    std::string owner = eq->getOwnerName();

    // Mostrar menú emergente
    QMenu menu(this);
    QAction* findMyAction = menu.addAction("Find My");

    QAction* selected = menu.exec(event->globalPos());
    if (selected == findMyAction) {
        FindMyWindow* window = new FindMyWindow(owner);
        window->show();
    }
}