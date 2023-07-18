#include <bits/stdc++.h>
using namespace std;
int maxProfitInfiniteTransaction(int prices[], int n)
{
    int profit = 0;
    int buy = prices[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (prices[i] <= prices[i - 1])
        {
            profit += (prices[i - 1] - buy);
            buy = prices[i];
        }
    }
    profit += (prices[i - 1] - buy);
    return profit;
}
int maxProfitTwoTransaction(vector<int> &prices)
{
    int n = prices.size();
    int ans = 0;
    vector<int> profit(n, 0);
    int sell = prices[n - 1];
    profit[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (prices[i] > sell)
        {
            sell = prices[i];
        }
        profit[i] = max(profit[i + 1], sell - prices[i]);
    }

    int buy = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (prices[i] < buy)
        {
            buy = prices[i];
        }
        profit[i] = max(profit[i - 1], profit[i] + (prices[i] - buy));
    }

    return profit[n - 1];
}
int main()
{
    int arr[] = {70, 18, 18, 97, 25, 44, 71, 84, 91, 50, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProfitInfiniteTransaction(arr, n) << endl;
}
// 79+66+22
