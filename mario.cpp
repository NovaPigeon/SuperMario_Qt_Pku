////////马里奥类////////
#include "mario.h"

Mario::Mario()
{
    x=30;
    y=405;//mario的绝对坐标,由于是以左上角为坐标原点，故y=450-45，45为mario高度
    windowX=0;//mario与地面的相对坐标，实现地面的相对运动
    goundState=0;//地面的状态
    walkState=0;//mario运动的状态
    jumpHeight=20;//mario跳跃的最大高度
    life=5;//mario的生命值
    isDie=false;//mario是否死亡
    direction="right";//mario运动的方向，左还是右
    isJump=false;//判断空格是否被按下
    isJumpEnd=true;//判断跳跃是否结束，以防止二段跳
    isSpaceRelease=true;//判断空格是否被松开，以检测滞空时间
    canMove=true;
}
void Mario::MarioJump()//弹跳
{

}
void Mario::MarioMove(QString key)//水平移动,如果直接调用direction的话，会导致mario在没有移动时移动
{
    //刚开始时，mario有相对窗口的运动，当mario居中时，mario就相对窗口静止，相对地面运动
    if(key=="left"&&x<=400&&canMove&&x>=30)//如果x<30,mario可能会消失在边界
    {
        x-=5;
        windowX-=5;
        walkState+=57;
    }
    else if(key=="right"&&x<=400&&canMove)
    {
        x+=5;
        windowX+=5;
        walkState+=57;
    }
    else if((key=="left"&&x<30)||(key!="NULL"&&!canMove))//mario处于屏幕最左侧或者被卡着不动时，mario姿势变化，位置不变
    {
        walkState+=57;
    }
    else if(key=="right"&&x>400&&canMove)
    {
        x+=5;
        goundState+=5;
        walkState+=57;
    }
    else if(key=="left"&&x>400&&canMove)
    {
        x-=5;
        goundState-=5;
        walkState+=57;
    }
    //循环复位
    if(goundState>=1000)
        goundState=0;
    if(goundState<-5)
        goundState=995;
    if(walkState>=1140)
        walkState=0;
    //滞空时mario不做动作
    if(!isJumpEnd)
        walkState=0;
}

void Mario::MarioDie()//播放mario的死亡动画
{

}
