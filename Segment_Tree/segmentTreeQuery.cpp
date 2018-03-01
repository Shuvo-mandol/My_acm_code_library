#include<bits/stdc++.h>
using namespace std;

// Build Segment Tree

void buildSegmentTree(int indx, int L, int R, int ar[], int sum[])
{
    sum[indx]= 0;
    if(L==R)
    {
        sum[indx]= ar[L];
        return;
    }

    int mid= (L+R)/2;
    buildSegmentTree(indx*2, L, mid, ar, sum);
    buildSegmentTree(indx*2+1, mid+1, R, ar, sum);

    sum[indx]= sum[indx*2]+sum[indx*2+1];
}

// Perform query in segment Tree

int query(int indx, int L, int R, int l, int r, int ar[], int sum[])
{
    if(r<L || R<l)
        return 0;
    if(l<=L && R<=r)
        return sum[indx];
    int mid= (L+R)/2;
    int x= query(indx*2, L, mid, l, r, ar, sum);
    int y= query(indx*2+1, mid+1, R, l, r, ar, sum);

    return x+y;
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

    cout<<query(1, 1, n, 1, 4, ar, sum)<<endl;  //Find value from index 1 to 4

    return 0;
}


