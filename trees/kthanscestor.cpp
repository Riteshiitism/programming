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
void path(Node *root, int node, vector<int> tmp, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->data == node)
    {
        tmp.push_back(root->data);
        ans = tmp;
    }
    tmp.push_back(root->data);
    path(root->left, node, tmp, ans);
    path(root->right, node, tmp, ans);
    tmp.pop_back();
}
Node *solve(Node *root, int node, int &k, Node *&ans)
{
    if (root == NULL)
        return NULL;
    if (root->data == node)
    {
        k--;
        return root;
    }

    Node *l = solve(root->left, node, k, ans);
    Node *r = solve(root->right, node, k, ans);
    if (k == 0)
    {
        ans = root;
        // cout<<ans->data<<endl;
    }
    if (l != NULL)
    {
        k--;
        return l;
    }
    else if (r != NULL)
    {
        k--;
        return r;
    }
    else
    {
        return NULL;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    //*****method 1********//
    Node *ans = NULL;
    Node *tmp = solve(root, node, k, ans);
    if (ans == NULL)
        return -1;
    return ans->data;

    //*****method 2********//
    // vector<int>tmp;
    // vector<int>ans;
    // path(root,node,tmp,ans);
    // // for(auto val:ans){
    // //     cout<<val<<" ";
    // // }
    // int n = ans.size();
    // if(k>=n) return -1;
    // return ans[n-1-k];
}