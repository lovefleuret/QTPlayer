#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalhelper.h"
#include "easylogging++.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUi();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUi()
{
        //加载样式
    QString qss = GlobalHelper::GetQssStr(":/res/qss/mainwindow.qss");

    setStyleSheet(qss);
}
