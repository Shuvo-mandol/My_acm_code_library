#include<bits/stdc++.h>
using namespace std;

#define N 100

int binarySearch(int ar[], int n, int m) // Binary search
{
    int low = 1;
    int high = n;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(ar[mid] == m)
            return mid;
        else if(m < ar[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int n, m;
    int ar[N];
    cin >> n;                            // Total number of elements
    for(int i=1; i<=n; i++)
        cin >> ar[i];                    // Sorted elements

    cin >> m;                            // Element to be searched
    int res = binarySearch(ar, n, m);
    if(res != -1)
        cout<<m<<" "<<"found at position "<<res;
    else
        cout<<"Not found";
    return 0;
}
