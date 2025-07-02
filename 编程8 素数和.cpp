#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i=2,prime=0;
	cin>>n;
	while(i<=n)
	{  int isprime=0;
		for(int j=1;j<=sqrt(i);j++)
		{  
		   if(i%j==0) isprime+=1;
			
			if(isprime>=2) break;
			
		}
		
	   if(isprime==1){
	   	prime+=i;  
		   }
	   i++;
	}
	
	cout<<prime;
   return 0;	
}
