#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int ar[], int n)
{
    for(int i=1; i<n; i++)
    {
        int value= ar[i];
        int hole= i;
        while(hole>0 && ar[hole-1]>value)
        {
            ar[hole]= ar[hole-1];
            hole--;
        }
        ar[hole]= value;
    }
}

int main()
{
    int n;
    cin >> n;
    int ar[n+1];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    InsertionSort(ar,n);
    for(int i=0; i<n; i++)
        cout<<ar[i]<<" ";
    return 0;
}


