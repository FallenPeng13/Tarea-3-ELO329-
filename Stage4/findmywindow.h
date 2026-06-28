#ifndef FINDMYWINDOW_H
#define FINDMYWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <string>

#include "territory.h"

class FindMyWindow : public QWidget {
    Q_OBJECT
public:
    FindMyWindow(const std::string& owner, Territory* territory, QWidget* parent = nullptr);

private slots:
    void refresh();

private:

    std::string ownerName;
    QVBoxLayout* layout;
    QTimer* timer;
    Territory* territory;
};


#endif // FINDMYWINDOW_H
