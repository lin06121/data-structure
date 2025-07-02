#include<iostream>
 using namespace std;
 int main()
 {
 	int n;
 	
 	cin>>n;
 	for (int i=1;i<=n*(n-1)/2;i+=2){
	 
 	   for (int j=(n*(n-1)/2-i)/2;j>=1;j-=1)
 	     {cout<<' ';
		  }
 	   for (int k=1;k<=i;k++)
		  cout<<'*';	
 	   	
 	   	  cout<<endl;
 	   	
 	   	
 	       }
		
 	   
 	
 	
 	
 	return 0;
 	
 	
 }
