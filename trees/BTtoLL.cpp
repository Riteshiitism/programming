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
// morris traversal    O(1) extra space
void flatten(Node *root) // preorder
{
    Node *cur = root;
    Node *pred;
    while (cur != NULL)
    {
        if (cur->left != NULL)
        {
            pred = cur->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}
// recursive O(n) extra space
// reverse post order
void solve(Node *root, Node *&prev)
{
    if (root == NULL)
        return;

    solve(root->right, prev);
    solve(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}
void flattenRecursive(Node *root)
{
    Node *prev = NULL;
    solve(root, prev);
}

// O(n) extra space is used
void flatteniterative(Node *root)
{
    stack<Node *> st;
    if (root != NULL)
        st.push(root);
    while (st.size())
    {
        Node *topNode = st.top();
        st.pop();
        if (topNode->right)
            st.push(topNode->right);
        if (topNode->left)
            st.push(topNode->left);

        if (st.size())
        {
            topNode->right = st.top();
        }
        topNode->left = NULL;
    }
}
int main()
{
}