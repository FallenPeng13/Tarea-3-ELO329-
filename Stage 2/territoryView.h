#ifndef TERRITORYVIEW_H
#define TERRITORYVIEW_H

#include <QWidget>
#include <QPixmap>
#include "territory.h"

class TerritoryView : public QWidget {
    Q_OBJECT
public:
    TerritoryView(Territory* territory, const std::string& imageName, QWidget* parent = nullptr);
    int getImageWidth() const;
    int getImageHeight() const;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Territory* territory;
    QPixmap backgroundImage;
};

#endif // TERRITORYVIEW_H
