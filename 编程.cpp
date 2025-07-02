#include"stdio.h"
#define N 100

#include<iostream>
using namespace std;

int main()
{
cout<<"aa";
return 0;

}
/*
float lagrange(float*x,float*y,float xx,int n)
{
      int i,j;
      float yy=0.0;
      float a[20];
      for(i=0;i<=n-1;i++)
      {
                         a[i]=y[i];
                         for(j=0;j<=n-1;j++)
                            if(j!=i) a[i]*=(xx-x[j])/(x[i]-x[j]);
                          yy+=a[i];

       }
       return yy;

}
int main()
{
    int i,n;
    float x[20],y[20],xx,yy;
    printf("?/");
    scanf("%d",&n);
    if(n<=0)
    {
            printf("!");
            return 1;
     }
     for(i=0;i<=n;i++)
     {
         printf("x[%d]=",i);
         scanf("%f",&x[i]);
         printf("y[%d]=",i);
         scanf("%f",&y[i]);
     }
     printf("\n");
     printf("xx=");
     scanf("%f",&xx);
     yy=lagrange(x,y,xx,n);
     printf("x=%f,y=%f\n",xx,yy);
     return 0;
     }
*/
