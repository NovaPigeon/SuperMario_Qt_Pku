////////音乐控制类////////
#ifndef MUSIC_H
#define MUSIC_H
#include"mybutton.h"
#include <QWidget>
#include<QSound>

class music : public QWidget
{
    Q_OBJECT
public:
    explicit music(QWidget *parent = 0);
    QSound*bloodRewarding;//生命值奖励音效
    QSound*breakBrick;//顶碎砖块
    QSound*eatMushroom;//吃到蘑菇
    QSound*finish;//过关音乐
    QSound*gameBegin;//开始界面音乐
    QSound*getCoin;//得到金币
    QSound*beatEnemy;//击败敌人
    QSound*speedUpLevel;//加速关卡背景音乐
    QSound*timeEnding;//倒计时
    QSound*underWaterLevel;//水下关卡背景音乐(可替换成其他关卡)
signals:

public slots:

};

#endif // MUSIC_H
