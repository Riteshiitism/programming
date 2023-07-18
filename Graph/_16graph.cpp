#include <bits/stdc++.h>
using namespace std;
// Function to find the number of islands.
// bool chk(vector<vector<bool>> &vis, int I, int J, int n, int m, vector<vector<char>> &grid)
// {
//     if ((((I >= 0 && I < n) && (J >= 0 && J < m)) && !vis[I][J]) && (grid[I][J] == '1'))
//     {
//         return true;
//     }
//     return false;
// }
// void dfs(int i, int j, vector<vector<char>> &grid, int n, int m, vector<vector<bool>> &vis)
// {
//     vis[i][j] = true;

//     // left-up
//     int I = i - 1;
//     int J = j - 1;
//     if (chk(vis, I, J, n, m, grid))
//     {
//         dfs(I, J, grid, n, m, vis);
//     }

//     // up
//     I = i - 1;
//     J = j;
//     if (chk(vis, I, J, n, m, grid))
//     {
//         dfs(I, J, grid, n, m, vis);
//     }

//     // up - right
//     I = i - 1;
//     J = j + 1;
//     if (chk(vis, I, J, n, m, grid))
//     {
//         dfs(I, J, grid, n, m, vis);
//     }

//     // right
//     I = i;
//     J = j + 1;
//     if (chk(vis, I, J, n, m, grid))
//     {
//         dfs(I, J, grid, n, m, vis);
//     }

//     // right-bottom
//     I = i + 1;
//     J = j + 1;
//     if (chk(vis, I, J, n, m, grid))
//     {
//         dfs(I, J, grid, n, m, vis);
//     }

//     // bottom
//     I = i + 1;
//     J = j;
//     if (chk(vis, I, J, n, m, grid))
//     {
//         dfs(I, J, grid, n, m, vis);
//     }

//     // bottom-left
//     I = i + 1;
//     J = j - 1;
//     if (chk(vis, I, J, n, m, grid))
//     {
//         dfs(I, J, grid, n, m, vis);
//     }

//     // left
//     I = i;
//     J = j - 1;
//     if (chk(vis, I, J, n, m, grid))
//     {
//         dfs(I, J, grid, n, m, vis);
//     }
// }

// int numIslands(vector<vector<char>> &grid)
// {
//     int n = grid.size();
//     int m = grid[0].size();
//     int cnt = 0;
//     vector<vector<bool>> vis(n, vector<bool>(m, false));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if ((vis[i][j] == false) && (grid[i][j] == '1'))
//             {
//                 cnt++;
//                 dfs(i, j, grid, n, m, vis);
//             }
//         }
//     }
//     return cnt;
// }
bool isValid(int x, int y, vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if (x < 0 || x >= m)
        return false;
    if (y < 0 || y >= n)
        return false;

    if (grid[x][y] == '0')
        return false;

    return true;
}
void bfs(int i, int j, vector<vector<char>> &grid)
{
    int arr_i[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int arr_j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = '0';
    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        int I = tmp.first;
        int J = tmp.second;
        for (int k = 0; k < 8; k++)
        {
            if (isValid(I + arr_i[k], J + arr_j[k], grid))
            {
                cout<<I + arr_i[k]<<" "<<J + arr_j[k]<<endl;
                q.push({I + arr_i[k], J + arr_j[k]});
                grid[I + arr_i[k]][J + arr_j[k]] = '0';
            }
            else
                continue;
        }
    }
    return;
}
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                cout<<i<<" "<<j<<endl;
                ans++;
                bfs(i, j, grid);
            }
        }
    }

    return ans;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>> grid(m,vector<char>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j<n; j++){
            cin>>grid[i][j];
        }
    }

    cout<<numIslands(grid)<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
9 3
0 1 0
0 1 0
0 0 0
1 1 0
1 0 1
0 1 1
1 1 1
0 1 1
1 0 1*/