#include <bits/stdc++.h>
using namespace std;
void dfs(int s,vector<int>adj[],vector<bool>&vis,vector<int>&inTime,vector<int>&outTime,int &timer){
	vis[s] = true;
	inTime[s]  = timer++;
	for(int child:adj[s]){
		if(!vis[child]){
			dfs(child,adj,vis,inTime,outTime,timer);
		}
	}
	outTime[s] = timer++;
}
int main() {
	int N;
    cin>>N;
	vector<int>adj[N+1];
	for(int i = 0; i < N-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>inTime(N+1);
	vector<int>outTime(N+1);
	vector<bool>vis(N+1,false);
	int timer = 1;
	dfs(1,adj,vis,inTime,outTime,timer);
	int q;
	cin>>q;
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(  ((inTime[x]<inTime[y])   && (outTime[y]<outTime[x]))  || ((inTime[y]<inTime[x])   && (outTime[x]<outTime[y])) ){
			if(t==0){
				if(inTime[x]<inTime[y]){
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}
			else{
				if(inTime[x]>inTime[y]){
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}
/*
9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1*/