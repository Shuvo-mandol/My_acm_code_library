#include<bits/stdc++.h>
using namespace std;

#define N 100

int main()
{
    int n, m;
    int ar[N];
    cin >> n;                             // Total number of elements
    for(int i=1; i<=n; i++)
    {
        cin >> ar[i];                     // Elements
    }
    cin >> m;                             // Element to be searched
    int flg = 1;
    for(int i=1; i<=n; i++)
    {
        if(ar[i] == m)
        {
            cout<<m<<" "<<"found at position "<<i;
            flg = 0;
            break;
        }
    }
    if(flg)
        cout<<"Not found.";
    return 0;
}
