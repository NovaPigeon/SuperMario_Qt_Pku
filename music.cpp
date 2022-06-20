#include "music.h"

music::music(QWidget *parent) : QWidget(parent)
{
    bloodRewarding=new QSound(":/Music/bloodrewarding.mp3",this);
    breakBrick=new QSound(":/Music/breakbrick.mp3",this);
    eatMushroom=new QSound(":/Music/eatmushroom.mp3",this);
    finish=new QSound(":/Music/finish.mp3",this);
    gameBegin=new QSound(":/Music/gamebegin.mp3",this);
    getCoin=new QSound(":/Music/getcoin.mp3",this);
    beatEnemy=new QSound(":/Music/heatenemy.mp3",this);//起错名字了
    speedUpLevel=new QSound(":/Music/speeduplevel.mp3",this);
    timeEnding=new QSound(":/Music/timeending.mp3",this);
    underWaterLevel=new QSound(":/Music/underwaterlevel.mp3",this);
}
