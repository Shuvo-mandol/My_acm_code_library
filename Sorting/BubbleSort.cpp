#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int ar[], int n)
{
    for(int k=0; k<n-1; k++)
    {
        int temp;
        for(int i=0; i<n-k-1; i++)
        {
            if(ar[i]>ar[i+1])
            {
                temp= ar[i];
                ar[i]= ar[i+1];
                ar[i+1]= temp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int ar[n+5];
    for(int i=0; i<n; i++)
        cin >> ar[i];
    bubbleSort(ar,n);
    for(int i=0; i<n; i++)
        cout<<ar[i]<<" ";
    return 0;
}
