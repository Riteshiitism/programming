#include <bits/stdc++.h>
using namespace std;

bool solve1(int s, int V, vector<int> adj[], vector<vector<int>> weight, vector<bool> &vis, int k)
{
    vis[s] = true;
    if (k <= 0)
        return true;

    for (int child : adj[s])
    {
        if (vis[child] == true)
            continue;

        int w = weight[s][child];
        if (w >= k)
            return true;

        if (solve1(child, V, adj, weight, vis, k - w))
            return true;
    }

    vis[s] = false;
    return false;
}
bool pathMoreThanK1(int V, int E, int k, int arr[])
{
    vector<int> adj[V];
    vector<vector<int>> weight(V, vector<int>(V));

    for (int i = 0; i < 3 * E; i = i + 3)
    {
        int u = arr[i];
        int v = arr[i + 1];
        int w = arr[i + 2];
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[u][v] = max(w, weight[u][v]);
        weight[v][u] = max(w, weight[u][v]);
    }
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << weight[i][j] << " ";
        }
        cout << endl;
    }

    return solve1(0, V, adj, weight, vis, k);
}

bool solve(int src, int k, vector<pair<int, int>> g[], vector<bool> &vis)
{
    vis[src] = true;
    cout << src << " " << k << " ";
    if (k <= 0)
        return true;

    for (auto x : g[src])
    {
        int u = x.first;
        int w = x.second;
        if (vis[u] == true)
            continue;
        if (w >= k)
        {
            cout << u << " " << w << endl;
            return true;
        }

        if (solve(u, k - w, g, vis))
            return true;
    }
    vis[src] = false;
    return false;
}
bool pathMoreThanK(int v, int E, int k, int a[])
{
    vector<pair<int, int>> g[v];

    for (int i = 0; i < 3 * E; i = i + 3)
    {
        g[a[i]].push_back({a[i + 1], a[i + 2]});
        g[a[i + 1]].push_back({a[i], a[i + 2]});
    }
    for (int i = 0; i < 3 * E; i = i + 3)
    {
        for (auto child : g[a[i]])
        {
            if (a[i] == 2)
                cout << a[i] << " " << child.first << " " << child.second << endl;
        }
    }
    vector<bool> vis(v, false);
    return solve(0, k, g, vis);
}

int main()
{
    // 5 6 96
    // int arr[] = {1, 1, 20, 4, 0, 31, 2, 3, 64, 2, 4, 44, 4, 4, 88, 2, 4, 0};
    // // cout<<pathMoreThanK(5,5,96,arr)<<endl;
    // cout << pathMoreThanK1(5, 5, 96, arr) << endl;

    deque<string> st;
    st.push_back("3");
    st.push_back("334");
    st.push_back("34");
    st.push_back("43");

    while(st.size()){
        cout<<st.front()<<" ";
        st.pop_front();
    }
}