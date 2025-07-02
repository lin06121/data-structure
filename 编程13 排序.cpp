#include<iostream>
using namespace std;
int main()
{
	int a[100],n,temp;
	cin>>n;
	for(int i=0;i<=n-1;i++)
	{
	  cin>>a[i];		
	}
	
	for(int i=1;i<=n-1;i++)
	{
	   for(int j=i-1;j>=0;j--)
	   {
	   	 if(a[j]>a[j+1]) 
	   	 {  temp=a[j];
	   	     a[j]=a[j+1];
	   	    a[j+1]=temp; 
			}
			
		   }	
		
		
	}
	
	for(int i=0;i<=n-1;i++)
	{
		cout<<a[i];
	}
	
return 0;	
	
	
	
}
