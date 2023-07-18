#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

//***********method 1********
// find path of n1  from root to n1
// find path of n2 from root to n2
// find last common node in both path that will be lowest common ancestor
void find(Node *root, int x, vector<int> tmp, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == x)
    {
        tmp.push_back(root->data);
        ans = tmp;
    }

    tmp.push_back(root->data);

    find(root->left, x, tmp, ans);
    find(root->right, x, tmp, ans);
}
void find(Node *root, int x, Node *&ans)
{
    if (root == NULL)
        return;
    if (root->data == x)
    {
        ans = root;
    }

    find(root->left, x, ans);
    find(root->right, x, ans);
}
Node *lca(Node *root, int n1, int n2)
{
    vector<int> path1;
    vector<int> tmp;
    find(root, n1, tmp, path1);

    vector<int> path2;
    find(root, n2, tmp, path2);
    //   for(int val:path1){
    //       cout<<val<<" ";
    //   }
    //   cout<<endl;
    //   for(int val:path2){
    //       cout<<val<<" ";
    //   }
    int rootData = -1;
    int i = 0;
    int j = 0;
    while (i < path1.size() && j < path2.size() && path1[i] == path2[j])
    {
        rootData = path1[i];
        i++;
        j++;
    }
    // cout<<rootData<<endl;
    Node *ans;
    find(root, rootData, ans);
    return ans;
}

//****************mathod 2************
// if from both child a node receive something not NULL then it will be LCA
Node *lca(Node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *l = lca(root->left, n1, n2);
    Node *r = lca(root->right, n1, n2);

    if (l != NULL && r != NULL)
        return root;
    else if (l != NULL && r == NULL)
        return l;
    else if (l == NULL && r != NULL)
        return r;
    else
        return NULL;
}