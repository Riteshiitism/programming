#include <bits/stdc++.h>
using namespace std;
void dfs(int s, vector<int> adj[], vector<bool> &vis, stack<int> &st)
{
    vis[s] = true;
    for (int child : adj[s])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis, st);
        }
    }
    st.push(s);
    return;
}
vector<int> topologicalSort(vector<int> adj[], int v)
{
    //   vector<int>indegree(v,0);
    //   for(int i = 0; i < v; i++){
    //       for(int child:adj[v]){
    //           indegree[child]++;
    //       }
    //   }
    vector<bool> vis(v, false);
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
    while (st.size())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src)
{
    vector<int> adj[v];
    vector<vector<int>> weight(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(v);
        weight[u][v] = w;
    }

    vector<int> dist(v, INT_MIN);

    vector<int> sorted = topologicalSort(adj, v);

    dist[src] = 0;
    for (int i = 0; i < v; i++)
    {
        int u = sorted[i];
        for (int v : adj[u])
        {
            if ((dist[u] != INT_MIN) && dist[v] < dist[u] + weight[u][v])
            {
                dist[v] = dist[u] + weight[u][v];
            }
        }
    }

    return dist;
}
int main()
{
}