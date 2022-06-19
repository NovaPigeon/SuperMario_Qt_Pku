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

signals:

public slots:
};

#endif // MUSIC_H
