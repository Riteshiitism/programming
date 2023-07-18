#include <bits/stdc++.h>
using namespace std;
bool isSafe(int node, int color, vector<int> adj[], vector<int> &col)
{
    for (int child : adj[node])
    {
        if (col[child] == color)
            return false;
    }

    return true;
}
bool solve(vector<int> adj[], int n, int m, vector<int> &col)
{
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 0)
        {
            for (int color = 1; color <= m; color++)
            {
                if (isSafe(i, color, adj, col))
                {
                    col[i] = color;
                    bool shouldMoveForward = solve(adj, n, m, col);
                    if (shouldMoveForward)
                        return true;
                    else
                    {
                        col[i] = 0;
                    }
                }
            }
            return false;
        }
    }
    return true;
}
bool graphColoring(vector<vector<bool>>graph, int m, int n)
{
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j])
            {
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }
    vector<int> col(n + 1, 0);
    bool ans = solve(adj, n, m, col);
    
    for(int i = 1; i <= n; i++){
        cout<<col[i]<<" ";
    }
    cout<<endl;
    return ans;
}
void dfs(int s, vector<int> adj[], vector<bool> &vis, vector<int> &col, int n)
{
    vis[s] = true;
    // cout<<s<<" ";
    vector<bool> available(n + 1, true);
    for (int child : adj[s])
    {
        if (col[child] != -1)
        {
            available[col[child]] = false;
        }
    }
    bool chk = true;
    for (int i = 1; i <= n; i++)
    {
        if (available[i] == true)
        {
            col[s] = i;
            chk = false;
            break;
        }
    }
    if (chk)
    {
        col[s] = 1;
    }
    cout << s << " " << col[s] << endl;
    for (int child : adj[s])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis, col, n);
        }
    }
}
// bool graphColoring(int n, vector<vector<bool>> graph, int m)
// {
//     vector<int> adj[n + 1];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (graph[i][j])
//             {
//                 adj[i + 1].push_back(j + 1);
//                 adj[j + 1].push_back(i + 1);
//             }
//         }
//     }
//     vector<bool> vis(n + 1, false);
//     vector<int> col(n + 1, -1);
//     for (int i = 1; i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             dfs(i, adj, vis, col, n);
//         }
//     }
//     int cnt = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         // cout<<col[i]<<" ";
//         cnt = max(cnt, col[i]);
//     }
//     return cnt <= m;
// }
int countMincolor(int n, vector<vector<bool>> graph, int m)
{
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j])
            {
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }
    vector<int> res(n + 1, -1);
    res[1] = 1;
    vector<bool> available(n + 1, false);
    int cn = 0;
    for (int i = 2; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            if (res[x] != -1)
            {
                available[res[x]] = true;
            }
        }
        int cr;
        for (cr = 1; cr <= n; cr++)
        {
            if (available[cr] == false)
            {
                break;
            }
        }

        res[i] = cr;
        cn = max(cn, cr);
        for (auto x : adj[i])
        {
            if (res[x] != -1)
            {
                available[res[x]] = false;
            }
        }
    }
    cout << cn << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }

    return cn;
}
// void addEdge(vector<int> adj[], int u, int v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
int main()
{
    int N = 12;
    int M = 4;
    vector<vector<bool>> graph(N, vector<bool>(N, 0));
    // bool graph[N][N];

    for (int i = 0; i < 35; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        graph[x - 1][y - 1] = true;
        graph[y - 1][x - 1] = true;
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl<<graphColoring(N,graph,M);
    cout << endl
         << countMincolor(N, graph, M);


         cout<<graphColoring(graph,M,N);
}
/*
1 3 3 9 7 12 8 9 5 8 6 11 9 12 1 12 11 12 7 9 2 12 10 11 3 10 1 7 6 12 2 4 10 12 4 6 2 11 4 5 6 10 2 10 2 9 7 11 2 5 5 12 7 10 7 8 5 10 4 7 6 9 9 11 1 5 2 3 4 12
1-3
3-9
7-12
8-9
5-8
6-11
9-12
1-12
11-12
7-9
2-12
1-11
3-10
1-7
6-12
2-4
10-12
4-6
2-11
4-5
6-10
2-10
2-9
7-11
2-5
5-12
7-10
7-8
5-10
4-7
6-9
9-11
1-5
2-3
4-12
*/
/*
void dfs(int s, vector<int> adj[], vector<bool> &vis, vector<int> &col, int n)
{
    vis[s] = true;
    vector<bool> available(n+1, true);
    for (int child : adj[s])
    {
        if (col[child] != -1)
        {
            available[col[child]] = false;
        }
    }
    bool chk = true;
    for (int i = 1; i <= n; i++)
    {
        if (available[i] == true)
        {
            col[s] = i;
            chk = false;
            break;
        }
    }
    if(chk){
        col[s] = 1;
    }
    for (int child : adj[s])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis, col, n);
        }
    }
}
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>adj[n+1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][j]){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<bool>vis(n+1,false);
        vector<int>col(n+1,-1);
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i,adj,vis,col,n);
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt = max(cnt,col[i]);
        }
        return cnt<=m;
    }*/