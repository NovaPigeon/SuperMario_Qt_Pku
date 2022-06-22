/////////水管类//////////
#include "pipe.h"

Pipe::Pipe()
{
    //记录水管在地图的坐标和长短，0为短管，1为长管
    int arr[5][2]={
        {400,0},
        {550,1},
        {250,0},
        {700,1},
        {2000,1}
    };
    QVector<int> v;
    for(int i=0;i<5;++i)
    {
        v.push_back(arr[i][0]+2000);
        v.push_back(arr[i][1]);
        mp.push_back(v);
        v.clear();
    }
    heightLong=100;
    heightshort=50;
    widthLong=70;
    widthShort=70;

}
