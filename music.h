////////音乐控制类////////
#ifndef MUSIC_H
#define MUSIC_H
#include"mybutton.h"
#include <QWidget>
#include<QSound>

class Music : public QWidget
{
    Q_OBJECT
public:
    explicit Music(QWidget *parent = 0);
   QSound*beatEnemy;
   QSound*bloodRewarding;
   QSound*breakBrick;
   QSound*die;
   QSound*eatMushroom;
   QSound*fail;
   QSound*finish;
   QSound*gameBegin;
   QSound*getCoin;
   QSound*mainMusic;
signals:

public slots:

};

#endif // MUSIC_H
