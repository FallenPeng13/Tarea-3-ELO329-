#include "mainwindow.h"
#include <QFileDialog>
#include <QMenuBar>
#include <fstream>
#include <string>
#include <cmath>

#include "cellular.h"

using namespace std;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    // Seleccionar archivo de configuración
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Select configuration file", "", "Text files (*.txt)");

    if (fileName.isEmpty()) {
        close();
        return;
    }

    setupSimulator(fileName.toStdString());

    // Menú Simulation (sin funcionalidad en Etapa 1)
    QMenu* simulMenu = menuBar()->addMenu("Simulation");
    simulMenu->addAction("Play");
    simulMenu->addAction("Pause");

    // ScrollArea como en JavaFX
    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setWidget(territoryView);
    setCentralWidget(scrollArea);

    setWindowTitle("EloTelTag Simulation: Stage 1");
    resize(1000, 700);
}

MainWindow::~MainWindow() {
    delete territory;
}

void MainWindow::setupSimulator(const string& filename) {
    ifstream file(filename);
    string imageName;
    int personNumber;

    file >> imageName;
    file >> timeStep;
    file >> personNumber;

    territory = new Territory();
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

    // Leer datos del celular
    file >> x >> y >> r >> theta >> dt;
    theta = theta * M_PI / 180.0;  // grados a radianes
    dt = dt * M_PI / 180.0;

    Cellular* cellular = new Cellular(personName, x, y, r, theta, dt);
    territory->addEquipment(cellular);

    // Saltar tags
    for (int j = 0; j < tagNumber; j++) {
        skipEloTags(file);
    }

    // Saltar tablet si existe
    if (hasTablet == 1) {
        double tx, ty, tr, ttheta, tdt;
        file >> tx >> ty >> tr >> ttheta >> tdt;
    }
}

void MainWindow::skipEloTags(ifstream& file) {
    string tagName;
    double x, y, r, theta, dt;
    file >> tagName >> x >> y >> r >> theta >> dt;
}
