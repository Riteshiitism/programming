#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }
};
//20.
Node *reverseDLL(Node *head)
{
    Node *prev = NULL;
    Node *cur = head;
    while (cur != NULL)
    {
        Node *tmp = cur->next;
        cur->next = prev;
        cur->prev = tmp;
        prev = cur;
        cur = tmp;
    }
    return prev;
}
//21.
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    // Naive approach
    //  unordered_map<int,bool>mp;
    //  Node* cur = head;
    //  vector<pair<int,int>>ans;
    //  while(cur!=NULL){
    //      // if(mp[target-(cur->data)]){
    //      //     pair<int,int>p;
    //      //     p.first = target-(cur->data);
    //      //     p.second = cur->data;
    //      //     ans.push_back(p);
    //      // }
    //      mp[cur->data]=1;
    //      cur=cur->next;
    //  }

    //********this can be done by using one loop is order of pair doesn't matter
    // cur = head;
    // while(cur!=NULL){
    //     if(mp[target-(cur->data)] && cur->data!=target-(cur->data)){
    //         pair<int,int>p;
    //         p.first = cur->data;
    //         p.second = target-(cur->data);
    //         ans.push_back(p);
    //         mp[cur->data] = false;
    //     }
    //     cur = cur->next;
    // }
    // return ans;

    // better appoach  two pointer approach
    vector<pair<int, int>> ans;
    Node *s = head;
    Node *e = head;
    while (e != NULL && e->next != NULL)
    {
        e = e->next;
    }
    while (s->data < e->data)
    {
        int x = s->data + e->data;
        if (x == target)
        {
            pair<int, int> p;
            p.first = s->data;
            p.second = e->data;
            ans.push_back(p);
            s = s->next;
            e = e->prev;
        }
        else if (x > target)
        {
            e = e->prev;
        }
        else
        {
            s = s->next;
        }
    }
    return ans;
}
int main()
{
}