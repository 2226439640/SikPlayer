#include "sikplayer.h"
#include "ui_sikplayer.h"
#include "QIcon"
#include "resConfig.h"
#include "QMenu"
#include "QFileDialog"
#include "QPalette"
#include "QGridLayout"
#include "mystatuswidget.h"
using namespace SikConfig;

SikPlayer::SikPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SikPlayer)
{
    this->setWindowIcon(QIcon(icoUrl));

    ui->setupUi(this);

    ui->menubar->setVisible(false);

//    connect(ui->fileMenu, &QMenu::triggered, this, [&](){
//        filelist = QFileDialog::getOpenFileNames();
//        for(QString file : filelist)
//        {
//            QStringList splname = file.split("/");
//            ui->FileBrowser->append(splname[splname.length()-1]);
//        }
//    });

//    QPalette pal;
//    pal.setColor(QPalette::Background, Qt::black);
//    ui->FileBrowser->setAutoFillBackground(true);
//    ui->FileBrowser->setPalette(pal);
//    ui->centralwidget->setAutoFillBackground(true);
//    ui->centralwidget->setPalette(pal);

    QGridLayout* layout = new QGridLayout();
    layout->setMargin(0);
    videoWidget = new QVideoWidget(this);
    player = new QMediaPlayer();
    player->setVideoOutput(videoWidget);
    fileBrowser = new QTableWidget(this);
    fileBrowser->setColumnCount(2);
    fileBrowser->setHorizontalHeaderLabels({"文件名", "时间"});
    mystatusWidget* status = new mystatusWidget(this);
    status->setFixedHeight(150);
    layout->addWidget(videoWidget, 0, 0, 1, 4);
    layout->addWidget(fileBrowser, 0, 4, 1, 1);
    layout->addWidget(status, 1, 0, 1, 5);
    layout->setSpacing(0);
    ui->centralwidget->setLayout(layout);

    this->setStyleSheet("QWidget#status{border: 3px, gray; border-color: gray; border-style: groove; border-radius: 5px;}");
}

SikPlayer::~SikPlayer()
{
    delete ui;
}

void SikPlayer::enterEvent(QEvent*)
{
    ui->menubar->show();
}
