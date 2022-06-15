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
#include"mounster.h"
namespace Ui {
class MainScene;
}

class MainScene : public QWidget
{
    Q_OBJECT

public:
    PauseScene pauseScene;//暂停菜单
    int timerSlow;
    int timerNormal;
    int timerFast;//三个计时器的编号，Fast用于加速，Slow用于记录通关时间，Normal用于常规绘图
    int gameProgress;//判断游戏是否正在进行
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
private:
    Ui::MainScene *ui;
signals:
    void back();//返回上一页
};

#endif // MAINSCENE_H
