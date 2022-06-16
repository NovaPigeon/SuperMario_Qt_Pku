////////////游戏主界面////////////
#include "mainscene.h"
#include "ui_mainscene.h"
MainScene::MainScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this->setFixedSize(1000,500);
    this->setWindowTitle("SuperMario");
    SetPauseScene();
    SetButtons();
    timerSlow=startTimer(40);
    timerNormal=startTimer(25);
    timerFast=startTimer(15);
}
void MainScene::SetPauseScene()
{
    //实现返回按钮
    MyButton*backBtn=new MyButton(":/Image/backBtn.png");
    backBtn->setParent(&pauseScene);
    backBtn->move(0.5*pauseScene.width()-0.5*backBtn->width(),0.7*pauseScene.height());
    connect(backBtn,&MyButton::clicked,[=](){
        backBtn->ZoomUp();
        backBtn->ZoomDown();
        //先实现按钮弹跳特效，而后等待0.5s后发送back()信号
        QTimer::singleShot(500,this,[=](){
            emit pauseScene.back();
        });
    });
    //实现退出按钮
    MyButton *exitBtn=new MyButton(":/Image/exitBtn.png");
    exitBtn->setParent(&pauseScene);
    exitBtn->move(0.5*pauseScene.width()-0.5*exitBtn->width(),0.3*pauseScene.height());
    connect(exitBtn,&MyButton::clicked,
            [=](){
        exitBtn->ZoomUp();
        exitBtn->ZoomDown();
        //先暂停0.5s，弹出一个是否选择退出的问题对话框
        QTimer::singleShot(500,this,[=](){
            int ret=QMessageBox::question(this,"Quit",
                                          "Do you really want to quit the game?",
                                          QMessageBox::No,
                                          QMessageBox::Yes);
            switch (ret) {
            case QMessageBox::Yes:
                this->close();//如果选Yes，则退出游戏；否则什么都不用做
                break;
            default:
                break;
            }
        });
    });
}
void MainScene::SetButtons()
{
    //实现返回按钮
    MyButton*backBtn=new MyButton(":/Image/backBtn.png");
    backBtn->setParent(this);
    backBtn->move(0.945*this->width(),0.89*this->height());
    connect(backBtn,&MyButton::clicked,[=](){
        backBtn->ZoomUp();
        backBtn->ZoomDown();
        //先实现按钮弹跳特效，而后等待0.5s后发送back()信号
        QTimer::singleShot(500,this,[=](){
            emit back();
        });
    });
    //实现暂停按钮
    MyButton*pauseBtn=new MyButton(":/Image/pauseBtn.png");
    pauseBtn->setParent(this);
    pauseBtn->move(0.945*this->width()-50,0.89*this->height());
    connect(pauseBtn,&MyButton::clicked,[=](){
        pauseBtn->ZoomUp();
        pauseBtn->ZoomDown();
        QTimer::singleShot(500,this,[=](){
            pauseScene.setParent(this);
            pauseScene.open();
        });
    });
    //继续
    connect(&pauseScene,&PauseScene::back,[=](){
            pauseScene.close();
    });
    //实现音乐设置按钮
    MyButton*musicBtn=new MyButton(":/Image/musicBtn.png");
    musicBtn->setParent(this);
    musicBtn->move(0.945*this->width()-100,0.89*this->height());
    connect(musicBtn,&MyButton::clicked,[=](){
        musicBtn->ZoomUp();
        musicBtn->ZoomDown();
        QTimer::singleShot(500,this,[=](){

        });
    });
}
void MainScene::SetWholeGame()
{

}
//重写paintEvent事件
void MainScene::paintEvent(QPaintEvent *ev)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建背景图并绘制之
    QPixmap pix(":/Image/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
//重写计时事件(动画效果主要通过计时事件和绘图事件的结合来实现)
void MainScene::timerEvent(QTimerEvent *event)
{

}
//重写键盘事件
void MainScene::keyPressEvent(QKeyEvent *event)
{

}
void MainScene::keyReleaseEvent(QKeyEvent *event)
{

}
MainScene::~MainScene()
{
    delete ui;
}
