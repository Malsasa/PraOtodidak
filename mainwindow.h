#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    QWidget         *widgetUtama;
    QVBoxLayout     *vboxUtama;
    QHBoxLayout     *hboxUtama;
    QPushButton     *tombolUbuntu;
    QPushButton     *tombolMP3;
    QPushButton     *tombolAplikasi;
    QPushButton     *tombolSimulatorTerminal;

    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
