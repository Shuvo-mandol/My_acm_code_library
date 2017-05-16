#include<bits/stdc++.h>
using namespace std;

#define MAX 10
int stk[MAX];
int top= -1;
void push();
void pop();
void display();

int main()
{
    int ch;
    cout<<">>> C program to represent a stack >>> "<<endl;
    do
    {
        cout<<"1. Push"<<endl;
        cout<<"2. pop"<<endl;
        cout<<"3. display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice : ";
        int ch;
        cin >> ch;
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout<<"End of program "<<endl;
            return 0;
        default:
            cout<<"Enter a right choice : "<<endl;
        }
    }
    while(ch!=4);
    return 0;
}

void push()
{
    int num;
    cout<<"Enter a value : ";
    cin >> num;
    if(top>9)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        top++;
        stk[top]= num;
    }
}

void pop()
{
    if(top== -1)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        cout<< stk[top]<<" deleted " <<endl;
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        cout<<"Elements are : ";
        int i;
        for(i=0; i<=top; i++)
            cout<< stk[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"No elements to display "<<endl;
}

