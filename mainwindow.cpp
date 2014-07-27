// Proyek Sebelum Proyek Otodidak
// Dibuat pada malam Id pada Sunday, July 27, 2014 10:21 PM

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QWidget     *widgetUtama                   =       new     QWidget;
    QVBoxLayout *vboxUtama                     =       new     QVBoxLayout;
    QHBoxLayout *hboxUtama                     =       new     QHBoxLayout;
    QPushButton *tombolUbuntu                  =       new     QPushButton("UBUNTU");
    QPushButton *tombolMP3                     =       new     QPushButton("MP3");
    QPushButton *tombolAplikasi                =       new     QPushButton("APLIKASI");
    QPushButton *tombolSimulatorTerminal       =       new     QPushButton("SIMULATOR TERMINAL");

    hboxUtama->addWidget(tombolUbuntu);
    hboxUtama->addWidget(tombolMP3);
    hboxUtama->addWidget(tombolAplikasi);
    hboxUtama->addWidget(tombolSimulatorTerminal);

    widgetUtama->setLayout(hboxUtama);
    this->setCentralWidget(widgetUtama);

}

MainWindow::~MainWindow()
{
    delete ui;
}
