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
void solve(Node *root, int k, vector<int> path, int &ans)
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    solve(root->left, k, path, ans);
    solve(root->right, k, path, ans);

    int sz = path.size();
    int sum = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            ans++;
    }

    path.pop_back();
}
int sumK(Node *root, int k)
{
    vector<int> path;
    int ans = 0;
    solve(root, k, path, ans);
    return ans;
}
//-9 -6 2 -12 0 -5 N -3 4 -19 5 -9 2 N -3 3 -13 -8 -11 -6 N -16 -13
//-7