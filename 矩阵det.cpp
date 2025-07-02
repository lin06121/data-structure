#include<iostream>
using namespace std;
int main()
{ float a[100][100];
int m;
   cout<<"矩阵的行，列m";
   cin>>m; 
  for(int i=0;i<=m-1;i++)
	{
	for(int j=0;j<=m-1;j++)
	  {
	  cout<<"a["<<i<<"]"<<"["<<j<<"]"; 
	  cin>>a[i][j];
       }
    }
	  //输入矩阵
    float b[100];
	for(int k=0;k<=m-1;k++)
	//对第k列操作 
	 {  int g=k,l=1;
	   while(a[g][k]==0)
	   //判断主对角线元素是否是0 
	   {  
	     for(int j=0;j<=m-1;j++)
	     { 
		   b[j]=a[g][j];
	       a[g][j]=a[g+l][j];
	       a[g+l][j]=b[j];
		   //若是，交换下一行 
		 }
		 l+=1;
		 //若下一行为0；交换下下行 
	   }  
	   //化对角矩阵 
	 	for(int i=g+1;i<=m-1;i++)
	 	 {   
	 	 	for(int j=m-1;j>=0;--j)
	 	 	 
	 	 	 {
			   
	 	 	  a[i][j]=a[i][j]-a[i][k]/a[g][k]*a[g][j];
	 	 	  cout<<i<<'\t'<<j<<'\t'<<a[i][j]<<endl;
	 	 	
	 	     }
	 	 	
		  }
	
	  }
	 
	 	
	 float det=1;	
	 	for(int d=0;d<=m-1;d++)
	 	{
	 		det*=a[d][d];
	 		
	 		
		 }
	 	
	 cout<<det;
	 	//对角乘积 
	 	
	 	
	 	
	 	
	 	
	 	
	 	
	 	
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	for(int i=0;i<=m-1;i++)
	{
	  cout<<endl;
	   for(int j=0;j<=m-1;j++)
	    {
	    	cout<<a[i][j]<<'\t';
	    	
		}
	
	
    }
 	
	
	
	
	
	return 0;
	
}
