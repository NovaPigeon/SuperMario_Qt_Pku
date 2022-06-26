#include "music.h"
//#include<gamebeginwindow.h>

Music::Music(QWidget *parent) : QWidget(parent)
{
    beatEnemy=new QSound(":/Music/beatenemy.wav",this);
    bloodRewarding=new QSound(":/Music/bloodrewarding.wav",this);
    breakBrick=new QSound(":/Music/breakbrick.wav",this);
    die=new QSound(":/Music/die.wav",this);
    eatMushroom=new QSound(":/Music/eatmushroom.wav",this);
    fail=new QSound(":/Music/fail.wav",this);
    finish=new QSound(":/Music/finish.wav",this);
    gameBegin=new QSound(":/Music/gamebegin.wav",this);
    getCoin=new QSound(":/Music/getcoin.wav",this);
    mainMusic=new QSound(":/Music/mainmusic.wav",this);
    ButtonClicked=new QSound(":/Music/clicked.wav",this);
}
