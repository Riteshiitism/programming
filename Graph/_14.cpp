#include <bits/stdc++.h>
using namespace std;
vector<int> indegreeCal(vector<int> adj[], int n)
{
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int child : adj[i])
        {
            indegree[child]++;
        }
    }
    return indegree;
}
vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
{
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];

        adj[x].push_back(y);
    }
    vector<int> mintime(n, INT_MAX);
    vector<int> indegree = indegreeCal(adj, n);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            mintime[i - 1] = 1;
        }
    }

    while (q.size())
    {
        int k = q.size();
        for (int i = 0; i < k; i++)
        {
            int tmp = q.front();
            q.pop();
            for (int child : adj[tmp])
            {
                indegree[child]--;
                if (indegree[child] == 0)
                {
                    q.push(child);
                    mintime[child - 1] = mintime[tmp - 1] + 1;
                }
            }
        }
    }
    return mintime;
}
int main(){
    
}