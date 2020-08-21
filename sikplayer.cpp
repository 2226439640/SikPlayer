#include "sikplayer.h"
#include "ui_sikplayer.h"
#include "QIcon"
#include "resConfig.h"
#include "QMenu"
#include "QFileDialog"
#include "QPalette"
#include "QGridLayout"
#include "mystatuswidget.h"
#include <QTableWidgetItem>
#include "QMessageBox"
using namespace SikConfig;

SikPlayer::SikPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SikPlayer)
{
    this->setWindowIcon(QIcon(icoUrl));
    this->setAttribute(Qt::WA_TransparentForMouseEvents);

    ui->setupUi(this);

    ui->menubar->setVisible(false);



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
    videoWidget->show();
    playlist = new QMediaPlaylist();
    player->setPlaylist(playlist);
    fileBrowser = new QTableWidget(this);
    fileBrowser->setColumnCount(2);
    fileBrowser->setHorizontalHeaderLabels({"文件名", "时间"});
    fileBrowser->setFixedWidth(200);
    mystatusWidget* status = new mystatusWidget(this);
    status->setFixedHeight(150);
    layout->addWidget(videoWidget, 0, 0, 1, 4);
    layout->addWidget(fileBrowser, 0, 4, 1, 1);
    layout->addWidget(status, 1, 0, 1, 5);
    layout->setSpacing(0);
    ui->centralwidget->setLayout(layout);

    connect(ui->fileMenu, &QMenu::triggered, this, [&](){
        QStringList templist = QFileDialog::getOpenFileNames();
        for(QString file : templist)
        {
            filelist.append(file);
        }
        for(QString file : filelist)
        {
            playlist->addMedia(QMediaContent(QUrl(file)));
        }
        updateList(filelist);
    });

    connect(status, &mystatusWidget::Play, this, [&](){
        if(playlist->isEmpty())
        {
            QMessageBox();
            return;
        }
        player->play();
    });

    connect(status, &mystatusWidget::Stop, this, [&](){
        player->play();
    });

    //this->setStyleSheet("QWidget#status{border: 3px, gray; border-color: gray; border-style: groove; border-radius: 5px;}");
}

SikPlayer::~SikPlayer()
{
    delete ui;
}

void SikPlayer::enterEvent(QEvent*)
{
    ui->menubar->show();
}

void SikPlayer::updateList(QStringList &playlist)
{
    fileBrowser->setRowCount(playlist.count());
    for(int i=0; i<playlist.size(); ++i)
    {
        QStringList splname = playlist[i].split("/");
        QTableWidgetItem* item = new QTableWidgetItem(splname[splname.size()-1]);
        fileBrowser->setItem(i, 0, item);
    }
}
