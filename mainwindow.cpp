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
    // kalau mau beraksi seperti Otodidak versi 1, fungsi yang dipakai bukan destroy tetapi close
    // ternyata tidak ada perubahan
    // dikomentari pada Sunday, August 17, 2014 05:30 PM
    this->close();
}

void MainWindow::BukaJendelaBaru()
{
    // deklarasi pembuatan objek jendela baru
    jendelaKedua = new QMainWindow;

    QPushButton *tombolA      = new QPushButton("INI ADALAH AKU");
    QPushButton *tombolB      = new QPushButton("INI ADALAH DIA");
    QVBoxLayout *layoutLayerA = new QVBoxLayout;
    QVBoxLayout *layoutLayerB = new QVBoxLayout;
    QPushButton *tombolLayerA = new QPushButton("LAYER A");
    QPushButton *tombolLayerB = new QPushButton("LAYER B");
    QWidget     *widgetA      = new QWidget;
    QWidget     *widgetB      = new QWidget;
    QWidget     *widgetC      = new QWidget;

    // percobaan QStackedLayout
    slSatu    = new QStackedLayout;

    widgetA->setLayout(layoutLayerA);
    widgetB->setLayout(layoutLayerB);

    layoutLayerA->addWidget(tombolLayerA);
    layoutLayerB->addWidget(tombolLayerB);

    // urusi widget Monday, August 18, 2014 12:52 AM
    slSatu->addWidget(widgetA);
    slSatu->addWidget(widgetB);

    // pembuatan layout dasar untuk menampung stacked layout dan widget lainnya
    // dikomentari pada Monday, August 18, 2014 08:04 PM
    QVBoxLayout     *layoutA    =   new     QVBoxLayout;

    // pemasangan stacked layout ke dalam layout normal dilakukan dengan hanya addLayout() bukan dengan membuat QWidget baru
    // dengan cara ini, penghematan widget dan layout bisa dilakukan
    // sehingga bisa dilakukan di dalam suatu QVBoxLayout penambahan layout sekaligus penambahan widget tanpa banyak QWidget baru
    // Monday, August 18, 2014 08:03 PM
    layoutA->addLayout(slSatu);
    layoutA->addWidget(tombolA);
    layoutA->addWidget(tombolB);
    widgetC->setLayout(layoutA);

    jendelaKedua->setCentralWidget(widgetC);
    jendelaKedua->showNormal();

    // fungsi ini bertugas mematikan jendela utama
    MainWindow::MatikanMainWindow();

    // berhasil!
    // pergeseran layer bisa dilakukan dengan memasang slot satu fungsi tunggal
    // fungsi eksternal yang dibuat di luar fungsi pembuat jendela BukaJendelaBaru()
    // bukan dengan cara memanggil slSatu->setCurrentIndex(int nomor) sebagai argumen SLOT
    // Monday, August 18, 2014 08:00 PM
    connect(tombolA, SIGNAL(clicked()), this, SLOT(stackSatu()));
    connect(tombolB, SIGNAL(clicked()), this, SLOT(stackDua()));

}

// berhasil!
// untuk melakukan pergantian layer, harus dibuat fungsi penggeser layer terpisah dari fungsi pembuat jendela
// tidak dijadikan satu dalam fungsi pembuat jendela
// objek stack layout harus dideklarasikan dalam kelas yang sama dengan MainWindow utama, bukan dengan membuat kelas baru di mainwindow.h
// oleh karena itu, slSatu bisa dipanggil dari sini
// Monday, August 18, 2014 07:58 PM
void MainWindow::stackSatu()
{
    slSatu->setCurrentIndex(0);
}

void MainWindow::stackDua()
{
    slSatu->setCurrentIndex(1);
}
