#include<bits/stdc++.h>
using namespace std;
void dfs(int s,vector<int>adj[],vector<bool>&vis,int &cnt){
    vis[s] = true;
    cnt++;
    for(int child:adj[s]){
        if(!vis[child]){
            dfs(child,adj,vis,cnt);
        }
    }
    return ;
}
long long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    int p = astronaut.size();
    vector<int>adj[n];
    for(int i = 0; i < p; i++){
        int u = astronaut[i][0];
        int v = astronaut[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // cout<<"chk1"<<endl;
    vector<bool>vis(n,false);
    vector<int>con_com;
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        bool chk = true;
        if(!vis[i]){
            chk = false;
            dfs(i,adj,vis,cnt);
        }
        if(chk==false){
            
            con_com.push_back(cnt);
        }
        
    }
    // cout<<"chk1"<<endl;
    long long int ans = (long long int)n*(n-1)/2;        // special way
    int N = con_com.size();
    for(int i = 0; i<N; i++){
        long long int x = (long long int)con_com[i];
        if(con_com[i]>=2){
            ans -= x*(x-1)/2;                             // special way
        }
    }
    cout<<N<<endl;
    return ans;
}
int main(){
    int n = 100000;
    vector<vector<int>>ast = {{1,2},{3,4}};
    // vector<vector<int>>ast = {{1,0},{3,2},{0,4}};
    // vector<vector<int>>ast = {{2,0}};
    cout<<journeyToMoon(n,ast)<<endl;
}
/*
100000 2
1 2
3 4
5 3
0 1
2 3
0 4*/