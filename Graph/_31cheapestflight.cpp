#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < flights.size(); i++)
    {
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];
        adj[u].push_back({v, w});
    }
    vector<int> price(n, INT_MAX);
    queue<pair<int, pair<int, int>>> q;
    price[src] = 0;
    q.push({0, {src, price[src]}});
    while (q.size())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;
        if (stops > k)
            continue;
        for (auto tmp : adj[node])
        {
            int v = tmp.first;
            int w = tmp.second;
            if (price[v] > cost + w)                 // we can not replace cost with price of node because price of node contains minimum and cost is minimum price with some x stops
            {
                price[v] = cost + w;
                q.push({stops + 1, {v, price[v]}});
            }
        }
    }

    if (price[dst] == INT_MAX)
        return -1;
    return price[dst];
}