//
// Created by 玉林 on 25-5-12.
//
#include<iostream>
using namespace std;
int divide(int a[],int low,int high)
    {int k=a[low];
    do{ while(low<high && a[high]>=k) --high;
      if(low<high) {a[low]=a[high]; ++low;}
      while(low<high && a[low]<=k) ++low;
      if(low<high) {a[high]=a[low]; --high;}
      }while(low!=high);
      a[low]=k;
      return low;
      }

void quick_sort(int arr[], int low, int high)
    {int mid;
  if(low >=high) return;
  mid=divide(arr,low, high);
  quick_sort(arr, low, mid-1);
  quick_sort(arr, mid + 1, high);

 }

int delete_duplicates(int arr[], int n)
    { int i,j=0;
    quick_sort(arr, 0, n-1);
    for(i=1;i<n;i++)
    { if(arr[i]!=arr[j]) arr[++j]=arr[i];
      }
   return j;
    }

int main()
{

  int a[]={6,88,4,6,2,8,5,4,3,4,5,6,9};
   for (int i=0;i<=12;i++)
   {
     cout<<a[i]<<" ";
   }
  cout<<endl;
  int m=delete_duplicates(a,13);
  cout<<m<<endl;
  for (int i=0;i<=m;i++)
  {
    cout<<a[i]<<" ";
  }
  return 0;


}