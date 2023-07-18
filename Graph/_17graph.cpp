#include <bits/stdc++.h>
using namespace std;
void dfs(int s, vector<int> adj[], stack<int> &st, vector<bool> &vis)
{
    vis[s] = true;
    for (int child : adj[s])
    {
        if (vis[child] == false)
        {
            // cout<<child<<" ";
            dfs(child, adj, st, vis);
        }
    }
    st.push(s);
    return;
}
void solve(int idx, vector<pair<char, char>> &ans, string dict[], int N)
{
    vector<int> adj[26];
    for (int i = 0; i < N - 1; i++)
    {
        string str1 = dict[i];
        string str2 = dict[i + 1];
        int m = str1.length();
        int n = str2.length();
        int i1 = 0;
        int i2 = 0;
        bool chk = true;
        while (i1 < m && i2 < n)
        {
            if (str1[i1] == str2[i2])
            {
                i1++;
                i2++;
            }
            else
            {
                chk = false;
                break;
            }
        }
        if (!chk)
        {
            // ans.push_back({str1[a],str2[b]});
            // cout<<str1[i1]<<" "<<str2[i2]<<endl;
            adj[str1[i1] - 'a'].push_back(str2[i2] - 'a');
        }
    }
    // for (int i = 0; i < 26; i++)
    // {
    //     // cout<<i<<"-->";
    //     for (int child:adj[i])
    //     {
    //         cout<<child<<" ";
    //     }
    //     cout<<endl;

    // }

    vector<int> sorted;
    stack<int> st;
    vector<bool> vis(26, false);
    for (int i = 0; i < 26; i++)
    {
        if (adj[i].size() && vis[i] == false)
        {
            // cout<<i<<endl;
            dfs(i, adj, st, vis);
        }
    }
    string str = "";
    while (st.size())
    {
        // cout<<st.top()<<" ";
        char character = char(st.top() + 'a');
        str += character;
        st.pop();
    }
    cout << str << endl;
}
vector<int> indegreeCalc(vector<int> adj[], int k)
{
    vector<int> indegree(26, -1);
    for (int i = 0; i < 26; i++)
    {
        
        for (int child : adj[i])
        {
            indegree[i] = 0;
            indegree[child] = 0;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        for (int child : adj[i])
        {
            indegree[child]++;
        }
    }
    return indegree;
}
string findOrder(string dict[], int n, int k)
{
    vector<int> adj[26];
    for (int i = 0; i < n - 1; i++)       // construct directed graph
    {
        string x = dict[i];
        string y = dict[i + 1];
        int u = 0;
        int v = 0;
        while (u < x.length() && v < y.length() && x[u] == y[v])
        {
            u++;
            v++;
        }
        if (u < x.length() && v < y.length())
        {
            adj[x[u] - 'a'].push_back(y[v] - 'a');       // construct directed graph
        }
    }

    // topological sort
    vector<int> indegree = indegreeCalc(adj, k);
    queue<int> q;
    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        cout<<indegree[i]<<" ";
        if (indegree[i] == 0)
        {
            q.push(i);
            ans.push_back(i + 'a');
        }
    }
    cout<<endl;
    int cnt = 0;
    while (q.size())
    {

        int tmp = q.front();
        q.pop();
        for (int child : adj[tmp])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
                ans.push_back(child + 'a');
            }
        }

        cnt++;
    }
    cout<<cnt<<endl;
    // if (cnt != k)
    //     return "";
    return ans;
}
int main()
{
    // string dict[] = {"baa","abcd","abca","cab","cad"};
    // int N = 5;
    // int K = 4;
    // string ans = findOrder(dict,N,K);

    // string dict[] = {"caa", "aaa", "aab"};
    // int N = 3;
    // int K = 3;
    // vector<pair<char, char>> ans;
    // solve(0, ans, dict, N);
    
    string dict[] = {"wrt","wrf","er","ett","rftt"};
    int N = 5;
    int K = 4;
    cout<<findOrder(dict,N,K)<<endl;;
}