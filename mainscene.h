////////////游戏主界面////////////
#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include<aboutscene.h>
#include<mybutton.h>
#include<QPainter>
#include<QDebug>
#include<QMessageBox>//标准对话框
#include <QWidget>
#include<QString>
#include<QTimer>
#include<QKeyEvent>
#include<QDialog>
#include"pausescene.h"
#include"brick.h"
#include"castle.h"
#include"mario.h"
#include"pipe.h"
#include"monster.h"
#include"mushroom.h"
namespace Ui {
class MainScene;
}

class MainScene : public QWidget
{
    Q_OBJECT

public:
    PauseScene pauseScene;//暂停菜单
    Brick* brick;
    Castle* castle;
    Mario* mario;
    Pipe* pipe;
    Monster* monster;
    Mushroom* mushroom;//游戏画面各组成要素
    int timerNormal;
    int timerFast;//两个计时器的编号，Fast用于加速，Normal用于常规绘图
    double time;//计算通关时间
    bool gameProgress;//判断游戏是否正在进行
    bool timerFastKilled;//判断加速计时器是否开启
    QString key;//用于记录键盘事件，当移动时为“left/right”，不移动时为“NULL”，以与mario->direction区分，后者记录的是mario的朝向
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();
    //重写绘图事件
    void paintEvent(QPaintEvent* ev);
    //重写计时事件(动画效果主要通过计时事件和绘图事件的结合来实现)
    void timerEvent(QTimerEvent *event);
    //重写键盘事件
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void SetButtons();//设置游戏主界面的pause,music,back按钮
    void SetPauseScene();//设置游戏的暂停画面
    void SetWholeGame();//设置游戏的主要参数(初始化)
    void CollisionCheck();//碰撞检测
    void Fall();//各种物体从高处落到低处(如果放到mario等类内部，则需要将地图传入，会导致耦合，所以就放外面了)
private:
    Ui::MainScene *ui;
signals:
    void back();//返回上一页
};

#endif // MAINSCENE_H
