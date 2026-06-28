#ifndef FINDMYWINDOW_H
#define FINDMYWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <string>

class FindMyWindow : public QWidget {
    Q_OBJECT
public:
    FindMyWindow(const std::string& owner, QWidget* parent = nullptr);

private:
    void refresh();  // actualiza la lista desde ETNube

    std::string ownerName;
    QVBoxLayout* layout;
};

#
#endif // FINDMYWINDOW_H
