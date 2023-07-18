#include <bits/stdc++.h>
using namespace std;
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    vector<int> dist(n, 1e9);
    int m = edges.size();
    if (m == 0)                    // handle no. of edges 0 case
        return 0;
    dist[edges[0][0]] = 0;         // can't do dist[0]=0  
    int cnt = n - 1;
    while (cnt--)
    {
        for (int i = 0; i < m; i++)
        {
            int par = edges[i][0];
            int child = edges[i][1];
            int w = edges[i][2];
            if ((dist[par] != 1e9) && dist[child] > dist[par] + w)
            {
                dist[child] = dist[par] + w;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int par = edges[i][0];
        int child = edges[i][1];
        int w = edges[i][2];
        if ((dist[par] != 1e9) && dist[child] > dist[par] + w)
        {
            return 1;
        }
    }
    return 0;
}
int main(){
    int n = 5;
    vector<vector<int>> edges =  {{1,0,5},{1,4,6},{1,2,-2},{2,3,3},{3,1,-4}};
    cout<<isNegativeWeightCycle(n,edges)<<endl;


    // int n = 1;
    // vector<vector<int>> edges =  {};                         
    // cout<<isNegativeWeightCycle(n,edges)<<endl;
}