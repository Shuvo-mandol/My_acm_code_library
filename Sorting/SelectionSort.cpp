#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int ar[], int n)
{
   int minimum;
   for(int i=0; i<n-1; i++)
   {
       minimum= i;
       for(int j=i+1; j<n; j++)
       {
           if(ar[j]<ar[minimum])
           {
               minimum= j;
           }
       }
       swap(ar[i], ar[minimum]);
   }
}

int main()
{
    int n;
    cin >> n;
    int ar[n+1];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    SelectionSort(ar,n);
    for(int i=0; i<n; i++)
        cout<<ar[i]<<" ";
    return 0;
}

