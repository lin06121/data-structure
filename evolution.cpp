//
// Created by yulin on 25-7-4.
//
//this is a evolution agologythem to find the maxnum of fuction of f
// f=20+x_1^2+x_2^2-10\left(\cos{2\pi x_1}+\cos{2\pi x_2}\right)
#include<iostream>
#include<time.h>
#include<math.h>
#include<conio.h>
#include <filesystem>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define num_C 12 //个体个数
#define N 100 //群体规模
#define pc 0.9//交叉概率
#define pm 0.1//变异概率
#define ps 0.6//变异时选择概率
#define genmax 2000//最大代数
int randominteger(int min, int max);
void inital_gen(struct unit group[N]);
void sort(struct unit group[N]);
void copy_unit(struct unit *p1, struct unit *p2);
void cross(struct unit *p3, struct unit *p4);
void varation(struct unit group[N],int i);
void evolution(struct unit group[N]);
float caculate_cost(struct unit *p);
void print_optimum(struct unit group[N],int k);

//定义个体信息
struct unit {
    int path[num_C]; //个体信息
    double cost; //个体代价
};
struct unit group[N];
int num_gen = 0;
int main() {
    int i,j;
    srand((int)time(nullptr));
    inital_gen(group);
    evolution(group);
    getch();
    return 0;
}

//inital group
void inital_gen(struct unit group[N]) {
    int i,j;
    struct unit *p;
    for (i = 0; i < N-1; i++) {
        p=&group[i];
        for (j = i+1; j < 12; j++) {
            p->path[j] = randominteger(0,9);
        }
        caculate_cost(p);
    }
}

// group evolution
void evolution(struct unit group[N]) {
    int i,j;
    int temp1,temp2,temp3,temp4,temp5;
    temp1 = N*pc/2;
    temp2 = N*(1-pc);
    temp3 = N*(1-pc/2);
    temp4 = N*(1-pc);
    temp5 = N*pc;
    for (i = 0; i < genmax ; i++) {
       //select
        for (j = 0; j < temp4-1; j++) {
           copy_unit(&group[j],&group[j+temp5]);
        }
        //cross
        for (j = 0; j < temp1-1; j++) {
            cross(&group[temp2+j],&group[j+temp3]);
        }
        //变异
       varation(group,i);
    }
    sort(group);
    print_optimum(group,i-1);
}

//cross
void cross(struct unit *p3, struct unit *p4) {
    int i,j,cross_point;
    int son1[num_C],son2[num_C];
    for (i = 0; i < num_C; i++) {
        son1[i] = -1;
        son2[i] = -1;
    }
    cross_point = randominteger(1,num_C-1);
    for (i=0;i<cross_point;i++) {
        son1[i]=p3->path[i];
    }
    for (i=cross_point;i<num_C-1;i++) {
        for (j=0;j<num_C-1;j++) {
            son1[i]=p4->path[j];
        }
    }
    for (i=cross_point;i<num_C-1;i++) {
        son2[i]=p4->path[i];
    }
    for (i=0;i<cross_point;i++) {
        for (j=0;j<num_C-1;j++) {
            son2[i]=p3->path[j];
        }
    }

    for (i=0;i<num_C-1;i++) {
        p3->path[i]=son1[i];
        p4->path[i]=son2[i];
    }
    caculate_cost(p3);
    caculate_cost(p4);
}

//varation
void varation(struct unit group[N],int flag_v) {
    int flag,i,j,k,temp;
    struct unit *p;
    flag=randominteger(1,100);
    if ((!flag>(flag_v>100))?(5*100*pm):(100*pm)) {
        i=randominteger(1,N-1);
        j=randominteger(1,num_C-1);
        k=randominteger(1,num_C-1);
        p=&group[i];
        temp=p->path[j];
        p->path[j]=p->path[k];
        p->path[k]=temp;
        caculate_cost(p);
    }
}

void sort(struct unit group[N]) {
    int i,j;
    struct unit temp,*p1,*p2;
    for (j= 0; j < N-1; j++) {
        for (i = 0; i < N-1; i++) {
           p1=&group[i-1];
            p2=&group[i];
            if (p1->cost > p2->cost) {
                copy_unit(p1,&temp);
                copy_unit(p2,p1);
                copy_unit(&temp,p2);
            }
        }
    }
}

float caculate_cost(struct unit *p) {
    double x1,x2;
    x1=0;
    if (p->path[0] >5) {
        x1=p->path[1]+p->path[2]*0.1+p->path[3]*0.01+p->path[4]*0.001+p->path[5]*0.0001;
    }
    else if (p->path[0] <6) {
        x1=0-(p->path[1]+p->path[2]*0.1+p->path[3]*0.01+p->path[4]*0.001+p->path[5]*0.0001);
    }
    x2=0;
    if (p->path[6] >5) {
        x2=p->path[7]+p->path[8]*0.1+p->path[9]*0.01+p->path[10]*0.001+p->path[11]*0.0001;
    }
    else if (p->path[6] <6) {
        x2=0-(p->path[7]+p->path[8]*0.1+p->path[9]*0.01+p->path[10]*0.001+p->path[11]*0.0001);
    }
    p->cost=20+x1*x1+x2*x2-10*(cos(2*3.1415*x1)+cos(2*3.1415*x2));
    return (p->cost);
}

void copy_unit(struct unit *p1,struct unit *p2) {
    int i;
    for (i = 0; i < num_C; i++) {
        p2->path[i] = p1->path[i];
    }
    p2->cost = p1->cost;
}

int randominteger(int min, int max) {
    int k;
    double d;
    k=rand();
    k=(k!=RAND_MAX)?k:k-1;
    d=(double)k/((double)RAND_MAX);
    k=(int)(d*(max-min+1));
    return min+k;

}

void print_optimum(struct unit group[N],int k) {
    struct unit *p;
    double x1,x2;
    x1=x2=0;
    p=&group[0];
    if (p->path[0] >5) {
        x1=p->path[1]+p->path[2]*0.1+p->path[3]*0.01+p->path[4]*0.001+p->path[5]*0.0001;
    }
    else if (p->path[0] <6) {
        x1=0-(p->path[1]+p->path[2]*0.1+p->path[3]*0.01+p->path[4]*0.001+p->path[5]*0.0001);
    }
    x2=0;
    if (p->path[6] >5) {
        x2=p->path[7]+p->path[8]*0.1+p->path[9]*0.01+p->path[10]*0.001+p->path[11]*0.0001;
    }
    else if (p->path[6] <6) {
        x2=0-(p->path[7]+p->path[8]*0.1+p->path[9]*0.01+p->path[10]*0.001+p->path[11]*0.0001);
    }

    printf("%lf",x1);
    printf("%lf",x2);
    printf("函数最小值为%f\n",p->cost);
}

