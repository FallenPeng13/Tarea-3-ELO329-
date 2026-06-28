#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <fstream>
#include <QMainWindow>
#include <QScrollArea>
#include "territory.h"
#include "territoryview.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    void setupSimulator(const std::string& filename);
    void setupPersonEquipment(std::ifstream& file);
    void skipEloTags(std::ifstream& file);

    Territory* territory;
    TerritoryView* territoryView;
    double timeStep;
};


#endif // MAINWINDOW_H
