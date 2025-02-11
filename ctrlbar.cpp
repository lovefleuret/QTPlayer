#include "ctrlbar.h"
#include "ui_ctrlbar.h"

CtrlBar::CtrlBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlBar)
{
    ui->setupUi(this);
    //设置按钮图标
    QIcon icon_play(":/ctrl/icon/play.png");
    ui->playOrPauseBtn->setIcon(icon_play);
    
    QIcon icon_stop(":/ctrl/icon/stop.png");
    ui->stopBtn->setIcon(icon_stop);
}

CtrlBar::~CtrlBar()
{
    delete ui;
}

void CtrlBar::on_playOrPauseBtn_clicked()
{
    qDebug("play or pause btn");
}

void CtrlBar::on_stopBtn_clicked()
{
    qDebug("stop play btn");
}
