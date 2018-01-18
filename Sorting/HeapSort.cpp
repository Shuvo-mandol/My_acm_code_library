#include<bits/stdc++.h>
using namespace std;

#define MAX 8
int n;
int ar[MAX+1];

void InsertValue(int val)
{
    if(n==MAX)
    {
        cout<<"Heap is full\n\n";
        return;
    }
    ++n;
    ar[n]= val;
    int p= n;
    while(p>1)
    {
        int pr= p/2;
        if(ar[pr]>ar[p])
        {
            swap(ar[pr], ar[p]);
            p= pr;
        }
        else break;
    }
}

int DeleteValue()
{
    if(n==0)
    {
        cout<<"\nHeap is empty\n\n";
        return -1;
    }
    int k= ar[1];
    ar[1]= ar[n];
    n--;
    int p= 1;
    while(2*p<=n)
    {
        int ch= 2*p;
        if(2*p+1<=n)
        {
            if(ar[ch]>ar[ch+1])
                ch++;
        }
        if(ar[p]>ar[ch])
        {
            swap(ar[p], ar[ch]);
            p= ch;
        }
        else break;
    }
     return k;
}

int main()
{
    int flg= 1;
    while(flg)
    {
        cout<<"1. Insert()\n";
        cout<<"2. Delete()\n";
        cout<<"3. Exit()\n\n";
        cout<<"Option : ";
        int Option;
        cin >> Option;
        switch(Option)
        {
        case 1:
            int val;
            cout<<"Insert value : ";
            cin >> val;
            cout<<"\n";
            InsertValue(val);
            break;
        case 2:
            int num;
            num = DeleteValue();
            if(num!=-1)
                cout<<"Deleted Value : "<<num<<"\n\n";
            break;
        default:
            flg= 0;
            break;
        }
    }
    return 0;
}
