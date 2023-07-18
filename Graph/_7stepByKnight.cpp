#include <bits/stdc++.h>
using namespace std;
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    int x1 = KnightPos[0];
    int y1 = KnightPos[1];

    int x2 = TargetPos[0];
    int y2 = TargetPos[1];
    if (x1 == x2 && y1 == y2)
        return 0;

    vector<vector<int>> vis(N + 1, vector<int>(N + 1, 0));
    queue<pair<int, int>> q;
    pair<int, int> p;
    p.first = x1;
    p.second = y1;
    q.push(p);
    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        int i = tmp.first;
        int j = tmp.second;

        int I = i - 2;
        int J = j - 1;
        if (((I >= 1 && I <= N) && (J >= 1 && J <= N)) && vis[I][J] == 0)
        {
            vis[I][J] = 1 + vis[i][j];
            q.push(make_pair(I, J));
        }

        I = i - 2;
        J = j + 1;
        if (((I >= 1 && I <= N) && (J >= 1 && J <= N)) && vis[I][J] == 0)
        {
            vis[I][J] = 1 + vis[i][j];
            q.push(make_pair(I, J));
        }

        I = i - 1;
        J = j + 2;
        if (((I >= 1 && I <= N) && (J >= 1 && J <= N)) && vis[I][J] == 0)
        {
            vis[I][J] = 1 + vis[i][j];
            q.push(make_pair(I, J));
        }

        I = i + 1;
        J = j + 2;
        if (((I >= 1 && I <= N) && (J >= 1 && J <= N)) && vis[I][J] == 0)
        {
            vis[I][J] = 1 + vis[i][j];
            q.push(make_pair(I, J));
        }

        I = i + 2;
        J = j + 1;
        if (((I >= 1 && I <= N) && (J >= 1 && J <= N)) && vis[I][J] == 0)
        {
            vis[I][J] = 1 + vis[i][j];
            q.push(make_pair(I, J));
        }

        I = i + 2;
        J = j - 1;
        if (((I >= 1 && I <= N) && (J >= 1 && J <= N)) && vis[I][J] == 0)
        {
            vis[I][J] = 1 + vis[i][j];
            q.push(make_pair(I, J));
        }

        I = i + 1;
        J = j - 2;
        if (((I >= 1 && I <= N) && (J >= 1 && J <= N)) && vis[I][J] == 0)
        {
            vis[I][J] = 1 + vis[i][j];
            q.push(make_pair(I, J));
        }

        I = i - 1;
        J = j - 2;
        if (((I >= 1 && I <= N) && (J >= 1 && J <= N)) && vis[I][J] == 0)
        {
            vis[I][J] = 1 + vis[i][j];
            q.push(make_pair(I, J));
        }
    }

    return vis[x2][y2];
}
int main()
{
    int N = 6;
    vector<int> knightPos = {4, 5};
    vector<int> targetPos = {1, 1};
    cout<<minStepToReachTarget(knightPos,targetPos,N)<<endl;
}