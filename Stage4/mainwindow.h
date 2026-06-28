#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <fstream>
#include <QMainWindow>
#include <QScrollArea>
#include <QTimer>
#include "territory.h"
#include "territoryview.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void play();
    void pause();
    void advance();

private:
    void setupSimulator(const std::string& filename);
    void setupPersonEquipment(std::ifstream& file);

    Territory* territory;
    TerritoryView* territoryView;
    QTimer* timer;
    double timeStep;
};

#endif // MAINWINDOW_H