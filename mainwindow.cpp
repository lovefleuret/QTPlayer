#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalhelper.h"
#include "easylogging++.h"
#include "ffmsg_queue.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->playListDockWidget->setFeatures(QDockWidget::DockWidgetMovable | 
                       QDockWidget::DockWidgetFloatable);
    initUi();

    //事件绑定


    
    FFmsg_Queue queueTest;
    MessageQueue *q = (MessageQueue *)malloc(sizeof(MessageQueue));
    q->recycle_msg = NULL;
    q->recycle_count = 0;
    q->alloc_count = 0;
    q->abort_request = 0;
    q->nb_messages = 0;



    
    //写入数据到队列
    queueTest.msg_queue_init(q);
    queueTest.msg_queue_put_simple3(q, 1, 2, 3);
    queueTest.msg_queue_put_simple3(q, 4, 5, 6);
    queueTest.msg_queue_put_simple3(q, 7, 8, 9);


    queueTest.show_queue_info(q);

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
