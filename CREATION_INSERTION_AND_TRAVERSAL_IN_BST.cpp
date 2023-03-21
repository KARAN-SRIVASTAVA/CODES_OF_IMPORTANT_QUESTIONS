// Binary Search Tree
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void InsertInBST(node *&root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return;
    }
    if (root->data > d)
        InsertInBST(root->left, d);
    else
        InsertInBST(root->right, d);
}
void lot(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    node *root = NULL;
    int d = INT_MIN;
    while (1)
    {
        cin >> d;
        if (d == -1)
            break;
        InsertInBST(root, d);
    }
    cout << "Level Order Traversal of BST is :" << endl;
    lot(root);
    cout << "InOrder Traversal of BST is :" << endl;
    inorder(root);
    cout << endl;
    cout << "PreOrder Traversal of BST is :" << endl;
    preorder(root);
    cout << endl;
    cout << "PostOrder Traversal of BST is :" << endl;
    postorder(root);
    cout << endl;
    return 0;
}
/*
input:
12 15 11 14 19 9 10 17 -1
output:
Level Order Traversal of BST is :
12 
11 15 
9 14 19 
10 17 
InOrder Traversal of BST is :
9 10 11 12 14 15 17 19 
PreOrder Traversal of BST is :
12 11 9 10 15 14 19 17 
PostOrder Traversal of BST is :
10 9 11 14 17 19 15 12
*/
