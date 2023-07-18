#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>adj[],int u,vector<int>&vis,int res,int &ans,int cnt,vector<vector<int>>&cost){
    vis[u] = true;
    cnt++;
    if(cnt==vis.size()){
        ans = min(ans,res+cost[u][0]);
        return;
    }
    for(auto it:adj[u]){
        int v = it[0];
        int w = it[1];
        if(vis[v]==false){
            dfs(adj,v,vis,res+w,ans,cnt,cost);
        }
    }
    vis[u]=false;
    cnt--;
}
int tsp(int pos,int mask,int &visAll,vector<vector<int>>&cost,vector<vector<int>>&dp){
    // base case 
    if(mask == visAll){
        return cost[pos][0];
    }
    if(dp[pos][mask]!=-1)  return dp[pos][mask];
    
    int ans = INT_MAX;
    
    for(int city = 0; city < cost.size(); city++){
        if((mask & (1<<city)) == 0){
            int newAns = cost[pos][city] + tsp(city,mask|(1<<city),visAll,cost,dp);
            ans = min(ans,newAns);
        }
    }
    
    dp[pos][mask] = ans;
    return dp[pos][mask];
}
int total_cost(vector<vector<int>>cost){

    // // brute force
    // int V = cost.size();
    // vector<vector<int>>adj[V];
    // for(int i = 0; i < V;i++){
    //     for(int j = 0; j < V; j++){
    //         if(cost[i][j]!=0){
    //             adj[i].push_back({j,cost[i][j]});
    //         }
    //     }
    // }
    
    // int res = 0;
    // int ans = INT_MAX;
    // int cnt = 0;
    // vector<int>vis(V,false);
    // dfs(adj,0,vis,res,ans,0,cost);
    
    // return ans;

    // using dp
    int V = cost.size();
    int visAll = (1<<V)-1;
    vector<vector<int>>dp(V,vector<int>(visAll,-1));
    return tsp(0,1,visAll,cost,dp);
    
    
}
int main(){

}