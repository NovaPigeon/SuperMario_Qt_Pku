////////////砖块类(包含问号砖和普通砖)/////////
#include "brick.h"

Brick::Brick()
{
    unknownState=0;
    //砖块的状态，分别为x，y和砖块的种类(0:普通砖块;1:含金币的砖块;2:含蘑菇的砖块;3:含怪物的砖块;)
    int arr[38][4] = {{800,  350, 1},
                      {1050, 350, 2},
                      {1100, 200, 1},
                      {1150, 350, 1},
                      {3650, 350, 1},
                      {4450, 200, 1},
                      {5000, 350, 1},
                      {5150, 350, 2},
                      {5150, 200, 1},
                      {5300, 350, 1},
                      {6100, 200, 1},
                      {6150, 200, 1},
                      {7350, 350, 2},
                      {8400, 270, 1},
                      {8450, 270, 1},
                      {8500, 270, 1},
                      {8550, 270, 1},
                      {8600, 270, 1},
                      {8650, 270, 1},
                      {8700, 270, 1},
                      {8750, 270, 1},
                      {8800, 270, 1},
                      {8850, 270, 1},
                      {7800, 310, 1},
                      {8250, 150, 0},
                      {8300, 150, 0},
                      {7850, 310, 1},
                      {7900, 310, 1},
                      {7900, 270, 0},
                      {7950, 270, 0},
                      {8000, 270, 0},
                      {8000, 230, 0},
                      {8050, 230, 0},
                      {8100, 230, 0},
                      {8100, 190, 0},
                      {8150, 190, 0},
                      {8200, 190, 0},
                      {8200, 150, 0}

                     };
    QVector<int> v;
    for(int i=0;i<38;++i)
    {
        for(int j=0;j<3;++j)
            v.push_back(arr[i][j]);
        v.push_back(1);//1表示砖块尚未被摧毁
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

}
