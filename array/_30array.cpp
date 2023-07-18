#include <bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    long long res = INT_MAX;
    for (int i = m - 1; i < n; i++)
    {
        res = min(res, a[i] - a[i - (m - 1)]);
    }
    return res;
}