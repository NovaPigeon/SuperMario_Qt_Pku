/////////游戏的暂停菜单////////
#ifndef PAUSESCENE_H
#define PAUSESCENE_H

#include <QWidget>
#include<QEvent>
#include<QPainter>
#include<QDialog>
#include<QMessageBox>
#include"mybutton.h"
#include"music.h"
class PauseScene : public QDialog
{
    Q_OBJECT
public:
    PauseScene();
    void paintEvent(QPaintEvent *event);
    Music musicControl;
signals:
    void back();
public slots:
};

#endif // PAUSESCENE_H
