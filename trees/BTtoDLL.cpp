#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int x)
    {
        this->data = x;
        this->right = this->left = NULL;
    }
};
void solve(Node *root, Node *&prev, Node *&head)
{
    if (root == NULL)
        return;

    solve(root->left, prev, head);
    if (prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    solve(root->right, prev, head);
}
Node *bToDLL(Node *root)
{
    Node *head = NULL;
    Node *prev = NULL;

    solve(root, prev, head);

    return head;
}