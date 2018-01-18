#include<bits/stdc++.h>
using namespace std;

void CountingSort(int ar[], int n)
{
    int k= 0;
    for(int i=0; i<n; i++)
    {
        if(ar[i]>k)
            k= max(k, ar[i]);
    }
    int aux[k+2];
    for(int i=0; i<=k+1; i++)
        aux[i]= 0;

    for(int i=0; i<n; i++)
        aux[ar[i]]++;

    int j=0;
    for(int i=0; i<=k; i++)
    {
        int temp= aux[i];
        while(temp--)
        {
            ar[j]= i;
            j++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int ar[n+1];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    CountingSort(ar,n);
    for(int i=0; i<n; i++)
        cout<< ar[i]<<" ";
    return 0;
}
