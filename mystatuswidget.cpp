#include "mystatuswidget.h"
#include "ui_mystatuswidget.h"
#include "resConfig.h"
#include "QIcon"

using namespace SikConfig;

mystatusWidget::mystatusWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mystatusWidget)
{
    ui->setupUi(this);
    ui->upButton->setIcon(QIcon(upUrl));
    ui->upButton->setFixedWidth(50);
    ui->upButton->setFixedHeight(50);
    ui->upButton->setFlat(true);
    ui->backButton->setIcon(QIcon(backUrl));
    ui->backButton->setFixedSize(50, 50);
    ui->backButton->setFlat(true);
    ui->stopButton->setIcon(QIcon(stopUrl));
    ui->stopButton->setFlat(true);
    ui->stopButton->setFixedSize(50, 50);
    ui->timelabel->setFixedHeight(50);
}

mystatusWidget::~mystatusWidget()
{
    delete ui;
}
