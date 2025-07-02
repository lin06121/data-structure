#include<iostream>
using namespace std;
int main()
{  char str[101];
   cin.getline(str,101);
   int a1=0,a2=0,a3=0,a4=0;
   for(int i=0;str[i]!='\0';i++)
   {  if(('A'<=str[i]&&str[i]<='Z')||('a'<=str[i]&&str[i]<='z')) a1++;
   	  else if('0'<=str[i]&&str[i]<='9')  a2++;
   	  else if(str[i]==' '||str[i]=='\t')  a3++;
   	  else a4++;
	} 
	
	
	cout<<a1<<a2<<a3<<a4;
	
	
	
	
	return 0;
	
	
	
	
}
