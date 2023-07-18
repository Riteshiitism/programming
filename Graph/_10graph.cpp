#include <bits/stdc++.h>
using namespace std;
void dfs(int s,vector<int>list[],vector<bool>&vis){
        vis[s]=true;
        for(int child:list[s]){
            if(!vis[child]){
                dfs(child,list,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)  return -1;
        vector<int>list[n];
        for(int i = 0; i < connections.size(); i++){
            int x = connections[i][0];
            int y = connections[i][1];

            list[x].push_back(y);
            list[y].push_back(x);
        }
        int comp = 0;
        vector<bool>vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                comp++;
                dfs(i,list,vis);
            }
        }
        return comp-1;
    }
int main(){
    // vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    vector<vector<int>> connections = {{1,4},{0,3},{1,3},{3,7},{2,7},{0,1},{2,4},{3,6},{5,6},{6,7},{4,7},{0,7},{5,7}};
    int n = 11;
    cout<<makeConnected(n,connections);
}