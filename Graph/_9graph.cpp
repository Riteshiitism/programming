#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution
{
public:
    void dfs(Node* node,Node* &root,vector<Node*>&vis){
        root->val = node->val;
        vis[root->val] = root;
        for(auto child:node->neighbors){
            if(vis[child->val]==NULL){
                Node* newNode = new Node();
                (root->neighbors).push_back(newNode);
                dfs(child,newNode,vis);
            }
            else{
                (root->neighbors).push_back(vis[child->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {


        // using dfs
        // if(node == NULL) return NULL;
        // Node* root = new Node();
        // vector<Node*>vis(1000,NULL);
        // dfs(node,root,vis);
        // return root;



        // using bfs
        if(node==NULL) return NULL;
        vector<Node*>vis(200,NULL);
        Node* root = new Node(node->val);
        queue<Node*>q;
        q.push(node);
        vis[node->val] = root;
        while(q.size()){
            Node* tmp = q.front();
            q.pop();
            Node* tmpRoot = vis[tmp->val];
            for(auto child: tmp->neighbors){
                if(vis[child->val]==NULL){
                    Node* newNode = new Node(child->val);
                    (tmpRoot->neighbors).push_back(newNode);

                    q.push(child);
                    vis[child->val] = newNode;
                }
                else{
                    (tmpRoot->neighbors).push_back(vis[child->val]);
                }
            }
        } 
        return root;
    }
};