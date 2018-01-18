#include<bits/stdc++.h>
using namespace std;

void mergeIndex(int ar[], int start, int mid, int end)
{
    int p= start;
    int q= mid+1;
    int arr[end-start+1];
    int k= 0;

    for(int i=start; i<=end; i++)
    {
        if(p>mid)
            arr[k++]= ar[q++];
        else if(q>end)
            arr[k++]= ar[p++];
        else if(ar[p]<ar[q])
            arr[k++]= ar[p++];
        else
            arr[k++]= ar[q++];
    }

    for(int i=0; i<k; i++)
        ar[start++]= arr[i];
}

void merge_sort(int ar[], int start, int end)
{
    if(start<end)
    {
        int mid= (start+end)/2;
        merge_sort(ar,start,mid);
        merge_sort(ar,mid+1,end);

        mergeIndex(ar,start,mid,end);
    }
}

int main()
{
    int n;
    cin >> n;
    int ar[n+1];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    merge_sort(ar,0,n-1);
    for(int i=0; i<n; i++)
        cout<< ar[i]<<" ";
    return 0;
}

