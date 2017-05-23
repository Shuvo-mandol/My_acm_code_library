#include<bits/stdc++.h>
using namespace std;
#define MAX 10
int qu[MAX];
int front= -1;
int rear = -1;
void insert_element();
void delete_element();
void display_element();

int main()
{
    int option;
    cout<<">>> C program to display queue >>> "<<endl;
    do
    {
        cout<< "1. Insert_element"<<endl;
        cout<< "2. Delete_element"<<endl;
        cout<< "3. Display_element"<<endl;
        cout<< "4. Exit"<<endl;
        cout<< "Enter a option : ";
        cin >> option;
        cout<<endl;
        switch(option)
        {
            case 1: insert_element();
            break;
            case 2: delete_element();
            break;
            case 3: display_element();
            break;
            case 4: cout<<"End of program ";
            return 0;
            default: cout<<"Enter a right value "<<endl;
        }
    }
    while(option != 4);

    return 0;
}

void insert_element()
    {

        int num;
        cout<<"Enter a value to be inserted : ";
        cin >> num;
        if(front==0 && rear== MAX-1 || front== rear+1)
        {
            cout<<"Overflow"<<endl;
        }
        else if(front==-1 && rear== -1)
        {
            front= 0;
            rear=0;
            qu[rear]= num;
        }
        else if(rear== MAX-1 && front !=0)
        {
            rear=0;
            qu[rear]= num;
        }
        else
        {
            rear++;
            qu[rear]= num;
        }
    }
    void delete_element()
    {
        int element;
        if(front== -1)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        element= qu[front];
        if(front== rear && front!=-1 && rear!= -1)
        {
            cout<<element<<" Deleted"<<endl;
        }
        if(front == rear)
        {
            front= -1;
            rear= -1;
        }
        else
        {
            if(front== MAX-1)
            front=0;
            else
            front++;
            cout<<element<<" deleted";
            cout<<endl;
        }
    }
    void display_element()
    {
        int i;
        if(front== -1)
        {
            cout<<"No elements to display"<<endl;
            return;
        }
        else
        {
           cout<<"The elements are : ";
           i=front;
           if(front<= rear)
           {
               while(i<=rear)
               {
                  cout<< qu[i]<<" ";
                  i++;
               }
           }
           else
           {
               while(i<=MAX-1)
               {
                   cout<< qu[i]<<" ";
                   i++;
               }
               i=0;
               while(i<= rear)
               {
                   cout<< qu[i]<<" ";
                   i++;
               }
           }
           cout<<endl;
        }
    }
