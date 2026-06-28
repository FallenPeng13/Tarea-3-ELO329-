#include "mainwindow.h"
#include <QFileDialog>
#include <QMenuBar>
#include <fstream>
#include <string>
#include <cmath>

#include "cellular.h"
#include "eloteltag.h"
#include "tablet.h"

using namespace std;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Select configuration file", "", "Text files (*.txt)");

    if (fileName.isEmpty()) {
        close();
        return;
    }

    setupSimulator(fileName.toStdString());

    // Menú Simulation con Play y Pause funcionales
    QMenu* simulMenu = menuBar()->addMenu("Simulation");
    QAction* playAction  = simulMenu->addAction("Play");
    QAction* pauseAction = simulMenu->addAction("Pause");

    connect(playAction,  &QAction::triggered, this, &MainWindow::play);
    connect(pauseAction, &QAction::triggered, this, &MainWindow::pause);

    // Timer para mover equipos
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::advance);

    // ScrollArea
    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setWidget(territoryView);
    setCentralWidget(scrollArea);

    setWindowTitle("EloTelTag Simulation: Stage 2");
    timer->start(timeStep * 1000);  // arranca automáticamente
    resize(1000, 700);
}

MainWindow::~MainWindow() {
    delete territory;
}

void MainWindow::play() {
    timer->start(timeStep * 1000);
}

void MainWindow::pause() {
    timer->stop();
}

void MainWindow::advance() {
    std::vector<Equipo*>& all = territory->getEquipment();
    for (Equipo* eq : all) {
        eq->move(timeStep,
                 territoryView->getImageWidth(),
                 territoryView->getImageHeight());
        eq->update(timeStep, all);
    }
    territoryView->update();
}

void MainWindow::setupSimulator(const string& filename) {
    ifstream file(filename);
    string imageName;
    int personNumber;

    file >> imageName;
    file >> timeStep;
    file >> personNumber;

    territory    = new Territory();
    territoryView = new TerritoryView(territory, imageName);

    for (int i = 0; i < personNumber; i++) {
        setupPersonEquipment(file);
    }
}

void MainWindow::setupPersonEquipment(ifstream& file) {
    string personName;
    int tagNumber, hasTablet;
    double x, y, r, theta, dt;

    file >> personName >> tagNumber >> hasTablet;

    // celular
    file >> x >> y >> r >> theta >> dt;
    theta = theta * M_PI / 180.0;
    dt    = dt    * M_PI / 180.0;
    territory->addEquipment(new Cellular(personName, x, y, r, theta, dt));

    //EloTelTags
    for (int j = 0; j < tagNumber; j++) {
        string tagName;
        file >> tagName >> x >> y >> r >> theta >> dt;
        theta = theta * M_PI / 180.0;
        dt    = dt    * M_PI / 180.0;
        territory->addEquipment(new EloTelTag(personName, tagName, x, y, r, theta, dt));
    }

    // Tablet
    if (hasTablet == 1) {
        file >> x >> y >> r >> theta >> dt;
        theta = theta * M_PI / 180.0;
        dt    = dt    * M_PI / 180.0;
        territory->addEquipment(new Tablet(personName, x, y, r, theta, dt));
    }
}