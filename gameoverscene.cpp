//////////游戏结束页//////////
#include "gameoverscene.h"

GameOverScene::GameOverScene()
{
    //设置固定的窗口大小
    this->setFixedSize(200,250);
    //设置窗口标题
    this->setWindowTitle("GameOver");
    //设置窗口样式
    this->setWindowModality(Qt::ApplicationModal);
}
void GameOverScene::paintEvent(QPaintEvent *event)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建背景图并绘制之
    QPixmap pix(":/Image/pauseScene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}