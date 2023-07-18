#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n)
{
    // int prefixSum[n]={0};
    // prefixSum[0]=arr[0];
    if (arr[0] == 0)
        return true;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
            return true;
        // prefixSum[i]=prefixSum[i-1]+arr[i];
        arr[i] = arr[i - 1] + arr[i];
        if (arr[i] == 0)
        return true;
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]] >= 2)
        return true;
    }
    return false;
}
int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subArrayExists(arr, n);
}