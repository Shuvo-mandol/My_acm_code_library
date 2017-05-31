#include<bits/stdc++.h>
using namespace std;

#define N 100

int ternarySearch(int ar[], int n, int m)  // Ternary search
{
    int low = 1;
    int high = n;
    while(low <= high)
    {
        int mid1 = low + (high-low)/3;
        int mid2 = high - (high-low)/3;
        if(ar[mid1] == m)
            return mid1;
        if(ar[mid2] == m)
            return mid2;
        if(m < ar[mid1])
            high = mid1-1;
        else if(m > ar[mid2])
            low = mid2+1;
        else
        {
            low = mid1+1;
            high = mid2-1;
        }
    }
    return -1;
}


int main()
{
    int n, m;
    int ar[N];
    cin >> n;                              // Total number of elements
    for(int i=1; i<=n; i++)
        cin >> ar[i];                      // Sorted elements

    cin >> m;                              // Element to be searched
    int res = ternarySearch(ar, n, m);
    if(res != -1)
        cout<<m<<" "<<"found at position "<<res;
    else
        cout<<"Not found";
    return 0;
}
