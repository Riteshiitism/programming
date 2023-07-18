#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int data;
    TreeNode(int x)
    {
        this->data = x;
        this->right = this->left = NULL;
    }
};

// <<<<<<<<<<----------- using preorder and inorder  --------------->>>>>>>>>
// approach 1  optimised
int find(vector<int> &inorder, int key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == key)
        {
            return i;
        }
    }
    return -1;
}
TreeNode *solve(int &idx, int s, int e, int n, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp)
{
    // base case
    if (idx >= n || s > e)
    {
        return NULL;
    }
    int key = preorder[idx++];
    // int pos = find(inorder,key,n);
    int pos = mp[key];
    TreeNode *head = new TreeNode(key);

    head->left = solve(idx, s, pos - 1, n, preorder, inorder, mp);
    head->right = solve(idx, pos + 1, e, n, preorder, inorder, mp);
    return head;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();
    int idx = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
    return solve(idx, 0, n - 1, n, preorder, inorder, mp);
}

// approach 2    better

TreeNode *solve(int s, int e, int n, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp)
{
    // base case
    if (s > e)
        return NULL;
    int headIdx = n;
    int idx;
    for (int i = s; i <= e; i++)
    {
        if (headIdx > mp[inorder[i]])
        {
            headIdx = mp[inorder[i]];
            idx = i;
        }
    }
    cout << headIdx << endl;
    TreeNode *head = new TreeNode(preorder[headIdx]);

    head->left = solve(s, idx - 1, n, preorder, inorder, mp);
    head->right = solve(idx + 1, e, n, preorder, inorder, mp);

    return head;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[preorder[i]] = i;
    }
    return solve(0, n - 1, n, preorder, inorder, mp);
}

// approach 3  normal   gives TLE
TreeNode *solve(int s, int e, int n, vector<int> &preorder, vector<int> &inorder)
{
    // base case
    if (s > e)
        return NULL;
    int headIdx;
    int idx;
    for (int i = s; i <= e; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (inorder[i] == preorder[j])
            {
                if (headIdx > j)
                {
                    headIdx = min(headIdx, j);
                    idx = i;
                    break;
                }
            }
        }
    }
    cout << headIdx << endl;
    TreeNode *head = new TreeNode(preorder[headIdx]);

    head->left = solve(s, idx - 1, n, preorder, inorder);
    head->right = solve(idx + 1, e, n, preorder, inorder);

    return head;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();
    return solve(0, n - 1, n, preorder, inorder);
}



// <<<<<<<<<<----------- using postorder and inorder  --------------->>>>>>>>>
int find(vector<int> &inorder, int key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == key)
        {
            return i;
        }
    }
    return -1;
}
TreeNode *solve(int &idx, int s, int e, int n, vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp)
{
    // base case
    if (idx < 0 || s > e)
        return NULL;
    int key = postorder[idx--];
    // int pos = find(inorder,key,n);
    int pos = mp[key];

    TreeNode *head = new TreeNode(key);

    head->right = solve(idx, pos + 1, e, n, inorder, postorder, mp);
    head->left = solve(idx, s, pos - 1, n, inorder, postorder, mp);

    return head;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    int idx = n - 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode *ans = solve(idx, 0, n - 1, n, inorder, postorder, mp);
    return ans;
}
