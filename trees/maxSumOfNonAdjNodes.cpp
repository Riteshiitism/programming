#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int x){
        this->data = x;
        this->right = this->left = NULL;
    }
};
int solve(Node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int taken = root->data;
    if (root->left)
    {
        taken += solve(root->left->left) + solve(root->left->right);
    }
    if (root->right)
    {
        taken += solve(root->right->left) + solve(root->right->right);
    }
    int notTaken = 0 + solve(root->left) + solve(root->right);

    return max(taken, notTaken);
}
int solveMem(Node *root, unordered_map<Node *, int> &mp)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    if (mp.find(root) != mp.end())
        return mp[root];

    int taken = root->data;
    if (root->left)
    {
        taken += solveMem(root->left->left, mp) + solveMem(root->left->right, mp);
    }
    if (root->right)
    {
        taken += solveMem(root->right->left, mp) + solveMem(root->right->right, mp);
    }
    int notTaken = 0 + solveMem(root->left, mp) + solveMem(root->right, mp);

    mp[root] = max(taken, notTaken);
    return max(taken, notTaken);
}
int getMaxSum(Node *root)
{
    // return solve(root);

    unordered_map<Node *, int> mp;
    return solveMem(root, mp);
}