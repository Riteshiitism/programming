#include<bits/stdc++.h>
using namespace std;
vector<int> indegreCal(vector<int> adj[], int n)
{
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int child : adj[i])
        {
            indegree[child]++;
        }
    }
    return indegree;
}
bool isPossible(int n, vector<pair<int, int>> &prereq)
{
    vector<int> adj[n];
    for (int i = 0; i < prereq.size(); i++)
    {
        int x = prereq[i].first;
        int y = prereq[i].second;
        adj[y].push_back(x);
    }

    // vector<bool>vis(n,false);
    vector<int> indegree = indegreCal(adj, n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            // vis[i]=true;
        }
    }
    int cnt = 0;
    while (q.size())
    {
        int tmp = q.front();
        q.pop();

        for (int child : adj[tmp])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
                // vis[i]=true;
            }
        }
        cnt++;
    }

    return (cnt == n);
}