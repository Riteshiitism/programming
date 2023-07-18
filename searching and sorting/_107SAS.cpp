// condition   1 <= arr[i] <= n-1
#include <bits/stdc++.h>
using namespace std;
int repeatingElement(vector<int> arr, int n){// tortoise approach
    int fast = arr[0];
    int slow = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow!=fast);
    slow = arr[0];
    while (slow!=fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
    
}
vector<int> findTwoElement(vector<int> arr, int n)
{
    int B;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] < 0)
        {
            B = abs(arr[i]);
        }
        else
        {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
    }
    int A;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            A = i + 1;
    }
    // int A = abs((n*(n+1)/2)-(sum-B));
    vector<int> ans;
    ans.push_back(B);
    ans.push_back(A);
    return ans;
}

int main()
{
    int n = 3;
    vector<int>arr = {1, 3, 3};
    vector<int> ans = findTwoElement(arr,n);
    for(int val:ans){
        cout<<val<<" ";
    }

}