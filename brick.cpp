////////////砖块类(包含问号砖和普通砖)/////////
#include "brick.h"

Brick::Brick()
{
    unknownState=0;
    //先使用参考的砖块地图
    //砖块长50 宽40
    //砖块的状态，分别为x，y，砖块的种类，和砖块的状态(0:普通砖块;1:含金币的砖块;2:不含金币的砖块;)
    int arr[64][3] = {{500,460,0},
                      {550,420,0},
                      {550,460,0},
                      {600,460,0},
                      {600,420,0},
                      {600,380,0},
                      {600,200,2},
                      {750,460,0},
                      {750,420,0},
                      {750,380,0},
                      {750,200,1},
                      {800,460,0},
                      {800,420,0},
                      {800,200,2},
                      {850,420,0},
                      {850,460,0},
                      {850,200,2},
                      {900,200,0},
                      {1000,380,2},
                      {1050,380,1},
                      {1100,380,2},
                      {2450,460,0},
                      {2500,420,0},
                      {2550,380,0},
                      {2600,340,0},
                      {3000,460,0},
                      {3500,300,2},
                      {3500,460,0},
                      {3550,420,0},
                      {3600,380,0},
                      {3650,340,0},
                      {3700,300,0},
                      {3700,100,2},
                      {5000,460,0},
                      {5050,420,0},
                      {5100,380,0},
                      {5200,380,2},
                      {5250,380,2},
                      {5350,380,0},
                      {5400,420,0},
                      {5450,460,0},
                      {6500,350,2},
                      {6550,350,1},
                      {6600,350,0},
                      {6600,250,2},
                      {6650,350,1},
                      {6650,250,1},
                      {6700,350,2},
                      {6700,250,2},
                      {7300,250,2},
                      {7580,320,2},
                      {7800,460,0},
                      {7850,420,0},
                      {7900,380,0},
                      {7950,340,0},
                      {8000,300,0},
                      {8050,300,0},
                      {8100,300,0},
                      {8150,300,0},
                      {8200,300,0},
                      {8250,300,0},
                      {8300,300,0},
                      {8350,300,0},
                      {8400,300,0}
                     };
    QVector<int> v;
    for(int i=0;i<64;++i)
    {
        arr[i][0]+=500;
        arr[i][1]-=50;
        for(int j=0;j<3;++j)
            v.push_back(arr[i][j]);
        v.push_back(1);//1表示砖块尚未被摧毁
        v.push_back(0);//0表示特殊砖块保持其初始状态
        mp.push_back(v);
        v.clear();
    }
    //    for (QVector < QVector < int >> ::iterator it = mp.begin(); it != mp.end();it++)
    //    {
    //        qDebug()<<" "<<*(it->begin()+0)<<" "<<*(it->begin()+1)<<" "<<*(it->begin()+2)<<" "<<*(it->begin()+3);
    //        qDebug()<<"\n";
    //    }
}
void Brick::BrickStateChange()
{
    unknownState += 50;
    unknownState=unknownState%750;
    for (QVector < QVector < int >> ::iterator it = mp.begin(); it != mp.end();it++)
    {
        if(*(it->begin()+4)!=0 && *(it->begin()+4)!=8)
            *(it->begin()+4) +=1;
        else if(*(it->begin()+4)==8)
            *(it->begin()+4) =0;
    }

}
