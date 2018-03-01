#include<bits/stdc++.h>
using namespace std;

// Build segment Tree from Array

void buildSegmentTree(int indx, int L, int R, int ar[], int sum[])
{
    sum[indx]= 0;
    if(L == R)
    {
        sum[indx]= ar[L];
        return;
    }

    int mid= (L+R)/2;
    buildSegmentTree(indx*2, L, mid, ar, sum);
    buildSegmentTree(indx*2+1, mid+1, R, ar, sum);

    sum[indx]= sum[indx*2]+sum[indx*2+1];
}

int main()
{
    int n;
    cin >> n;
    int ar[n+5];
    int sum[n*4];
    for(int i=0; i<n*4; i++)
        sum[i]= 0;
    for(int i=1; i<=n; i++)
        cin >> ar[i];
    buildSegmentTree(1,1,n,ar,sum);

    return 0;
}
