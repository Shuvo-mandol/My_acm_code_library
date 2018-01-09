#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;                     // Data
    struct node * left;          // Pointer to left node
    struct node * right;        // Pointer to right node
};

struct node * newNode(int data)
{
    struct node * temp;
    temp= (node * )malloc(sizeof(node));
    temp->data= data;
    temp->left= NULL;
    temp->right= NULL;
    return temp;
};

struct node * insertNode(struct node * root, int data) // Function for inserting node
{
    if(root==NULL)
        return newNode(data);
    else
    {
        if(data <= root->data)
            root->left= insertNode(root->left, data);
        else
            root->right= insertNode(root->right, data);
        return root;
    }
};

void postorder(struct node*root)
{
    if(root)
    {
        postorder(root->left);       // Move to left sub tree
        postorder(root->right);     // Move to right sub tree
        cout<< root->data <<" ";   // Root->data
    }
}

int main()
{
    struct node * root;
    root= (node * )malloc(sizeof(node));
    root= NULL;

    int n;                              // Total nodes
    cin>> n;
    for(int i=0; i<n; i++)
    {
        int v;
        cin>> v;
        root= insertNode(root, v);
    }
    postorder(root);
    return 0;
}


