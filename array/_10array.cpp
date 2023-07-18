#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int n, int pos)
{
    if (pos >= n - 1)
        return 0;
    if (arr[pos] == 0)
        return INT_MAX;
    int jump = arr[pos];
    int ans = INT_MAX;
    for (int i = 1; i <= jump; i++)
    {
        ans = min(ans, 1 + solve(arr, n, pos + i));
    }
    return ans;
}
int solveMem(int arr[], int n, int pos, vector<int> &dp)
{
    if (pos >= n - 1)
    {
        dp[pos] = 0;
        return 0;
    }
    if (arr[pos] == 0)
    {
        // dp[pos]=INT_MAX;
        return INT_MAX;
    }
    if (dp[pos] != -1)
        return dp[pos];
    int jump = arr[pos];
    int ans = INT_MAX;
    for (int i = 1; i <= jump; i++)
    {
        ans = min(ans, 1 + solveMem(arr, n, pos + i, dp));
    }

    dp[pos] = ans;
    return dp[pos];
}
int solveTab(int arr[], int n)
{
    vector<int> dp(n, 0);
    for (int i = 1; i <= n - 1; i++)
    {
        int m = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= i - j)
            {
                m = min(m, dp[j] + 1);
            }
        }
        if (m == INT_MAX)
            return -1;
        dp[i] = m;
    }

    return dp[n - 1];
}
int minJumps(int arr[], int n)
{
    // 1st approach
    // return solve(arr,n,0);

    // int N = 1e8;
    // vector<int>dp(N,-1);
    // return solveMem(arr,n,0,dp);

    // return solveTab(arr,n);

    // 2nd approach
    int maxReach = arr[0];
    int jump = 1;
    int step = arr[0];
    if (n == 1)
        return 0;
    else if (arr[0] == 0)
        return -1;
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return jump;
            }
            maxReach = max(maxReach, i + arr[i]);
            step--;
            if (step == 0)
            {
                jump++;
                if (i >= maxReach)
                {
                    return -1;
                }
                step = maxReach - i;
            }
        }
    }
}
int main()
{
    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    // int arr[] = {1, 3, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr, n) << endl;
}