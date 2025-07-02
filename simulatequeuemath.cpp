//
// Created by 玉林 on 25-3-18.
#include<iostream>
#include <cstdlib>
 using namespace std;
 int main()
 { int n,l1,h1,l2,h2;//n 总人数，l1 h1 l2 h2到达时间范围，完成时间范围
   cin>>n>>l1>>h1>>l2>>h2;
   int a=0, c= rand() % (h2 - l2 + 1) + l2;//a 第n人到达时间， c 第n人完成时间
   int waitingtime=0;
   for (int i=0;i<=n;i++)
     { int x = rand() % (h1 - l1 + 1) + l1;
        a=a+x;
        int y=rand() % (h2 - l2 + 1) + l2;
        int tmp=c;//保存c（n-1）
        c=y+(a>c? a:c);
        if(tmp-a>0) waitingtime+=tmp-a;
        }

    cout<<"averege waiting time "<<waitingtime/n;


    return 0;
    }
//b 第n人开始时间；
// an=an-1  +  x;
//bn=  an (if an >cn-1 ) |  cn-1  (if an < cn-1)  代入可得递归