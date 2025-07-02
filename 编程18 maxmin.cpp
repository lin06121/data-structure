#include <iostream>
using namespace std;
void minmaxvalue(int a[],int n,int &min,int &max)
{ int min1,max1,min2,max2;
   switch(n){
   case 1:
         min=max=a[0];
		 return;
   case 2:
        if(a[0]<a[1]) 
		{min=a[0];max=a[1];
		}
          else 
		  {min=a[1];max=a[0];
		  } 
		  return;
   default: 
            minmaxvalue(a,n/2,min1,max1);
            minmaxvalue(a+n/2,n-n/2,min2,max2);       
             if(min1<min2)
			 {min=min1;
			 } 
			 else
			 {
			 min=min2;}
             if(max1>max2)
			 {max=max1;
			 } 
			 else{
			 	max=max2;
			 } 
             return;
   }

}
int main()
{ int a[10];
for(int i=0;i<10;i++)
{

    cin>>a[i];
}
int min=100,max=0;
minmaxvalue(a,10,min,max);
cout<<max<<min;



}
