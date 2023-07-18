#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size();
    int n = image[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    int pColor = image[sr][sc];
    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        int i = tmp.first;
        int j = tmp.second;
        image[i][j] = color;

        // top
        int I = i - 1;
        int J = j;
        if (((I >= 0 && I < m) && (J >= 0 && J < n)) && (image[I][J] == pColor) && !vis[I][J])
        {
            q.push({I, J});
            vis[I][J] = true;
        }
        // left
        I = i;
        J = j - 1;
        if (((I >= 0 && I < m) && (J >= 0 && J < n)) && (image[I][J] == pColor) && !vis[I][J])
        {
            q.push({I, J});
            vis[I][J] = true;
        }
        // right
        I = i;
        J = j + 1;
        if (((I >= 0 && I < m) && (J >= 0 && J < n)) && (image[I][J] == pColor) && !vis[I][J])
        {
            q.push({I, J});
            vis[I][J] = true;
        }
        // bottom
        I = i + 1;
        J = j;
        if (((I >= 0 && I < m) && (J >= 0 && J < n)) && (image[I][J] == pColor) && !vis[I][J])
        {
            q.push({I, J});
            vis[I][J] = true;
        }
    }
    return image;
}
int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    image = floodFill(image,1,1,2);
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    
}