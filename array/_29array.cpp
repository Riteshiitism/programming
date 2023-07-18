#include <bits/stdc++.h>
using namespace std;
long long trappingWater(int arr[], int n)
{
    int l[n];
    int r[n];
    int x = arr[0];
    l[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < x)
        {
            l[i] = x;
        }
        else
        {
            l[i] = 0;
            x = arr[i];
        }
    }
    r[n - 1] = 0;
    x = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < x)
        {
            r[i] = x;
        }
        else
        {
            r[i] = 0;
            x = arr[i];
        }
    }
    long long int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (l[i] != 0 && r[i] != 0)
        {
            ans = ans + min(l[i], r[i]) - arr[i];
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 13;
    cout << trappingWater(arr, n) << endl;
}