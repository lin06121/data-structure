#include <iostream>
using namespace std;
int main()
{ int n,m=1;
int a[100][100];
 cin>>n;
 int f=0,r=n-1,u=n-1,l=0;
 while(m<=n*n)
 { for(int k=l;k<=r;k++)
   { a[f][k]=m++;
      
   }
     f++;
   for(int k=f;k<=u;k++)
   { a[k][r]=m++;
      
   }
      r--;
      if(f<u){
	  
   for(int k=r;k>=l;k--)
   { a[u][k]=m++;
      
   }
     u--;}
     
     if(l<r){
	 
   for(int k=u;k>=f;k--)
   { a[k][l]=m++;
     

   }
      l++ ;}
  

  }
for(int i=0;i<=n-1;i++)
  { for(int j=0;j<=n-1;j++)
    {
        cout<<a[i][j];
        if(j<n-1) cout<<" ";
    }

  cout<<endl;


 }

  











}
