#include <bits/stdc++.h>
using namespace std;
bool dfs(int s, vector<int> adj[], vector<bool> &vis, int &timer, vector<int> &disc, vector<int> &low, vector<int> &par, int &c, int &d)
{
    vis[s] = true;
    low[s] = disc[s] = timer++;
    for (int child : adj[s])
    {
        if (vis[child] == false)
        {
            par[child] = s;
            if (dfs(child, adj, vis, timer, disc, low, par, c, d))
            {
                return true;
            }
            low[s] = min(low[s], low[child]);

            if ((s == c && child == d))
            {
                if (low[child] > disc[s])
                    return true;
            }
            if ((s == d && child == c))
            {
                if (low[child] > disc[s])
                    return true;
            }
        }
        else
        {
            if (child == par[s])
            {
                continue;
            }
            else
            {
                low[s] = min(low[s], disc[child]);                        // backedge
            }
        }
    }
    return false;
}
int isBridge(int V, vector<int> adj[], int c, int d)
{
    vector<int> disc(V);
    vector<int> low(V);
    vector<int> par(V, -1);
    vector<bool> vis(V, 0);
    int timer = 0;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == false)
        {
            if (dfs(i, adj, vis, timer, disc, low, par, c, d))
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
}