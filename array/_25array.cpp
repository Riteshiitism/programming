#include <bits/stdc++.h>
using namespace std;
int countOccurence(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]] > (n / k))
        {
            m[arr[i]] = -1;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int arr[] = {3,1,2,2,1,2,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k=4;
    cout << countOccurence(arr, n,k);
}