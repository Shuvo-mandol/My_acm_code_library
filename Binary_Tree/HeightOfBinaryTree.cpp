#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    struct node * left;
    struct node * right;
};

struct node * newNode(char ch)
{
    struct node * temp;
    temp= (struct node * )malloc(sizeof(node));
    temp->data= ch;
    temp->left= NULL;
    temp->right= NULL;
    return temp;
}

struct node * insertNode(struct node * root, string s, char ch, int i)
{
    if(root==NULL)
        return newNode(ch);
    else
    {
        if(s[i]=='L')
        {
            root->left= insertNode(root->left, s, ch, i= i+1);
        }
        else if(s[i]=='R')
        {
            root->right= insertNode(root->right, s, ch, i= i+1);
        }
    }
    return root;
};

int height(struct node * root)
{
    if(root==NULL)
        return 0;

    int left= height(root->left);
    int right= height(root->right);

    int h;
    if(left>right)
        h= 1+left;
    else
        h= 1+right;

    return h;
}

int main()
{
    int n;             // Total nodes
    cin >> n;
    char ch;          // Root node
    cin >> ch;

    struct node * root;
    root= (struct node * )malloc(sizeof(node));
    root->data= ch;
    root->left= NULL;
    root->right= NULL;

    for(int i=0; i<n-1; i++)
    {
        string s;
        cin >> s >> ch;
        insertNode(root, s, ch, 0);
    }

    cout<< height(root) <<endl;

    return 0;
}

/*sample input

13
a
L b
R c
LL d
LR e
LRL f
LRR g
LRRL h
LRRR i
RL j
RR k
RRL l
RRR m

*/

/*Sample output

5

*/

