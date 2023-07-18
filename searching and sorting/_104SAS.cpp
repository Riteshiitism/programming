#include <bits/stdc++.h>
using namespace std;
long long int squreRoot(long long int n)
{
    long long int s = 1;
    long long int e = n;
    long long int ans;
    while (s <= e)
    {
        long long int m = s + (e - s) / 2;
        if (m * m == n)
            return m;
        else if (m * m > n)
        {
            e = m - 1;
        }
        else
        {
            ans = m;
            s = m + 1;
        }
    }
    return ans;
}
int countSquares(int N)
{
    int n = squreRoot(N);
    if (n * n == N)
        return n - 1;
    else
    {
        return n;
    }
}
int main()
{
    int n = 99;
    cout<<countSquares(n);
}