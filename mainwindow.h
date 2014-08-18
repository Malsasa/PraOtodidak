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
    QToolButton     *tombolUbuntu;
    QToolButton     *tombolMP3;
    QToolButton     *tombolAplikasi;
    QToolButton     *tombolSimulatorTerminal;
    QStackedLayout  *slSatu;

    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QMainWindow *jendelaKedua;

public slots:
    void BukaJendelaBaru();
    void MatikanMainWindow();
    void stackSatu();
    void stackDua();

};

#endif // MAINWINDOW_H
