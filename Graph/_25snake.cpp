#include <bits/stdc++.h>
using namespace std;

int snakesAndLadders(vector<vector<int>>& board) {
        int n = board[0].size();
        cout<<n<<endl;
        vector<bool>vis(n*n + 1,false);
        queue<int>q;
        q.push(1);
        vis[1] = true;
        int step = 0;
        int tar = n*n;
        cout<<tar<<endl;
        bool found = false;
        if(n==1) found = true;
        while(q.size() && found==false){
            int k = q.size();
            while(k--){
                int idx = q.front();
                q.pop();
                cout<<idx<<" --> ";
                for(int dice = 1; dice <= 6; dice++){
                    int tmp = idx+dice;
                    
                    int i = (tmp-1)/n;
                    int j = (tmp-1)%n;
                    if(i%2==1){
                        j = (n-1)-j;
                    }
                    i = (n-1)-i;
                    // cout<<tmp<<" "<<i<<" "<<j<<" "<<board[i][j]<<" -->> ";
                    
                    if(tmp==tar)  found = true;
                    if(tmp<=tar && vis[tmp]==false && board[i][j]!=-1){
                        vis[tmp] = true;
                        if(board[i][j]==tar) found = true;
                        q.push(board[i][j]);
                        cout<<board[i][j]<<" ";
                    }
                    else if(tmp<=tar && vis[tmp]==false && board[i][j]==-1){
                        vis[tmp] = true;
                        q.push(tmp);
                        cout<<tmp<<" ";
                    }
                }
                cout<<endl;
            }
            step++;
        }
        if(found == false) return -1;

        return step;
        
    }
int main()
{
    // vector<vector<int>> board = {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
    vector<vector<int>> board = {{-1,-1},{-1,3}};
    cout << snakesAndLadders(board) << endl;
}