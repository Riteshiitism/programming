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
void findParent(Node *root, unordered_map<Node *, Node *> &mp)
{
    mp[root] = NULL;
    queue<Node *> q;
    q.push(root);
    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        if (tmp->left != NULL)
        {
            mp[tmp->left] = tmp;
            q.push(tmp->left);
        }
        if (tmp->right != NULL)
        {
            mp[tmp->right] = tmp;
            q.push(tmp->right);
        }
    }
}
Node *search(Node *root, int target)
{
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;

    Node *l = search(root->left, target);
    Node *r = search(root->right, target);

    if (l != NULL)
        return l;
    else if (r != NULL)
        return r;
    else
        return NULL;
}
int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> mp;
    findParent(root, mp);
    // for(auto it:mp){
    //     if(it.first!=NULL && it.second!=NULL){
    //         cout<<(it.first)->data<<" "<<(it.second)->data<<endl;
    //     }
    // }

    Node *tmp = search(root, target);
    // cout<<tmp->data<<endl;

    queue<Node *> q;
    unordered_map<Node *, bool> vis;
    q.push(tmp);
    vis[tmp] = true;
    int ans = 0;
    while (q.size())
    {
        int k = q.size();
        while (k--)
        {
            auto frontNode = q.front();
            q.pop();
            // cout<<frontNode->data<<" ";

            if (mp[frontNode] != NULL && vis.find(mp[frontNode]) == vis.end())
            {
                q.push(mp[frontNode]);
                vis[mp[frontNode]] = true;
            }
            if (frontNode->left != NULL && vis.find(frontNode->left) == vis.end())
            {
                q.push(frontNode->left);
                vis[frontNode->left] = true;
            }
            if (frontNode->right != NULL && vis.find(frontNode->right) == vis.end())
            {
                q.push(frontNode->right);
                vis[frontNode->right] = true;
            }
        }
        // cout<<endl;
        ans++;
    }
    return ans - 1;
}