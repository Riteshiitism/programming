#include <bits/stdc++.h>
using namespace std;
bool isBipartiteUsingBFS(int V, vector<int> adj[])
{
    vector<int> col(V, 0);
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (col[i] == 0)
        {
            q.push(i);
            col[i] = 1;
            while (q.size() > 0)
            {
                int u = q.front();
                q.pop();
                int color = col[u];
                for (int v : adj[u])
                {
                    if (col[v] == 0)
                    {
                        col[v] = -color;
                        q.push(v);
                    }
                    else
                    {
                        if (col[v] == col[u])
                        {
                            return false;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }

    return true;
}
bool dfs(int u, vector<int> adj[], vector<int> &col)
{
    int color = col[u];
    for (int v : adj[u])
    {
        if (col[v] == 0)
        {
            col[v] = -color;
            if (dfs(v, adj, col) == false)
            {
                return false;
            }
        }
        else
        {
            if (col[v] == col[u])
            {
                return false;
            }
            else
                continue;
        }
    }
    return true;
}
bool isBipartiteUsingDFS(int V, vector<int> adj[])
{
    vector<int> col(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (col[i] == 0)
        {
            col[i] = 1;
            if (dfs(i, adj, col) == false)
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
}