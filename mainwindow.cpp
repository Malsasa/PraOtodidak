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
    QToolButton *tombolUbuntu                  =       new     QToolButton;
    QToolButton *tombolMP3                     =       new     QToolButton;
    QToolButton *tombolAplikasi                =       new     QToolButton;
    QToolButton *tombolSimulatorTerminal       =       new     QToolButton;

    // pengaturan kemampuan mekar setiap tombol (Sunday, July 27, 2014 10:57 PM)
    tombolUbuntu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tombolMP3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tombolAplikasi->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tombolSimulatorTerminal->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // pengaturan ukuran minimal tombol
    tombolUbuntu->setMinimumSize(66,66);
    tombolMP3->setMinimumSize(66,66);
    tombolAplikasi->setMinimumSize(66,66);
    tombolSimulatorTerminal->setMinimumSize(66,66);

    // pengaturan objek ikon untuk setiap tombol (Sunday, July 27, 2014 10:57 PM)
    QIcon       ikonTombolUbuntu(":/gambar/ubuntu-logo.svg");                   // semuanya svg
    QIcon       ikonTombolMP3(":/gambar/rhythmbox.svg");
    QIcon       ikonTombolAplikasi(":/gambar/synaptic.svg");
    QIcon       ikonTombolSimulatorTerminal(":/gambar/terminal.svg");

    // pengaturan gaya tombol yakni teks di bawah gambar (Sunday, July 27, 2014 10:57 PM)
    tombolUbuntu->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tombolMP3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tombolAplikasi->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tombolSimulatorTerminal->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    // pengaturan ukuran ikon tombol dengan bantuan kelas QSize (Sunday, July 27, 2014 11:06 PM)
    QSize ukuranIkonTombol(48, 48);
    tombolUbuntu->setIconSize(ukuranIkonTombol);
    tombolMP3->setIconSize(ukuranIkonTombol);
    tombolAplikasi->setIconSize(ukuranIkonTombol);
    tombolSimulatorTerminal->setIconSize(ukuranIkonTombol);

    // penempelan ikon ke dalam setiap tombol (Sunday, July 27, 2014 10:57 PM)
    tombolUbuntu->setIcon(ikonTombolUbuntu);
    tombolMP3->setIcon(ikonTombolMP3);
    tombolAplikasi->setIcon(ikonTombolAplikasi);
    tombolSimulatorTerminal->setIcon(ikonTombolSimulatorTerminal);

    // penulisan teks ke dalam setiap tombol (Sunday, July 27, 2014 10:57 PM)
    tombolUbuntu->setText("UBUNTU");
    tombolAplikasi->setText("APLIKASI");
    tombolMP3->setText("MP3");
    tombolSimulatorTerminal->setText("SIMULATOR \nTERMINAL");

    // penempelan widget-widget ke dalam layout (Sunday, July 27, 2014 10:57 PM)
    hboxUtama->addWidget(tombolUbuntu);
    hboxUtama->addWidget(tombolMP3);
    hboxUtama->addWidget(tombolAplikasi);
    hboxUtama->addWidget(tombolSimulatorTerminal);

    // penempelan layout pada widget utama (Sunday, July 27, 2014 10:57 PM)
    widgetUtama->setLayout(hboxUtama);

    // penempelan widget utama pada jendela utama, ditempel sebagai central widget (Sunday, July 27, 2014 10:57 PM)
    this->setCentralWidget(widgetUtama);

    //tes signal slot untuk membuka jendela baru, dibuat pada Sunday, August 17, 2014 05:21 PM
    connect(tombolMP3, SIGNAL(clicked()), this, SLOT(BukaJendelaBaru()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MatikanMainWindow()
{
    this->destroy(true, true);
}

void MainWindow::BukaJendelaBaru()
{
    QMainWindow *jendelaKedua = new QMainWindow();
    QPushButton *tombolA      = new QPushButton("INI ADALAH AKU");
    QWidget     *widgetA      = new QPushButton;
    QVBoxLayout *layoutA      = new QVBoxLayout;
    layoutA->addWidget(tombolA);
    widgetA->setLayout(layoutA);
    jendelaKedua->setCentralWidget(widgetA);
    jendelaKedua->showMaximized();
    MainWindow::MatikanMainWindow();

}
