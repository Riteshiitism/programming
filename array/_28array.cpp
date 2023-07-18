#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(int arr[], int n, int sum)
{
    sort(arr, arr + n);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = arr[i] + arr[j];
            if (m.find(sum - x) != m.end() && m[sum - x] > i && m[sum - x] > j)
            {
                return true;
            }
        }
    }

    return false;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 13;
    cout<<find3Numbers(arr,n,sum)<<endl;
}