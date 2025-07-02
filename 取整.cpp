#include <iostream>
using namespace std;
void qz (float n)
 {
 	int x=0;
	for (n;n>=1;x++)
 	{
 		n--;
	 }
	cout<<x; 
 }

int main()
{
	float a;
	cin>>a;
	qz(a);
	return 0;
 } 


