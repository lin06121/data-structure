#include<iostream>
#include<cstring>
 using namespace std;
  void Arrange(char str[],int k);
  void swap(char str[],int k,int i);
 // char array(char str[],int max);
  int main()
  {
  	int max;char str2[30];
  	
  	cout<<"ÔªËØ¸öÊý";
	  cin>>max;
	for (int v=0;v<=max-1;v++)
  	cin>>str2[v];
  	Arrange(str2,0);
  	
  //	for (int g=0;g<=max;g++)
  	
  	//cout<<str2[g];
  	
  	
  	
  	return 0;
  }
  
  
  
  /*
  char array(char str[],int max)
  {
  	char str[30];int max;
	for (int i=0;i<=max;i++)
  	 cin>>str[i];
  	return max;
  }
 */

 
 	void Arrange(char str[],int k)
 	{  int i;
 	  if (k==strlen(str)) cout<<str<<endl;
 	  else for (i=k;i<=strlen(str);i++)
 	    {
 	    	swap(str,k,i);
 	       Arrange(str,k+1);
 	       swap(str,k,i);
 	    	
 	    	
		 }
 		
 		
	 }
 	
 	
 	void swap(char str[],int k,int i)
 	{ int temp;
 	  temp=str[k];
 	  str[k]=str[i];
 	  str[i]=temp;
 		
 		
 		
 		
	 }

 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 
