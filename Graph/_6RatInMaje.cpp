#include <bits/stdc++.h>
using namespace std;
void solve(int i, int j, string str, vector<vector<int>> &vis, vector<vector<int>> &m, int n, vector<string> &ans)
{
    if (i == (n - 1) && j == (n - 1))
    {
        ans.push_back(str);
        return;
    }
    if (m[i][j] == 0)
        return;
    vis[i][j] = 1;

    // down move
    int I = i + 1;
    int J = j;

    // condition 1    I >= 0 && I<n  &&  J>=0  && J<n
    // condition 2    vis[I][J]==false
    // condition 3    m[I][J] == 1
    if (((I >= 0 && I < n) && (J >= 0 && J < n)) && (vis[I][J] == false) && (m[I][J] == 1))
    {
        solve(I, J, str + "D", vis, m, n, ans);
    }

    // left move
    I = i;
    J = j - 1;
    if (((I >= 0 && I < n) && (J >= 0 && J < n)) && (vis[I][J] == false) && (m[I][J] == 1))
    {
        solve(I, J, str + "L", vis, m, n, ans);
    }

    // right move
    I = i;
    J = j + 1;
    if (((I >= 0 && I < n) && (J >= 0 && J < n)) && (vis[I][J] == false) && (m[I][J] == 1))
    {
        solve(I, J, str + "R", vis, m, n, ans);
    }

    // up move
    I = i - 1;
    J = j;
    if (((I >= 0 && I < n) && (J >= 0 && J < n)) && (vis[I][J] == false) && (m[I][J] == 1))
    {
        solve(I, J, str + "U", vis, m, n, ans);
    }

    vis[i][j] = 0; // backtrack
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<vector<int>> vis(n, vector<int>(n, 0));

    string str = "";
    vector<string> ans;
    solve(0, 0, str, vis, m, n, ans);

    return ans;
}
int main()
{
    int N = 4;
    vector<vector<int>> m = { {1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1} };
    vector<string> ans = findPath(m,N);
    for(string str:ans){
        cout<<str<<" ";
    }
}