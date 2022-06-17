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
    SetWholeGame();
    SetPauseScene();
    SetButtons();
    timerNormal=startTimer(25);
    //timerFast=startTimer(15);当且仅当加速时开启
}
void MainScene::SetPauseScene()
{
    //实现继续按钮
    MyButton*continueBtn=new MyButton(":/Image/continueBtn.png");
    continueBtn->setParent(&pauseScene);
    continueBtn->move(0.5*pauseScene.width()-0.5*continueBtn->width(),0.1*pauseScene.height());
    connect(continueBtn,&MyButton::clicked,[=](){
        continueBtn->ZoomUp();
        continueBtn->ZoomDown();
        //先实现按钮弹跳特效，而后等待0.5s后发送back()信号
        QTimer::singleShot(500,this,[=](){
            emit pauseScene.back();
        });
    });
    //实现退出按钮
    MyButton *exitBtn=new MyButton(":/Image/exitBtn.png");
    exitBtn->setParent(&pauseScene);
    exitBtn->move(0.5*pauseScene.width()-0.5*exitBtn->width(),0.5*pauseScene.height());
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
            killTimer(timerNormal);
            if(!timerFastKilled)
                killTimer(timerFast);
            timerFastKilled=true;
            //关闭计时器，实现暂停
            pauseScene.setParent(this);
            pauseScene.open();
        });
    });
    //继续
    connect(&pauseScene,&PauseScene::back,[=](){
        pauseScene.close();
        timerNormal=startTimer(25);
        //重新开启计时器
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
    brick=new Brick;
    castle=new Castle;
    mario=new Mario;
    pipe=new Pipe;
    monster=new Monster;
    mushroom=new Mushroom;//游戏画面各组成要素
    gameProgress=true;//判断游戏是否正在进行
    timerFastKilled=false;//判断加速计时器是否开启
    time=0;
    key="NULL";
}
//重写paintEvent事件
void MainScene::paintEvent(QPaintEvent *ev)
{
    //创建画家，指定绘图设备,载入图像
    QPainter painter(this);
    QPixmap pixBackground(":/Image/background.png");//背景
    QPixmap pixGround(":/Image/ground.png");//地面
    QPixmap pixMarioLeft(":/Image/moveleft.png");//mario向左走
    QPixmap pixMarioRight(":/Image/moveright.png");//mario向右走
    QPixmap pixMarioDie(":/Image/mariodie.png");//mario的死亡动画
    QPixmap pixUnknownBrick(":/Image/unknownbrick.png");//问号砖
    QPixmap pixUnknownBrickAfter(":/Image/unknownbrickafter.png");//被mario顶破后的问号砖
    QPixmap pixNormalBrick(":/Image/normalbrick.png");//普通砖块
    QPixmap pixMushroom(":/Image/mushroom.png");//蘑菇
    QPixmap pixMounster(":/Image/mounster.png");//怪物
    QPixmap pixLongPipe(":/Image/longpipe.png");//长水管
    QPixmap pixShortPipe(":/Image/shortpipe.png");//短水管
    //设置字体
    painter.setFont(QFont("Times",25,QFont::Black));
    //绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pixBackground);
    //绘制时间
    painter.drawText(10,30,"time:"+QString::number(time,'f',1));
    //绘制地面
    painter.drawPixmap(0,450,pixGround,mario->goundState,0,1000,50);//截取自goundX始长1000pix的图片，以营造出动画效果
    //绘制砖块
    for (QVector < QVector < int >> ::iterator it = brick->mp.begin(); it != brick->mp.end();it++)
    {
        if (*(it->begin()) - mario->x > -50 && *(it->begin()) - mario->x < 1000)
        {
            if(*(it->begin()+2)==0 && *(it->begin()+3)==1)//如果该砖块是普通砖块且尚未被摧毁
                painter.drawPixmap(*(it->begin()) - mario->x, *(it->begin() + 1)-50, pixNormalBrick);
            if(*(it->begin()+2)!=0 && *(it->begin()+3)==1)//如果该砖块是未知砖块且尚未被破坏
                painter.drawPixmap(*(it->begin()) - mario->x, *(it->begin() + 1)-50,pixUnknownBrick,brick->unknownState,0,50,40);
            if(*(it->begin()+2)!=0 && *(it->begin()+3)==0)//如果该砖块是未知砖块且已被破坏
                painter.drawPixmap(*(it->begin()) - mario->x, *(it->begin() + 1)-50, pixUnknownBrickAfter);
        }
    }
    //绘制mario
    if(!mario->isDie)
    {
        if(mario->direction=="left")
            painter.drawPixmap(mario->windowX,mario->y,pixMarioLeft,mario->walkState,0,45,45);
        else if(mario->direction=="right")
            painter.drawPixmap(mario->windowX,mario->y,pixMarioRight,mario->walkState,0,45,45);
    }
    else
    {

    }

}
//重写计时事件(动画效果主要通过计时事件和绘图事件的结合来实现)
void MainScene::timerEvent(QTimerEvent *event)
{
    int timerid=event->timerId();
    if(timerid==timerNormal&&mario->isDie)//如果mario死亡，则实现其死亡画面
    {
        mario->MarioDie();
        update();
        return;
    }
    if(timerid==timerNormal)
    {
        mario->MarioMove(key);
        mario->MarioJump();
        CollisionCheck();
        mushroom->MushroomMove();
        monster->MonsterMove();
        brick->BrickStateChange();
        Fall();
        time+=0.025;
        update();
    }
    if(timerid==timerFast)
    {
        mario->MarioMove(key);
        mario->MarioJump();
        CollisionCheck();
    }


}
//重写键盘事件
void MainScene::keyPressEvent(QKeyEvent *event)
{
    if(!mario->isDie)//只有在mario没死时，才会检测键盘输入
    {
        switch (event->key()) {
        case Qt::Key_Right:
            mario->direction=key="right";
            break;
        case Qt::Key_Left:
            mario->direction=key="left";
            break;
        case Qt::Key_Space:
            mario->isJump=true;
            mario->isSpaceRelease=false;
            break;
        case Qt::Key_K:
            timerFast=startTimer(15);//开始加速
            timerFastKilled=false;
            break;
        default:
            break;
        }
    }
}
void MainScene::keyReleaseEvent(QKeyEvent *event)
{
    if(!mario->isDie)//只有在mario没死时，才会检测键盘输入
    {
        switch (event->key()) {
        case Qt::Key_Right:
            key="NULL";//不必把direction也清空，因为direction是个持续的状态
            mario->walkState=0;//将mario复原为站立的状态
            break;
        case Qt::Key_Left:
            key="NULL";
            mario->walkState=0;
            break;
        case Qt::Key_Space:
            mario->isJump=false;//此时isJumpEnd仍未复原，是以仍能防止二段跳
            mario->isSpaceRelease=true;
            break;
        case Qt::Key_K:
            killTimer(timerFast);
            timerFastKilled=true;//关闭加速计时器，也就是说加速只在持续按下K时生效
            break;
        default:
            break;
        }
    }
}
void MainScene::CollisionCheck()
{

}
//各种物体从高处落到低处(如果放到mario等类内部，则需要将地图传入，会导致耦合，所以就放外面了)
void MainScene::Fall()
{

}

MainScene::~MainScene()
{
    killTimer(timerNormal);
    if(!timerFastKilled)
        killTimer(timerFast);
    delete ui;
}
