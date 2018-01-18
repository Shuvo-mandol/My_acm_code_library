#include<bits/stdc++.h>
using namespace std;

int PartitionIndex(long int ar[], int start, int end)
{
    int pivot= ar[end];
    int pindex= start;
    for(int i=start; i<end; i++)
    {
        if(ar[i]<pivot)
        {
            swap(ar[i], ar[pindex]);
            pindex++;
        }
    }
    swap(ar[pindex], ar[end]);
    return pindex;
}

void QuickSort(long int ar[], int start, int end)
{
    if(start < end)
    {
        int pindex= PartitionIndex(ar, start, end);
        QuickSort(ar, start, pindex-1);
        QuickSort(ar, pindex+1, end);
    }
}

int main()
{
    int n;
    cin >> n;
    long int ar[n+1];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    QuickSort(ar,0,n-1);
    for(int i=0; i<n; i++)
        cout<< ar[i]<<" ";
    return 0;
}
